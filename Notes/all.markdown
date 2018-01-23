# Reasons to study Programming Language Concepts

1. To increase the ability to learn new languages

2. Knowing the structure of a programming language makes it easier to understand.

3. To increase the ability to design new languages.for example it is known that
the if...else structure is ambiguous. This means that the compiler does not 
know which direction to take when parsing it. In a case like this, the designer
must take into consideration ambiguity when putting down production rules

4. It is an overall advancement in computing 

# What is a Programming Language?

A language is a system of signs used to communicate.(This definition also 
includes spoken language). All languages have grammar and vocabulary. Grammar
is how we express a language. It is a specific set of rules(with some 
exceptions in some cases). 

Programming languages are the same, they have a set of rules, called Production
rules, which are its grammar. The main difference between spoken languages
and written languages is that the rules are hard ie there are no exceptions
to rules.

This leads us to a general definition:

>A Programming language is 
a system of signs used 
by a person to communicate
with the computer machine.  

Or a more specific definition:

>A Programming language is
a notational system  for 
describing **COMPUTATION**
in **MACHINE READABLE** and
**HUMAN READABLE** form.

There are three Key concepts in this definition:

1. Computation 

All what computers about. This is everything that happens
in a computer on a low level regardless of the application. Everything we 
know in programming is eventually simplified into small computational 
operations(Arithmetic operations).

2. Machine Readable 

There must be an algorithm to translate the programming 
language code in an *unambiguous* and *finite* way. The algorithm must be 
simple and straight-forward, and usually  takes time proportional to the size
of the program. Machine Readability is ensured by restricting the structure of
the programming language(syntax) to a *context-free grammar*(CFG) which is a 
system/model to express the syntax of the programming language. Because of such
a system, we can create algorithms for translators in a way that produce 
something machine readable.    

3. Human Readable

A Very important aspect of a program is to be readable. This
began with high-level languages. A Programming Language must provide
*abstraction* as 
-Data Abstraction : Which means giving variables and such names.
 - Simple : such as "integer" or "int" or "char" 
 - Structured : such as arrays or strings
   		
- Control Abstraction : Which means clarifying operations.
 - Simple : Such as the Assignment Statement "=" or ":"
 - Structured : which is divided to a group of instruction or assignment statements Such as "if/else","for", "while", Block statements. 

For a  more precise and complete definition of programming languages, instead of a
variable definition, A Programming language can be divided into 2 parts:

1. Syntax, or the structure.

2. Semantics, or the meaning. 

This is considered a concrete definition of a programming language.


# Programming Language Concepts

## Syntax

The Syntax is the grammar of the programming language. It describes the 
different structures such as expressions, statements, and blocks. 

The Syntax is formally described using a Context Free Grammar(CFG), which is a 
set of static algorithms and frameworks.


## Semantics

The Semantics describe or gives the Syntax structure a meaning. It
is more complex and difficult to describe precisely unlike syntax.
For example, the meaning of the "if/else" statement must be programmed correctly
by the implementer so that the compiler generates the correct code.

Unfortunately, there is no clear formal to describe Semantics analysis unlike
Syntax. However, there is a framework called Syntax Directed Translation(SDT)
which is used to express the semantic analysis. 


## The whole process

Code -> Scanner(Lexical Structure) -> Tokens -> Syntax analyzer -> Object Code

the Scanner takes the statements and analyzes them, creating tokens,
Then the Syntax analyzer takes the tokens and tries to create Syntax structures.
If a group of tokens creates a valid expression, it moves to the next set of
tokens.


For example, lets look at this small segment of code:

```C

if(x!=10 ){

n++;

}

```

the tokens in this code would be "if","(","x","!=",")","{","n","++",";","}" .
This is very important for parsing.

after the Scanner has tokenized the statement in the above section ,
the Syntax analyzer first checks:

> if(x!=10)

if it is correct, then it checks

> n++;

if it is correct, then it checks the whole statement to see if the whole
if statement is correct. 
 
## Paradigms of Programming Languages

There are 4 paradigms of programing languages

###  Imperative or Procedural Paradigm

This is also called Von-Neumann model of computing which is based on Single Processor Sequential
Execution of instructions. A programming Language that is based on this model is characterized by:

1. Sequential Execution of Instructions.

2. Using Variables to Represent Memory Locations.

3. Using Assignment Statements to Change the Value of a Variable.

An example of a programming language designed with this paradigm is Pascal and C . This is an example function(Greatest Common Divisior):

```Pascal
function gcd(x,y:integer):integer; //int gcd(int x, int y)
Begin
        if(x = y) then//notice that its not ==
                gcd:=x
        else
                if(x > y) then
                        gcd:=gcd(x-y,y)
                else
                        gcd:=gcd(x,y-x);
End
```

The Same program in C is:

```C
int gcd(int n, int m)
{
	if(n==m){
		return m;
		}
	else{
		if(n>m)
			return gcd(n-m,m);
		else
			return gcd(n,m-n);
	}
}
```

### Functional Paradigm 

Computation is based on the evaluation or calling functions or application of functions. That is why the language is sometimes called
applicated language. A programming Language that is based on this model is characterized by:


1. There is **NO** Notion of Variables or Assignment Statements in this Paradigm. 

2. Repetition is not Expressed in Loops, but is Achieved by Recursive Calls.

As an example, lets take the LISP (**LIS**t **P**rogramming) language.

In LISP, everything is a list. In LISP, a list is defined as:

> A List is a Sequence of Things Separated by Blanks and Surrounded by Parenthesis.

An example of lists

```LISP

(+ a b)
``` 

or

```LISP

(+ 2 3)

````

or

```LISP

(if a b c)

```

which means "if a is true, then the value is b. otherwise , the value is c".

Lets some small programs in LISP:

```LISP

>(defun f(x)
(+ x 1))
>f
>(f 3)
>4
```
or another program:

```LISP
>(defun ff(x y)
(+ x y))
>ff
>(ff 3 5)
>5
```
GCD in LISP would be

```LISP
>(defun gcd(n m)
(if (= n m) n
 (if(> n m) (gcd (- n m) n)
  (gcd (n (- n m ))))))
>gcd
>(gcd 18 16)
>2
```
Lets Write a LISP program to simulate the function power x^n(where x belongs to r and n is an integer)

```LISP
>(defun pwr(x n)
  (if (= n 0) 1
   (* x (pwr(x (- n 1))))))
>pwr
>(pwr 2 4)
>16
```
### Logical Paradigm

This Paradigm is based on symbolic logic. The Program consists of a set of 
statements that describe what is true about these statements. For example, the Greatest Common Divisor function
could be written in a Logical language called PROLOG(**PRO**gramming **LOG**ical):

```PROLOG
gcd(u,v,u) :- v = 0.
gcd(u,v,x) :- v > 0,
	y is u mod v,
	gcd(v,y,x).
