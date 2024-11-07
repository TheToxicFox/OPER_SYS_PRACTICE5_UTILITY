#include <stdio.h>
#include <stdlib.h>

void set_error_path(const char *error_path) {
    if (error_path) {
        // Открываем файл для записи ошибок
        if (freopen(error_path, "w", stderr) == NULL) {
            perror("Error opening error log file");
        }
    }
}