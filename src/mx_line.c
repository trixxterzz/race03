#include "../inc/header.h"

void mx_init_arr(int size, t_line arr[size], int max_y, int max_x){
    for (int i = 0; i < size; i++){
        arr[i].len = rand() % (max_y - 1) + 1;
        arr[i].is_printed = 0;
        arr[i].x = rand() % max_x;
        arr[i].start = 0;
        arr[i].end = 0;
    }
}