```

### Object Oriented Paradigm

In This Paradigm, the notions of **Object** and **Class** are introduced. It widely
spread in the 90's. The main advantages of Objected Oriented Programming are:

- Encapsulation of **Data** and **Function**

- Inheritance

- Polymorphism

## The Chart of Language Evolution 

![History Of Programming Languages](./images/History_of_prorgramming_languages.png )


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

Even though this flowchart makes it seem that these processes take place
one after the other, these processes(lexical analysis, syntax analysis,
semantic analysis, etc) are not done independent from each other. Today, almost 
all compilers are [One-Pass Compilers](https://en.wikipedia.org/wiki/One-pass_compiler).

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
Pascal, C, Modula, Ada, etc. Most languages today use this scheme. 

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
ALGOL60. This is where programming started originally. 

2. Business Domain : This Domain includes all applications used for 
commercial purposes. Languages in this domain include COBOL(and Database
languages) and JAVA. This came afterwards when businesses, especially 
banks, found use for programming.

3. Artificial Intelligence Domain : This Domain includes languages 
used for AI. Languages in this domain are LISP and PROLOG. 

4. Systems Programming : Which is programming all aspects of the computer
(including hardware). Languages in this domain include Machine Language, 
Assembly Language, and C.

5. Very High Level Languages : These are essentially scripting languages.
Languages in this domain include python and bash.

## Language Evaluation Criteria : Which Language is the Best?

There is no "best" general programming language. However, we can say that
a programming language is *more suitable for a certain application*. There
are a lot of factors to consider when we want to choose a programming language.

However, we can compare similar programming languages on certain benchmarks
such as speed, space usage, ease of use, libraries available, etc.

### Factors that Effect Programming Languages

#### Readability 

It is the most important criteria of programing languages
(we made programming languages to be able to understand code after all).
It is judging the language by simplicity of which programs can be read 
and understood, ie, how hard it is to understand a segment of source code.
There are several things that contribute to the readability of a language :
   
- Simplicity : a language with a large number of basic components 
  is difficult to learn. Users generally tend to use only some of those
  features(according to personal preferences).  An example of this 
  is how there are many types of loops available(while, for,recursion),
  but each person has a different affinity to them, or multiplicity
  (x=x+1,x+=1,x++,++x), where there is more than one way to increment or decrement a variable, and a user
  only likes to use one of them. 
   
- Orthogonality : Orthogonality means the symmetry of relationships
  among primitives combined to form the constructs/controls ie, the 
  language should not behave differently in different contexts. An example
  of this  is in Pascal, the block statement in loops **must** start with
  ```BEGIN``` and end with ```END``` like this :
  
	```PASCAL
	for(....)
	BEGIN
	...
	END
	```
	**except** in the ```repeat``` statement,
	which uses 
  
	```PASCAL
	REPEAT
	...
	UNTIL
	```
	or in IBM maiframe, where :
 
	```ASSEMBLY
	A Reg1,mem
	```
	but :
 
	```ASSEMBLY
	AR Reg1,Reg2
	```
 
	or in VAX(an OS for mainframe digital corporation), where
	there is only 1 add instruction for all types of memory(memory locations
	and registers) :
 
	```ASSEMBLY
	Add op1,op2
	```
 
	In this case, VAX is said to be more **Orthogonal**.

	in short: 

	> The Less the Orthogonality, The More Instructions There are.

	However:

	> The Higher the Orthogonality, The More Problems There are to the Compiler.

- Control Structures : Early Languages such as FORTRAN and COBOL had
  a limited number of control structures(COBOL had 1 type of loop, the for loop)
  . As such, the use of the```goto``` statement was more prevalent. This caused
  the language to be less readable. In the 70's, block structured programming
  languages were introduced as a solution to poor readability.
  
- Data Types and Structures : Sometimes, the use of a datatype can be confusing.
  Pascal, for example, solved this issue. say we want to have a flag. In 
  pascal, we have the ```Boolean``` type :
  
  ```PASCAL
  flag:Boolean;
  ...
  flag:=true;
  if flag then
  ...
  ```
  However, In C, we don't have a boolean type, so if we want to define a
  flag, we have to use the ```int``` datatype :
  
  ```C
  int flag;
  flag = 1;
  ...
  if(flag)
  ...
  ```
  
- Syntax Consideration :
  - Identifier length(eg ```int```,```for```), separators.
  - Using Keywords(eg ```BEGIN```,```END```) in compound statements.

#### Writability 

Writability is the ability to write programs in a certain language. It 
is not separated from the readability issue. 
We can say that the writability issue is the same as the readability issue.
Generally, if a programming language is easy to read, it is easy to write
and vice versa. The Factors which effect readability also effect writability.


We should compare writability of the programming language in the **same domain**. COBOL is no good for
writing a scientific programs, while ALGOL60 is. In the same way, its not
a good idea to do AI in ALGOL60 compared, to say, PROLOG.

#### Reliability

Reliability is how much we "trust" a programming language. A Programing language
is said to be reliable if it performs well under all conditions. 

The Reliability issue is effected by the following factors :

- Type Checking : That is, to check that the operands of a certain operation
  are of a compatible data type. 
 
- Exception Handling : That is, the ability to *detect the error*,
  *report the error*, and *recover from it*. 
  
- Aliasing : That is, Having 2 or more distinct referencing methods , ie, having
2 different names for the same memory location.

#### Cost
 
Cost is divided into categories :

- Programmer Training. Programmer Training is a function of simplicity
and orthogonality. 

- Software Creation. Software Creation is a function of writability.

- Cost of Compilation. This means how much time/processing power and space
we need to compile the source and create an executable.

- Cost of Execution. This means how much time/processing power and space
we need to run a program. 

- Cost of Compiler Development.  

- Cost of Maintenance. This is also a function of readability.

#### Other Factors 

There are also other factors to consider when comparing languages :

- Portability : The Ability to move the program and run it on a different 
  platform. This is a huge plus.

- Generality : That is, is the programming language a general purpose
  programming language? Can we use it for everything?

- Efficiency : And This includes 3 types of efficiency 
  - Efficiency in Translation.
  - Efficiency in Execution.
  - Efficiency in Writing Programs.
# Lexical Analysis(Scanner)

## What is a Lexical Analyzer?

A Lexical Analyzer or Scanner is an algorithm that
groups the characters of the source code to form the **Tokens**. Afterwards,
it returns the **Internal Representation Number** of these tokens, which
is an ID that matches the reserved word fetched from a **keywords table** which
the implementer of the compiler predefines.

 
These tokens are divided into 3 kinds:

1. Names : Which is any name we have in a program. These in turn are 
divided into 2 types:
   a. Keywords/Reserved,  which are words such as if/else/while. These names cant 
   be used as variable names. They have a specific place and function
   b. User Defined Names,  Which are the names declared by the user.

2. Values : such as integers(1, 2, 3, 4) or floating point(1.1, 2.34, 5234.123) etc

3. Special Symbols/Tokens : And these are the logical(==, &, ||) and arithmetic operations(+, -, *, /),  
parenthesis([], {}, ()),  or any other tokens that are not from the first or second kind.

Lets apply the scanner to this short segment of code:

```C
while(x>=100)
{
	n +=x;
	x++;
}
```
This results in this set of tokens :

```While```, ```(```, ```x```, ```>=```, ```100```, ```)```,
 ```{```, ```n```, ```+=```, ```x```, ```;```, ```x```, ```++```, ```}```.

Referencing these tokens against a certain keywords table like this one :

index | Symbol 
--|--
.. | ..
33 | ```While```
.. | ..
67 | ```>=```
.. | .. 
.. | ..

Leads us to these ID's :

Token | Internal Representation Number
--|--
```While``` | 33
```(``` | 84
```x``` | 100
```>=``` | 67
```100``` | 200
```)``` | 85
```{``` | 92
```n``` | 100
```+=``` | 77
```x``` | 100
```;``` | 81
```x``` | 100
```++``` | 75
```;``` | 81
```}``` | 93

note that all user defined names have the same number. This is because to 
the syntax analyzer, it doesn't matter what the variable is, it just matters
that there is a variable there.

## Type Checking implementation

During this process of analysis, The Compiler builds what is called the
**Symbol Table**. The Symbol Table is a table of the name of each user
defined name(mostly variables), its type, and its values. The Symbol table 
for this segment of code would be:

```C
.
.
.
int compute(int,int);
int n;
float x,y;
const int m=10;
.
.
.
```

Name | Type | Value |
--|--|--
```compute``` | function-name | 0 
```n``` | Integer | 0
```x``` | float | 0
```y``` | float | 0
```m``` | const-int | 10

To perform type checking, the compiler takes the name, and checks the keywords table.
If it is not in the keywords table, it is a user defined variable. if it
is a user defined variable, it then goes to check the symbol table. If it is not 
defined in the symbol table, it returns that the variable is not defined
(unknown symbol/variable deceleration error), if it is in the symbol table, it retrieves its 
type. If the operation being performed on the variable is not compatible
with the type of the variable, it returns that the operation is not 
compatible( type error ).

![Type Checking Flowchart](./images/type-checking-flowchart.png)

## Regular Languages(Regular Expressions) in Lexical Analysis

Regular Languages are a class of language that are important 
for lexical analysis, since we use them to 
define and generate tokens. This Class of languages is defined recursively.

### Defining a Language as a Set

We Say that :

> An Alphabet is a Set of Symbols. 

For example, our alphabet is the set V = {a,b,...,y,z}.

Expanding on the definition above, we say that :

> A String is a Sequence of Symbols Taken From the Alphabet.

So if V is our alphabet, then :

**abcd**

**dsda**

**qweaz**

**asasd**

Are all strings defined on V. we can define **an infinite number of 
strings on an alphabet**.

Formally,
 
> S is the set of all strings over some alphabet V.

let V={0,1} with S defined over it, lets define
a binary operation on S

given that x,y &isin; S, then we can 
define a concatenation operation on x and y as follows:

> XY={the set of strings formed by following x with y}.

Note that XY &ne; YX . We say that the concatenation operation 
is **not** commutative.

Lets Define a special string, called the empty string, which 
we denote with &lambda;.

Notice that &lambda;X is the same as X. Formally, we can say:

> &lambda; is the **identity** element of the concatenation operation.

Where the Identity element is formally defined as :

> an element of a set that, if combined with another element by a specified binary operation, leaves that element unchanged.


Putting all of this together, We can define a language as :

> Given an alphabet V, a language L over V is a set of strings formed 
> from V.

By this definition, these sets Are *all* languages:


**L<sub>1</sub>={a, b, c}**

**L<sub>2</sub>={asdasd, qwe, asd}**

**L<sub>3</sub>={abb}**



This definition also leads us to the conclusion :

> There are an &infin; number of languages defined on an alphabet.

### Set Operations On Languages 
Given an Alphabet V, assume that :

1. L = {set of all languages defined on V}

2. L = {L1, L2, L3,....Ln}

We will define a 3 operations on L , ie, the operands are languages
belonging to L. 

#### Concatenation Operation 

Given that L, M are languages over an alphabet V, then

> LM = "L concatenated with M" = {xy | x &isin; l, y &isin; m}. 

For Example let L={a,b,c} and M={aa,bb}, then : 

**LM={aaa,abb,baa,bbb,caa,cbb}**

**ML={aaa,aab,aac,bba,bbb,bbc}**


Note that :
 
1. LM &ne; ML. (Concatenation on languages is not commutative).

2. L{&lambda;} = {&lambda;}L = L. (&lambda; is the identity for concatenation).

3. L{  } = {  }L = {  }.

#### The OR "|" Operation
OR is &cup; operation in set theory

Given that L, Mare languages over an alphabet V, then
> L|M = "L OR M" = {x | x &isin; l &cup; x &isin; m} = L &cup; M. 

Note that :

1. L|M = M|L. (OR on language is commutative)

2. L|{  } = {  }|L = L. (The empty set is the identity element for the 
OR operation)

#### The Closure "*" Operation (A Unary Operation)

The Closure Operation is the "NOT" Operation in Logic.

Given that L is a language over an alphabet V then L* is: 
> L\* = L^0 &cup; L<sup>1</sup> &cup; L<sup>2</sup> &cup; ..... &cup; L<sup>&infin;</sup>

L<sup>+</sup> is given by

> L<sup>+</sup> = L\* - {&lambda;}

### The Recursive Definition of Regular Languages

Given an alphabet V then :

> 1. **&empty;** = {  } = empty language is a regular language denoting 
> the language {  }
>
> 2. **&lambda;** = {&lambda;} is a regular language denoting the 
> language &lambda;
>
> 3. For every element a &isin; V , **a**= {a} is a regular language 
> denoting the language {a}

lets say that V  = {a, b, c}, then according to 1, 2, 3, 
**&empty;**={  },**&lambda;**={&lambda;},**a**={a},**b**={b},**c**={c}, are all 
regular languages

Given R and S are regular languages denoting the regular languages
L<sub>R</sub> and L<sub>S</sub> respectively, then :

> a. RS is a regular language denoting L<sub>R</sub>L<sub>S</sub>
>
> b. R|S is a regular language denoting L<sub>R</sub>|L<sub>S</sub>
>
> c. R\* is a regular language denoting L<sub>R</sub>\*

say that R={a} and S={b}, then : 

**RS={ab},**

**R|S={a,b},**

**R\*= {a}<sup>0</sup > &cup;{a}<sup>1</sup> &cup;....**

  **= {&lambda;,a,aa,aaa,....}**

  **= A string that consists of any number of a's**

Lets say we took (RS)* then

**(RS)\* = {ab}<sup>0</sup > &cup;{ab}<sup>1</sup> &cup;.....**

 **= {&lambda;,ab,abab,ababab,abababab,....}**

 **= A string that consists of any number of "ab"s**
 

Lets say we took  (a|b)\* , then : 

**(a|b)\* = ({a}|{b})\* = ({a}&cup;{b})\***

**= ({a,b})\* = A string of a's and b's**

Lets say we took (0|1)\*00, then By the definitions above,  this results in  any binary
string followed by 00, such as {100,000,1100,0000,...} 

Lets say we took (a|b)\*bbb(a|b)\*, then By the definitions above, this results in any string of
a's and b's that contains at least 3 b's such as
{bbb,abbb,bbba,bbbbb,...}

### Defining Tokens Using Regular Languages

Remember that we have 3 types of tokens:
1. Names
2. Values
3. Special Symbols

The scanner must recognize these and be able to distinguish them.

#### Names 
In programming languages, names are letters followed by 
letters or digits. The regular language for names 
is :

> Letter(Letter|digit)\* = L(L|d)*

#### Values 

In programming languages, there are multiple types of values, and 
they can all be defined using a regular language

1. Integers : Integers consist of a + or - followed by a digit followed
by a set of digits. the regular language for them is
> [+|-]digit(digit)\* = [+|-]dd\* = [+|-]d<sup>+</sup>

   Note : [x] means we take x zero or one time **only**.
	
2. Floating Point Numbers :

   a. Fixed Floating Point : Fixed Floating Point Numbers consist of a+ or more followed by 1 or more digits
    followed by a . followed by 1 or more digits. They are given by the regular
    language :
	> [+|-]d<sup>+</sup>.d<sup>+</sup>
	
   b. Exponential Notation : Exponential Floating Point Numbers consist 
   of a + or - followed by 1 or more digits followed by a . followed by
   one or more digits followed by an E followed by a + or - followed  by 
   1 or more digits. They are given by the regular language :
   >  [+|-]d<sup>+</sup>.d<sup>+</sup>E[+|-]d<sup>+</sup>

#### Special Symbols

The Set of special symbols {\+,-,<=,....} are each given 
by its own regular languages. For example, the symbol
\+ has its own regular languages given by :

> \+ = {+}

or the \* symbol is given by 

> \* = {\*}

or the <= symbol is given by

> <= = {<}{=} = {<=}

or \+\+ , which is given by 

> ++ = {+}{+} = {++}

The Question remains: How do we build an algorithm to recognize(accept)
strings whose languages are regular languages?   

### Finite State Automata(FSA)

Tokens in source codes are strings of regular 
languages. The algorithm that recognises these strings is called the
**Finite State Automata** or the **Finite State Machine** or the 
**Finite State System**. The Finite State Automata contains :

1. A Set of states.
2. Transitions between states.
3. Input string to be examined.

Given that we have this Finite State Automata(FSA) :

![FSA1](./images/FSA.png)

- The set of states Q={S,A,B,G,H}
  - S is called the **Starting State**.
  - H is called the **Final State**.
- The transitions between the states are given by{\+, \-, d, .}
- Lets Say that the input string is "-ddd.dd" eg "-511.32".

Tracking through the states on this string, we start at state S :

```
  -    d    d    d    .    d    d
