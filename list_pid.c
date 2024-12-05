/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** bootstrap my_top
*/
#include "my.h"

int read_pid(void)
{
    DIR *dir;
    struct dirent *info_dir;
    int line = 7;

    dir = opendir("/proc/");
    if (dir == NULL)
        return 84;
    info_dir = readdir(dir);
    while (info_dir) {
        if (info_dir->d_name[0] != '.' && my_char_isnum(info_dir->d_name[0])) {
            mvprintw(line, 0, "%7s", info_dir->d_name);
            line++;
        }
        info_dir = readdir(dir);
    }
    closedir(dir);
    return 0;
}
