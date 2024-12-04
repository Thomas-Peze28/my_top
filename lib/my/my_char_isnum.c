/*
** EPITECH PROJECT, 2024
** my_char_isnum
** File description:
** Return if char is num char
*/

#include "my.h"

int my_char_isnum(char const letter)
{
    if (letter >= 48 && letter <= 57) {
        return 1;
    } else {
        return 0;
    }
}
