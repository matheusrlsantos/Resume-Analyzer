#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 

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
     
    word = strtok(NULL, " \n\t;,?!:" );   
  }

    return head; 
}


void normalize_token(token *head){

    token *current = head; 

    while(current != NULL){
      int i = 0; 
       
      while(current->data[i] != \0){
       
       current->data[i] = toupper(current->data[i]);
       
       i++; 
      }
        current = current->next; 
    }

}



void matching(token* head, match* date){
    token* current = head; 

    while(current != NULL){
        
        if(strcmp(current->data, path) == 0){
          add_token(date, current->data);
          

         date->much++; 
        } 

        current = current->next; 

    }

}





