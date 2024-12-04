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
    printf("%d\n", count);
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

void read_status(char *pid)
{
    char *buffer = malloc(strlen("/proc/") + strlen(pid) + 1);
    char *filepath;

    strcpy(buffer, "/proc/");
    filepath = strcat(buffer, pid);
    printf("%s\n", filepath);
}

int read_dir(char *path)
{
    DIR *dir;
    struct dirent *info_dir;
    char *pid;

    dir = opendir(path);
    if (dir == NULL)
        return 84;
    info_dir = readdir(dir);
    while (info_dir) {
        if (info_dir->d_name[0] != '.' && my_char_isnum(info_dir->d_name[0])) {
            pid = info_dir->d_name;
            read_status(pid);
        }
        info_dir = readdir(dir);
    }
    closedir(dir);
    return 0;
}
