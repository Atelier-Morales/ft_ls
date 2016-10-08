//
// Created by Fernan MORALES on 10/8/16.
//

#include "../includes/ft_ls.h"

void ft_arr_swap(void *arr_, int i, int j)
{
    void **arr = arr_;
    void *tmp;

    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int sort_strcmp(void *s1_, void *s2_, int reverse)
{
    char *s1 = s1_;
    char *s2 = s2_;
    if (reverse == 1)
        return (ft_strcmp(s1, s2) < 0);
    return (ft_strcmp(s1, s2) > 0);
}

void ft_arr_sort(void *arr_, int (*cmp_fn)(void *a, void *b, int rev), int reverse)
{
    void **arr = arr_;
    int i;
    int j;
    int len = ft_tabcount((char **)arr);

    i = 0;
    while (i < len - 1)
    {
        j = 0;
        while ( j < len - i - 1)
        {
            if (cmp_fn(arr[j], arr[j + 1], reverse))
                ft_arr_swap(arr, j, j + 1);
            j++;
        }
        i++;
    }
}