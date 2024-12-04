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
