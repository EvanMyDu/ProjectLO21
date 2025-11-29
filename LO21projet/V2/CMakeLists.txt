cmake_minimum_required(VERSION 4.0)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 main.c
        regle.c
        regle.h
        bc.c
        bc.h
        inference.c
        inference.h
)
