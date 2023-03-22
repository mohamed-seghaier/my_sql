//
// Created by Dali on 17/03/2023.
//

#ifndef MY_SQL_SQL_H
#define MY_SQL_SQL_H

#include "main.h"
#include "core.h"
typedef struct s_line t_line;

void    treatSqlCommand(t_line *);
void    cmdCreate(t_line *);
void    cmdShow(t_line *);
void    cmdDescribe(t_line *);
void    cmdInsert(t_line *);
void    cmdUse(t_line *);
void    cmdSelect(t_line *);

void    createDatabase(t_line *);
void    createTable(t_line *);
void    createUser(t_line *);

void    createUserDir(t_line *);

void    showDatabases(t_line *);
void    showDatabaseHeader();
void    showDatabaseFooter();
void    showTables(t_line *);

#endif //MY_SQL_SQL_H
