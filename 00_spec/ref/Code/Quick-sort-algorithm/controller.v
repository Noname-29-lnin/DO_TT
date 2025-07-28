module controller(clk,init,size,empty,complete,ret1,ret2,val1,val2,loc,push,pop,init_p,Qcomp);
  input clk,init,empty,complete;
  input[31:0] ret1,ret2,loc,size;
  output reg push,pop,init_p;
  output reg[31:0] val1,val2;
  output reg Qcomp;
  parameter S0=4'b0000,S1=4'b0001,S2=4'b0010,S3=4'b0011,S4=4'b0100,S5=4'b0101,S6=4'b0110,S7=4'b0111,S8=4'b1000,S9=4'b1001,Si=4'b1010;
  reg[3:0] state;
  reg[31:0]  i,j;
  //reg[31:0] loc;
  always @(posedge clk)
  begin
    case(state)
      S0:
        state<=init?S9:Si;
      Si:
        state<=init?S0:Si;
      S9:
        state<=S1;
      S1:
        state<=empty?S0:S2;
      S2:
        state<=S3;
      S3:
        state<=S4;
      S4:
        state<=complete?S5:S4;
      S5:
        state<=S6;
      S6:
        state<=S7;
      S7:
        state<=S8;
      S8:
        state<=S1;
    endcase
  end
  always @(state)
  begin
    case(state)
      S0:
      begin
        push<=1;
        val1<=0;
        val2<=size-1;
        Qcomp<=0;
        init_p<=0;
      end
      Si:
      begin
        Qcomp<=1;
        push<=0;
      end
      S9:
      begin
        push<=0;
      end
      S2:
      begin
        pop<=1;
        push<=0;
      end
      S3:
        pop<=0;
      S4:
        init_p<=1;
      S5:
        init_p<=0;
      S6:
      begin
        if(ret1<(loc-1) && loc>0)
        begin
          push<=1;
          val1<=ret1;
          val2<=loc-1;
        end
      end
      S7:
      begin
        if((loc+1)<ret2 && loc[31]==0)
        begin
          push<=1;
          val1<=loc+1;
          val2<=ret2;
        end
      end
      S8:
        push<=0;
    endcase
  end
endmodule
