
#ifndef FILE_H
#define FILE_H

#include <stdio.h> 


// Structure to hold information about a file, including its pointer, name, content, and size. 
typedef struct arqui{
    FILE* file; 
    char* filename;
    char* content;
    long filesize;   
}arq; 

// Executes all functions to load the file and its content into the arq structure. Returns 0 on sucess, -1 on failure. 
int load_arq(arq* namtext);  

// Copies the content of the file into a new string and returns it. 
char* copy_arq(arq* nametext); 

// Returns the size of the file in bytes. 
int len_arq(arq* len);

// Closes the file pointer and frees any allocated memory associated with the arq structure. 
void close_arqui(arq* nametext); 

// Returns a string containing all the content of the file. 
char* all_mall(arq* len); 



#endif 