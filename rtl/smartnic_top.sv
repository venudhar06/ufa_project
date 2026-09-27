module smartnic_top (
    input  logic        clk,
    input  logic        rst_n,

    // Software Rule Programming Interface (SRAM Write)
    input  logic        sw_write_en,
    input  logic [7:0]  sw_write_addr,
    input  logic [63:0] sw_write_data,

    // Streaming Network Packet Input
    input  logic        in_valid,
    input  logic [63:0] in_data,
    input  logic        in_last,

    // Lookup Result Output
    output logic        match_valid,
    output logic [63:0] match_action
);

    // Internal Wires connecting Parser to SRAM Lookup
    logic        parser_out_valid;
    logic [31:0] src_ip, dst_ip;
    logic [15:0] src_port, dst_port;
    logic [7:0]  protocol;

    // Instantiate Packet Parser
    packet_parser parser_inst (
        .clk       (clk),
        .rst_n     (rst_n),
        .in_valid  (in_valid),
        .in_data   (in_data),
        .in_last   (in_last),
        .out_valid (parser_out_valid),
        .src_ip    (src_ip),
        .dst_ip    (dst_ip),
        .src_port  (src_port),
        .dst_port  (dst_port),
        .protocol  (protocol)
    );

    // Use lowest byte of Destination IP as the SRAM lookup address
    logic [7:0] lookup_addr;
    assign lookup_addr = dst_ip[7:0];

    // Instantiate SRAM Lookup Engine
    sram_lookup #(
        .DATA_WIDTH(64),
        .ADDR_WIDTH(8)
    ) lookup_inst (
        .clk        (clk),
        .rst_n      (rst_n),
        .write_en   (sw_write_en),
        .write_addr (sw_write_addr),
        .write_data (sw_write_data),
        .req_valid  (parser_out_valid),
        .req_addr   (lookup_addr),
        .resp_valid (match_valid),
        .resp_data  (match_action)
    );

endmodule