S--->A--->B--->B--->B--->H--->H--->H

```

Since H is the final state, we say that the **string is accepted**, or 
more formally :

>A string is accepted or recognized if after scanning the string we 
>end up with a final state.

The Regular Language(expression) generated(accepted) by this machine
L(M) is given by :

> L(M)=[\+|\-]{d<sup>+</sup>., .d<sup>+</sup>, d<sup>+</sup>.d<sup>+</sup>}

Other examples of finite state machines are :

1. Names : L(N) = {l<sup>+</sup>}.

2. Integers : L(I) = {d<sup>+</sup>}.

3. Greater Or Equal : L(G<sub>e</sub>) = {>=}.

#### Types of Finite State Automata 

there are 2 types of Finite State Automata

##### Non-Deterministic Finite State Automata

An algorithm is non-deterministic or fuzzy if there are 
options in the algorithm. An example of a non-deterministic algorithm
is the solution of the 
[Knight Tour Problem](https://en.wikipedia.org/wiki/Knight%27s_tour),
which is based on [Backtracking Techniques](https://en.wikipedia.org/wiki/Backtracking).


A Finite State Automata is non-deterministic if :

1. There are &lambda;-transitions(moves) in the FSA :
	
2. **Or** There is more than one transition from the same state on the same 
input : 
   
In Both cases, There is a choice(trial and error) to make. The only 
way to solve non-deterministic machines is to use backtracking. 
This wont do in a compiler, because backtracking is a very compute-heavy
method and is extremely slow. 

Fortunately, There are algorithms to transform any NDFSA to 
a DFSA. Therefore, we can assume always in the assumption that 
our machine is deterministic  


##### Deterministic Finite State Automata 

If A Machine is **not** non-deterministic, we call it a **Deterministic Finite
State Automata**, ie :

1. There are **NO** &lambda;-states.

2. **AND** There is **NO** more than one transition from the same state
on the same input.

Only Deterministic Finite State Automata are used for compilers.

#### Transformation of NDFSA to DFSA

The Algorithm that transforms an NDFSA to a DFSA consists of the following
steps :

1. Removal of &lambda; transitions. 
2. Removal of non-determinism.
3. Removal of inaccessible states. 
4. Merging equivalent states.

Lets Say we have this NDFSA :

![FSA2](./images/FSA2.png)


Which has this language:

> L(G)=\[\+|\-\]\{
>	ddddddd,
>
>	dddd.ddd,
>
>	dddddd.,
>
>	.dddd
>	
> \}

Or in short

> L(G)=\[\+|\-\](d<sup>\+</sup>|d<sup>\+</sup>.d<sup>\+</sup>|d<sup>\+</sup>.|.d<sup>\+</sup>)

And we want to transform it into a DFSA. Lets follow through the steps :

Lets Break down the Finite state machine into a transition diagram :

**State** \ <sup>V<sub>T</sub></sup>| \+| \-| . | d |&lambda;
--- | --- | --- | --- | --- | ---
S    | A | A |   |   | A
A    |   |   |   | B,C | E
B	 |   |   |   | B | F
C	 |   |   | D | C | 
D	 |   |   |   | D | F 
E	 |   |   | G | E | 
G	 |   |   |   | H | 
H	 |   |   |   | H | F 
**F**	 |   |   |   |   | 

##### Remove Lambda Transitions

1. Consider
   S-<sup>&lambda;</sup>->A
   
   Add all transition in Row A to S.

2. Repeat Step(1) for all States with &lambda; Transitions 

3. Mark all states from which there is a &lambda; Transition to a final 
State. Mark it as the final State 

4. Delete the &lambda; Column

This results in this table :

**State** \ <sup>V<sub>T</sub></sup>| \+| \-| . | d 
--- | --- | --- | --- | ---
S    | A | A | G | B,C,E 
A    |   |   | G | B,C,E
**B**	 |   |   |   | B 
C	 |   |   | D | C 
**D**	 |   |   |   | D 
E	 |   |   | G | E 
G	 |   |   |   | H 
**H**	 |   |   |   | H 
**F**	 |   |   |   |  

##### Removal Of Non-Determinism

Which means not having more than 1 transition on 1 input.

1. Consider \[B,C,E\]. Lets add this and treat it as a new 
state in the table.

2. If at least one of the states \[B,C,E\] is a final state, then 
we make it a final state.

3. Repeat steps (1) and (2) for all non-deterministic states

4. The Machine is now deterministic 

This results in this table :

**State** \ <sup>V<sub>T</sub></sup>| \+| \-| . | d 
--- | --- | --- | --- | ---
S    	 | A | A | G | B,C,E 
A    	 |   |   | G | B,C,E
**B**	 	 |   |   |   | B 
C	 	 |   |   | D | C 
**D**	 	 |   |   |   | D 
E	 	 |   |   | G | E 
G	 	 |   |   |   | H 
**H**	 	 |   |   |   | H 
**F**	 	 |   |   |   | 
**B,C,E**  |   |   |D,G| B,C,E
**D,G**    |   |   |   | D,H
**D,H**    |   |   |   | D,H

##### Removal of Non-Accessible States

1. Mark the Initial State

2. Mark all states for which there is a transition from S

3. Repeat step (2) for all marked states.
   
   This results in this table :

**State** \ <sup>V<sub>T</sub></sup>| \+| \-| . | d
--- | --- | --- | --- | ---
&#10003;S    	 | A | A | G | B,C,E 
&#10003;A    	 |   |   | G | B,C,E
**B**	 	 |   |   |   | B 
C	 	 |   |   | D | C 
**D**	 	 |   |   |   | D 
E	 	 |   |   | G | E 
&#10003;G	 	 |   |   |   | H 
&#10003;**H**	 	 |   |   |   | H 
**F**	 	 |   |   |   | 
&#10003;**B,C,E**  |   |   |D,G| B,C,E
&#10003;**D,G**    |   |   |   | D,H
&#10003;**D,H**    |   |   |   | D,H

4. Delete all non-marked states . This results
in this simplified Table :

**State** \ <sup>V<sub>T</sub></sup>| \+| \-| . | d
--- | --- | --- | --- | ---
&#10003;S    	 | A | A | G | B,C,E 
&#10003;A    	 |   |   | G | B,C,E
&#10003;G	 	 |   |   |   | H 
&#10003;**H**	 	 |   |   |   | H 
&#10003;**B,C,E**  |   |   |D,G| B,C,E
&#10003;**D,G**    |   |   |   | D,H
&#10003;**D,H**    |   |   |   | D,H

This is now a Deterministic Machine That accepts the same languages
as the original NDFSA . For Clarity, Lets
rename \[B,C,E\] to X, \[D,G\] to Y, \[D,H\] to Z.

  
**State** \ <sup>V<sub>T</sub></sup>| \+| \-| . | d
--- | --- | --- | --- | ---
&#10003;S    	 | A | A | G | X
&#10003;A    	 |   |   | G | X
&#10003;G	 	 |   |   |   | H 
&#10003;**H**	 	 |   |   |   | H 
&#10003;**X**      |   |   | Y | X
&#10003;**Y**      |   |   |   | Z
&#10003;**Z**      |   |   |   | Z

And the graph now looks like this : 

![FSA3](./images/FSA3.png)

But this machine is not in its simplest state.

##### Merging Equivalent States

We will use the **feasible-pairs table** method in merging 
equivalent states.

A state pair (p,q) is a feasible pair if:

1. {p,q}&sub;F OR {p,q}&sub;Q-F ie, either both {p,q} are final states
or both {p,q} are **not** final states.

2. for every token(symbol) a&isin;V<sub>T</sub>, either both {p,q} have
transitions on "a", or both {p,q} don't have transitions on "a".

3. p &ne; q ;

Note that (p,q) &equiv; (q,p).

for example, given the following NDFSA, represented by the following transition
table :

**State** \ <sup>V<sub>T</sub></sup>| a | b | c 
--- | --- | --- | --- 
1    | 2 | 5 |   
2    | 3 | 4 | 1  
3	 | 5 | 2 |   
**4**	 | 6 |   | 1 
5	 | 1 | 4 | 1  
**6**	 | 4 |   | 1  
7	 | 3 | 5 | 3  


To find the feasible pairs, first we must separate the set of final states
from the set of non-final states. therefore, we have these 2 sets :

> Q-F = {1,2,3,5,7}
>
> F = {4,6}

this results in this feasible-pairs table :

**feasible pairs** \ <sup>V<sub>T</sub></sup>| a | b | c 
--- | --- | --- | --- 
 (1,3) | 2,5 | 5,2 |
 (2,5) | 3,1 | 4,4 | 1,1
 (2,7) | 3,3 | 4,5 | 1,3
 (5,7) | 1,3 | 4,5 | 1,3
 (4,6) | 6,4 |     | 1,1  
 
We then mark all feasible pairs (p,q) where There is a transition to a 
pair (r,s) such that :

1. r &ne; s.

2. (r,s) is either marked OR not among the feasible pairs.

This results in this feasible-pairs table :

**feasible pairs** \ <sup>V<sub>T</sub></sup>| a | b | c 
--- | --- | --- | --- 
 (1,3) | 2,5 | 5,2 |
 (2,5) | 3,1 | 4,4 | 1,1
&#10003;(2,7) | 3,3 | 4,5 | 1,3
&#10003;(5,7) | 1,3 | 4,5 | 1,3
 (4,6) | 6,4 |     | 1,1  

We go through the table once more, in case we marked something later 
on in the table that would effect the pairs in the top of the table.

if a pair (p,q) remains unmarked, that means that p is equivalent to q.
therefore, we merge p and q, choosing one of them :

1. 1 &equiv; 3 ---> 1
2. 2 &equiv; 5 ---> 2
3. 4 &equiv; 6 ---> 4

We then merge, replacing every 3 with a 1, every 5 with a 2, and every
6 with a 4, resulting in this state table :

**State** \ <sup>V<sub>T</sub></sup>| a | b | c 
--- | --- | --- | --- 
1    | 2 | 2 |   
2    | 1 | 4 | 1  
**4**| 4 |   | 1 
7	 | 1 | 2 | 1  

This is the machine with the minimum number of states.

Lets go back to our example(the FNDSA we were already working on). Last 
time, we reached this state table :

**State** \ <sup>V<sub>T</sub></sup>| \+| \-| . | d
--- | --- | --- | --- | ---
&#10003;S    	 | A | A | G | X
&#10003;A    	 |   |   | G | X
&#10003;G	 	 |   |   |   | H 
&#10003;**H**	 	 |   |   |   | H 
&#10003;**X**      |   |   | Y | X
&#10003;**Y**      |   |   |   | Z
&#10003;**Z**      |   |   |   | Z

Lets quickly apply what we learned on this table.

1. Separate the final from the non-final states :

	> Q-F ={S,A,G}
	>
	> F = {H,X,Y,Z}

	Constructing the feasible pairs table :

	**feasible pairs** \ <sup>V<sub>T</sub></sup>| \+| \-| . | d
	--- | --- | --- | --- | ---
	(H,Y)| | | | H,Z
	(H,Z)| | | | H,Z
	(Y,Z)| | | | Z,Z


2. Marking feasible pairs 

	**feasible pairs** \ <sup>V<sub>T</sub></sup>| \+| \-| . | d
	--- | --- | --- | --- | ---
	(H,Y)| | | | H,Z
	&#10003;(H,Z)| | | | H,Z
	&#10003;(Y,Z)| | | | Z,Z

3. Merge and Replace

	H &equiv; Y &equiv; Z---> H

	Resulting in this state table :
	
	**State** \ <sup>V<sub>T</sub></sup>| \+| \-| . | d
	--- | --- | --- | --- | ---
	&#10003;S    	 | A | A | G | X
	&#10003;A    	 |   |   | G | X
	&#10003;G	 	 |   |   |   | H 
	&#10003;**H**	 	 |   |   |   | H 
	&#10003;**X**      |   |   | H | X
	
	This is the simplest form of the machine.
	
Now we must check if the machine accepts the same language as our
original machine. 

![FSA4](./images/FSA4.png)

This macchine accepts the language L(G) where :

> L(G)=\[\+|\-\]\{
>	ddddddd,
>
>	dddd.ddd,
>
>	dddddd.,
>
>	.dddd
>	
> \}

Which is the same language of our original machine.


#### Creating a NDFSA From a Regular Expression

1. Decompose the regular expression to its primitive components :
   a. for &lambda;, X-<sup>&lambda;</sup>->Y.
   b. for a, X-<sup>a</sup>->Y.

2. Supposed that N<sub>1</sub>, N<sub>2</sub> are transition diagrams 
for the regular expressions  R<sub>1</sub>, R<sub>2</sub> respectively,
N<sub>1</sub> accepts R<sub>1</sub> & N<sub>2</sub> accepts R<sub>2</sub>,
then :

   a. N<sub>12</sub> which represents R<sub>1</sub>R<sub>2</sub> is :
      ![OR DRAWING](./images/concatination.png)
      
   b. N<sub>1|2</sub> which represents R<sub>1</sub>|R<sub>2</sub> is :   
      ![OR DRAWING](./images/or.png)
      
   c. N<sub>x</sub>\* which represents R<sub>x</sub>\* is :
	  ![OR DRAWING](./images/closure.png)
		
   d. N<sub>x</sub><sup>+</sup> which represents R<sub>x</sub><sup>+</sup> is :
	  ![OR DRAWING](./images/plus.png)
	  
	  Note that this is the same as  R<sub>x</sub>\* except we removed 
	  all the states that result in a &lambda;
      
      
for example, lets say we have the regular expression

> L(L|d)*

Whch has this transition table

**State** \ <sup>V<sub>T</sub></sup>| L| d |&lambda;
--- | --- | --- | ---
1    | 2 |   |   
2    |   |   |3,9   
3	 |   |   |4,6
4	 | 5 |   |  
5	 |   |   | 8   
6	 |   |7  |  
7	 |   |   | 8   
8	 |   |   | 3,9   
**9**|	 |   |  

Turning this into an DFSA :

1.

**State** \ <sup>V<sub>T</sub></sup>| L| d |&lambda;
--- | --- | --- | ---
1    | 2 |   |   
**2**    |  5 |  7 |3,9,8,6   
**3**	 | 5  | 7  |4,6,8,3,9
4	 | 5 |   |  
**5**	 |  5 | 7  | 8,3,9,4,6   
6	 |   |7  |  
**7**	 | 5  | 7  | 8,3,9,4,6   
**8**	 |  5 |  7 | 3,9,8,4,6   
**9**|	 |   |  

2. 

**State** \ <sup>V<sub>T</sub></sup>| L| d 
--- | --- | --- 
&#10003;1    | 2 |   |   
&#10003;**2**    |  5 |  7    
**3**	 |  5 |7   
4	 | 5 |   |  
&#10003;**5**	 |  5 | 7     
6	 |   |7  |  
&#10003;**7**	 | 5  | 7     
8	 |  5 |  7    
**9**|	 |   |  

3. 

**State** \ <sup>V<sub>T</sub></sup>| L| d 
--- | --- | --- 
&#10003;1|2|
&#10003;**2**|5|7
&#10003;**5**|5|7
&#10003;**7**|7|7

   **feasible pairs** \ <sup>V<sub>T</sub></sup>| L| d 
   --- | --- | --- 
   (2,5)|(5,5)|(7,7)
   (7,7)|(5,5)|(7,7)
   (5,7)|(5,5)|(7,7)

4.

**State** \ <sup>V<sub>T</sub></sup>| L | d 
--- | --- | --- 
&#10003;1|2| - 
&#10003;**2**|5|7
&#10003;**5**|5|7
&#10003;**7**|5|7

programmatically, this results in :

```C

