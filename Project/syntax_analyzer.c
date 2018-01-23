#include "lexical_analyzer.c"

token* tokens ;
int error_flag;
int error_code;

int is_match(char* expected_token){//match the expected token
	tokens = get_next_token(tokens);
	if((strcmp(tokens->content,expected_token))==0){
		return 1;
	}else{
		return 0;
	}
}

int is_key_word(){

	int i;
	for(i=0;i<MAX_WORDS;i++){
		if(strcmp(tokens->content,key_words[i])==0){
			return 1;
		}
	}
	return 0;
}

void parse(){

	error_flag=0;
	error_code=-1;
	
	
	
	module_declaration();
	success();
	
}

void error(){

	
printf("There is an error in your syntax code is %d",error_code);
printf("\n%s %d %d\n",tokens->content,tokens->line_number,tokens->position);
exit(1);

}

void success(){

	printf("\nThere were no syntax errors in your code :D\n");
}


void module_declaration(){
 //printf("you are in module_declaration function\n");


	module();//start paring
	
	if(is_match(".")){//if it returns the end symbol

		return;//exit with no errors
	}else{
		error();//otherwise exit with errors
	
	}
}
	
void module(){
 //printf("you are in module function\n");
	module_heading();
	
	declarations();
	
	compound_stmt();
	
}
	
void module_heading(){
 //printf("you are in module_heading function\n");
	
	if((strcmp(tokens->content,"module")==0)){//if it starts right
		tokens=get_next_token(tokens);
		if(is_key_word()==0){
			
			if(is_match(";")){//if it returns the end symbol
				tokens = get_next_token(tokens);
				return;
			}else{
			error_code = 3;
			error();//otherwise exit with errors
			}
			
		}else{
			error_code = 2;
			error();
		}
		
	}else{
		error_code = 1;
		error();
		}
	
	
	}
	
void declarations(){
 //printf("you are in declarations function\n");
	
	const_decl();
	
	var_decl();
	
	task_decl();
	
	}
	
void compound_stmt(){
 //printf("you are in compound_stmt function\n");
	
	if((strcmp(tokens->content,"begin")==0)){
		
		stmt_list();
		
		if((strcmp(tokens->content,"end")==0)){
			
		}else{
			error_code = 9;
			error();
		}
		
	}else{
		error_code = 8;
		error();
	}
}

void const_decl(){
 //printf("you are in const_decl function\n");

	if((strcmp(tokens->content,"const")==0)){
			while(1){
				tokens=get_next_token(tokens);
				if((strcmp(tokens->content,"var")==0)||(strcmp(tokens->content,"begin")==0)||(strcmp(tokens->content,"task")==0)){
					break;
				}else{
					const_item();
					if(!is_match(";")){
						error();
						break;
					}
				}
			}
			return;		
	}
	

	
	}
void var_decl(){
 //printf("you are in var_decl function\n");
	
	if((strcmp(tokens->content,"var")==0)){
			while(1){
				tokens=get_next_token(tokens);
				if((strcmp(tokens->content,"begin")==0)||(strcmp(tokens->content,"task")==0)){
					break;
				}else{
					var_item();
					if(!is_match(";")){
						error();
						break;
					}
				}
			}
			return;		
	}
	

	
	
	}
void task_decl(){
 //printf("you are in task_decl function\n");
	
	if (strcmp(tokens->content,"task")==0){
	task_heading();
	declarations();
	compound_stmt();
	if(is_match(";")){
		return;
	}else{
	error();
	}
	}else{
		return;
	}	
	
}
	
void const_item(){
 //printf("you are in const_item function\n");
	
	if(!is_key_word()){
		if(is_match("=")){
		if(!is_key_word()){
			tokens=get_next_token(tokens);
			return;
		}else{
			error_code=4;
			error();
		}
		}else{
			error_code=5;
			error();
		}
	
	}else{
		error_code=6;
		error();
	}
	
	}
	
void var_item(){
 //printf("you are in var_item function\n");
	
	if(!is_key_word()){
		if(is_match("=")){
		if(!is_key_word()){
			tokens=get_next_token(tokens);
			return;
		}else{
			error_code=14;
			error();
		}
		}else{
			error_code=15;
			error();
		}
	
	}else{
		error_code=16;
		error();
	}
	
	}
