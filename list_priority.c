/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** bootstrap my_top
*/
#include "my.h"

char *buildpath_stat(char *pid)
{
    char *buffer = malloc(strlen("/proc/") + strlen(pid) + 1);
    char *buffer2;
    char *filepath;

    strcpy(buffer, "/proc/");
    filepath = strcat(buffer, pid);
    buffer2 = malloc(strlen(filepath) + strlen("/stat") + 1);
    strcpy(buffer2, "/stat");
    filepath = strcat(filepath, buffer2);
    return filepath;
}

int get_pr(char *filepath)
{
    char *str = fs_return_full_open_file(filepath);
    char **arr = my_str_to_word_array02(str, ' ');
    int pr = atoi(arr[17]);

    return pr;
}

int get_ni(char *filepath)
{
    char *str = fs_return_full_open_file(filepath);
    char **arr = my_str_to_word_array02(str, ' ');
    int ni = atoi(arr[18]);

    return ni;
}

void display_prio(char *pid, int line)
{
    int pr;
    int ni;

    pr = get_pr(buildpath_stat(pid));
    ni = get_ni(buildpath_stat(pid));
    mvprintw(line, 16, "%3d\n", pr);
    mvprintw(line, 20, "%3d\n", ni);
}

int read_priority(void)
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
        if (info_dir->d_name[0] != '.' && my_char_isnum(info_dir->d_name[0]
            && line < getmaxy(stdscr))) {
            pid = info_dir->d_name;
            display_prio(pid, line);
            line++;
        }
        info_dir = readdir(dir);
    }
    closedir(dir);
    return 0;
}
