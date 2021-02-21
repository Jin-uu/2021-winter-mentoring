#include "view.h"
#include "model.h"
#include <stdio.h>
#include <ncurses.h>
#include <stdbool.h>

int main() {
    int key;
    int st_x = 22, st_y = 9;
    tetris *model = tetris_alloc();
    bool new_block_needed = false;

    initscr();
    keypad(stdscr, true);
    noecho();
    timeout(1000);
    curs_set(false);
    
    while (1) {
        key = getch();
        clear();
        // printf("%d\n", key);
        switch (key)
        {
        case KEY_UP:
            render_msg("up  ");
            --st_y;
            // mvprintw(--st_y, st_x, "Z");
            break;
        case KEY_DOWN:
            render_msg("down ");
            ++st_y;
            // mvprintw(++st_y, st_x, "Z");
            break;
        case KEY_LEFT:
            render_msg("left ");
            --st_x;
            // mvprintw(st_y, --st_x, "Z");
            break;
        case KEY_RIGHT:
            render_msg("right");
            ++st_x;
            // mvprintw(st_y, ++st_x, "Z");
            break;
        case 'q':
        case 'Q':
            goto FIN;
        default:
            break;
        }
        model -> board[st_y][st_x] = 1;
        model -> board[st_y][st_x+1] = 1;
        model -> board[st_y+1][st_x+1] = 1;
        model -> board[st_y+1][st_x+2] = 1;
        render_board(model->board);
        render_next_block(model->next_block);
        refresh();
        model -> board[st_y][st_x] = 0;
        model -> board[st_y][st_x+1] = 0;
        model -> board[st_y+1][st_x+1] = 0;
        model -> board[st_y+1][st_x+2] = 0;

        // if (new_block_needed) {
            tetris_set_needs_new_block(model);
        // }
    }

FIN:
    endwin();

    tetris_free(model);
    return 0;
}
