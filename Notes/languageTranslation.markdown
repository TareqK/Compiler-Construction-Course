# Language Translation

Early programmers used *Machine Language* to program ie, The language of
numbers. The Programmer wrote his program in HEX which is translated
automatically to binary. For example, look at the following piece of 
code:

```HEX
2 4 6 3 
3 4 4 6
5 4 5 7
```

This is a Machine Language program. 

Later on, they improved this and created assembly. In compiler construction,
there is no difference between Assembly and Machine Language. Assembly
simply gave *mnemonics* to Machine Language instructions. Assuming 
some architecture X, the above hex program would be 

```ASSEMBLY
LOD 4,X
ADD 4,y
STO 4,Z
```
in Assembly. Assuming 4 is a certain register, the above code means

>Load the contents of memory location 63 whose name is X into register 4.
>
>Add the value stored in memory location 46 whose name is Y to the value in register 4.
>
>Store the value stored in register 4 to the memory location 57 whose name is Z. 

This was still difficult. After Assembly, we created **High Level Languages** such as Pascal, Basic, ADA, C, etc. And with 
the creation of High Level Languages, there was now a need for **Translators**.

## What is a Translator?

The Most general definition of a translator is:

> A Translator is an Algorithm Which Translates the Source Code Into 
> a Target Code. 

so basically, The process is : 

> Source Code -> Translator -> Target Code.

In Reality, the process is more nuanced, but that is the basic flow. 

If the source code is an assembly language program, and the target code
is a machine language program, the translator is called an **Assembler**.
If the source code is a high-level language program, and the target
code is assembly or machine language, the translator is called a **Compiler**.


### Compilers 
given the above, a compiler is defined as :

> An Algorithm that Translates High Level Language Program
> to an Assembly Program or a Machine Language Program.

The Process of compilation and execution, for say, C code is :

>       	    	                     Library Linking             Input Data
>           	    	                            V                         V
> 		Source Code(*.c) -> Compiler(gcc) -> Object Code(*.obj) -> Executable Code(*.bin) -> Output Data
>

A Compiler **generates** Object Code(Machine Code). This is in contrast with an **Interpreter**

### Interpreters

A Simple definition of an interpreter is:

> An Interpreter is an Algorithm that Translates the Source Code to 
> an Intermediate Code which is Executed by Another Algorithm(Program)
> with the Input Data to Produce the Output Data. 

The General process of interpretation is :

>       	    	                    			Input Data
>           	    	                                              V
> 		Source Code -> Interpreter -> Intermediate Code -> Another Algorithm -> Output Data
>
