#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include "LINKED_LIST.h"

struct token* creat_token(token *head, char* data){
     head = (token*)malloc(sizeof(token)); 

     if(head == NULL){
        return NULL; // Memory allocation failed 
     }

     head->next = NULL; 
     head->data = data; 
     
     return head; // token created successfully 
}


struct token* add_token(token *head, char* data){ 

    token *new_token = creat_token(head, data); 
     
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

struct token* del_token(token *head, char* data){
     if(head == NULL){
        return NULL; 
     }
     if(strcmp(head->data, token) == 0 && head->next !=NULL){
        token *temp = head; 
        head = head->next;
        free(temp); 
     }

     struct token* prev = head;
     struct token*  current = head->next; 
     struct token*  next = head->next->next;  
    
     
     while(current->prev->next != NULL){
        if(strcmp(current->data, token) == 0){ 
          prev->next = next; 
          free(current);
        }else{
      current = current->next;
        } 
     }

     return head; 

}








