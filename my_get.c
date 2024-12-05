/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** bootstrap my_top
*/
#include "my.h"

char **my_getloaddavg(void)
{
    char *str = fs_return_open_file("/proc/loadavg");
    char **arr = my_str_to_word_array02(str, ' ');

    return arr;
}

char **my_getmemusage(void)
{
    char *str = fs_return_full_open_file("/proc/meminfo");
    char **arr = my_str_to_word_array02(str, ' ');

    return arr;
}

char **my_gettime(void)
{
    char *str = fs_return_full_open_file("/proc/driver/rtc");
    char **arr = my_str_to_word_array02(str, '\n');
    char **arr2 = my_str_to_word_array02(arr[0], ' ');

    return arr2;
}
