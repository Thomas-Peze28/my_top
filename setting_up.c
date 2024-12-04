/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** bootstrap setting_up
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"

int fs_open_file(char const *filepath)
{
    int fd;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        printf("FAILURE\n");
    } else {
        printf("SUCESS\n");
    }
    return fd;
}

char *fs_return_open_file(char const *filepath)
{
    int fd;
    int size = 29;
    char buffer[30];
    char *dest = malloc(30);

    fd = open(filepath, O_RDONLY);
    read(fd, buffer, size);
    my_strcpy(dest, buffer);
    close(fd);
    return dest;
}

char *fs_return_full_open_file(char const *filepath)
{
    int fd;
    int size = fs_return_file_size(filepath) - 1;
    char buffer[fs_return_file_size(filepath)];
    char *dest = malloc(fs_return_file_size(filepath));

    fd = open(filepath, O_RDONLY);
    read(fd, buffer, size);
    my_strcpy(dest, buffer);
    close(fd);
    return dest;
}

int fs_return_file_size(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[1];
    int file_size = 0;

    while (read(fd, buffer, 1) > 0) {
        file_size++;
    }
    close(fd);
    return file_size;
}
