#include <stdio.h> 
#include <string.h> 

#include "read_arqui.h"

int load_arq(void){

 int* len_arq(arq* len){

   len->file = fopen(len->filename, "r"); 

   if(len->file == NULL){
      printf("Error opening file: %s\n", len->filename); 
      return NULL; 
   }

   fseek(len->file, 0, SEEK_END);
  len->filesize = ftell(len->file); 
   rewind(len->file);

   return len->filesize;  
 }

 char* all_mall(arq* len){

 len->content = (char*)malloc(len->filesize + 1);  

   if(len->content == NULL){
      printf("Memory allocation failed\n"); 
      return NULL; 
   }

  return len->content; 

 }


 char* copy_arq(arq* nametext){

   size_t read = fread(nametext->content, sizeof(char), nametext->filesize, nametext->file);
   
   if(read == NULL){
      printf("Don't have content in %s\n", nametext->file); 
      return NULL; 
   }

   if(read != nametext->filesize){
        printf("Error copy file: %s\n", file); 
      return NULL; 
   }
   nametext->content[nametext->filesize] = "\0"; 

   return nametext->content; 
 }


 void close_arqui(arq* nametext){
   fclose(nametext->file);
   return;  
 } 
}