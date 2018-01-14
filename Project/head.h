#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"
#define MAX_WORDS 15
#define WORD_LENGTH 8


const char key_words[MAX_WORDS][WORD_LENGTH]={"module", "const",
	"var", "integer", "task", "begin", "end", "input", "out",
	"if", "fi", "then", "else", "while", "do"};

//a linked list of tokens. We do this because it makes it easier to get the 
//next token from the source code.

typedef struct token{

	char content[80];//we are arbitriarily limiting the length of one token for allocation reasons
	int line_number;
	int position;
	struct token* next;
	
}token;

token* get_tokens_from_string(char*);
token* get_next_token(token*);
char* read_file(char*);
int is_match(char*);
int is_key_word();
void parse();
void error();

void module_declaration();
void module_heading();
void declarations();
void compound_stmt();
void module();
void const_decl();
void var_decl();
void task_decl();
void const_item();
void var_item();
void name_list();
void task_heading();
void stmt_list();
void statement();
void ass_stmt();
void inout_stmt();
void if_stmt();
void while_stmt();
void arith_exp();
void term();
void add_sign();
void mul_sign();
void else_part();
void bool_exp();
void relational_oper();
void factor();
void name_value();
void success();
