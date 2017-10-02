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

## Regular Languages(Regular Expressions)

Regular Languages are a class of language that are important 
for lexical analysis.

### Defining a Language as a Set

We Say that :

> An Alphabet is a Set of Symbols. 

For example, our alphabet is the set V = {a,b,...,y,z}.

Expanding on the definition above, we say that :

> A String is a Sequence of Symbols Taken From the Alphabet.

So if V is our alphabet, then :

```
abcd
dsda
qweaf
asasd
```
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

By this definition, these sets :

```
L1={a, b, c}
L2={asdasd, qwe, asd}
L2={abb}
```
Are *all* languages.

This definition also leads us to the conclusion :

> There are an &infin; number of languages defined on an alphabet.

### Set Operations On Languages 
Given an Alphabet V, assume that :

> L = {set of all languages defined on V}

also :

> L = {L1, L2, L3,....Ln}

We will define a 3 operations on L , ie, the operands are languages
belonging to L. 

#### Concatenation Operation 

Given that L, M are languages over an alphabet V, then
> LM = "L concatenated with M" = {xy | x &isin; l, y &isin; m}. 

For Example, 

```
L={a,b,c}
M={aa,bb}
LM={aaa,abb,baa,bbb,caa,cbb}
ML={aaa,aab,aac,bba,bbb,bbc}
```

Note that :
 
1. LM &ne; ML. (Concatenation on languages is not commutative).

2. L{&lambda;} = {&lambda;}L = L. (&lambda; is the identity for concatenation).

3. L{} = {}L = {}.

#### The OR "|" Operation
OR is &cup; operation in set theory

Given that L, Mare languages over an alphabet V, then
> L|M = "L OR M" = {x | x &isin; l &cup; x &isin; m} = L &cup; M. 

Note that :

1. L|M = M|L. (OR on language is commutative)

2. L|{ } = { }|L = L. (The empty set is the identity element for the 
OR operation)

#### The Closure "*" Operation (A Unary Operation)

The Closure Operation is the "NOT" Operation in Logic.

Given that L is a language over an alphabet V then L* is: 
> L* = L^0 &cup; L^1 &cup; L^2 &cup; ..... &cup; L&infin;

L+ is given by

> L+ = L* - {&lambda;}



