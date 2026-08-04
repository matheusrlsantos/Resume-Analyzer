#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h> 

int db_open(const char *path); 

int db_has_skill(const char * token); 

void db_close(void); 

#endif