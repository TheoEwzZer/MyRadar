/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** Displays the number given as a parameter.
*/

#include <unistd.h>
int my_putchar(char c);

int my_putchar_error(char c)
{
    write(2, &c, 1);
    return 1;
}

int my_put_nbr_error(long nbr, int count)
{
    if (nbr < 0) {
        count += my_putchar_error('-');
        count = my_put_nbr_error(-nbr, count);
    } else {
        int reste = nbr % 10;
        int quotient = nbr / 10;
        if (quotient != 0) {
            count = my_put_nbr_error(quotient, count);
        }
        count += my_putchar_error(reste + 48);
    }
    return count;
}

int my_put_nbr(long nbr, int count)
{
    if (nbr < 0) {
        count += my_putchar('-');
        count = my_put_nbr(-nbr, count);
    } else {
        int reste = nbr % 10;
        int quotient = nbr / 10;
        if (quotient != 0) {
            count = my_put_nbr(quotient, count);
        }
        count += my_putchar(reste + 48);
    }
    return count;
}

int my_put_nbr_count(long nbr, int count)
{
    if (nbr < 0) {
        count++;
        count = my_put_nbr_count(-nbr, count);
    } else {
        int quotient = nbr / 10;
        if (quotient != 0) {
            count = my_put_nbr_count(quotient, count);
        }
        count++;
    }
    return count;
}
