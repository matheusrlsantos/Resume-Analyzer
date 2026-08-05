#include <string.h> 
#include <ctype.h> 
#include <stdlib.h>
#include <stdio.h> 

#include "Token.h" 
#include "Linked_list.h" 
#include "Database.h"
#include "File.h" 

// All information about the file is stored in file structure, which is defined in Token.h. 

token *tokenize(arq *data){
if(data->content == NULL){
    return NULL; 
}

const char *delimiters = " \n\r\t,;:!?-=/\\()[]{}";

char *word = strtok(data->content, delimiters); 

if(word == NULL){
    return NULL; 
}

token *head = NULL; 

   while(word != NULL){
    if(strlen(word) != 0){    
      char* word_copy = strdup(word); 
      head = add_node(head, word_copy);
    
    } 
     
    word = strtok(NULL,delimiters);   
  }

    return head; 
}


token* normalize_token(token *head){

    token *current = head; 

    while(current != NULL){
      int i = 0; 
       
      while(current->data[i] != '\0'){
       
       current->data[i] = toupper(current->data[i]);
       
       i++; 
      }
        current = current->next; 
    }
    return head; 
} 



match* matching(token* head){
    token* current = head; 
    match* list_head = NULL; 
    match* list_tail = NULL; 
    
   
 

    while(current != NULL){
      
      int achou = db_has_skill(current->data);
       

        if(achou){
          match* new_match = calloc(1, sizeof(match));
            if(new_match== NULL){
              current = current->next; 
              continue; 
            }

            new_match->skill = strdup(current->data);
            new_match->next = NULL; 

            if(list_head == NULL){

               list_head = new_match; 
               list_tail = new_match;
        
            }else{

               list_tail->next = new_match; 
               list_tail = new_match; 

            }

          }
        current = current->next; 

        } 

    
    return list_head; 

}

match* load_token(arq* text){
  if(text == NULL) return NULL; 

  token *local_tokens = tokenize(text); 
  
  if(local_tokens == NULL){
    return NULL; 
  }
  local_tokens = normalize_token(local_tokens); 

  if(local_tokens == NULL){
    return NULL; 
  }
   match* date = matching(local_tokens); 

  if(date == NULL){
    return NULL; 
  }
   if(text->file != NULL){
   fclose(text->file);
   text->file = NULL; 
   }

   if(text->content != NULL){
   free(text->content); 
   text->content  = NULL; 
   }

   while(local_tokens != NULL){
   token *temp = local_tokens; 
   local_tokens = local_tokens->next; 
    
   
   if(temp->data != NULL){
    free(temp->data); 
   }
   
   free(temp); 
   }
  local_tokens = NULL; 




  return date; 
 }



