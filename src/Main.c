#include <stdio.h> 
#include <stdlib.h>



#include "File.h"
#include "Feedback.h"
#include "Token.h" 
#include "Database.h" 

int main(void){
 
    db_open("database/database.db");
    
    printf("Welcome to Resume Analyzer!\n");

    int running = 1; 

   while(running){

    arq *nametext = calloc(1, sizeof(arq));

    printf("Please enter the path to the resume file: \n"); 
    scanf("%ms", &nametext->filename);

    load_arq(nametext);
    
    if(load_arq(nametext) == -1){
    printf("Error loading file.\n");
    continue;
    }
    
    match *date = load_token(nametext);

    load_feedback(date);

    

    printf("Continue? (1- Yes/ 0- No)\n");
    scanf("%d", &running);
}
 
  db_close(); 

  return 0; 
}


