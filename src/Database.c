#include "Database.h"

#include <stdio.h> 
#include <sqlite3.h> 
#include <stdlib.h> 

static sqlite3 *db = NULL;


int db_open(const char *path){
   if (sqlite3_open(path, &db) != SQLITE_OK) {
    printf("Error in opening database!\n");
    return 0;
}
return 1; 
}

int db_has_skill(const char * token){
    if(db == NULL) return 0; 
    
  

    const char *sql = "SELECT Skills.skill FROM Skills "
                      "LEFT JOIN Synonyms ON Skills.id = Synonyms.skill_id "
                      "WHERE LOWER(?) = LOWER(Skills.skill) "
                      "OR LOWER(?) = LOWER(Synonyms.synonym);";
    
    sqlite3_stmt *stmt = NULL; 
    
    if(sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
        return 0; 
    }
     

    if(sqlite3_bind_text(stmt, 1, token, -1, SQLITE_STATIC) != SQLITE_OK){
        sqlite3_finalize(stmt); 
        return 0; 
    }  

    if(sqlite3_step(stmt) == SQLITE_ROW){
        sqlite3_finalize(stmt); 
        return 1; 
    }
  

    sqlite3_finalize(stmt); 
    return 0; 
}





void db_close(){
    if(db != NULL){
        sqlite3_close(db); 
        db = NULL; 
    }
}
