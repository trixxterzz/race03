#include "../inc/header.h"

void mx_quit(void) {
    halfdelay(1);
    noecho();
    if (getch() == 'q') {
        curs_set(true);
        endwin();
        exit(0);
    }
}

