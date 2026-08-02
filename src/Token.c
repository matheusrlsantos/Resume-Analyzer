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



match* matching(token* head){
    token* current = head; 
    match* date = NULL; 

 

    while(current != NULL){
        
        if(db_has_skill(current->data)){
          date = add_node(date, current->data);
          

        
        } 

        current = current->next;
         

    }
    return date; 

}

int load_token(token* text){
  token *tokens = tokenize(text); 
  
  if(tokens == NULL){
    return -1; 
  }
  tokens = normalize_token(tokens); 

  if(tokens == NULL){
    return -1; 
  }
   match* date = matching(tokens); 

  if(tokens == NULL){
    return -1; 
  }

  return 0; 
 }



