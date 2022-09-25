#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc > 2){
        mx_printerr("too much arguments\n");
    }
    if (argv[1] && mx_strcmp(argv[1], "-s") != 0){
        mx_printerr("invalid flag\n");
    }
    setlocale(LC_ALL, "ja_JP.UTF-8");
    WINDOW * win;
    win = initscr();
    curs_set(0);
    noecho();
    martix(win);

    endwin();
    return 0;
}

