cmake_minimum_required(VERSION 3.10)

project(Praktika5_UtilityC VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(Praktika5_UtilityC main.c   help.c users.c processes.c errors.c log.c)
target_compile_options(Praktika5_UtilityC PRIVATE -Wall -Werror)
