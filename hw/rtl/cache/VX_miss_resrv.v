`include "VX_cache_define.vh"

module VX_miss_resrv #(
    parameter CACHE_ID          = 0,
    parameter BANK_ID           = 0, 
    
    // Number of Word requests per cycle
    parameter NUM_REQS          = 1, 
    
    // Size of line inside a bank in bytes
    parameter CACHE_LINE_SIZE   = 1, 
    // Number of banks
    parameter NUM_BANKS         = 1,
    // Number of ports per banks
    parameter NUM_PORTS         = 1,
    // Size of a word in bytes
    parameter WORD_SIZE         = 1, 
    // Miss Reserv Queue Knob
    parameter MSHR_SIZE         = 1, 
    parameter ALM_FULL          = (MSHR_SIZE-1),
    // core request tag size
    parameter CORE_TAG_WIDTH    = 1,

    localparam MSHR_ADDR_WIDTH = $clog2(MSHR_SIZE)
) (
    input wire clk,
    input wire reset,

`ifdef DBG_CACHE_REQ_INFO
`IGNORE_UNUSED_BEGIN
    input wire[31:0]                    deq_debug_pc,
    input wire[`NW_BITS-1:0]            deq_debug_wid,
    input wire[31:0]                    lkp_debug_pc,
    input wire[`NW_BITS-1:0]            lkp_debug_wid,
    input wire[31:0]                    rel_debug_pc,
    input wire[`NW_BITS-1:0]            rel_debug_wid,
