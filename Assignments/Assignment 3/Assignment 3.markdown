Tareq Kirresh, 1142828

Given the Grammar 

>  S` --> S (1)
> 
> S --> L = R (2)
>
> S --> R (3)
> 
> L --> \* R (4)
> 
> L --> a (5)
>
> R --> L (6)

Build the SLR(1) Parsing Table

I<sub>0</sub> :
- S` --> .S I<sub>1</sub> 
 
- S --> .L = R I<sub>2</sub> 

- S --> .R I<sub>3</sub> 
 
- L --> .\* R I<sub>4</sub> 
 
- L --> .a I<sub>5</sub> 

- R --> .L I<sub>2</sub> 


I<sub>1</sub> :

- S` --> S.$  Accept

I<sub>2</sub> :

- S --> L. = R 

- R --> L. Complete

I<sub>3</sub> :

- S --> R. Complete

I<sub>4</sub> :

- L --> a. Complete

I<sub>5</sub>

- L --> \* . R 

CLOSURE(I<sub>5</sub>) :

I<sub>1</sub> :

- S` --> S.$  ACCEPT

I<sub>2</sub> :

- S --> L. = R 

- R --> L. COMPLETE

I<sub>3</sub> :

- S --> R. COMPLETE

I<sub>4</sub> :

- L --> a. COMPLETE

I<sub>5</sub>

- L --> \* . R 

- R --> .L

- L --> .a

READ():

I<sub>1</sub> :

- S` --> S.$  ACCEPT

I<sub>2</sub> :

- S --> L =. R I<sub>6</sub>

- R --> L. COMPLETE

I<sub>3</sub> :

- S --> R. COMPLETE

I<sub>4</sub> :

- L --> a. COMPLETE

I<sub>5</sub>

- L --> \*  R. COMPLETE

- R --> L. COMPLETE

- L --> a COMPLETE

I<sub>6</sub>

- S --> .L = R 

CLOSURE(I<sub>6</sub>)

I<sub>1</sub> :

- S` --> S.$ ACCEPT

I<sub>2</sub> :

- S --> L = R. COMPLETE 


- R --> L. COMPLETE

I<sub>3</sub> :

- S --> R. COMPLETE

I<sub>4</sub> :

- L --> a. COMPLETE

I<sub>5</sub>

- L --> \*  R. COMPLETE 

- R --> L. COMPLETE

- L --> a. COMPLETE

I<sub>6</sub>

- S --> .L = R 

- R --> .L

- L --> . \* R

- L --> . a
