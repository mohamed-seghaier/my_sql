//
// Created by Dali on 16/03/2023.
//

#ifndef MY_SQL_UTILS_H
#define MY_SQL_UTILS_H

#include "./main.h"


/**
 * GET_NEXT_LINE.C
 */
char    *get_next_line(int);
void	my_memset(char *, int, int);

/**
 * UTILS.C
 */
int     my_strlen(const char *);
char    *my_strcpy(char *);
int     my_getnbr(char *);
char	*my_strcat(char *, char *);
int     my_strcmp(char *, char *);
char    **my_strtab(char *, char);
char    *remplitab(char *, char *, int, char);
int     my_eolen(char *, char);
char    *epurStrForSqlCmd(char *);
int     tablen(char **);




#endif //MY_SQL_UTILS_H
