/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** bootstrap my_top
*/
#include "my.h"

char get_tasktatus(char *filepath)
{
    FILE *file = fopen(filepath, "r");
    int status;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "State: %ls", &status) == 1) {
            return status;
        }
    }
    fclose(file);
    return 0;
}

char *buildpath_status(char *pid)
{
    size_t path_size = strlen("/proc/") + strlen(pid) + strlen("/status") + 1;
    char *filepath = malloc(path_size);

    strcpy(filepath, "/proc/");
    strcat(filepath, pid);
    strcat(filepath, "/status");
    return filepath;
}

void count_tasks_status(sys_info_t *SYS, char *filepath)
{
    char status = get_tasktatus(filepath);

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
