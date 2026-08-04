#ifndef TOKEN_H
#define TOKEN_H

#include "Token.h" 
#include "Linked_list.h" 
#include "Database.h"
#include "File.h" 

typedef struct matching_data{
    char * skill; 
    int  score;

    struct matching_data *next; 
}match; 

token *tokenize(arq* data); 

match* matching(token* head); 

token *normalize_token(token* head); 

match* load_token(arq* text); 


#endif