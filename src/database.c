#include "database.h"


static sqlite3 *db = NULL;


int db_open(const char *path){
    return sqlite3_open(path, &db); 
}


void db_close(void){
    if(db != NULL){
        sqlite3_close(db); 
        db = NULL; 
    }
}

