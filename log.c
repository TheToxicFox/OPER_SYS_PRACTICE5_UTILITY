#include <stdio.h>
#include <stdlib.h>

//Вывод log в виде файла
void set_log_path(const char *path) {
    FILE *log_file = freopen(path, "a", stdout);
    if (!log_file) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }
}