void name_list(){
 //printf("you are in name_list function\n");
	
	tokens = get_next_token(tokens);
	while(is_match(",")){
		tokens = get_next_token(tokens);
	}
	
	}
void task_heading(){
 //printf("you are in task_heading function\n");
	tokens = get_next_token(tokens);
	if((strcmp(tokens->content,"task")==0)){
		
		tokens = get_next_token(tokens);
		if(is_match(";")){
			
		}else{
			error();
		}
		
	}
	else{
		error();
	}
	
	}
void stmt_list(){
 //printf("you are in stmt_list function\n");
			while(1){
				tokens=get_next_token(tokens);
				if((strcmp(tokens->content,"end")==0)){
					break;
				}else{
					const_item();
					if(!is_match(";")){
						error();
						break;
					}
				}
			}
			return;		
	}
void statement(){
 //printf("you are in statement function\n");
	
	tokens = get_next_token(tokens);

	if(strcmp(tokens->content,"input")==0||strcmp(tokens->content,"out")){
	inout_stmt();
	}else if(strcmp(tokens->content,"if")){
	if_stmt();
	}else if(strcmp(tokens->content,"while")){
	while_stmt();
	}else if(strcmp(tokens->content,"begin")){
	compound_stmt();
	}else{
		ass_stmt();
	}
	
	}
void ass_stmt(){
 //printf("you are in ass_stmt function\n");
	tokens = get_next_token(tokens);
	if(is_match("=")){
		arith_exp();
		
	}else{
		error();
	}
	}
void inout_stmt(){
 //printf("you are in inout_stmt function\n");
	if(is_match("input")){
		if(is_match("(")){
			tokens = get_next_token(tokens);
			if(is_match(")")){
				
			}else{
				error();
			}
		}else{
			error();
		}
	}else if(is_match("out")){
				if(is_match("(")){
			name_value();
			if(is_match(")")){
				
			}else{
				error();
			}
		}else{
			error();
		}
	
	}else{
		
	}
}
	
void if_stmt(){
 //printf("you are in if_stmt function\n");
	
	if(is_match("if")){
		bool_exp();
		if(is_match("then")){
			statement();
			else_part();
			if(is_match("fi")){
				
			}else{
				error();
			}
		
		}else{
			error();
		}
		
	}else{
		error();
	}
	
	}
void while_stmt(){
 //printf("you are in while_stmt function\n");
	if(is_match("while")){
		bool_exp();
		if(is_match("do")){
			statement();
		}
		
	}else{
		error();
	}
}
void arith_exp(){
 //printf("you are in arith_exp function\n");
	term();
	add_sign();
	term();
	}
void term(){
 //printf("you are in term function\n");
	
	factor();
	if(is_match("(")){
		
		arith_exp();
		if(is_match(")")){
			
		}else{
			error();
		}
		
	}else{
		error();
	}
	
	}
	
void factor(){
 //printf("you are in factor function\n");
	
}

void add_sign(){
 //printf("you are in add_sign function\n");
	if(is_match("+")||is_match("-")){
		
	}else{
		error();
	}
	
	}
void mul_sign(){
 //printf("you are in mul_sign function\n");
	if(is_match("/")||is_match("*")){
		
	}else{
		error();
	}
	
	
	}
void else_part(){
 //printf("you are in else_part function\n");
	if(is_match("else")){
		statement();
		
	}else{
		return;
	}
	
	}
void bool_exp(){
 //printf("you are in bool_exp function\n");
	name_value();
	relational_oper();
	name_value();
	
	}
void relational_oper(){
 //printf("you are in relational_oper function\n");
	
	if((strcmp(tokens->content,"="))){
		return;
		
	}else if((strcmp(tokens->content,"<"))){
		tokens = get_next_token(tokens);
		if((strcmp(tokens->content,">"))||(strcmp(tokens->content,"="))){
			return;
		}else{
			return;
		}
	}else if((strcmp(tokens->content,">"))){
		tokens = get_next_token(tokens);
		if((strcmp(tokens->content,"="))){
			return;
			
		}else{
			return;
		}
	}
	
	}
	
void name_value(){
 //printf("you are in name_value function\n");
	tokens = get_next_token(tokens);
	
	}

