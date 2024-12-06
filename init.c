/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** bootstrap my_top main
*/
#include "my.h"

void init(sys_info_t *SYS)
{
    my_getloaddavg(SYS);
    init_mem(SYS);
    init_swap_total(SYS);
    init_swap_free(SYS);
    init_swap_cached(SYS);
    my_getcpupercent(SYS);
    my_get_users_number(SYS);
    my_gettime();
    SYS->tasks.total = 0;
    SYS->tasks.running = 0;
    SYS->tasks.stopped = 0;
    SYS->tasks.sleeping = 0;
    SYS->tasks.zombie = 0;
    read_dir_tasks("/proc/", SYS);
}

void init_mem(sys_info_t *SYS)
{
    FILE *file = fopen("/proc/meminfo", "r");
    double total;
    double free;
    double available;

    if (fscanf(file, "MemTotal: %lf kB\nMemFree: %lf kB\nMemAvailable: %lf kB"
        , &total, &free, &available) == 3) {
        SYS->memory.total = total / 1024;
        SYS->memory.free = free / 1024;
        SYS->memory.available = available / 1024;
        SYS->memory.used = SYS->memory.total - SYS->memory.available;
    }
    fclose(file);
}

int init_swap_total(sys_info_t *SYS)
{
    FILE *file = fopen("/proc/meminfo", "r");
    double swaptotal;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "SwapTotal: %lf kB", &swaptotal) == 1) {
            SYS->memory.swap_total = swaptotal / 1024.0;
            return 0;
        }
    }
    fclose(file);
    return 0;
}

int init_swap_free(sys_info_t *SYS)
{
    FILE *file = fopen("/proc/meminfo", "r");
    double swapfree;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "SwapFree: %lf kB", &swapfree) == 1) {
            SYS->memory.swap_free = swapfree / 1024.0;
            return 0;
        }
    }
    fclose(file);
    return 0;
}

int init_swap_cached(sys_info_t *SYS)
{
    FILE *file = fopen("/proc/meminfo", "r");
    double swapused;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "SwapCached: %lf kB", &swapused) == 1) {
            SYS->memory.swap_used = swapused / 1024.0;
            return 0;
        }
    }
    fclose(file);
    return 0;
}
