#include <stdio.h> 
#include <stdlib.h> 

#include "Token.h"
#include "Feedback.h"

void feedback(match* date){
    match* current = date; 
    
    if(current == NULL){
        printf("No skills found in the resume. \n"); 
        return; 
    }

    while(current != NULL){
        printf("Skill found: %s\n", current->skill); 
        current = current->next; 
    }
 }



void load_feedback(match* date){
    feedback(date); 

    while(date != NULL){
        match* temp = date; 
        date = date->next; 
        free(temp); 
    }
   

}



