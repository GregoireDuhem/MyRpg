/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** split an str into word and put them in a word array
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int word_count(char const *str)
{
    int count = 0;
    int i = 0;

    while (str[i] && ((str[i] < 'a' || str[i] > 'z')
        && (str[i] < 'A' || str[i] > 'Z' )
        && (str[i] < '0' || str[i] > '9')))
        i++;
    while (str[i]) {
        while (str[i] && ((str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= 'A' && str[i] <= 'Z' )
            || (str[i] >= '0' && str[i] <= '9')))
            i++;
        count++;
        while (str[i] && ((str[i] < 'a' || str[i] > 'z')
            && (str[i] < 'A' || str[i] > 'Z' )
            && (str[i] < '0' || str[i] > '9')))
            i++;
    }
    return count;
}

int word_len(char const *str)
{
    static int i = 0;
    int len = 0;

    while (str[i] && ((str[i] < 'a' || str[i] > 'z')
        && (str[i] < 'A' || str[i] > 'Z' )
        && (str[i] < '0' || str[i] > '9')))
        i++;
    while (str[i] && ((str[i] >= 'a' && str[i] <= 'z')
        || (str[i] >= 'A' && str[i] <= 'Z' )
        || (str[i] >= '0' && str[i] <= '9'))) {
        i++;
        len++;
    }
    while (str[i] && ((str[i] < 'a' || str[i] > 'z')
        && (str[i] < 'A' || str[i] > 'Z' )
        && (str[i] < '0' || str[i] > '9')))
        i++;
    if (str[i] == '\0')
        i = 0;
    return len;
}

char **malloc_array(char const *str)
{
    char **array = malloc(sizeof(char *) * (word_count(str) + 1));

    if (!array)
        return NULL;
    for (int i = 0; i < word_count(str); i++) {
        array[i] = malloc(sizeof(char) * (word_len(str) + 1));
        if (!array[i])
            return NULL;
    }
    return array;
}

int check_conditions(char const *str, int i)
{
    if ((str[i] < 'a' || str[i] > 'z')
        && (str[i] < 'A' || str[i] > 'Z' )
        && (str[i] < '0' || str[i] > '9'))
        return 1;
    else
        return 0;
}

char **my_str_to_word_array(char const *str)
{
    char **array;
    int i = 0;
    int j = 0;
    int k = 0;

    if (!str)
        return NULL;
    if (!(array = malloc_array(str)))
        return NULL;
    while (j < word_count(str)) {
        while (check_conditions(str, i) == 1 && str[i])
            i++;
        while (check_conditions(str, i) == 0 && str[i])
            array[j][k++] = str[i++];
        array[j][k] = '\0';
        j++;
        k = 0;
    }
    array[word_count(str)] = NULL;
    return array;
}
