#ifndef LINKED_LIST_H
#define LINKED_LIST_H 

typedef struct node{
    struct node *next; 
    char* data;  
}token; 

token* creat_token(char* data); 

token* add_token(token *head, char* data); 

token* del_token(token *head, char* data); 

struct token* destroy_all_list(token *head); 

#endif 