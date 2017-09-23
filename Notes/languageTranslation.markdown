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

If the source code is an assembly language program, and the target code
is a machine language program, the translator is called an **Assembler**.
If the source code is a high-level language program, and the target
code is assembly or machine language, the translator is called a **Compiler**.


## Compilers 

given the above, a compiler is defined as :

> An Algorithm that Translates High Level Language Program
> to an Assembly Program or a Machine Language Program.

The Process of compilation and execution, for say, C code is :
```
                                    Library Linking             Input Data
                                           V                         V
Source Code(*.c) -> Compiler(gcc) -> Object Code(*.obj) -> Executable Code(*.bin) -> Output Data
```
A Compiler **generates Object Code(Machine Code)**. This is in contrast with an **Interpreter**

#### Advantages 

- Generate Object Code

- Faster Programs

#### Disadvantages

- Harder to Implement

## Interpreters

A Simple definition of an interpreter is:

> An Interpreter is an Algorithm that Translates the Source Code to 
> an Intermediate Code which is Executed by Another Algorithm(Program)
> with the Input Data to Produce the Output Data. 

The General process of interpretation is :
```
                                                     Input Data
                                                          V
Source Code -> Interpreter -> Intermediate Code -> Another Algorithm -> Output Data
```

A simple interpretation would be changing an equation from infix to postfix and calculation it.
```
                                                     Input Data
                                                          V
infix Code -> Translator Converter -> postfix Code -> Some Program -> Result
```

in Java : 
```
                                    Input Data
                                         V
*.java -> Java Compiler -> Byte Code -> JVM -> Result
```
#### Advantages

- Interpreters generate a **Portable** intermediate code. This means we can 
**Write Once Run Everywhere**.

- Easier to Implement

#### Disadvantages

- Slower

Both Compilers and Interpreters Perform the Following Steps :

- Lexical Analysis(scanner) : Which simply groups the characters of the
source code to form what is called the **Tokens**. This Only detects
legal character errors.

- Syntax Analysis : Groups the set of tokens from the scanner to form 
**Syntax Structures**. This Catches syntax errors.

- Semantic Analysis : Gives the syntax structures meaning. This is 
the hardest task.

- Code Generation : Both Compilers and Interpreters do code generation, 
but they differ in how. While the Compiler generates *Object Code*, the 
interpreter generates *Intermediate Code*. 

These similarities and differences are highlighted in the following diagram:


![Translation Workflow](./images/Translation-Workflow.png)

## Runtime Environment

A Runtime Environment is defined as :

> The Space Allocation for Programs and Data in Memory During Execution.

There are 3 types of Runtime Environment :

1. Fully-Static Environment.

2. Fully-Dynamic Environment.

3. Stack-Based Environment.

### Fully-Static Environments

In this type of environment, **all** properties of the programming language are predetermined before 
execution. This means that all the **address allocation is performed when the 
code is loaded**, not when it is run.


FORTRAN for example, uses this scheme.
In FORTRAN, all memory locations of all variables are fixed during
program execution. In Addition, FORTRAN has only one type of procedure/function
called **subroutine**. In Subroutines, there are **no nested subroutines**, ie, 
you cannot define a subroutine in a subroutine.
This also means that there is **no recursion**. Thus, the original FORTRAN is suitable
for a fully-static environment. 

### Fully-Dynamic Environments

This Scheme is more suitable for dynamically computed 
procedures such as LISP. It is best with functional and logical programming. This is because
it allows us to do recursive function calls, as the allocation is done dynamically. 

### Stack Based Environments 

It Is A Hybrid of the above 2 schemes. In This Kind of environment, the static allocation is used
for the variables and other data structures, while a stack is used for recursion, 
nested functions, and procedures during execution.  This scheme is best used with block structured
languages (Imperative/Procedural languages) such as all ALGOL-like languages including 
Pascal, C, Modula, Ada, etc. 

**TODO ADD DIAGRAM OF THIS ENVIRONMENT MEMORY MAP. TAKE IT FROM ASHJAN**

Indeed, most languages today use this scheme. 

Languages with strong static structures are more likely to be compiled. 
ie, generally, imperative languages are compiled. Conversely, 
Languages with more dynamic structures are more likely to be interpreted, 
ie, generally, functional and logical languages are interpreted. 

## Error Detection and Recovery

During any point or place in the translation process,
errors can arise. Generally, efficiency is a trade-off with 
complexity in error handling. The Faster we handle errors, the 
less robust our error handling will be. More complex error handling 
routines, while they do make using the language and fixing bugs
easier, they take more processing power and time.

There are 4 types of errors that can arise in the compilation process:

1. Lexical Errors : Lexical Errors arise when an illegal *character* is detected. an 
   example of this is the number symbol in C. they are easiest to find and fix and 
   are detected during Lexcical Analysis.

2. Syntax errors : Syntax Errors arise when  grammatical errors are detected.
 This happens when the source code does not follow the grammar of the syntax 
 language, ie, the *Production Rules*. An example of this is missing semicolons
 in C and Java. They are the a little harder but still easy to find and fix. They 
 are detected during Syntax Analysis

3. Semantic Errors :
Semantic Errors are detected either during Semantic Analysis or During Execution.
There are 2 types of Semantic Errors :

   - Static : And these are pre-excecution. An example of these
	 are type mismatch errors.
	 
   - Dynamic : And these are detected **only** during execution. An example
     of these is division by zero.
     
4. Logical Errors :
These are errors that are related to the logic the code was written in, and 
what the programmer thinks he means with a statement vs what the compiler
actually understands it as. This is completely human error, and is the 
hardest to fix.

## Programming Languages Domain

Programming Languages are divided into several domains

1. Scientific Domain : This Domain includes all applications with 
a computational base. Languages in this domain include FORTRAN, C, and 
ALGOL60 .

2. Business Domain : This Domain includes all applications used for 
commercial purposes. Languages in this domain include COBOL and JAVA.

3. Educational Domain 
