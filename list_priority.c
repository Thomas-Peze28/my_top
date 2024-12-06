/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** bootstrap my_top
*/
#include "my.h"

char *buildpath_stat(char *pid)
{
    size_t path_size = strlen("/proc/") + strlen(pid) + strlen("/stat") + 1;
    char *filepath = malloc(path_size);

    strcpy(filepath, "/proc/");
    strcat(filepath, pid);
    strcat(filepath, "/stat");
    return filepath;
}

int get_pr(char *filepath)
{
    char *str = fs_return_full_open_file(filepath);
    char **arr = my_str_to_word_array02(str, ' ');
    int pr = atoi(arr[17]);

    free(str);
    free(arr);
    return pr;
}

int get_ni(char *filepath)
{
    char *str = fs_return_full_open_file(filepath);
    char **arr = my_str_to_word_array02(str, ' ');
    int ni = atoi(arr[18]);

    free(str);
    free(arr);
    return ni;
}

void display_prio(char *pid, int line)
{
    char *filepath = buildpath_stat(pid);
    int pr = get_pr(filepath);
    int ni = get_ni(filepath);

    free(filepath);
    mvprintw(line, 16, "%3d", pr);
    mvprintw(line, 20, "%3d", ni);
}

int read_priority(void)
{
    DIR *dir;
    struct dirent *info_dir;
    int line = 7;

    dir = opendir("/proc/");
    if (dir == NULL)
        return 84;
    info_dir = readdir(dir);
    while (info_dir) {
        if (info_dir->d_name[0] != '.' && my_char_isnum(info_dir->d_name[0]
            && line < getmaxy(stdscr))) {
            display_prio(info_dir->d_name, line);
            line++;
        }
        info_dir = readdir(dir);
    }
    closedir(dir);
    return 0;
}
