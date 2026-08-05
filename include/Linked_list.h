#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Structure to represent a node in a linked list, cotaining a pointer to the next node and a string data field. 
typedef struct node{
    struct node *next; 
    char* data;  
}token; 

// Creates a new node with the given data and returns a pointer to it. 
token* creat_node(token* head, char* data); 

// Adds a new node using the function creat_node and returns the head of the list. 
token* add_node(token *head, char* data); 

// Deletes the node with the specified data from the linked list and returns the head of the list. 
token* del_node(token *head, char* data); 

// Destroys all nodes in the linked list and frees the associated memory. Returns NULL. 
token* destroy_all_list(token *head); 

#endif 