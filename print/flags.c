//
// Created by Dali on 16/03/2023.
//


#include "../headers/print.h"

void	flag_d(va_list ap)
{
	my_putnbr(va_arg(ap, int));
}

void	flag_s(va_list ap)
{
	my_putstr(va_arg(ap, char *));
}

void	flag_c(va_list ap)
{
	my_putchar(va_arg(ap, int));
}
