#include <stdio.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"

void list_users(const char *log_path) {
    struct passwd *pw;
    FILE *output;

    // Если указан путь к лог-файлу, открываем его для записи
    if (log_path) {
        output = fopen(log_path, "w");
        if (output == NULL) {
            perror("Error opening log file");
            return;
        }
    } else {
        // Если путь к лог-файлу не указан, выводим на экран
        output = stdout;
    }

    // Получаем и выводим список пользователей
    while ((pw = getpwent()) != NULL) {
        fprintf(output, "User: %s, Home Dir: %s\n", pw->pw_name, pw->pw_dir);
    }
    endpwent();

    // Закрываем лог-файл
    if (log_path) fclose(output);
}
