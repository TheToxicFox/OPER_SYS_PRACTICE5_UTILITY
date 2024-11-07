#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"

void list_processes(const char *log_path) {
    FILE *output;

    if (log_path) {
        output = fopen(log_path, "w");
        if (output == NULL) {
            perror("Error opening log file");
            return;
        }
    } else {
        output = stdout;
    }

    // Используем ps для вывода процессов
    FILE *fp = popen("ps -e --sort=pid", "r");
    if (fp == NULL) {
        perror("Failed to run ps command");
        if (log_path) fclose(output);
        return;
    }

    // Читаем вывод команды и записываем в файл или на консоль
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        fprintf(output, "%s", buffer);
    }

    pclose(fp);
    if (log_path) fclose(output);
}
