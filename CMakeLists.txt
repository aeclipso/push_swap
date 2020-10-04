cmake_minimum_required(VERSION 3.17)
project(Push_Swap_0_0_3 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(sort_func)

add_executable(Push_Swap_0_0_3
        include/pushswap.h
        sort_func/func.h
        sort_func/push_func.c
        sort_func/revrot_func.c
        sort_func/rotate_func.c
        sort_func/swap_func.c
        general.c
        main.c
        reading.c
        stringtonumbers.c
        whitespace.c)
