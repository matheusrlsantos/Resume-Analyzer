#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node{
    struct node *next; 
    char* data;  
}token; 

token* creat_node(token* head, char* data); 

token* add_node(token *head, char* data); 

token* del_node(token *head, char* data); 

token* destroy_all_list(token *head); 

#endif 