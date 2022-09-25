#pragma once

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>

typedef struct s_line{
    int len;
    int x;
    int is_printed;
    int start;
    int end;
}              t_line;

int mx_strlen(const char *str);
int mx_strcmp(const char *str1, const char *str2);
void mx_printerr(const char *str);

void mx_quit(void);
void mx_draw_intro(void);

void mx_colors_init(void);
int martix(WINDOW *win);
wchar_t mx_alphabet(void);
void mx_init_arr(int size, t_line arr[size], int max_y, int max_x);

