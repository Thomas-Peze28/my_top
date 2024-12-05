/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** bootstrap my_top
*/
#include "my.h"

int get_uid(char *filepath)
{
    char *str = fs_return_full_open_file(filepath);
    char **arr = my_str_to_word_array02(str, '\n');
    char **arr2 = my_str_to_word_array02(arr[8], '\t');
    int uid;

    uid = atoi(arr2[1]);
    return uid;
}

int read_user(void)
{
    DIR *dir;
    struct dirent *info_dir;
    struct passwd *pwd;
    int line = 7;

    dir = opendir("/proc/");
    if (dir == NULL)
        return 84;
    info_dir = readdir(dir);
    while (info_dir) {
        if (info_dir->d_name[0] != '.' && my_char_isnum(info_dir->d_name[0])) {
            pwd = getpwuid(get_uid(buildpath_status(info_dir->d_name)));
            mvprintw(line, 8, "%-7s\n", pwd->pw_name);
            line++;
        }
        info_dir = readdir(dir);
    }
    closedir(dir);
    return 0;
}
