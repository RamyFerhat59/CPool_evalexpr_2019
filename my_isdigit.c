/*
** EPITECH PROJECT, 2019
** my_isdigit.c
** File description:
** my_isdigit
*/

int my_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
