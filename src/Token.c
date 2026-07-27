#include <stdio.h> 
#include <string.h> 

include "Token.h" 
include "Linked_list.h" 

token *tokenize(char *data){
if(data == NULL){
    return NULL; 
}
char *word = strtok(data, '' '\n' '\t' ';' ',' '.' '?' '!' ':' ); 

if(word == NULL){
    return NULL; 
}

token *head = NULL; 

while(word != NULL){
    head = add_token(head, word);
     
    word = strtok(NULL, '' '\n' '\t' ';' ',' '.' '?' '!' ':' );   
  }

    return head; 
}
