#include <stdio.h> 
#include <string.h> 

#include "read_arqui.h"

char* len_arq(arq* len){

   len->file = fopen(len->filename, "r"); 

   if(len->file == NULL){
      printf("Error opening file: %s\n", len->filename); 
      return NULL; 
   }

   fseek(len->file, 0, SEEK_END);
   long size = ftell(len->file); //Think about it tomorrouw. 

   len->content = (char*)malloc(size + 1);  //Don't forget to allocate space for the NULL terminal 

   if(len->content == NULL){
      printf("Memory allocation failed\n"); 
      return NULL; 
   }
   
   return len->content; 
}


FILE* read_arqui(arq* nametext){
    nametext->file = fopen(nametext->filename, "r"); 

   if (nametext == NULL){
        printf("Error opening file: %s\n", nametext->filename); 
        return; 
   }
   return nametext->file; 

}

FILE* write_arqui(arq* nametext){
    
    nametext->file = fopen(nametext->filename, "w"); 

    if (nametext->file == NULL){
        printf("Error opening file: %s\n", nametext->filename); 
        return;
    }

    fprintf(nametext->file, "%s", nametext->filename);
    return nametext->file; 
} 

FILE* append_arqui(arq* nametext){
      nametext->file = fopen(nametext->filename, "a"); 

    if (nametext->file == NULL){
        printf("Error opening file: %s\n", nametext->filename); 
        return;
    }

    fprintf(nametext->file, "%s", nametext->filename);
    return nametext->file;
}

void close_arqui(arq* nametext){
   fclose(nametext->file);
   return;  
} 