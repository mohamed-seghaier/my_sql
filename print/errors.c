//
// Created by Dali on 16/03/2023.
//

#include "../headers/errors.h"

void
my_printerror(char *str) {
    while (*str) {
        my_putcherror(*str);
        str++;
    }
}

void
my_putcherror(char c) {
    write(2, &c, 1);
}