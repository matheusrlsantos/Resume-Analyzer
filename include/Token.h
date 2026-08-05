#ifndef TOKEN_H
#define TOKEN_H

#include "Token.h" 
#include "Linked_list.h" 
#include "Database.h"
#include "File.h" 

// Structure to hold information about a matching skill, including its name, score, and a pointer to the next matching skill. 
typedef struct matching_data{
    char * skill; 
    int  score;

    struct matching_data *next; 
}match; 

// Tokenizes the content of the given arq structure and returns a linked list of tokens. 
token *tokenize(arq* data); 

// Matches the tokens in the given linked list against the skills in the database and returns a linked list of matching skills. 
match* matching(token* head); 

//  Normalizes the tokens in the given linked list by converting them to lowercase and removing any leading or trailing whitespace.
// Returns the head of the normallized linked list. 
token *normalize_token(token* head); 

// Executes all functions to load the tokens from the given arq structure and returns a linked list of matching skills. 
match* load_token(arq* text); 


#endif