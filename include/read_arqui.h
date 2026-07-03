
#ifndef PATH_H
#define PATH_H

#include <stdio.h> 

typedef struct arqui{
    FILE* file; 
    char* filename;
    char* content;  
}arq; 

char* len_arq(arq* len); 

FILE* read_arqui(arq* nametext); 

void  close_arqui(arq* nametext);  

FILE* write_arqui(arq* nametext);  

FILE* append_arqui(arq* nametext); 

#endif 