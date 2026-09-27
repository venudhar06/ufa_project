module sram_lookup #(
    parameter DATA_WIDTH = 64,
    parameter ADDR_WIDTH = 8
)(
    input  logic                  clk,
    input  logic                  rst_n,
    
    // Write Interface (Software populates flow rules)
    input  logic                  write_en,
    input  logic [ADDR_WIDTH-1:0] write_addr,
    input  logic [DATA_WIDTH-1:0] write_data,
    
    // Read/Lookup Interface (Hardware queries rules)
    input  logic                  req_valid,
    input  logic [ADDR_WIDTH-1:0] req_addr,
    output logic                  resp_valid,
    output logic [DATA_WIDTH-1:0] resp_data
);

    // 256-entry SRAM lookup table (64-bit entries)
    logic [DATA_WIDTH-1:0] memory [0:(1<<ADDR_WIDTH)-1];

    // Synchronous Read/Write Logic
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            resp_valid <= 1'b0;
            resp_data  <= '0;
        end else begin
            // Handle write operation
            if (write_en) begin
                memory[write_addr] <= write_data;
            end
            
            // Handle read lookup operation (1 cycle latency)
            resp_valid <= req_valid;
            if (req_valid) begin
                resp_data <= memory[req_addr];
            end
        end
    end

endmodule
