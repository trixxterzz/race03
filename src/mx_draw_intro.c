#include "../inc/header.h"

void mx_draw_intro(void) {
    char *intro[] = {"Wake up , Neo..", "The Matrix has you..",
                     "Follow the white rabbit", "Knock, knock, Neo"};
    int phrases_count = sizeof(intro) / sizeof(intro[0]);
    int phrase_length;

    for (int i = 0; i < phrases_count; ++i) {
        phrase_length = mx_strlen(intro[i]);
        for (int j = 0; j < phrase_length; ++j) {
            mvaddch(4, 2 + j, intro[i][j] | COLOR_PAIR(2));
            refresh();
            mx_quit();
            usleep(170000);
        }
        clear();
        usleep(100000);
    }
}

