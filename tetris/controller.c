#include "view.h"
#include "model.h"
#include <stdio.h>
#include <ncurses.h>
#include <stdbool.h>

int main() {
    int key;
    tetris *model = tetris_alloc();
    bool new_block_needed = false;

    initscr();
    keypad(stdscr, true);
    noecho();
    timeout(1000);
    curs_set(false);

    while (1) {
        key = getch();
        // printf("%d\n", key);
        switch (key)
        {
        case KEY_UP:
            render_msg("up  ");
            break;
        case KEY_DOWN:
            render_msg("down ");
            break;
        case KEY_LEFT:
            render_msg("left ");
            break;
        case KEY_RIGHT:
            render_msg("right");
            break;
        case 'q':
        case 'Q':
            goto FIN;
        default:
            break;
        }
        
        render_board(model->board);
        render_next_block(model->next_block);
        refresh();

        // if (new_block_needed) {
            tetris_set_needs_new_block(model);
        // }
    }

FIN:
    endwin();

    tetris_free(model);
    return 0;
}
