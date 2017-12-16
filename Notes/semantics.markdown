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
are also static attributes. However, when we say ```x :=2```, the 
attribute ```value=2``` is a dynamic attribute because it is assigned
during execution.

3. In ``` y^:integer```, the attributes ```variable```, ```integer```,
and ```type pointer``` are static attributes. However, in the statement
```new(y)```, the attribute ```location``` is a dynamic attribute.




