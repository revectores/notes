# Verilog HDL

### Introduction

**Hardware Description Language**(HDL) is the language used to specify the behaviours of hardware. **Field Programmable Gate Array**(FPGA) is a type of programmable hardware, which uses **VHDL** as the description language.

**Synthesis** Process: Converting HDL into the actual circuit gates. (translate the high-level language into the low-level)



### Basic Structure of Verilog

1. Verilog is constructed by **module**, each module can be split into separate file. every module are specify by `module` and `endmodule`.

2. Each Verilog HDL only contains one **top module**.

3. Each module should defined the input and output ports. We specify IO ports then the internal implementation of it.
4. Time-relative parts store in the `always` block. Inside the `always` block can only register

```verilog
// port definition
module FenPin(clk_in, clk_out);
  // port description
  input clik_in;
  output clk_out;
  
  // variable assignment 
  reg c_out = 0;
  assign clk_out = c_cout;
  always @ (posedge clk_in)
    begin
      c_out =~ c_out;
    end
endmodule
```



```verilog
module AND4(a,b,out);
  output[3:0] out;
  input[3:0] a,b;
  assign out = a&b;
endmodule
```



### Data Type

Two data types included in Verilog, `Net` and `Variable`. The most important type is `wire` in `Net`, and `reg` in `Variable`.



##### # Expression of Number



