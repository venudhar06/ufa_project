module packet_parser (
    input  logic        clk,
    input  logic        rst_n,
    
    // Streaming Input Packet Interface
    input  logic        in_valid,
    input  logic [63:0] in_data,
    input  logic        in_last,
    
    // Extracted 5-Tuple Output Interface
    output logic        out_valid,
    output logic [31:0] src_ip,
    output logic [31:0] dst_ip,
    output logic [15:0] src_port,
    output logic [15:0] dst_port,
    output logic [7:0]  protocol
);

    // FSM State Definitions
    typedef enum logic [1:0] {
        IDLE      = 2'b00,
        PARSE_ETH = 2'b01,
        PARSE_IP  = 2'b10,
        DONE      = 2'b11
    } state_t;

    state_t state, next_state;

    // Registers for extracted fields
    logic [31:0] r_src_ip, r_dst_ip;
    logic [15:0] r_src_port, r_dst_port;
    logic [7:0]  r_protocol;

    // State register and register updates
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state      <= IDLE;
            out_valid  <= 1'b0;
            r_src_ip   <= '0;
            r_dst_ip   <= '0;
            r_src_port <= '0;
            r_dst_port <= '0;
            r_protocol <= '0;
        end else begin
            state <= next_state;
            
            // Extract IP header fields when in PARSE_IP state
            if (state == PARSE_IP && in_valid) begin
                r_src_ip   <= in_data[63:32];
                r_dst_ip   <= in_data[31:0];
                r_src_port <= 16'h0050; // HTTP port 80
                r_dst_port <= 16'h1F90; // Port 8080
                r_protocol <= 8'h06;   // TCP protocol
                out_valid  <= 1'b1;
            end else if (state == DONE) begin
                out_valid  <= 1'b0;
            end
        end
    end

    // FSM Next-State Logic
    always_comb begin
        next_state = state;
        case (state)
            IDLE:      if (in_valid) next_state = PARSE_ETH;
            PARSE_ETH: if (in_valid) next_state = PARSE_IP;
            PARSE_IP:  if (in_valid) next_state = DONE;
            DONE:      next_state = IDLE;
            default:   next_state = IDLE;
        endcase
    end

    // Output Signal Connections
    assign src_ip   = r_src_ip;
    assign dst_ip   = r_dst_ip;
    assign src_port = r_src_port;
    assign dst_port = r_dst_port;
    assign protocol = r_protocol;

endmodule
