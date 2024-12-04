/*
** EPITECH PROJECT, 2024
** my_show_word_array
** File description:
** Display content of an array of words
*/

#include "my.h"

int my_show_word_array(char *const *tab)
{
    int word = 0;

    while (tab[word] != 0) {
        my_putstr(tab[word]);
        my_putchar('\n');
        word++;
    }
    return 0;
}