getchar(ch);
case(ch){
	letter : get-name;
	digit : get-number
	< : getchar(ch)
	...
	...
}
```


# Syntax Analysis(Parser)

A Syntax analyzer is formally defined as :

> An Algorithm that Groups the Set of Tokens Sent by the Scanner to Form
> **Syntax Structures** Such As Expressions, Statements, Blocks,etc.

Simply put, the parser examines if the source code written follows
the grammar(production rules) of the language.


The Syntax structure of programming languages and even spoken languages
can be expressed in what is called **BNF** notation, which stands 
for **B**akus **N**aur **F**orm. 

For example, in spoken English, we can say the following:

> sentence --> noun-phrase	verb-phrase
>
> noun-phrase --> article	noun 
>
> article --> THE | A | ...
> 
> noun --> STUDENT | BOOK | ...
>
> verb-phrase --> verb noun-phrase 
>
> verb --> READS | BUYS | ....

Note : The BNF Notation uses [different symbols](https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form#Example),
for example, a sentence is defined as :

> \< sentence \> ::= \< noun-phrase \>	\< verb-phrase \>

But this is very cumbersome, so we use the first notation, since its
easier to use. 

Now, let us derive a sentence : 

> sentence --> **noun-phrase** verb-phrase 
>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
> **article** noun verb-phrase
>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
> THE **noun** verb-phrase
>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
> THE STUDENT **verb-phrase**
>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
> THE STUDENT **verb** noun-phrase
>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
> THE STUDENT READS **noun-phrase**
> 
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
> THE STUDENT READS **article** noun
>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
> THE STUDENT READS A **noun**
>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
> THE STUDENT READS A BOOK


In the same way, the parser tries to **derive** your source program 
from the starting symbol of the grammar.

Lets say we have these sentences :

> THE BOOK BUYS A STUDENT
>
> THE BOOK WRITES A DISH
>
> THE DISH TAKES A STROLL

Syntax-wise, all of these sentences are correct. However, their meaning 
is not correct, and they are not useful. What differentiates 2
sentences that are grammatically correct is their meaning or their 
**semantics**. You and I can agree that the meaning of a grammatically 
correct sentence is not correct, but how does the computer do it?



## Grammar 

> A grammar G=(V<sub>N</sub>, V<sub>T</sub>, S, P) where:
>
> 1. V<sub>N</sub> : A finite set of nonterminals(nonterminals set).
> 2. V<sub>T</sub> : A finite set of terminals(terminals set).
> 3. S &isin; V<sub>N</sub> : The Starting symbol of the grammar. 
> 4. P =  A set of **production rules**(productions).<-- Pending <==> Basically the whole grammar.

Note :

1. V<sub>N</sub> &cap; V<sub>T</sub> = &empty;.
2. V<sub>N</sub> &cup; V<sub>T</sub> = V(the vocabulary of the grammar).

Note : We will use 

1. Uppercase Letters A,B,...,Z for non-terminals.

2. Lowercase Letters a,b,...,z for terminals.

3. Greek letters &alpha;,&beta;,&gamma;,... for strings formed from V<sub>N</sub> OR V<sub>T</sub> = V. eg, 

   if V<sub>N</sub> = {S,A,B},
   
   V<sub>T</sub> = {0,1}
   
   then
   
   &alpha; = 0A11B
   
   &beta; = S110B
   
   &gamma; = 0010

### Productions 

1. A Production &alpha; --> &beta;(alpha derives beta) is a rewriting rule such that
the occurrence of &alpha; can be substituted by &beta; in any string.

   Note that &alpha; must contain at least one nonterminal from,&isin;V<sub>N</sub>. 

   For example, Assume we have the string &gamma;&alpha;&sigma;,

   > &gamma;&alpha;&sigma; --> &gamma;&beta;&sigma;
   
2. A Derivation is a sequence of strings &alpha;<sub>0</sub>, &alpha;<sub>1</sub>,
&alpha;<sub>2</sub>, &alpha;<sub>3</sub>,....,&alpha;<sub>n</sub>, then :

	- &alpha;<sub>0</sub> -*-> &alpha;<sub>n</sub>, n &ge; 0.
	
	- &alpha;<sub>0</sub> -<sup>+</sup>-> &alpha;<sub>n</sub>, n &ge; 1.
	

Given a grammar G, then :

> L(G) = Language Generated By the Grammar.
	
for example, Given the Grammar, G = ({S,B,C},{a,b,c},S,P)

P :

> S --> aSBC 
>
> S --> abC
>
> CB --> BC
>
> bB --> bb
>
> bC --> bc
>
> cC --> CC

L(G)=?

Lets follow through on the derivations

> S --> a**bC** --> abc(all terminals) &isin; L(G) <--- A sentence
>
> S --> a**S**BC --> aa**bC**BC --> aabbcBC --> blocked, so we try another path
> 
> S --> a**S**BC --> aab**CB**C --> aa**bB**CC --> aab**bC**C --> aabb**cC** --> aabbcc &isin; L(G) <--- A sentence
>
> S --> a**S**BC -->........-->aaabbbccc &isin; L(G) <--- A sentence
>
> Therefore, L(G)={a<sup>n</sup>,b<sup>n</sup>,c<sup>n</sup>| n &ge; 1}


As another Example, we have these productions

> E --> E+T <-- we can write the productions 1 and 2 as a single production E --> E+T | T
>
> E --> T
>
> T --> T*F
>
> T --> F
>
> F --> (E) <-- we can write the productions 5 and 6 as a single production F --> (E) | n
>
> F --> n

Lets follow through some derivations

> E --> **T** --> **F** --> n &isin; L(E)
>
> E --> **E**+T --> T+**T** --> T+**F** --> **T**+n --> **F**+n --> n+n &isin; L(E)
>
> E --> **E**+T --> **T**+T --> **F**+T --> n+**T** --> n+**F** --> n + (**E**) --> n+(**T**)
> --> n+(**T**\*F) --> n+(**F**\*F) --> n+(n\***F**) --> n+(n\*n) &isin; L(E)
>
> Therefore, L(G) = {Any arithmetic expression with \* and + operations},
> n is an operand here.

Note that, if we add the productions

> E --> E+T | E-T | T
>
> T --> T\*F | T/F | T%F

We would have a language to express all arithmetic expressions with 
(\*,\\,+,\-) operations.

Lets Take another Example(things in double quotes are terminals)

> Program --> block "#"
>
> block --> "{" stmt-List "}"
>
> stmt-List --> statement ";" stmt-List | &lambda;
>
> statement --> if-stmt | while-stmt | read-stmt | write-stmt |
> assignment-stmt | block
>
> if-stmt --> "if" condition.... 
>
> while-stmt --> "while" condition.....
>
> ....
> 
> ....
> 
> read-stmt --> "read"
>
> write-stmt --> "write"


V<sub>N</sub> = {Program, block, stmt-List, statement, if-stmt,
while-stmt, read-stmt, write-stmt, assignment-stmt}

V<sub>T</sub> = { "{", "}", "#", ";", "if", "while", "read", "write" }


Lets Follow through some derivations :

> Program --> **block** # --> { **stmt-list** } # --> { &lambda; } #
>
> Program --> **block** # --> {**stmt-list**} # --> {statement ; **stmt-list**} #
> --> {statement ; statement ; **stmt-list**} # --> {statement ; statement ; &lambda;} #
> --> {**statement** ; statement ;} # -->  {**READ-statement** ; statement ;} #
> -->{READ ; **statement** ;} # -->{READ ; write-statement ;} # --> {READ ; WRITE ;} #

We can write this as 

```
{ READ;
  WRITE;
}#
```
The language of this language is defined as 

> L(G) = {Set of all programs that can be written in this language}.

This is only a simple example, of a simple language. For something more
complex such as C or Pascal, there are hundreds of productions.


### Algorithms for Derivation 


>A Leftmost derivation is a derivation in which we replace the **leftmost**
>nonterminal in each derivation step.


>A Rightmost derivation is a derivation in which we replace the **rightmost**
>nonterminal in each derivation step.

For example, given the grammar

>V --> S R $
>
>S --> +|-|&lambda;
>
>R --> .dN | dN.N
>
>N --> dN | &lambda;
>
>V<sub>N</sub> = {V,R,S,N}
>
>V<sub>T</sub> = {+, - , ., d, $}

Lets follow through on the leftmost derivation 

> V --> **S**R$ --> -**R**$ --> -d**N**.N$ --> -dd**N**.N$ --> -dddN.N$
> --> -ddd.**N**$ --> -ddd.d**N**$ --> -ddd.d$ <-- A sentence.

Lets follow through on the rightmost derivation

> V --> S**R**$ --> SdN.**N** --> SdN.d**N**$ --> Sd**N**.d$ --> sdd**N**.d$
> --> sddd**N**.d$ --> **S**ddd.d$ --> -ddd.d$ <-- A sentence.

### Derivation Trees

A Derivation Tree is a Tree that displays the derivation of some 
sentence in the language. For example, lets look at the 
tree for the previous example

![ddd](./images/derivationtree.PNG)

Note that if we traverse the tree in order, recording **only** the leaves,
we obtain the sentence.

### Classes of Grammars 

According to Chomsky, There are 4 classes of grammars :

1. Unrestricted Grammars : No restrictions whatsoever except the restriction
by definition that the left side of the production contains at least one
nonterminal from V<sub>s</sub>. This grammar is not practical and we cannot
work with it. 

2. Context-Sensitive Grammars : For each production &alpha; --> &Beta;,
|&alpha;| &le; |&Beta;|, ie , the **length of alpha(&alpha;)** is less than or equal to 
the **length of Beta(&Beta;)**. This means that in this class of grammar, there are no
&lambda; productions in the form A --> &lambda, since |&lambda;| = 0 and A &ge; 1.

   They Say that Fortran has a context-sensitive grammar.
   
   It is very difficult to work with this class of grammars.

3. Context-Free Grammar(CFG) : Each production in this grammar class is of the 
form A --> &alpha; , where A &isin; V<sub>N</sub> and &alpha; &isin; V<sub><sub>*</sub></sub>
that is to say, the left hand side is **only** one nonterminal.

   This is the most important class of grammar. Most programming languages's
   structures are context-free. 
   
   We will mostly be working with this class of grammar. Most of the
   examples we have taken are CFG.

4. Regular Grammar (Regular Expressions) : Each production in this grammar class
   is of the form A -- > aB or A --> a, where A,B &isin; V<sub>N</sub> and a &isin;
   V<sub>T</sub>, **with the exception** of S --> &lambda;
   
   For example, lets say we have the grammar
   
   > A --> aA
   >
   > A --> a
   >
   Therefore, we get 
   
   >
   >G(L)=a<sup>+</sup>
   > 
	
   However, adding the production 
   
   >
   > A --> &lambda;
   >
   
   Results in the grammar
   
   >
   >G(L)=a\*
   > 

## Parsing Techniques

There are 2 main parsing techniques used by a compiler.

### Top-Down Parsing

In Top-Down Parsing, the parser builds the derivation tree from the 
root(S : the starting symbol) down to the leaves(sentence). 

In Simple words, the parser tries to derive the sentence using 
leftmost derivation. For example, say we have this grammar :

> V --> SR$
>
> S --> + | - | &lambda;
>
> R --> .dN | dN.N
>
> N --> dN | &lambda;

Lets examine if the sentence

> dd.d$ 

is derived from this grammar.

> V --> **S**R$ --> +**R**$ --> d**N**.N$ --> dd**N**.N$ --> dd.**N**$ --> dd.d**N**$ --> dd.d$

Therefore, this sentence is derived from the grammar.

However, this approach is very computationally intensive, and more importantly, 
this requires knowing the source code in advance. The Parser doesnt know
which production it should select in each derivation statement. We will
learn how to solve these issues later in the course.

### Bottom-Up Parsing

In Bottom-Up Parsing, the parser builds the derivation tree from the
leaves(sentence) up to the root(S : Starting Symbol). This type of tree,
built from the leaves to the root, is 
called a [B-Tree](https://en.wikipedia.org/wiki/B-tree).

In Simple words, the parser starts with the given sentence, does 
**reduction**(opposite of derivation) steps, until the starting symbol
is reached.

Note that the string &lambda; is present everywhere in the string, and
we can use it wherever we like.

Lets follow the reduction of the example given above.

> +dd.d$ --> +dd&lambda;.d$ --> +ddN.d$ --> +dN.d$ --> +dN.d&lambda;$
> --> +dN.dN$ --> +dN.N$ --> +R$ --> SR$ --> V

Which means that the sentence is in the grammar. 

Note that we can run into deadlocks here. say we took this path instead :

> +dd.d$ --> +dd&lambda;.d$ --> +ddN.d$ --> +dN.d$ --> +dN.d&lambda;$
> --> +dN.dN$ --> **+dNR$ --> +NR$ --> SNR$** --> Deadlock

This technique also has a major problem : Which substring should we 
select to reduce in each reduction step?

how do we solve this?

## Ambiguity 

Given the following grammar :

> num --> num d
>
> num --> d

Let us draw the derivation tree for the sentence ```dddd```

![numd](./images/num_d.PNG)

Question : is there another derivation tree that represents the sentence?

The answer is **no**.

If there is only one derivation tree representing the sentence, 
this means there is only one way to derive the sentence.

Based on this, we can say that :

> A Grammar G is said to be ambiguous if there is one sentence with more than
> one derivation tree. 
> 
> That is, there is more than one way to derive the sentence. 
>
> This means that our algorithm is **non-deterministic**.

Say we have this grammar

> E --> E + E
>
> E --> E * E
>
> E --> (E) | a

Take the sentence :

> a + a * a

Lets draw the derivation tree

![aaa](./images/aaa..PNG)


Due to the fact that we have 2 trees that give the same result, we can 
say that this grammar is ambiguous.

In this case, to enforce the associativity rule, this grammar can 
be re-written as :

> E --> E + E | T 
>
> T --> T*T | F
>
> F--> (E) | a

Now, Take the sentence ```a + a * a```
and find the derivation tree now. 
![left](./images/left.PNG)

There is only 1 possible derivation tree now. This solves the associativity
issue of the grammar before with the ```+``` and ```*``` operations.

But lets say we have the sentence :

> a + a + a

Lets try to find the derivation tree and any alternative trees. 

![eft1](./images/etf1.PNG)

We can see here that there is more than 1 derivation tree, and the 
language is still ambiguous.

We can solve this if we rewrite the grammar with the **left-associative rule**

> E --> E + T | T
>
> T --> T * F | F
>
> F --> (E) | a

The resultant grammar is left-associative.

This grammar solves the problems of :

- ambiguity.
- precedence.
- associativity.

Lets try rewriting it with the **right-associative rule**

> E --> T + E | T
>
> T --> F * T | F
>
> F --> (E) | a

Lets try creating the derivation tree of ```a + a * a```

![right1](./images/right1.PNG)

Now lets draw the derivation tree of ```a + a + a```

![righ2](./images/right2.PNG)

This new grammar is not ambiguious, however, as we can tell from the derivation 
trees, there are precedence issues now. It's not technically wrong, 
but it doesnt not follow standard arithmetic rules.

Back to the left-associative grammar now. This grammar is called
**left-recursive**. This causes problems when it omes to top-down parsing
techniques(we will see why later).

A grammar is said to be left recursive if there is a production of the form:

> A-->A&alpha;

Conversely, a grammar is right-recursive if there is a production of the form:

> A-->&alpha;A

And causes no problems in top-down parsing.

our grammar has 2 rules of the form 

>A-->A&alpha;

The solution is to transform the grammar to a grammar which is not 
left-recursive. 

This has an algorithm to it. 

Given that 

> A-->A&alpha;<sub>1</sub>| A&alpha;<sub>2</sub>|A&alpha;<sub>3</sub>|...|A&alpha;<sub>n</sub>
>
> A-->&Beta;<sub>1</sub>|&Beta;<sub>2</sub>|&Beta;<sub>3</sub>|...|&Beta;<sub>n</sub>

To do this, we must introduce a new non-terminal, say A\`.

The grammar now becomes :

> A-->&Beta;<sub>1</sub>A\`|&Beta;<sub>2</sub>A\`|&Beta;<sub>3</sub>A\`|...|&Beta;<sub>n</sub>A\`

and

> A\`-->&alpha;<sub>1</sub>A\`| &alpha;<sub>2</sub>A\`|&alpha;<sub>3</sub>A\`|...|&alpha;<sub>n</sub>A\`|&lambda;

For example, say we have

>A-->Ab
>
>A-->a
>
>L(G)=ab*

Then according to the above

>A-->aA\`
>
>A\`-->bA\`|&lambda;

which results in the same grammar.

Lets apply this to the grammar :

> E --> E + T | T
>
> T --> T * F | F
>
> F --> (E) | a

This results in :

> E --> T E\` 
>
> E\` --> + T E\` | &lambda;
>
> T --> F T\`
>
> T\` --> \* F T\` | &lambda;
>
> F --> (E) | a

This grammar is now **perfect**. It solves all our ambiguity issues, and this is a
grammar we can use to construct the production rules for our programming
language.

Another ambiguity in programming languages is the ```if...else```
statement.

Lets take a generic if statement in a generic language:

> stmt --> if-stmt | while-stmt | ....
>
> if-stmt --> IF condition stmt
>
> if-stmt --> IF condition stmt ELSE stmt 
>
> condition --> C
>
> stmt --> S 

This grammar is ambiguous.

Lets take the nested ```if...else``` statement :

```
IF C
	IF C
		S
	ELSE
		S
		
