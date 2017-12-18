# Semantics

Recall :

> Programming Language syntax means what the language constructs look like.

Also recall :

> Programming Language semantics means what those language constructs
> actually do(meaning).

Programming language semantics are much more complex to express than 
the syntax. Programming language semantics can be specified by :

1. The Programming language reference manual (most common and simple).

2. Translator (Compiler or Interpreter).
   - By Experiment.
   - Execute programs to find out what they do.
   - Machine dependant(generally it is not portable).
3. Formal Definition (mathematical model). It is complex and abstract.

We will mainly be using the first method. We will also use ALGOL-like languages 
in our discussion.

## Binding 

Using names or identifiers in a programming language is a basic, fundamental
abstraction - variable names, constant names, procedure and function
names are all examples of this.

Related to names is the concept of **location**. Simply put, the 
location is the address of the name in memory. Another thing related
to the name is the **value**, which is the storable quantity in memory.

But how is the meaning of names determined?

It is determined by its **attributes** (properties associated with it).

For example :

```PASCAL

const n = 15;

```

in this declaration, we associated 2 attributes :

1. It is a constant name.

2. it has a value of 15.

Another example :

```PASCAL

VAR
   x:integer;

```
again, 2 attributes are associated with this name :

1. It is a variable.

2. It is an integer.

Another example :

```PASCAL

function compute(n:integer, x:Real):Real;
	Begin
	.
	.
	.
	.
	.
	end;

```

Associated with the name ```compute``` (function name) is :

1. It's type : a function name.

2. Number and type of parameters : it takes 2 parameters, one of type ```integer```.
and one of type ```Real```.

3. It's return value : The function returns ```Real```.

4. The code body of the function.

Another example : 

```Pascal

Var 
	y:^integer;

```

Associated with the name ```y``` is :

1. It's a variable name.

2. It's a pointer variable to an integer.

---

Notice that in all the examples above are attributes that are determined
at declaration. However, we can assign attributes outside the declaration.
For example : 

```PASCAL

x := 2

```

this means that we add a new attribute to the name ```x```, which is the
value.

---

In the example :

```PASCAL

Var
	y:^integer

```

we can say 

```PASCAL

new(y);

```

in this case, we add a third attribute to ```y``` which is the location.

When we first declared y, it pointed to junk (something random). When we 
used ```new(y)```, pascal reserved a place in the memory the size
of an integer and changed the reference to it (without having to name it,
unlike C). 

---

The process of associating  attributes to names is called **Binding**.
This happens at **Binding Time**.

> Binding Time : The time during the translation(compilation) process
> when the attribute is computed and associated to the name. 

There are 2 kinds of binding times.

1. Static Binding : binding which occurs before execution. We call those
attributes static attributes.

2. Dynamic Binding : binding which occurs during execution. 

Examples : 

1. ```const n=2``` is a static attribute. This is because the 
attributes ```constant``` and ```value=2``` is assigned during 
compilation.

2. In ```x:integer``` the attributes ```variable``` and ```type integer```
are also static attributes. However, when we say ```x:=2```, the 
attribute ```value=2``` is a dynamic attribute because it is assigned
during execution.

3. In ``` y^:integer```, the attributes ```variable```, ```integer```,
and ```type pointer``` are static attributes. However, in the statement
```new(y)```, the attribute ```location``` is a dynamic attribute.

Binding can be performed prior to translation. There are a number of examples of this :

- Binding values to the ```integer``` type or the ```boolean``` type in PASCAL is performed
at **language definition time** . Meaning that if the ```integer``` type is 
16 bits, then its range would be (-2^16) &le; integer &le; (2^16 - 1 ).
  - This is the same for the ```TRUE``` and ```FALSE``` values binded to ```boolean``` type.


- The constant ```MAXINT``` in PASCAL is defined at **implementation time**(when the 
language was created). it is an ```integer``` with the highest possible value for the
platform.
  
---

In short, Binding can be performed at :

- Language definition time.

- Language implementation time.

- Translation time.
  - at lexical analysis.
  - at syntax analysis.
  - at code generation.
  - However, this binding is static.

- Execution time
  - This binding is dynamic.

### Symbol Table 

The Symbol Table is a special data structure used to maintain the binding 
during the translation process.

---

### Environment 

The Environment is the memory allocation part of the execution process. 
ie, binding names to the storage locations is called Environment. 

### Memory 

Memory is the binding the storage locations to values.

### Declarations and Blocks

Declarations are the principle method to establish binding.  There 
are 2 types of declarations:

1. Explicit Declaration:
   - Pascal : 
     
              var
                x:integer
                ok,y,Boolean;
   
             
     
    - ALGOL68 : 
       
             
                 Begin 
                   Integer X;
                   Boolean ok;
                 End
                 
    - ADA :   
               
                 Declare
                   x:integer;
                   y:boolean;
    - C :
                 
                  int n;
                 
2. Implicit Declaration : The variable is declared when it is used. 
for example, ```int n = 10```.


Declarations are associated with **blocks**. There are 2 types of 
blocks:

1. Main Program Block.

2. Procedure and Function Block.

for example, in PASCAL :

```PASCAL

Program Test;
  Var
    .
    .
    .
  Procedure P;
    Var 
      .
      .
      .
   Begin
    .
    .
    .
   End;
   
  function q:integer;
    Var 
      .
      .
      .
   Begin
    .
    .
    .
   End;
   
  Begin(*main*)
    .
    .
    .
    .
  End.
   


```

These are all declarations for program Test. Regular declaration scoping
applies here.

In ALGOL :

```ALGOL

Begin 
  Integer X;
  Boolean Y;
  .
  .
  .
  X := 2;
  Y ;= True
  .
  .
  .
End


``` 

In ADA:

```ADA

Declare 
  X : Integer;
  Y : Boolean;
  Begin
    X := 2;
    Y := 0;
  End;

```

---

Declarations bind different attributes to names especially the static
type of attributes. Note that the declaration itself has an attribute, 
which is the position of the declaration in the program. This is important
to determine the **scope/visibility** of the variable. 

#### Scope of Declaration

The Scope of Declaration is the region in which you can use or reference
a variable.

In block structured languages, the scope of declaration is limited to the 
block in which it is declared/appears and all other blocks contained
within it(the nested blocks). 

For example, consider the following program in PASCAL :

```PASCAL

Program Ex-1;
  VAR X : Integer; ________
  Procedure P;     ______  |
    VAR X:Real;    ____  | |
    BEGIN              | | |
      .                | | | 
      .                | | |
      .                | | |
    END;           ____| | |
  Procedure q;     ____  | |
    VAR Z:Boolean; __  | | |
    BEGIN            | | | |
      .              | | | |
      .              | | | |
      .              | | | |
    End;           __| | | |
                       | | |
  BEGIN(*main*)        | | |
    .                  | | | 
    .                  | | |
    .                  | | |
    .                  | | |       
  END.                 | | |
                     __|_|_|

```

Pascal has this scope rule:

> The scope of declaration extends from the point Just after the 
> declaration to the end of the block it is declared/located.

In ALGOL 60:

```ALGOL

A:BEGIN
  Integer:X;
  Boolean:Y;
  X:=2;
    .
    .
    .
  B:BEGIN
     Integer c,d;
      .
      .
      .
    END
    .
    .
    .
   END
   
```

```X``` and ```Y``` have scope in blocks ```A``` and ```B```. while ```c```
and ```d``` have scope only in ```B```
