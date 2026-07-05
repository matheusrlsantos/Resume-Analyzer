
#ifndef PATH_H
#define PATH_H

#include <stdio.h> 

typedef struct arqui{
    FILE* file; 
    char* filename;
    char* content;
    long filesize;   
}arq; 

int load_arq(arq* namtext);  


#endif 