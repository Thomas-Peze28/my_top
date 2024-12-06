/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** bootstrap my_top
*/
#include "my.h"

char **my_getcpuusage(void)
{
    char *str = fs_return_full_open_file("/proc/stat");
    char **arr = my_str_to_word_array02(str, '\n');
    char **arr2 = my_str_to_word_array02(arr[0], ' ');

    free(str);
    free(arr);
    return arr2;
}

void apply_to_struct(sys_info_t *SYS, float *delta, float total)
{
    SYS->cpu.us = (delta[1] / total) * 100;
    SYS->cpu.ni = (delta[2] / total) * 100;
    SYS->cpu.sy = (delta[3] / total) * 100;
    SYS->cpu.id = (delta[4] / total) * 100;
    SYS->cpu.wa = (delta[5] / total) * 100;
    SYS->cpu.hi = (delta[6] / total) * 100;
    SYS->cpu.si = (delta[7] / total) * 100;
    SYS->cpu.st = (delta[8] / total) * 100;
}

void my_getcpupercent(sys_info_t *SYS)
{
    char **temp;
    char **info = my_getcpuusage();
    float *delta = malloc(sizeof(float) * 10);
    float total = 0;

    sleep(3);
    temp = my_getcpuusage();
    for (int i = 1; i < 9; i++) {
        delta[i] = atof(temp[i]) - atof(info[i]);
        total += delta[i];
    }
    apply_to_struct(SYS, delta, total);
    free(delta);
    free(info);
    free(temp);
}
