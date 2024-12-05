/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** bootstrap my_top
*/
#include "my.h"

int count_tasks(char *path)
{
    DIR *dir;
    struct dirent *info_dir;
    int count = 0;

    dir = opendir(path);
    if (dir == NULL)
        return 84;
    info_dir = readdir(dir);
    while (info_dir) {
        if (info_dir->d_name[0] <= '9' && info_dir->d_name[0] >= '0') {
            count++;
        }
        info_dir = readdir(dir);
    }
    closedir(dir);
    return count;
}

void my_get_users_number(sys_info_t *SYS)
{
    struct utmp entry;
    int count = 0;
    FILE *file = fopen("/var/run/utmp", "r");

    if (file == NULL) {
        return;
    }
    while (fread(&entry, sizeof(entry), 1, file)) {
        if (entry.ut_type == USER_PROCESS) {
            count++;
        }
    }
    fclose(file);
    SYS->user_count = count;
}
