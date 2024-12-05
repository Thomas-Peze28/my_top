/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** bootstrap my_top
*/
#include "my.h"

char get_status(char *filepath)
{
    char *str = fs_return_full_open_file(filepath);
    char **arr = my_str_to_word_array02(str, '\n');
    char **arr2 = my_str_to_word_array02(arr[2], '\t');

    return arr2[1][0];
}

char *buildpath_status(char *pid)
{
    char *buffer = malloc(strlen("/proc/") + strlen(pid) + 1);
    char *buffer2;
    char *filepath;

    strcpy(buffer, "/proc/");
    filepath = strcat(buffer, pid);
    buffer2 = malloc(strlen(filepath) + strlen("/status") + 1);
    strcpy(buffer2, "/status");
    filepath = strcat(filepath, buffer2);
    return filepath;
}

void count_tasks_status(sys_info_t *SYS, char *filepath)
{
    char status = get_status(filepath);

    if (status == 'R')
        SYS->tasks.running++;
    if (status == 'S' || status == 'I')
        SYS->tasks.sleeping++;
    if (status == 'Z')
        SYS->tasks.zombie++;
    if (status == 'T')
        SYS->tasks.stopped++;
    SYS->tasks.total++;
}

int read_dir_tasks(char *path, sys_info_t *SYS)
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
            count_tasks_status(SYS, buildpath_status(pid));
        }
        info_dir = readdir(dir);
    }
    closedir(dir);
    return 0;
}
