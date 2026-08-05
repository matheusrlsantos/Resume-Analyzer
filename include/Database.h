#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h> 

// Opens the database at the specified path and returns a handle to it. 
int db_open(const char *path); 

// Checks if the database has a skill associated whith the given token. Returns 1 if the skill exists, 0 otherwise. 
int db_has_skill(const char * token); 

// Closes the database and releases any resources associated with it. 
void db_close(void); 

#endif