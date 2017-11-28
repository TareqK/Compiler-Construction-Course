# Question 1

## Part A



Symbol | FIRST() set
---|---
$ |	$
d  |  d
a 	|a
&lambda; 	|&lambda;
b 	|b
c 	|c
S 	|d, b, c, a, &lambda;
A 	|a, &lambda;
B 	|b, c
S' 	|d, b, c, a, &lambda;



Symbol | FOLLOW() set
---|---
S' | $
S  | $
A  | d, a, $
B  | a, $
   
## Part B


Symbol | FIRST() set
---|---
a 	|a
&lambda; 	|&lambda;
b 	|b
c 	|c
S' 	|a
S 	|a
A 	|a, b
B 	|a, &lambda;
C 	|b, &lambda;
D 	|c, &lambda;



Symbol | FOLLOW() set
---|---
S' | #
S |	a
A |	a,b,c
B |	a
C |	b,c
D | c
   
# Question 2

```

main(){

 get-token();
 
 call block();

 if(token!="$")
 {
	Error;
 }
 else{
	SUCCESS;
 }
	

}

block(){

	if(token != "begin")
	{
	throw_error();
	}
	else{
	get-token();
	call decls();
	}


}

decls(){
	
	while(token=="D"){
		get_token();
	}if(token == ";"){
	call decls();
	}else{
	if(token==""){
		get-token();
		call stmts();
	}else{
	throw_error();
	}
	}

}

stmts(){
	
	while(token!=";"){
		get_token();
		call statement();
	}
	if(token==""){
		get-token();
	}else{
	throw_error();
	}
	

}
statement(){
	if(token == "begin"){	
		call stmts();
	}
	else if(token == "end"){
		get-token();
	}
	else if(token == "if"){
		get-token();
		
	}
	else if(token == "while"){
		get-token();
		
	}
	else if(token == "ass"){
		get-token();
		
	}
	else if(token == "scan"){
		get-token();
		
	}
	else if(token == "print"){
		get-token();
		
	}
	else if(token != "" || ";"){
		throw_error();
	}
	}

```

# Question 3
 
S' -->  S $ 1

S  -->  iCSE 2   |    a 3

E  --> eS  4 |  &lambda; 5

C  --> c 6

Symbols | FIRST() set 
--|--
S |	i, a
E |	e, &lambda;
C |	c
S'| i, a


Symbols | FOLLOW() set
---|---
S' | $
S |	e, $
E |	e, $
C |	i, a


V<sub>N</sub>\\V<sub>T</sub>| i | a | e | c | $
---|---|---|---|---|---
 S`| 1 | 1 |   |   |
 S | 2 | 3 |   |   | 
 E |   |   |4,5|   | 5  
 C |   |   |   | 6 |

There is a conflict, this table is not LL(1)

b. S  -->  iCSE  | a  becomes S -->  iCSEd  |  a 



V<sub>N</sub>\\V<sub>T</sub>| i | a | e | c | d | $ 
---|---|---|---|---|---|---
 S`| 1 | 1 |   |   |   |
 S | 2 | 3 |   |   |   |
 E |   |   | 4 |   | 5 |  
 C |   |   |   | 6 |   | 

