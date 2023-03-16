cmake_minimum_required(VERSION 3.24)
project(my_sql C)

set(CMAKE_C_STANDARD 17)

add_executable(my_sql main.c headers/main.h)
