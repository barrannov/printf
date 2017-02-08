cmake_minimum_required(VERSION 3.6)
project(printf)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c ft_printf..c)
add_executable(printf ${SOURCE_FILES})