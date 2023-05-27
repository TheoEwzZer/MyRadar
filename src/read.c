/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** read
*/

#include "my_radar.h"

void sort_aircraft(var_t *var, int left, int right)
{
    int i = left;
    int j = right;
    aircraft_t *pivot = A[(left + right) / 2];
    while (i <= j) {
        while (A[i]->scale < pivot->scale)
            i++;
        while (A[j]->scale > pivot->scale)
            j--;
        if (i <= j) {
            aircraft_t *tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j)
        sort_aircraft(var, left, j);
    if (i < right)
        sort_aircraft(var, i, right);
}

int number_of_entities(char *script, char type)
{
    FILE *fp = fopen(script, "r");
    size_t len = 0;
    char *line = NULL;
    int nb = 0;

    if (!fp)
        return -1;
    while (getline(&line, &len, fp) != -1) {
        if (line[0] == type)
            nb++;
    }
    if (line) {
        free(line);
        line = NULL;
    }
    fclose(fp);
    return nb;
}

sfUint32 analyse_line(var_t *var, char *script)
{
    FILE *fp = fopen(script, "r");
    size_t len = 0;
    char *line = NULL;

    if (!fp)
        return 84;
    while (getline(&line, &len, fp) != -1) {
        if (init_line(var, line) == 84)
            return 84;
    }
    if (line) {
        free(line);
        line = NULL;
    }
    fclose(fp);
    sort_aircraft(var, 0, var->aircraft_nb - 1);
    return 0;
}
