/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** bootstrap my_top
*/
#include "my.h"

void get_state_info(char *pid, char *state, char *command)
{
    char *filepath = buildpath_status(pid);
    FILE *file = fopen(filepath, "r");
    char line[256];

    if (file == NULL) {
        free(filepath);
        return;
    }
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "State:", 6) == 0)
            sscanf(line, "State: %c", state);
        if (strncmp(line, "Name:", 5) == 0)
            sscanf(line, "Name: %s", command);
    }
    fclose(file);
    free(filepath);
}

void get_memory_info(char *pid, int *virt, int *res, int *shr)
{
    char *filepath = buildpath_status(pid);
    FILE *file = fopen(filepath, "r");
    char line[256];

    if (file == NULL) {
        free(filepath);
        return;
    }
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "VmSize:", 7) == 0)
            sscanf(line, "VmSize: %d kB", virt);
        if (strncmp(line, "VmRSS:", 6) == 0)
            sscanf(line, "VmRSS: %d kB", res);
        if (strncmp(line, "RssFile:", 8) == 0)
            sscanf(line, "RssFile: %d kB", shr);
    }
    fclose(file);
    free(filepath);
}

void display_virt(char *pid, int line, sys_info_t SYS)
{
    int virt = 0;
    int res = 0;
    int shr = 0;
    char state;
    char command[256];

    get_memory_info(pid, &virt, &res, &shr);
    get_state_info(pid, &state, command);
    mvprintw(line, 24, "%8d", virt);
    mvprintw(line, 33, "%8d", res);
    mvprintw(line, 42, "%8d", shr);
    mvprintw(line, 51, "%c", state);
    mvprintw(line, 53, "%4.1f", ((float)res / (float)MEM.total / 1024) * 100);
    mvprintw(line, 58, "%s", command);
}

int read_virt(sys_info_t SYS)
{
    DIR *dir;
    struct dirent *info_dir;
    int line = 7;
    char *pid;

    dir = opendir("/proc/");
    if (dir == NULL)
        return 84;
    info_dir = readdir(dir);
    while (info_dir) {
        if (info_dir->d_name[0] != '.' && my_char_isnum(info_dir->d_name[0])) {
            pid = info_dir->d_name;
            display_virt(pid, line, SYS);
            line++;
        }
        info_dir = readdir(dir);
    }
    closedir(dir);
    return 0;
}
