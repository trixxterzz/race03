#include "../inc/header.h"

int mx_strcmp(const char *str1, const char *str2) {
    while (*str1 == *str2) {
        if (*str1 == '\0') {
            break;
        }
        ++str1;
        ++str2;
    }
    return (*(unsigned char *)str1) - (*(unsigned char *)str2);
}

