//
// Created by Dali on 16/03/2023.
//

#ifndef MY_SQL_MAIN_H
#define MY_SQL_MAIN_H

#define TRUE 1
#define FALSE 0

typedef enum bool  {
    true = TRUE,
    false = FALSE
}bool;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "print.h"
#include "utils.h"
#include "core.h"
#include "errors.h"


int main(int, char **);
void remplistab(char **);
void remplictab(char **);




#endif //MY_SQL_MAIN_H
