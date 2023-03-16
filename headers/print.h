//
// Created by Dali on 16/03/2023.
//

#ifndef MY_SQL_PRINT_H
#define MY_SQL_PRINT_H

#include "main.h"
#include <stdarg.h>

/**
 * MY_PRINTF.C
 */
void    my_printf(char *, ...);
int     checkflag(char);
void    my_ptab(int, va_list);


/**
 * MY_PRINTERS.C
 */

void    my_putchar(char);
void    my_putstr(char *);
void	my_putnbr(int);

/**
 * FLAGS.C
 */
void flag_d(va_list);
void flag_s(va_list);
void flag_c(va_list);



#endif //MY_SQL_PRINT_H