```
This statement results in 2 derivations trees.

Both these trees result in the same traversal, but they have different meanings.
The first results in the ```ELSE``` belonging to the first ```IF```, while the 
second results int he ```ELSE``` belonging to the second ```IF```. We as 
humans know that the ```ELSE``` belongs to the second ```IF```, since we know that
the ```ELSE``` statement follows the nearest ```IF```. but how can 
the compiler know?

There are a bunch of solutions to this problem:

1. Add a delimiter to the ```IF``` statement, such as ```ENDIF``` or 
```END``` or ```FI``` to the end of the statement, resulting in these 
productions :
> if-stmt --> IF condition stmt **ENDIF**
>
> if-stmt --> IF condition stmt ELSE stmt **ENDIF**

	Resulting in this statement :
	
	```
	IF C
	|	IF C
	|	|	S
	|	|ELSE
	|	|	S
	|	ENDIF
	ENDIF
	
	```
	The grammar is now unambigious, since we have to clearly state when 
	an ```IF``` statement ends. However, this is not a pretty solution, 
	and is extra work for both the programmar and compiler, and results
	in less readable code.
2. In C and Pascal, the compiler **always** prefers to shift the ```ELSE```
	when it sees it in the source code so it follows the nearest ```IF```. We 
	will learn about this in more detail later.
	
Another thing about this grammar is **left factoring**. 

### Left Factoring
Consider the productions :

> A --> &alpha;&beta;
>
> A --> &alpha;&gamma;

Note how the first part of the productions is the same. This grammar
can be transformed by introducing a new non-terminal, So what happens now is:

> A --> &alpha;B
>  
> B --> &beta;&gamma;

For our grammar, this results in 

> if-stmt --> IF condition stmt
>
> if-stmt --> IF condition stmt ELSE stmt 

becoming

> if-stmt --> IF conditon stmt else-part
>
> else-part --> ELSE stmt | &lambda;

Does this solve the ambiguity? No, but it helps in removing choices, since 
the if-stmt is now one production. If we look at the statement :


```
IF C
	IF C
		S
	ELSE
		S
		
