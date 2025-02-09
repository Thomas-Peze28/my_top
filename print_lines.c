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
    my_gettime();
    mvprintw(0, 16, "%d user,", SYS.user_count);
    mvprintw(0, 25, "load average: %.2f, %.2f, %.2f\n"
        , SYS.loadavg1, SYS.loadavg2, SYS.loadavg3);
}

void print_third_line(sys_info_t SYS)
{
    mvprintw(2, 0, "Cpu(s): %-.1f us, %-.1f sy, %-.1f ni, %-.1f id"
            ", %-.1f wa, %-.1f hi, %-.1f si, %-.1f st\n"
            , CPU.us, CPU.sy, CPU.ni, CPU.id, CPU.wa, CPU.hi, CPU.si, CPU.st);
}
