#include "../inc/header.h"

wchar_t mx_alphabet(void){
    wchar_t alphabet[] = {L"゠ァアィイゥウェエォオカガキギクグケゲコゴサザシジスズセゼソゾタ"
                         "ダチヂッツヅテデトドナニヌネノハバパヒビピフブプヘベペホボポマミ"
                         "ムメモャヤュユョヨラリルレロヮワヰヱヲンヴヵヶヷヸヹヺ・ーヽヾヿ"};
    return alphabet[rand() % 96];
    
}

int martix(WINDOW *win) {
    int arr_size = win->_maxx / 2;
    t_line arr[arr_size];
    mx_init_arr(arr_size, arr, win->_maxy, win->_maxx);
    mx_colors_init();
    mx_draw_intro();

    attrset(COLOR_PAIR(2));
    halfdelay(1);
    int flag = 0;
    wchar_t prev;
    wchar_t last[arr_size];
    while (getch() != 'q'){
        attrset(COLOR_PAIR(2));
        for (int i = 0; i < arr_size; i++){
            if ((flag < arr_size && i != flag && arr[i].end == 0)){
                continue;
            }
            if (arr[i].is_printed == 0){
                if (arr[i].end < win->_maxy){
                    if (last[i]){
                        attrset(COLOR_PAIR(rand() % 7 + 1));
                        mvprintw(arr[i].end - 1, arr[i].x, "%lc", last[i]);
                    }
                    attrset(COLOR_PAIR(1));
                    prev = mx_alphabet();
                    mvprintw(arr[i].end, arr[i].x, "%lc", prev);
                    last[i] = prev;
                    arr[i].end += 1;
                }
                else if (arr[i].end == win->_maxy){
                    attrset(COLOR_PAIR(rand() % 7 + 1));
                    mvprintw(arr[i].end - 1, arr[i].x, "%lc", last[i]);
                    arr[i].end += 1;
                }
                if (arr[i].start > win->_maxy + 1){
                    arr[i].is_printed = 1;
                    continue;
                }
                if (arr[i].end > arr[i].len){
                    mvprintw(arr[i].start, arr[i].x, " ");
                    arr[i].start += 1;
                }
            } 
            else{
                arr[i].len = rand() % (win->_maxy - 1) + 1;
                arr[i].is_printed = 0;
                arr[i].x = rand() % win->_maxx;
                arr[i].start = 0;
                arr[i].end = 0;
                prev = mx_alphabet();
                attrset(COLOR_PAIR(rand() % 7 + 1));
                mvprintw(arr[i].end, arr[i].x, "%lc", prev);
                last[i] = prev;
                arr[i].end += 1;
            }
            refresh();
        }
        flag++;
        usleep(30000);
    }

    return 0;
}

