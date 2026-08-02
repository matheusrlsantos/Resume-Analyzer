#ifndef TOKEN_H
#define TOKEN_H 

#include "LINKED_LIST.h" 

typedef struct matching_data{
    char * skill; 
    int  score;

    struct matching_data *next; 
}match; 

token *tokenize(char *str); 

token *comp_token(token *list, char *data); 

token *normalize_token(token *list, char *data); 

token *destruct_token(token *list, char *data); 


#endif