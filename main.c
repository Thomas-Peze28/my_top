/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** bootstrap my_top main
*/
#include "my.h"

void init(sys_info_t *SYS)
{
    char **mem_info = my_getmemusage();

    my_getcpupercent(SYS);
    my_get_users_number(SYS);
    SYS->memory.total = atof(mem_info[1]) / 1024;
    SYS->memory.free = atof(mem_info[3]) / 1024;
    SYS->memory.available = atof(mem_info[5]) / 1024;
    SYS->memory.used = SYS->memory.total - SYS->memory.available;
    SYS->memory.swap_total = atof(mem_info[29]) / 1024;
    SYS->memory.swap_free = atof(mem_info[31]) / 1024;
    SYS->memory.swap_used = atof(mem_info[11]) / 1024;
    SYS->loadavg = my_getloaddavg();
    SYS->time = my_gettime()[1];
    SYS->tasks.total = count_tasks("/proc/");
    SYS->tasks.running = my_gettasks_total()[1];
    SYS->tasks.stopped = my_gettasks_stopped()[1];
    SYS->tasks.sleeping = SYS->tasks.total - atoi(SYS->tasks.running);
}

void print_first_line(sys_info_t SYS)
{
    mvprintw(0, 0, "top -");
    mvprintw(0, 6, "%s,", SYS.time);
    mvprintw(0, 16, "%d user ,", SYS.user_count);
    mvprintw(0, 25, "load average: %s, %s, %s\n"
        , SYS.loadavg[0], SYS.loadavg[1], SYS.loadavg[2]);
}

void display_window(sys_info_t SYS)
{
    while (1) {
        clear();
        init(&SYS);
        print_first_line(SYS);
        mvprintw(1, 0, "Tasks: %d total, %s running, %d sleeping, %s stopped\n"
            , TASK.total, TASK.running, TASK.sleeping, TASK.stopped);
        mvprintw(2, 0, "Cpu(s) : %-.1f us, %-.1f sy, %-.1f ni, %-.1f id"
            ", %-.1f wa, %-.1f hi, %-.1f si, %-.1f st\n"
            , CPU.us, CPU.sy, CPU.ni, CPU.id, CPU.wa, CPU.hi, CPU.si, CPU.st);
        mvprintw(3, 0, "MiB Mem : %-.1f total, %-.1f free, %-.1f used,\n"
            , MEM.total, MEM.free, MEM.used);
        mvprintw(4, 0, "MiB Swap : %-.1f total, %-.1f free, %-.1f used."
            " %-.1f avail Mem\n"
            , MEM.swap_total, MEM.swap_free, MEM.swap_used, MEM.available);
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
