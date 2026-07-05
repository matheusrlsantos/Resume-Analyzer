#include <stdio.h> 
#include <stdlib.h>
#include <locale.h> 


#include "read_arqui.h"

int main(void){

  setlocale(LC_ALL, "Portuguese_Brazil.1252");

   arq* nametext = (arq*)calloc(1, sizeof(arq));  
   

    
  printf("Digite o nome do arquivo: \n"); 
  scanf("%ms", &nametext->filename); 

  load_arq(nametext);

  printf("O nome do arquivo e: %s\n", nametext->filename); 
  printf("O tamanho do arquivo e: %ld bytes\n", nametext->filesize); 
  printf("O conteudo do arquivo e: %s\n", nametext->content); 

  return 0; 
}


