# alejandro_mozqueda_proj2

Two numbers will be inserted into some operation in hexadecimal format. The hexadecimal 
prefix is ”0x” and is not to be considered in any conversion process. The uint32t data 
type in C/C++ is being used to store the number as an unsigned 32-bit number. The provided 
text file is used as an example input. This program reads various commands, and it will 
perform the operation between the two hexadecimal numbers. The result of the operation 
is displayed to the terminal and build environment.
- ADD
- AND
- ASR
- LSR
- LSL
- NOT
- ORR
- SUB
- XOR
Every operation uses unsigned 32-bit values except the ASR operation. For ASR, 
the values are treated as signed 32-bit values. Using the provided text file as
an example input. 
The results output is printed in the same order as the text input file as the value 
in 32 bits.
