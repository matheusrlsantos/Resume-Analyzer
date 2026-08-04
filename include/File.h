
#ifndef FILE_H
#define FILE_H

#include <stdio.h> 

typedef struct arqui{
    FILE* file; 
    char* filename;
    char* content;
    long filesize;   
}arq; 

int load_arq(arq* namtext);  

char* copy_arq(arq* nametext); 

int len_arq(arq* len);

void close_arqui(arq* nametext); 

char* all_mall(arq* len); 



#endif 