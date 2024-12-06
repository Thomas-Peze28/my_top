/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** bootstrap my_top
*/
#include "my.h"

void my_getloaddavg(sys_info_t *SYS)
{
    FILE *file = fopen("/proc/loadavg", "r");
    double one;
    double two;
    double three;

    if (fscanf(file, "%lf %lf %lf", &one, &two, &three) == 3) {
        SYS->loadavg1 = one;
        SYS->loadavg2 = two;
        SYS->loadavg3 = three;
    }
    fclose(file);
}

void my_gettime(void)
{
    char hours[3];
    char minutes[3];
    char seconds[3];
    FILE *file = fopen("/proc/driver/rtc", "r");

    if (fscanf(file, "rtc_time : %2s:%2s:%2s\n"
        , hours, minutes, seconds) == 3) {
        mvprintw(0, 6, "%s:%s:%s,", hours, minutes, seconds);
    }
    fclose(file);
}
