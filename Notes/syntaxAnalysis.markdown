# Syntax Analysis(Parser)

The Syntax structure of programming languages and even spoken languages
can be expressed in what is called **BNF** notation, which stands 
for **B**akus **N**aur **F**orm. 

For example, in spoken English, we can say the following:
> Starting Symbol
>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;v
>
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

Note: The BNF Notation uses [different symbols](https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form#Example),
for example, a sentence is defined as :

> \< sentence \> ::= \< noun-phrase \>	\< verb-phrase \>

But this is very cumbersome, so we use the first notation, since its
easier to use. 

Now, let us derive a sentence : 

> sentence --> **noun-phrase** verb-phrase 
>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
> **article** noun verb-phrase
>
>  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
> THE **noun** verb-phrase
>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
> THE STUDENT **verb-phrase**
>
>  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
> THE STUDENT **verb** noun-phrase
>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
> THE STUDENT READS **noun-phrase**
> 
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
> THE STUDENT READS **article** noun
>
>  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
> THE STUDENT READS A **noun**
>
>  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
> THE STUDENT READS A BOOK

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

