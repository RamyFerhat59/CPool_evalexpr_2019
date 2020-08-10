/*
** EPITECH PROJECT, 2019
** my_isalnum.c
** File description:
** my_isalnul$
*/

int my_isalnum(char c)
{
    return (c > 47 && c < 58) ||
        (c > 64 && c < 91) ||
        (c > 96 && c < 123);
}
