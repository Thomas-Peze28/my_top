/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** bootstrap my_top main
*/
#include "my.h"

void display_mem(sys_info_t SYS)
{
    mvprintw(3, 0, "MiB Mem : %-.1f total, %-.1f free, %-.1f used,\n"
        , MEM.total, MEM.free, MEM.used);
    mvprintw(4, 0, "MiB Swap:  %-.1f total, %-.1f free, %-.1f used."
        " %-.1f avail Mem\n"
        , MEM.swap_total, MEM.swap_free, MEM.swap_used, MEM.available);
}

void read_all(void)
{
    read_pid();
    read_user();
    read_priority();
    read_virt();
}

void display_window(sys_info_t SYS)
{
    while (1) {
        clear();
        init(&SYS);
        print_first_line(SYS);
        mvprintw(1, 0, "Tasks: %d total, %d running, %d sleeping"
            ", %d stopped, %d zombie\n"
            , TASK.total, TASK.running, TASK.sleeping
            , TASK.stopped, TASK.zombie);
        print_third_line(SYS);
        display_mem(SYS);
        attron(A_REVERSE);
        mvprintw(6, 0, "%7s %-7s %3s %3s %8s %8s %8s %1s %s",
            "PID", "USER", "PR", "NI", "VIRT", "RES", "SHR", "S", "COMMAND");
        attroff(A_REVERSE);
        read_all();
        refresh();
    }
    endwin();
}

int main(void)
{
    sys_info_t SYS;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    display_window(SYS);
    return 0;
}
