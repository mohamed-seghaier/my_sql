//
// Created by Dali on 16/03/2023.
//

#ifndef MY_SQL_CORE_H
#define MY_SQL_CORE_H

#include "main.h"

/**
 * FORMATS:
 * -h --help || -v --version || -l --login || -u --user || -p --password || -s --sql || -f --format || -i --signin
 */

typedef struct s_args {
    int argc;
    char **argv;
}arg_t;

typedef struct s_usri {
    char *user;
    char *password;
    char *databaseSelected;
}usr_t;

typedef struct s_cmd {
    char **tab;
    char **sqlcmd;
}cmd_t;

typedef struct s_flags {
    char **shortFlags;
    char **longFlags;
}flags_t;

typedef struct s_line {
    arg_t args;
    flags_t flags;
    usr_t usr;
    cmd_t cmd;
} t_line;
typedef	void	(*ftab_t)(t_line *);


/**
 * SQL COMMANDS
 */

#define CMD_CREATE              0
#define CMD_SHOW                1
#define CMD_DESCRIBE            2
#define CMD_INSERT              3
#define CMD_SELECT              4
#define CMD_USE                 5
#define CMDTAB_NULL             6
#define CMDTAB_SIZE             7


/**
 * TERMINAL COMMANDS
 */

#define HELP            0
#define VERSION         1
#define LOGIN           2
#define SIGNIN          3
#define USER            4
#define PASSWORD        5
#define SQL             6
#define FORMAT          7
#define FTAB_NULL       8
#define FTAB_SIZE       9

/**
 * CORE.C
 */

void    starter_flags(int, char **, char **, char **);
void    exit_bad_args();
void    sqlBaseFunc(t_line *);


/**
 * ARGFUNC.C
 */

void    initArgPointerTab(ftab_t *);
void    initTlineStruct(int, char **, char **, char **, t_line *);
void    helper(t_line *);
void    versioner(t_line *);
void    loginer(t_line *);
void    userer(t_line *);
void    passworder(t_line *);
void    sqler(t_line *);
void    formater(t_line *);
void    loginer(t_line *);
void    signin(t_line *);
bool    checkUser(t_line *);

void    core(t_line *);
void    newUser(t_line *);


#endif //MY_SQL_CORE_H
