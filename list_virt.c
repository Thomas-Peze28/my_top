/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** bootstrap my_top
*/
#include "my.h"

int get_virt(char *filepath)
{
    char *str = fs_return_full_open_file(filepath);
    char **arr = my_str_to_word_array02(str, '\n');
    char **arr2 = my_str_to_word_array02(arr[18], '\t');
    int pr = atoi(arr2[1]);

    return pr;
}

void display_virt(char *pid, int line)
{
    int virt = get_virt(buildpath_status(pid));

    mvprintw(line, 27, "%3d\n", virt);
}

int read_virt(void)
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
            display_virt(pid, line);
            line++;
        }
        info_dir = readdir(dir);
    }
    closedir(dir);
    return 0;
}
