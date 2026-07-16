#ifndef TOKEN_H
#define TOKEN_H 

#include "LINKED_LIST.h" 

token *tokenize(char *str); 

token *comp_token(token *list, char *data); 

token *normalize_token(token *list, char *data); 

token *destruct_token(token *list, char *data); 


#endif