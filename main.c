/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** bootstrap my_top main
*/
#include "my.h"

void print_first_line(sys_info_t SYS)
{
    mvprintw(0, 0, "top -");
    mvprintw(0, 6, "%s,", SYS.time);
    mvprintw(0, 16, "%d user,", SYS.user_count);
    mvprintw(0, 25, "load average: %s, %s, %s\n"
        , SYS.loadavg[0], SYS.loadavg[1], SYS.loadavg[2]);
}

void print_third_line(sys_info_t SYS)
{
    mvprintw(2, 0, "Cpu(s): %-.1f us, %-.1f sy, %-.1f ni, %-.1f id"
            ", %-.1f wa, %-.1f hi, %-.1f si, %-.1f st\n"
            , CPU.us, CPU.sy, CPU.ni, CPU.id, CPU.wa, CPU.hi, CPU.si, CPU.st);
}

void display_mem(sys_info_t SYS)
{
    mvprintw(3, 0, "MiB Mem : %-.1f total, %-.1f free, %-.1f used,\n"
        , MEM.total, MEM.free, MEM.used);
    mvprintw(4, 0, "MiB Swap:  %-.1f total, %-.1f free, %-.1f used."
        " %-.1f avail Mem\n"
        , MEM.swap_total, MEM.swap_free, MEM.swap_used, MEM.available);
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
        mvprintw(6, 0, "%7s %-7s    PR  NI    VIRT    RES"
            "SHR S  %%CPU  %%MEM    TIME+ COMMAND", "PID", "USER");
        attroff(A_REVERSE);
        read_pid();
        read_user();
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
    init(&SYS);
    printf("TOTAL %d\n", SYS.tasks.total);
    get_uid("/proc/1/status");
    return 0;
}
