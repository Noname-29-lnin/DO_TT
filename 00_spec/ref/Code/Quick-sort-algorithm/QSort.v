module  QSort(xin,xout,init,clk,Qcomp,read,write);
  parameter N=8 ;
  input clk,init,read,write;
  output Qcomp;
  input[31:0] xin;
  output[31:0] xout;
  wire[31:0] ret1,ret2,val1,val2,out;
  wire[31:0] size;
  wire init_p,empty,complete,push,pop,c;
  assign size=N;
  assign c=clk;
  controller C(clk,init,size,empty,complete,ret1,ret2,val1,val2,out,push,pop,init_p,Qcomp);
  stack S(clk,val1,val2,push,pop,ret1,ret2,empty);
  partition P(xin,xout,ret1,ret2,ret1,out,clk,init_p,complete,read,write);
endmodule
