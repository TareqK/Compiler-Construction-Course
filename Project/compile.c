/*Tareq Kirresh*/
/*1142828*/
/*Compilers and Translators Project*/
/*A C program that takes a text file as input and compiles it*/
/*using the EBNF productions given*/
/*compiled on linux using GCC*/
/*uses linux command line optiosn and works based on unix newline sequence*/
/*so not guaranteed to work on other systems*/
/*Due Date 14/1/2018*/
/*Start Date 14/1/2018*/
/* بسم الله الرحمن الرحيم  */

#include "syntax_analyzer.c"

int main(int argc , char* argv[])
{
	if(argc >= 2){//if the second argument was given
	printf("compiling file %s\n",argv[1]);
	printf("the tokens are :\n");
	char* contents = read_file(argv[1]);
	tokens = get_tokens_from_string(contents);
	token* test_tokens=tokens;
	print_tokens(test_tokens);
	printf("_____________________________\n");
	parse();
	
    }
    else{
		printf("wrong arguments. usage: compile FILE_NAME\n");
	}
	
	printf("\nBye Now!!!!\n");
	return 0;
	exit(0);
}
