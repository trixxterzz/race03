#include "../inc/header.h"

void mx_printerr(const char *str) {
    write(2, str, mx_strlen(str));
    exit(1);
}

