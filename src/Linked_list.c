#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include "Linked_list.h"
#include "Token.h"

token* creat_node(token* head, char* data){
     head = (token*)malloc(sizeof(token)); 

     if(head == NULL){
        return NULL; // Memory allocation failed 
     }

     head->next = NULL; 
     head->data = data; 
     
     return head; // token created successfully 
}


token* add_node(token *head, char* data){ 

    token *new_token = creat_node(head, data); 
     
    if(head == NULL){
        return new_token; //And if head too is empty, so is to return new_token. 
    }

    token *current = head; 

    while(current->next != NULL){
       
        current = current->next; 
    }
     
       current->next = new_token; 

    return head; //head retrieved successfully. 
}

token* del_node(token *head, char* data){
     if(head == NULL){
        return NULL; 
     }
     
     if(strcmp(head->data, data) == 0 && head->next !=NULL){
        token *temp = head; 
        head = head->next; 
        free(temp); 
        temp = NULL;
         
       return head; 
     }
   
      if(strcmp(head->data, data) == 0 && head->next ==NULL){
         free(head); 
         head = NULL; 
         return NULL; 
      }

     token* prev = head;
     token*  current = head->next; 
     
    
     
     while(current != NULL){
        if(strcmp(current->data, data) == 0){ 
          prev->next = current->next; 
          free(current);
          break; 
        }else{
          prev = current; 
          current = current->next;
        } 
     }

     return head; 

   }

    token* destroy_all_list(token *head){
      token* current = head; 
      token* temp; 

      while(current != NULL){
         temp = current->next; 

         free(current->data); 
         free(current);

         current = temp; 
      }
      return NULL; 
   }