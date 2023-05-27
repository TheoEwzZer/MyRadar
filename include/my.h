/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my
*/

#ifndef MY_H_

    #define MY_H_

    #include <stdarg.h>

char **my_str_to_word_array(char const *str);
char *increment_str1(int count, char *str_tmp);
char *increment_str2(int count, char *str_tmp, int *j);
char *my_revstr(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
int check_isalpha(int i, char *str);
int int_at(int index, char *tab);
int middle(char *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_compute_square_root2(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_is_prime2(int nb);
int my_isneg(int nb);
int my_put_nbr(long nb, int count);
int my_put_nbr_error(long nbr, int count);
int my_putchar(char c);
int my_putchar_error(char c);
int my_putnbr_base(unsigned int nbr, char *base, int count);
int my_putstr(char const *str);
int my_showmem(char const *str, int size);
int my_showstr(char *str);
int my_str_isalpha(char const *str);
int my_str_isalphanum(char c);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strcmp(char const *s1, char const *s2);
unsigned int my_strlen(char const *str);
unsigned int my_strlen_double(char *const *str);
int my_strncmp(char const *s1, char const *s2, int n);
int my_swapstr(char *a, char *b);
int str_to_int(char *tab, int len, int negative);
long power10(int len);
void check_separator_lower(int i, char *str);
void check_separator_upper(int i, char *str);
void hexa(int i, char *str);
void my_sort_int_array(int *tab, int size);
void my_swap(int *a, int *b);
void my_swap_char(char **a, char **b);

#endif /* MY_H_ */
