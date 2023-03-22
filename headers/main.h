//
// Created by Dali on 16/03/2023.
//

#ifndef MY_SQL_MAIN_H
#define MY_SQL_MAIN_H


#define TRUE 1
#define FALSE 0
#define USERINFOFILE "./data/admin"
#define EXTENSION ""
#define SQLVERSION "0.0.1"

typedef enum bool  {
    true = TRUE,
    false = FALSE
}bool;
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

#include "print.h"
#include "utils.h"
#include "core.h"
#include "errors.h"
#include "sql.h"


int main(int, char **);
void remplistab(char **);
void remplictab(char **);




#endif //MY_SQL_MAIN_H
