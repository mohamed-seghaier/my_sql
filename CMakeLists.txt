cmake_minimum_required(VERSION 3.24)
project(my_sql C)

set(CMAKE_C_STANDARD 17)

add_executable(my_sql src/main.c headers/main.h print/flags.c print/my_printers.c print/my_printf.c headers/print.h utils/get_next_line.c utils/utils.c headers/utils.h src/core.c headers/core.h src/argfunc.c print/errors.c headers/errors.h src/sql.c headers/sql.h src/tables.c src/databases.c)
