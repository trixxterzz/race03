#include "../inc/header.h"

int mx_strlen(const char *str) {
    const char *end_of_string = str;

    while (*end_of_string) {
        ++end_of_string;
    }
    return (int)(end_of_string - str);
}