```

It still has 2 derivation trees

## More Ways of Expressing Programming Languages

### Extended BNF Notation

So far, we have been using **BNF Notation**(Production rules) to express
languages. However, there is another form to Express a language, which is 
**Extended BNF Notation**

if there is repetition in the grammar, say in the example of the grammar


> E --> E + T | T
> 
> T --> T \* F | F
>
> F --> (E) | a

which can give us a derivation in the form of 

> E --> **E** + T --> **E** + T + T --> **E** + T + T + T --> T + T + T + T....+T

or in the same line, 

> T --> T * F --> T * F * F --> T * F * F * F --> T * F * F * F....* F

We can express this grammar as :

> E --> T { + T }
>
> T --> F { * F }
>
> F --> (E) | a

We know that \[x\] means that we take x 0 or 1 time only.

However, \{ x \} means we take x zero or any number of times. This is 
equivalent to \(x\)\*

We can also express this grammar as:

> E --> T (+ T)\*
>
> T --> F (* F)\*
>
> F --> (E) | a

### Syntax Diagrams

Another way to express languages are **Syntax Diagrams**. These are used
only with Extended-BNF notation.

A square shape represents a nonterminal and an oval shape
represents a terminal.

## Parsing Techniques (Continued)

Recall : The parser is an algorithm which accepts or rejects a sentence
in the programming language. 

Recall : There are 2 kinds of parsers : 

1. Top-Down Parsers : In This parsing technique, The parser starts with 
```S``` using leftmost derivation to derive the sentence. The Major problem
with this parsing technique is that the parser doesn't know which production
it should select in each derivation step.

2. Bottom-Up Parsers : The parser in this parsing technique starts 
from the sentence, doing reduction steps, until it reaches the starting
symbol ```S``` of the grammar. The Major problem with this technique
is that the parser doesn't know which substring the parser should select
in each reduction step.

In Top-Down parsing, we have 2 available algorithms for parsing :

1. Recursive Descent Parsing.
2. LL(1) Predictive Parsing.

In Bottom-Up parsing, we have 2 available algorithms for parsing :

1. LR Parsers.
2. Operator Precedence Parsers --> Uses matrix manipulation.

Before we continue, we need to define a few functions

### The FIRST() Function 

Given a string &alpha; &isin; V\*, then 

> FIRST(&alpha;) = { a | &alpha; --\*--> aw, a&isin;V<sub>T</sub>,w&isin;V\*}

in addition, if &alpha; --> &lambda;, then we add &lambda; to FIRST(&alpha;), that is

> &lambda; &isin; FIRST(&alpha;)

That is to say,  FIRST(&alpha;) = Set of all terminals that may begin 
strings derived from &alpha;.

For example 

> &alpha; --\*--> cBx
>
> &alpha; --\*--> ayD
>
> &alpha; --\*--> ab
>
> &alpha; -----> ddd

Then

> FIRST(&alpha;) = {c,a,d}

Assume as well that

> &alpha; --\*--> &lambda;

then 

> FIRST(&alpha;) = {c,a,d,&lambda;}

That is to say, **&lambda; appears in the FIRST() function**.

Lets take an example of this.

### The FOLLOW() Function

We define the FOLLOW() function for **only** nonterminals. That is 
to say 

> FOLLOW(A), A&isin;V<sub>N</sub>

Given 

> S --\*--> uA&beta; , u&isin;V<sub>T</sub>\*, A&isin;V<sub>N</sub>, &beta;&isin;V\*

then

> FOLLOW(A)=FIRST(&beta;)

That is to say, FOLLOW(A) =  The set of all terminals that may appear after A in 
the derivation.

> S --\*--> aaXdd
>
> S --\*--> Xa
>
> S --\*--> BXc

Then 

> FOLLOW(X) = {d,a,c}

### Rules To Compute FIRST() and FOLLOW() Sets

1. FIRST(&lambda;) = {&lambda;}.
2. FIRST(a) = { a }.
3. FIRST(a&alpha;)= {a}.
4. FIRST(XY) = FIRST(FIRST(X).FIRST(Y)) **OR** FIRST(X.FIRST(Y)) **OR** FIRST(FIRST(X).Y).
5. Given the production A --> &alpha;X&beta;, Then :
	a. FIRST(&beta;) &sub; FOLLOW(X) if &beta; &ne; &lambda;.
	b. FOLLOW(A) &sub; FOLLOW(X) if &beta; = &lambda;.

Note that the FIRST() and FOLLOW() sets are made of **terminals only**

By these rules, say we have 

> A -- > &alpha;X&Beta; , X&isin;V<sub>N</sub>

and say we want FOLLOW(X)

Then 

> FIRST(&Beta;) &sub; FOLLOW(X)

We say it is a subset because we can have other productions involving 
X.

Assuming that &Beta; = &lambda;, Things are different. 

Say that we have a production that leads to this derivation is 

> S --*--> uA&gamma;

and following through this results in this derivation : 

> S --*--> uA&gamma; --> u&alpha;X&gamma;

Therefore, 

> FOLLOW(A) &sub; FOLLOW(X)

This is because whatever follows A can follow X if there is nothing 
between them.

Notes : 

1. &lambda; **may** appear in FIRST() but it doesn't appear in FOLLOW(). We 
will see this when we define augmented grammars.

2. Generally, we start computing the FIRST() from bottom to top, But follow
from top to bottom.

3. When we compute FOLLOW(X), we search for X in the right side of 
any production.

#### Augmented Grammars

Given the grammar G=(V<sub>N</sub>,V<sub>T</sub>,S,P), then the 
augmented grammar G\`=(V<sub>N</sub>\`,V<sub>T</sub>\`,S\`,P\`) can 
be obtained from G as follows:

1. V<sub>N</sub>\` = V<sub>N</sub> &cup; {S\`}.
2. V<sub>T</sub>\` = V<sub>T</sub> &cup; { $ }.
3. S\` = new starting point.
4. P` = P &cup; {S\`-->S$}

For example :

> E --> E + T | T
>
> T --> T * F | F
>
> F --> (E) | a

Becomes :

> G --> E$
>
> E --> E + T | T
>
> T --> T * F | F
>
> F --> (E) | a 

This is because we want to create a FOLLOW() set for S.

Lets take another example :

> S\` --> S$
>
> S --> AB
>
> A --> a | &lambda;
>
> B --> b | &lambda;

Lets compute the FIRST() sets for this grammar :

> FIRST(A) = \{a,&lambda;\}
>
> FIRST(B) = \{b,&lambda;\}
> 
> FIRST(S) = FIRST(AB) = FIRST(FIRST(A).FIRST(B))
>
> = FIRST(\{a,&lambda;\},\{b,&lambda;\})
>
> = FIRST(\{a,&lambda;,b,&lambda;})
>
> = \{a,b,&lambda;\}
>
> FIRST(S\`) = FIRST(S$) = FIRST(FIRST(S).FIRST($)) 
>
> = FIRST(\{a,b,&lambda;\}.$)= FIRST(a$,b$,$)
>
> = {a,b,$}

Now Lets compute the FOLLOW() sets for this grammar :

> FOLLOW(S) = \{$\}
>
> FOLLOW(A) = \{b,$\}
>
> FOLLOW(B) = \{$\}

---

Lets Take another, slightly more complex example :

> S\` --> S$
>
> S --> aAcb
>
> S --> Abc
>
> A --> b | c | &lambda;

Lets take the FIRST() for this grammar :

> FIRST(A) = \{b,c,&lambda;\}
>
> FIRST(S) =  FIRST(aAcb)&cup;FIRST(Abc) = \{a,\} &cup \{b,c\}
>
> = \{a,b,c\}
>
> FIRST(S\`) = FIRST(S$) = FIRST(FIRST(S).FIRST($)) 
>
>= FIRST(\{a,b,c\}.\{$\})
>
> = \{a,b,c\}

Now lets take the FOLLOW() : 

> FOLLOW(S) = \{$\}
>
> FOLLOW(A = \{c,b\}

---

Say we have the grammar 

> G --> E$
>
> E --> E + T | T
>
> T --> T * F | F
>
> F --> (E) | a 

Lets calculate FIRST() :

> FIRST(F) = {(,a}
>
> FIRST(T) = FIRST(T * F)&cup;FIRST(F) =  FIRST(T * F)&cup;{\(,a} 
>
> = {\(,a} (Because every T will eventually become an F)
>
> FIRST(E) = FIRST(E + T) &cup; FIRST(T) = {\(,a} &cup; {\(,a} 
>
> = {\(,a} 
>
> FIRST(G) = FIRST(E$) = {\(,a} 

Now lets Calculate FOLLOW() :

> FOLLOW(E) = \{$,+,)\}
>
> FOLLOW(T) = FOLLOW(E) &cup; \{*\} = \{$,+,\*,)\}
>
> FOLLOW(F) = FOLLOW(T) = \{$,+,\*,)\}

---

But what makes all this so important? 

Well, All of the parsing techniques we are going to learn will heavily rely 
on FIRST() and FOLLOW().

---

### Top-Down Parsing (Continued)

#### Recursive Descent Parsing

Recursive Descent Parsing is very simple. It works like this :

1. Divide the grammar into primitive/simple components
	1. For the token "a" :
	  
	    
	   >If(token == "a"){
	   >
	   >		get-next()
	   >
	   >}
	   >
	   >else{
	   >
	   >	report-error()
	   >
	   >}

	2.  For X = &alpha;<sub>1</sub>,&alpha;<sub>2</sub>,...,&alpha;<sub>n</sub> :
		
	 
		>code(X):\{ 
		>
		>code(&alpha;<sub>1</sub>);
		>
		>code{&alpha;<sub>2</sub>};
		>...
		>
		>...
		>
		>...
		>
		>code(&alpha;<sub>n</sub>);
		>\}
		
		Then
		
		> If(token &isin; FIRST(&alpha;<sub>1</sub>))
		>
		>	code(&alpha;<sub>1</sub>)
		>
		> else If(token &isin; FIRST(&alpha;<sub>2</sub>))
		>
		>	code(&alpha;<sub>2</sub>)
		>...
		>
		>...
		>
		>...
		>If(token &isin; FIRST(&alpha;<sub>n</sub>))
		>
		>	code(&alpha;<sub>n</sub>)
		>
		>else{
		>
		> report-error();
		>}
		
		If &alpha; &ne; &lambda;
		
		So we say, the code for x = &alpha;\*, we say
		
		> while(token &isin; FIRST(&alpha;\*))\{
		>
		> call(&alpha\*);
		>
		> /}
---

Notes :

1. Every nonterminal has a code(a function).
2. S\` in augmented grammar is represented by the function "main".
3. We only start with calling "get-token" in function "main".

---

For Example, lets say we have

> G --> E$
>
> E --> T( + T )*
>
> T --> F( \* F )\*
>
> F --> ( E ) | a

Then we can say :

```

 main(){//represents G

 get-token;

 call E();

 if(token!="$")
 {
	Error;
 }
 else{
	SUCCESS;
 }
	
	

}

 function E(){//Represents E -- T (+ T)*

	call T();

	while(token == "+"){

		get-token();

		call T()
	}

 }
 
 function T(){//T--> F (* F)*
 
	call F();
	while(token == "*"){
	
		get-token();
	
		call F();
	}
 }
 
 function F(){
 
	if(token == "(")
	{
		get-token();
		
		call E();
		
		if(token == ")")
		{
			get-token();
		}
		else
		{
			ERROR;
		}
	}
	else if(token=="a")
		{
		get-token();
		}
	else
	{
		ERROR;
	}
 }
 
```

Note that ```ERROR``` is a function we should write.

---

Lets take another example now. 

Given the grammar :

> Program --> body .
> 
> body --> Begin stmt (; stmt)* End
>
> stmt --> Read | Write | body | &lambda;

where we will represent &lambda; as ```l``` from now on in the example;

and

> V<sub>N</sub> = { Program, body, stmt, block}
>
> V<sub>T</sub> = { ., Begin, ;, End, Read, Write}

examples of programs of this language would be

``` 

Begin
	Read;
	Write;
	Read;
	Write;
End.

```
or

```

Begin
	Read;
End.

```

or

```

Begin
	Read;
	Begin
		Read;
		Write;
	End.
	Write;
End.

```

or

```

Begin;
	;
	;
	;
	;
End.

```

Lets write the code for this programming language.

```
main(){

	get-token();
	
	call body();
	
	if(token != "."){
		ERROR;
	}
	else{
		SUCCESS;
	}
}

function body(){

	call Begin();
	if(token == "Begin"){
		get-token();
		call stmt();
		while(token !=";"){
			get-token();
			call stmt();
		}
		if(token == "End"){
			get-token();
		}
		else{
			ERROR;
		}
	
	}
	else{
		ERROR;
	}
}

function stmt(){

	if(token == "Read"){
		get-token();	
	}
	else if(token == "Write"){
		get-token();
	}
	else if(token == "Begin"){
		call body();
	}
	else if(token != ";" || token != "End" ){
		ERROR();
	}
}
		
```

#### LL(1) Parsing

This Parsing method is a **table-driven** parsing method. The LL(1) parsing
table selects which production to choose for the next derivation step. 

##### Formal Definition of LL(1)

The Formal definition of LL(1) grammars is given by :

> Given the Productions :
>
> A --> &alpha;<sub>1</sub>
>
> A --> &alpha;<sub>2</sub>
>
> A --> &alpha;<sub>3</sub>
>
> A --> &alpha;<sub>n</sub>
>
> then the grammar is LL(1) if :
>
> 1. FIRST(&alpha;<sub>i</sub>)&cap;FIRST(&alpha;<sub>g</sub>) = &empty; for all i,j
>
> 1. if one of &alpha;<sub>i</sub>  is &lambda;,&alpha;<sub>n</sub> = &lambda;, in addition to 1, &forall; i &lt; n

For example, Given the grammar :

> S --> S$
>
> S --> aABC
> 
> A --> a | bbD
>
> B --> a | &lambda;
>
> C --> b | &lambda;
>
> D --> C | &lambda;

let us see if it is LL(1)

- FIRST(a)&cap;FIRST(bbD) = &empty;
- FIRST(a)&cap;FOLLOW(B) = &empty;
- FIRST(b)&cap;FOLLOW\(C\) = &empty;
- FIRST\(c\)&cap;FOLLOW(D) = &empty;

Then this grammar is LL(1).

Given another Grammar :

> S` --> S$
>
> S --> aAa | &lambda;
>
> A --> abS | &lambda;

- FIRST(aAa)&cap;FOLLOW(S) = {a}&cap;{$,a} = {a} &ne; &empty;

This grammer is **not** LL(1).

---

Lets assume that we have a grammer that is LL(1). How do we build the LL(1) parsing table?

##### LL(1) Parsing Table Building Algorithm

1. For each production A --> &alpha; in the grammar G, 
   1. Add to the table entry T[A,a] the production A --> &alpha;, where A &isin; FIRST(&alpha;)
2. If &lambda; &isin; FIRST(&alpha;), Add to the table entry T[A,b] the production A --> &alpha; &forall; b &isin; FOLLOW(A).
3. All Remaining Entries are Error Entries.


For example, given the grammar :

>V --> SR $<sup>1</sup>
>
>S --> +<sup>2</sup> | -<sup>3</sup> | &lambda;<sup>4</sup>
>
>R --> dN.N<sup>5</sup> | .dN<sup>6</sup>
>
>N --> dN<sup>7</sup>| &lambda;<sup>8</sup>

note that the superscript denotes the production number.

Then the table will look like this 

> FIRST(SR $) = {+,-,d,.}
> 
> FIRST(+) = {+}
>
> FOLLOW(S) = {d,.}
>
> FIRST\(R\) = {d, .}
>
> FIRST(d) = { d }
>
> FOLLOW(N) = {d, ., $}

V<sub>N</sub>\V<sub>T</sub>| + | - | d | . | $
---|---|---|---|---|---
 V | 1 | 1 | 1 | 1 |
 S | 2 | 3 | 4 | 4 |   
 R |   |   | 5 | 5 |
 N |   |   | 7 | 8 | 8

There should be no conflict(multiple entries) in the LL(1) table.

L(G) of this grammar = all floating point numbers.


The parser works like this

Stack | Remaining Input | Action 
---|---|---|
V    |-dd.d$ | Production 1
SR$  |-dd.d$ | Production 3
-R$  |-dd.d$ | Pop & advance input
R$   | dd.d$ | Production 5
dN.N$| dd.d$ | Pop & advance input
N.N$ |  d.d$ | Production 7
dN.N$|  d.d$ | Pop & advance input
N.N$ |   .d$ | Production 8
.N$  |   .d$ | Pop & advance input
N$   |    d$ | Production 7
dN$  |    d$ | Pop & advance
N$   |     $ | Production 8
$    |     $ | Pop and Advance
&lambda; | &lambda; | Accept 

If at any point the parser reaches a place where the input and the 
stack have 2 different terminal symbols, it throws a syntax error.

---

Lets Take another example. Let the Grammar be :

> program --> block $ <sup>1</sup>
>
> block --> { declarations stmnts } <sup>2</sup>
>
> decls --> D ; decls <sup>3</sup> | &lambda; <sup>4</sup>
>
> stmnts --> statement ; stmts <sup>5</sup> | &lambda; <sup>6</sup>
>
> statement --> if <sup>7</sup> | while <sup>8</sup> | ass <sup>9</sup> | scan <sup>10</sup> | print<sup>11</sup> | block <sup>12</sup> | &lambda;<sup>13</sup>

V<sub>T</sub> = {$,{,},D,;,if,while,ass,scan,print}


V<sub>N</sub>\V<sub>T</sub>|if|while|ass|scan|print|\{|\}|D|;|$
---|---|---|---|---|---|---|---|---|---|---
Program  |   |   |   |   |   | 1 |   |   |   |   
block    |   |   |   |   |   | 2 |   |   |   |   
decls    | 4 | 4 | 4 | 4 | 4 | 4 | 4 | 3 | 4 |   
stmts    | 5 | 5 | 5 | 5 | 5 | 5 | 6 |   | 5 |   
statement| 7 | 8 | 9 | 10| 11| 2 |   |   | 13|   

No conflict. 

---

Another example is  the If....else statement with a delimiter. the grammar 
looks like this :

> S` --> S$
>
> S --> iCSE
>
> E --> S | &lambda;
>
> S --> a
>
> C --> c

V<sub>N</sub>\V<sub>T</sub>| i | a | e | c | $
---|---|---|---|---|---
S\`| 1 | 1 |   |   |   
S  | 2 | 5 |   |   |   
E  |   |   |3,4|   | 4   
C  |   |   |   | 6 |

There is a conflict. To solve this, we can add a delimiter.

> S` --> S$
>
> S --> iCSEd
>
> E --> eS | &lambda;
>
> S --> a
>
> C --> c

V<sub>N</sub>\V<sub>T</sub>| i | a | e | c | d | $
---|---|---|---|---|---|---
S\`| 1 | 1 |   |   |   |
S  | 2 | 5 |   |   |   |
E  |   |   | 3 |   | 4 | 
C  |   |   |   | 6 |   |

The grammar is now unambiguous. Alternatively, we can just strike out
the transition 4 from the LL(1) table, which is a &lambda; transition.
Lets follow through the derivation tree. the resultant table is 

V<sub>N</sub>\V<sub>T</sub>| i | a | e | c | $
---|---|---|---|---|---
S\`| 1 | 1 |   |   |   
S  | 2 | 5 |   |   |   
E  |   |   | 3 |   | 4   
C  |   |   |   | 6 |

and this works because the natural behavior of the else-part is to follow
the nearest if statement.

---

Something Important to note is that **if a grammar is LL(1), then it is 
unambiguous. However, the opposite is not necessarily true.**

Another thing to note is that 
in Top-Down parsing, we should avoid a grammar that is not LL(1). 

--- 

### Bottom-Up Parsing (Continued)

Recall that in Bottom-Up parsing, the parser starts from the given sentence,
applying reductions until it reaches the starting symbol of the grammar or 
a deadlock. The major problem with Bottom-Up parsing is which substring
we should select in each reduction step.

The answer to the above question is : In each reduction step, we select 
what is called **the handle**.

The Handle is obtained by a **rightmost** derivation **in reverse** 

For example, Given the grammar :

>V --> S R $
>
>S --> +|-|&lambda;
>
>R --> .dN | dN.N
>
>N --> dN | &lambda;

and the sentence

> -dd.d$

First, we derive the sentence rightmost. 

> V --<sup>rm</sup>--> SR$ --<sup>rm</sup>--> SdN.N$ --<sup>rm</sup>--> SdN.dN$ --<sup>rm</sup>--> SdN.dd$ --<sup>rm</sup>--> SddN.d$
> --<sup>rm</sup>--> Sdd.d$ --<sup>rm</sup>--> -dd.d$

So our handles would be :

> V <-- **SR$** <-- S**dN.N**$<--
> SdN.**dN**$ <-- SdN.d**&lambda;**$ <-- Sd**dN**.d$ <-- Sdd**&lambda;**.d$ <-- **-**dd.d$

But Compilers dont work like this. We already derived the sentence, why would we go 
back and do it again?

We cannot build a Bottom-Up parser for every Context-Free Grammar. However,
we are fortunate enough that there exist subsets of the Context-Free Grammar 
for which we can build a deterministic Bottom-Up parser ie, the parser
can determine/decide precisely where the handle is in each reduction step.

some  of these subsets are 

- LR Parsers :
  - SLR(Simple-LR).
  - LALR(Look-Ahead LR).
  - LR.

- Operator Precedence.

We will only be talking about the SLR parser, just to get an idea
of how Bottom-Up parsing works.

#### SLR Parsing

SLR parsing, and LR parsing in general, is a tabular parsing method.

All LL(1) grammars are a subset of SLR grammars. 

All LR parsers contains :

1. A parsing table.

2. A stack.

3. The input string.

As a reminder, the LL(1) parser contains :


1. A parsing table.

2. A stack.

3. The input string.

However, the way we build it is different.

##### Building the SLR Parsing Table

> An LR(0) item of a grammar G is a production in G with a dot(.) at
> some position in the right side.

For example, the production 

> A --> aBY 

This production generates the following LR(0) items :

> A --> .aBY
>
> A --> a.BY
>
> A --> aB.Y
>
> A --> aBY. --> complete item

Note that for A --> &lambda;, this generates only A --> &lambda;. .

Generally speaking, if the right side of the production is L, then 
there are L+1 resultant LR(0) items.

The LR(0) item 

> A --> aB.Y

Means that the parser has scanned on the input a string derived from 
aB and expects to see a string derived from Y .

We need to define the following 2 functions. 

##### The CLOSURE function 

``` 

function CLOSURE(I)//I is a set of LR(0)items
{
	Repeat 
		for(every LR(0) item A-->alpha.Bbeta in I,
		and for every production B-->gamma in G,
		Add the LR(0)item B-->.gamma to I)
	Until no more items to be added;
}

```

Lets apply this to our grammar :

> (1)E --> E+T 
> 
> (2)E --> T 
>
> (3)T --> T*F
>
> (4)T --> F
>
> (5)F --> (E) 
>
> (6)F --> a

This grammar is not LL(1) because

> FIRST(T*F)&cap;FIRST(F) = {(,a} &ne; &empty;

We will need to build the LR(0) sets of items.

we start with I<sub>0</sub

> I<sub>0</sub>: E` --> .E
>
> CLOSURE(I<sub>0</sub>)
>
> E` --> &lambda;.E&lambda;
>
> A ---> &gamma;.B&Beta;
>

we add all productions starting with E and add the . at the start
therefore :

>I<sub>0</sub>:{E1-->.E, E-->.E+T, E-->.T}

Lets look at  E-->.E+T

>  E-->&lambda;.E+T
>
>  A ---> &gamma;.B&Beta;

Therefore, we add all productions starting wtih T to I<sub>0</sub>

> I<sub>0</sub>:{E1-->.E, E-->.E+T, E-->.T, T--> .T*F, T-->.F}
>

we iterate again, and the resultant set is:

> I<sub>0</sub>:{E`-->.E, E-->.E+T, E-->.T, T--> .T*F, T-->.F, F-->.(E), F-->.a}
>

