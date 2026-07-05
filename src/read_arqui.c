#include <stdio.h> 
#include <stdlib.h> 


#include "read_arqui.h" 


  int len_arq(arq* len){

   len->file = fopen(len->filename, "rb"); 

   if(len->file == NULL){
      printf("Error opening file: %s\n", len->filename); 
      return -1; 
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
   
   if(read == 0){
      printf("Don't have content in %s\n", nametext->filename); 
      return NULL; 
   }

   if(read != nametext->filesize){
      printf("Error copy file: %s\n", nametext->filename); 
      return NULL; 
   }
   nametext->content[nametext->filesize] = '\0'; 

   return nametext->content; 
 }


 void close_arqui(arq* nametext){
   fclose(nametext->file);
   nametext->file = NULL; 
   return;  
 } 


 int load_arq(arq* nametext){
  
  if(len_arq(nametext) == 0){
    return -1; 
  }
  
  if(all_mall(nametext) == NULL){
    return -1; 
  }
   
  if(copy_arq(nametext) == NULL){
    return -1; 
  }

  return 0; 
 }