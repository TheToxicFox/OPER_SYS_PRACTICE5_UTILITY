#include <stdio.h>

//Выводит подсказку для команд
void print_help() {
    printf("Usage:\n");
    printf("  -u, --users       Show list of users and their home directories\n");
    printf("  -p, --processes   Show list of running processes\n");
    printf("  -h, --help        Show this help message\n");
    printf("  -l, --log PATH    Output logs to file at PATH\n");
    printf("  -e, --errors PATH Redirect errors to file at PATH\n");
}