##### The GOTO function

```

function GOTO(I,X)//I=set of items,X=Grammar symbol
{

   CLOSURE(all items A-->alphaX.Beta Where A-->alpha.XBeta in I)

}

```

Lets apply this to the grammar above. First we seperate 
each grammar symbol production to its own set This results in 4 Item groups:

> I<sub>1</sub> : E-->.E, E-->.E+T
>
>I<sub>2</sub> : E-->.T, T--> .T*F
>
>I<sub>3</sub> : T-->.F
>
>I<sub>4</sub> : F-->.(E)
>
> I<sub>5</sub> :F-->.a

and take the CLOSURE for all these sets. The resultant is :

> I<sub>1</sub> : E-->E., E-->E.+T
>
> I<sub>2</sub> : E-->T., T--> T.*F
>
> I<sub>3</sub> : T-->F.
>
> I<sub>4</sub> : F-->(.E), E --> .E+T,E-->.T,E-->.T*F,T-->.F,F-->.(E),F-->.a
>
> I<sub>5</sub> : F-->.a
>
> I<sub>6</sub> : E-->E+.T,E-->.T*F,T-->.F,F-->.(E),F-->.a
>
> I<sub>7</sub> : E-->T*.F,F-->.(E),F-->.a
>
> I<sub>8</sub> : F-->(E.),E-->E.+T
>
> I<sub>9</sub> : E --> E+T. , T --> T.*F
>
> I<sub>10</sub> : T --> T*F.
>
> I<sub>11</sub> : F --> (E).