`IGNORE_UNUSED_END
`endif

    // allocate
    input wire                          allocate_valid,
    input wire [`LINE_ADDR_WIDTH-1:0]   allocate_addr,
    input wire [`MSHR_DATA_WIDTH-1:0]   allocate_data,
    output wire [MSHR_ADDR_WIDTH-1:0]   allocate_id,   
    output wire                         allocate_ready,

    // fill
    input wire                          fill_valid,
    input wire [MSHR_ADDR_WIDTH-1:0]    fill_id,

    // lookup
    input wire                          lookup_valid,
    input wire                          lookup_replay,   
    input wire [MSHR_ADDR_WIDTH-1:0]    lookup_id,
    input wire [`LINE_ADDR_WIDTH-1:0]   lookup_addr,
    output wire                         lookup_match,
    
    // dequeue    
    output wire                         dequeue_valid,
    output wire [MSHR_ADDR_WIDTH-1:0]   dequeue_id,
    output wire [`LINE_ADDR_WIDTH-1:0]  dequeue_addr,
    output wire [`MSHR_DATA_WIDTH-1:0]  dequeue_data,
    input wire                          dequeue_ready,

    // release
    input wire                          release_valid,
    input wire [MSHR_ADDR_WIDTH-1:0]    release_id
);
    `UNUSED_PARAM (CACHE_ID)
    `UNUSED_PARAM (BANK_ID)
    
    reg [MSHR_SIZE-1:0][`LINE_ADDR_WIDTH-1:0] addr_table, addr_table_n;
    reg [MSHR_SIZE-1:0] valid_table, valid_table_n;
    reg [MSHR_SIZE-1:0] ready_table, ready_table_n;
    
    reg allocate_rdy_r, allocate_rdy_n;
    reg [MSHR_ADDR_WIDTH-1:0] allocate_id_r, allocate_id_n;
    
    reg dequeue_val_r, dequeue_val_n, dequeue_val_x;
    reg [MSHR_ADDR_WIDTH-1:0] dequeue_id_r, dequeue_id_n, dequeue_id_x;

    reg [MSHR_SIZE-1:0] valid_table_x;
    reg [MSHR_SIZE-1:0] ready_table_x;

    wire [MSHR_SIZE-1:0] addr_match;
    
    wire allocate_fire = allocate_valid && allocate_ready;
    
    wire dequeue_fire = dequeue_valid && dequeue_ready;

    for (genvar i = 0; i < MSHR_SIZE; ++i) begin
        assign addr_match[i] = (i != lookup_id) && valid_table[i] && (addr_table[i] == lookup_addr);
    end
    
    always @(*) begin
        valid_table_x = valid_table;
        ready_table_x = ready_table;
        if (dequeue_fire) begin
            valid_table_x[dequeue_id] = 0;
        end
        if (lookup_replay) begin            
            ready_table_x |= addr_match;
        end
    end

    VX_priority_encoder #(
        .N (MSHR_SIZE)
    ) dequeue_pe (
        .data_in    (valid_table_x & ready_table_x),
        .index      (dequeue_id_x),
        .valid_out  (dequeue_val_x),
        `UNUSED_PIN (onehot)    
    );

    VX_priority_encoder #(
        .N (MSHR_SIZE)
    ) allocate_pe (
        .data_in    (~valid_table_n),
        .index      (allocate_id_n),
        .valid_out  (allocate_rdy_n),
        `UNUSED_PIN (onehot)    
    );

    always @(*) begin
        valid_table_n = valid_table_x;
        ready_table_n = ready_table_x;
        addr_table_n  = addr_table;
        dequeue_val_n = dequeue_val_r;
        dequeue_id_n  = dequeue_id_r;

        if (dequeue_fire) begin
            dequeue_val_n = dequeue_val_x;            
            dequeue_id_n  = dequeue_id_x;
        end

        if (allocate_fire) begin
            valid_table_n[allocate_id] = 1;
            ready_table_n[allocate_id] = 0;
            addr_table_n[allocate_id]  = allocate_addr;
        end

        if (fill_valid) begin
            dequeue_val_n = 1;
            dequeue_id_n  = fill_id;
        end

        if (release_valid) begin
            valid_table_n[release_id] = 0;
        end
    end

    always @(posedge clk) begin
        if (reset) begin
            valid_table    <= 0;
            allocate_rdy_r <= 0;
            dequeue_val_r  <= 0;
        end else begin
            valid_table    <= valid_table_n;
            allocate_rdy_r <= allocate_rdy_n;
            dequeue_val_r  <= dequeue_val_n;      
        end
        ready_table   <= ready_table_n;
        addr_table    <= addr_table_n;                
        dequeue_id_r  <= dequeue_id_n;
        allocate_id_r <= allocate_id_n;

        assert(!allocate_fire || !valid_table[allocate_id_r]);        
        assert(!release_valid || valid_table[release_id]);
    end

    `RUNTIME_ASSERT((!fill_valid || valid_table[fill_id]), ("%t: *** cache%0d:%0d invalid fill: addr=%0h, id=%0d", $time, CACHE_ID, BANK_ID, 
        `LINE_TO_BYTE_ADDR(addr_table[fill_id], BANK_ID), fill_id))

    VX_dp_ram #(
        .DATAW   (`MSHR_DATA_WIDTH),
        .SIZE    (MSHR_SIZE),
        .RWCHECK (1),
        .FASTRAM (1)
    ) entries (
        .clk    (clk),
        .waddr  (allocate_id_r),                                
        .raddr  (dequeue_id_r),
        .wren   (allocate_valid),
        .byteen (1'b1),
        .rden   (1'b1),
        .din    (allocate_data),
        .dout   (dequeue_data)
    );

    assign allocate_ready = allocate_rdy_r;
    assign allocate_id    = allocate_id_r;

    assign dequeue_valid  = dequeue_val_r;
    assign dequeue_id     = dequeue_id_r;
    assign dequeue_addr   = addr_table[dequeue_id_r];

    assign lookup_match  = (| addr_match);

    `UNUSED_VAR (lookup_valid)

`ifdef DBG_PRINT_CACHE_MSHR        
    always @(posedge clk) begin
        if (allocate_fire || fill_valid || dequeue_fire || lookup_replay || lookup_valid || release_valid) begin
            if (allocate_fire)
                $display("%t: cache%0d:%0d mshr-allocate: addr=%0h, id=%0d, wid=%0d, PC=%0h", $time, CACHE_ID, BANK_ID,
                    `LINE_TO_BYTE_ADDR(allocate_addr, BANK_ID), allocate_id, deq_debug_wid, deq_debug_pc);
            if (fill_valid)
                $display("%t: cache%0d:%0d mshr-fill: addr=%0h, id=%0d", $time, CACHE_ID, BANK_ID, 
                    `LINE_TO_BYTE_ADDR(addr_table[fill_id], BANK_ID), fill_id);
            if (dequeue_fire)
                $display("%t: cache%0d:%0d mshr-dequeue: addr=%0h, id=%0d, wid=%0d, PC=%0h", $time, CACHE_ID, BANK_ID, 
                    `LINE_TO_BYTE_ADDR(dequeue_addr, BANK_ID), dequeue_id_r, deq_debug_wid, deq_debug_pc);      
            if (lookup_replay)
                $display("%t: cache%0d:%0d mshr-replay: addr=%0h, id=%0d", $time, CACHE_ID, BANK_ID, 
                    `LINE_TO_BYTE_ADDR(lookup_addr, BANK_ID), lookup_id);
            if (lookup_valid)
                $display("%t: cache%0d:%0d mshr-lookup: addr=%0h, id=%0d, match=%b, wid=%0d, PC=%0h", $time, CACHE_ID, BANK_ID, 
                    `LINE_TO_BYTE_ADDR(lookup_addr, BANK_ID), lookup_id, lookup_match, lkp_debug_wid, lkp_debug_pc);
            if (release_valid)
                $display("%t: cache%0d:%0d mshr-release id=%0d, wid=%0d, PC=%0h", $time, CACHE_ID, BANK_ID, 
                    release_id, rel_debug_wid, rel_debug_pc);
            $write("%t: cache%0d:%0d mshr-table", $time, CACHE_ID, BANK_ID);
            for (integer i = 0; i < MSHR_SIZE; ++i) begin
                if (valid_table[i]) begin
                    $write(" ");                    
                    if (ready_table[i]) 
                        $write("*");
                    $write("%0d=%0h", i, `LINE_TO_BYTE_ADDR(addr_table[i], BANK_ID));
                end
            end
            $write("\n");
        end        
    end
`endif

endmodule