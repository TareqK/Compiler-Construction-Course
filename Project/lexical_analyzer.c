#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include "head.h"


token* get_tokens_from_string(char* content){//convert a string into a linked list of tokens.

	token* tokens = malloc(sizeof(token));
	tokens->next = NULL;
	token* current_token = tokens;
	int quotes = 0;
	int length = strlen(content);
	int i=0;
	int j=0;
	int line_number=1;
	int position=1;
	current_token->line_number=line_number;
	current_token->position=1;
	while(i<length){
		
		char* char_at_index= &content[i];

		
		if(strchr("<>=+-*'/%()[];.\"",*char_at_index)){//if we have reached a special char and arent in a quote
			
			if(*char_at_index=='"'){//start/end of quotes
				quotes=!quotes;
				goto exception;// we are doing this because i dont feel like writing the same
				//code twice.
			}
		
		if(!quotes){	
 exception: if(j>0){//if there was a token before this
					current_token->line_number=line_number;
					current_token->position=position;
					current_token->content[j]='\0';//finish the last token
					current_token->next =  malloc(sizeof(token));//allocate the next token
					current_token=current_token->next;//move forward
					position++;
				}
				current_token->line_number=line_number;
				current_token->position=position;
				current_token->content[0]= *char_at_index;//add the token content
				current_token->content[1]='\0';//finish this token
				current_token->next =  malloc(sizeof(token));//allocate the next token
				current_token = current_token->next;//move forward
				j=0;//reset the counter
				position++;
				goto to_next;
			}else{
				current_token->content[j]=*char_at_index;
				j++;
				position++;
			}
		}else if(strchr(" \n\r\v\t",*char_at_index)&&!quotes){//if we have reached a white space and we arent in a quote
				if(*char_at_index=='\r'||*char_at_index=='\n'){
					line_number++;
					position=1;
				}
				if(j>0){
					current_token->line_number=line_number;
					current_token->position=position;
					current_token->content[j]='\0';//finish the last token
					current_token->next =  malloc(sizeof(token));//allocate the next token
					current_token=current_token->next;//move forward
					j=0;
					position++;
				}else{
					goto to_next;
				}
			}else{

				current_token->content[j]=*char_at_index;
				j++;	
				position++;
			}	
		
		to_next:i++;
	
	}
	return tokens;
}

void print_tokens(token* tokens){
	token* current_token = tokens;
	while(current_token->next!=NULL){
		printf("%s \n",current_token->content);
		current_token = current_token->next;
	}
	
}

token* get_next_token(token* tokens){
	tokens= tokens->next;
	return tokens;
}
char* read_file(char* input_file_name){//read the whole file into a single string
	
	char* file_contents;
	long input_file_size;
	FILE* input_file = fopen(input_file_name, "rb");
	if(input_file==NULL){
		printf("check file name\n");//if the file does not exist
		exit(1);
	}
	fseek(input_file, 0, SEEK_END);
	input_file_size = ftell(input_file);
	rewind(input_file);
	file_contents = malloc(input_file_size * (sizeof(char)));
	fread(file_contents, sizeof(char), input_file_size, input_file);
	fclose(input_file);
	return file_contents;
}
#endif