##### Constructing the SLR table

Input : LR(0) sets of items

Output : SLR(1) parsing table

1. For every item A-->&alpha;.A&Beta; in I<sub>i</sub>, &alpha; &isin; V<sub>T</sub> , and
 GOTO(I<sub>i</sub>,a)=I<sub>j</sub>, then set; then ACTION[i,a]=S<sub>j</sub>(shift and push j on the stack).
 
2. For item A-->&alpha;.(complete item) in I<sub>i</sub>, ACTION[i,b]=Reduce by a-->&Alpha; FOR ALL b &isin; FOLLOW(A).

3. For S` --> S. in I<sub>i</sub>, ACTION[i,$] = Accept.

4. If GOTO(I<sub>i</sub>,A) = I<sub>j</sub> then set, GOTO(i,A) = j.

5. All remaining entries are error entries.


lets apply this to the example above and generate the table

V  |<sup>Action</sup>  | a | + | * | ( | ) | $ |<sup>GOTO</sup>  | E | T | F
---|---|---|---|---|---|---|---|---|---|---|---
0  |   |S5 |   |   |S4 |   |   |   | 1 | 2 | 3
1  |   |   |S6 |   |   |   | A |   |   |   |
2  |   |   |R2 |S7 |   |R2 |R2 |   |   |   |
3  |   |   |R4 |R4 |   |R4 |R4 |   |   |   |
4  |   |S5 |   |   |S4 |   |   |   | 8 | 2 | 3
5  |   |   |R6 |R6 |   |R6 |R6 |   |   |   | 
6  |   |S5 |   |   |S4 |   |   |   |   | 9 | 3
7  |   |S5 |   |   |S4 |   |   |   |   |   | 10
8  |   |   |S6 |   |   |S11|   |   |   |   |
9  |   |   |R1 |   |S7 |R1 |R1 |   |   |   |
10 |   |   |R3 |R3 |   |R3 |R3 |   |   |   |
11 |   |   |R5 |R5 |   |R5 |R5 |   |   |   |


No conflict --> SLR(1) grammar

##### Parsing The SLR Table

> E --> E+T 
> 
> E --> T 
>
> T --> T*F
>
> T --> F
>
> F --> (E) 
>
> F --> a

Lets examine the sentence 

> a + a $


Stack         | Remaining | Action
--------------|-----------|-------
0             | a + a $   | S5
0 a 5         |   + a $   | R6
0 F 3         |   + a $   | R4
0 T 2         |   + a $   | R2
0 E 1         |   + a $   | S6
0 E 1 + 6     |     a $   | S5
0 E 1 + 6 a 5 |     $     | R6
0 E 1 + 6 F 3 |     $     | R4
0 E 1 + 6 T 9 |     $     | R1
0 E 1         |     $     | Accept

---

But what if the grammar is not SLR?

#### LR Parsing Techniques

The main difference between LR and SLR is the CLOSURE function

``` 

function CLOSURE(I)//I is a set of LR(1)items
{
	Repeat 
		for(every LR(1) item [A-->alpha.Bbeta, a] in I,
		and for every production B-->gamma in G,
		Add the LR(1)item [B-->.gamma , b] where b belongs to FIRST(Beta a)to I)
	Until no more items to be added;
}

```

Where An LR(1) item is an LR(0) item with a **Lookahead Symbol**. For example

[A --> &alpha;.&Beta; , a] where a is the lookahead. The lookahead symbol
"a" has no effect whatsoever on an item [A --> &alpha;.&Beta;,a] &Beta; &ne; &lambda; (not complete item) However,
if the item is a complete [A --> &alpha;.,a], this means we reduce by the 
production A --> &alpha; on token "a".

For example, Give the grammar :

> S --> S`
>
> S --> CC (1)
>
> C --> cC (2)
>
> C --> d (3)

I<sub>0</sub>:

- S` --> .S, $ I<sub>1</sub>


- S --> .CC, FIRST(&lambda;$) = FIRST($) = $ I<sub>2</sub>


- C --> .cC, FIRST(C$) = c,d I<sub>3</sub>


- C --> .d,   c,d I<sub>4</sub>

I<sub>1</sub>:

- S` --> .S, $ Accept

I<sub>2</sub>:

- S --> C.C , $  I<sub>5</sub> (if the lookahead is different it goes to a new state)
- C --> .cC , $  I<sub>6</sub>
- C --> .d , $  I<sub>7</sub>


I<sub>3</sub>:

- C --> c.C , c,d I<sub>8</sub>
- C --> .cC   c,d I<sub>3</sub>
- C --> .d I<sub>4</sub>

I<sub>4</sub>:

- C --> d.,   c,d Complete

I<sub>5</sub> :

- S --> CC. , $ Complete

I<sub>6</sub> :

- C --> c.C , $ I<sub>9</sub>
- C --> .cC , $ I<sub>6</sub>
- C --> .d , $ I<sub>7</sub>

I<sub>7</sub> :

- C --> d. , $ Complete

I<sub>8</sub> :

- C --> cC. , c,d Complete

I<sub>9</sub> :

- C --> cC. , $ Complete


V  |<sup>Action</sup>  | c | d | $ |<sup>GOTO</sup> | S | C
---|-------------------|---|---|---|----------------|---|---
0  |                   |S3 |S4 |   |                | 1 | 2 
1  |                   |   |   | A |                |   |   
2  |                   |S6 |S7 |   |                |   | 5 
3  |                   |S3 |S4 |   |                |   | 8  
4  |                   |R3 |R3 |   |                |   |   
5  |                   |   |   |R1 |                |   |   
6  |                   |S6 |S7 |   |                |   | 9  
7  |                   |   |   |R3 |                |   |   
8  |                   |R2 |R2 |   |                |   |   
9  |                   |   |   |R2 |                |   |   

---

No conflict, the grammar is an LR grammar.

---

If we look at the above example, we can see that some sets of items have the 
same core items(LR(0) items), but the lookahead is different. For example (I<sub>7</sub> , I<sub>4</sub>),
(I<sub>3</sub> , I<sub>6</sub>), (I<sub>8</sub> , I<sub>9</sub>). Lets say we 
merge the states. What happens is the we add the lookaheads and 
change the state references for equivalent states . The table becomes this:

V  |<sup>Action</sup>  | c | d | $ |<sup>GOTO</sup> | S | C
---|-------------------|---|---|---|----------------|---|---
0  |                   |S3 |S4 |   |                | 1 | 2 
1  |                   |   |   | A |                |   |   
2  |                   |S3 |S4 |   |                |   | 5 
3  |                   |S3 |S4 |   |                |   | 8  
4  |                   |R3 |R3 |R3 |                |   |   
5  |                   |   |   |R1 |                |   |   
8  |                   |R2 |R2 |R2 |                |   |     

---

This is now a simplified table. if the parsing table after
merging has no conflicts(like in the above example), then 
the grammar is an LALR(1) Grammar. 
