module Qtest;
  parameter N = 8;
  reg clk, init, read, write;
  reg [31:0] xin;
  wire [31:0] xout;
  wire Qcomp;
  integer i, c;
  integer file, scan_result;
  reg [31:0] temp;

  QSort DUT(xin, xout, init, clk, Qcomp, read, write);

  initial begin
    // Initialize signals and DUT
    clk = 0;
    init = 0;
    read = 0;
    write = 0;
    DUT.P.state = 4'b0000;
    DUT.C.state = 4'b0000;
    DUT.P.set = 0;
    DUT.S.counter = 0;
    for (i = 0; i < 64; i = i + 1) begin
      DUT.S.mem[i] = 0;
    end

    // Open unsort.txt and read numbers
    #10;
    file = $fopen("unsort.txt", "r");
    if (file == 0) begin
      $display("Error: Could not open unsort.txt");
      $finish;
    end
    read = 1;
    for (i = 0; i < N; i = i + 1) begin
      scan_result = $fscanf(file, "%d\n", temp);
      if (scan_result != 1) begin
        $display("Error: Failed to read number %0d from unsort.txt", i);
        $fclose(file);
        $finish;
      end
      xin = temp;
      $display("Time %0t: Loading vec[%0d] = %0d", $time, i, xin);
      #10;
    end
    $fclose(file);
    read = 0;

    // Display initial array
    for (c = 0; c < N; c = c + 1) begin
      $write("%0d ", DUT.P.vec[c]);
    end
    $write("\n");

    // Trigger sorting
    #10 init = 1;
    #20 init = 0;

    // Wait for completion with timeout
    fork
      wait (Qcomp);
      #10000 begin
        $display("Error: Simulation timed out waiting for Qcomp");
        $finish;
      end
    join_any
    #10 write = 1;
    #80 write = 0;
    #10 $finish;
  end

  // Clock generation
  always #5 clk = ~clk;

  // Waveform dumping
  initial begin
    $dumpfile("Qtest.vcd");
    $dumpvars(0, Qtest);
  end

  // Display sorted array on Qcomp
  always @(posedge Qcomp) begin
    $display("Time %0t: Sorting complete, Qcomp = 1", $time);
    for (c = 0; c < N; c = c + 1) begin
      $write("%0d ", DUT.P.vec[c]);
    end
    $write("\n");
  end

endmodule
// module Qtest;
// parameter N=8 ;
// reg clk,init,read,write;
// reg[31:0] xin;
// wire[31:0] xout;
// wire Qcomp;
// integer i,c;
// integer seed=10;
// QSort DUT(xin,xout,init,clk,Qcomp,read,write);
// initial begin
//     clk=0;
//     init=0;
//     read=0;
//     write=0;
//     DUT.P.state=4'b0000;
//     DUT.C.state=4'b0000;
//     DUT.P.set=0;
//    // DUT.P.vec[0]=13;DUT.P.vec[1]=2;DUT.P.vec[2]=8;DUT.P.vec[3]=12;DUT.P.vec[4]=1;DUT.P.vec[5]=3;DUT.P.vec[6]=31;DUT.P.vec[7]=22;
//     DUT.S.counter=0;
//     for(i=0;i<64;i=i+1)begin
//       DUT.S.mem[i]=0;
//     end
//     #10 read=1;
//     xin=$urandom(seed)%100;
//     for(i=0;i<7;i=i+1)begin
//       #10 xin=$urandom(seed)%100;
//     end
//     //xin=6;#10 xin=2;#10 xin=8;#10 xin=12;#10 xin=1;#10 xin=3;#10 xin=31;#10 xin=22;
//     #10 read=0;
//     for(c=0;c<N;c=c+1)begin
//       $write("%0d ",DUT.P.vec[c]);
//     end
//     $write("\n");
//     #10 init=1;
//     #20 init=0;
//     #1000 write=1;
//     #5000 $finish;
// end
// always #5 clk=~clk;
// initial begin
//     $dumpfile("Qtest.vcd");
//     $dumpvars(0,Qtest);
// end
// always @(posedge Qcomp) begin
//     for(c=0;c<N;c=c+1)begin
//       $write("%0d ",DUT.P.vec[c]);
//     end
//     $write("\n");
// end
// endmodule
