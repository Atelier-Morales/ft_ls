//
// Created by Fernan MORALES on 10/8/16.
//

#include "../includes/ft_ls.h"
#include <sys/types.h>
#include <sys/stat.h>

char        *lower_str(char *s)
{
    char    *buf;
    size_t     i;

    buf = ft_strdup(s);
    i = 0;
    while (i < ft_strlen(buf))
    {
        buf[i] = ft_tolower(s[i]);
        i++;
    }
    return buf;
}

void ft_arr_swap(void *arr_, int i, int j)
{
    void **arr = arr_;
    void *tmp;

    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int         sort_strcmp(void *s1_, void *s2_, int reverse)
{
    char    *s1;
    char    *s2;

    s1 = OS_MODE == 0 ? lower_str(s1_) : s1_;
    s2 = OS_MODE == 0 ? lower_str(s2_) : s2_;
    if (reverse == 1)
        return (ft_strcmp(s1, s2) < 0);
    return (ft_strcmp(s1, s2) > 0);
}

int         sort_time(t_dir *tmp_next, t_dir *tmp, int reverse)
{
    char    *s1;
    char    *s2;

    s1 = OS_MODE == 0 ? lower_str(tmp_next->name) : tmp_next->name;
    s2 = OS_MODE == 0 ? lower_str(tmp->name) : tmp->name;
    if (ft_strcmp(tmp_next->timestamp, tmp->timestamp) != 0)
    {
        if (reverse == 1)
            return (ft_strcmp(tmp_next->timestamp, tmp->timestamp) < 0);
        return (ft_strcmp(tmp_next->timestamp, tmp->timestamp) > 0);
    }
    if (reverse == 1)
        return (ft_strcmp(s1, s2) > 0);
    return (ft_strcmp(s1, s2) < 0);
}

char                *get_timestamp(char *dir)
{
    char            *timestamp;
    char            *sec;
    char            *n_sec;
    struct stat     st;

    if (stat(ft_strjoin("./", dir), &st) != 0)
        return (NULL);
    sec = ft_strjoin(ft_itoa(st.st_mtimespec.tv_sec), ".");
    n_sec = get_nano_seconds(st.st_mtimespec.tv_nsec);
    timestamp = ft_strjoin(sec, n_sec);
    return (timestamp);
}

int         sort_dir_time(void *s1_, void *s2_, int reverse)
{
    char    *s1;
    char    *s2;
    char    *t1;
    char    *t2;

    s1 = OS_MODE == 0 ? lower_str(s1_) : s1_;
    s2 = OS_MODE == 0 ? lower_str(s2_) : s2_;
    t1 = get_timestamp(s1_);
    t2 = get_timestamp(s2_);
    if (ft_strcmp(t1, t2) != 0)
    {
        if (reverse == 1)
            return (ft_strcmp(t1, t2) > 0);
        return (ft_strcmp(t1, t2) < 0);
    }
    if (reverse == 1)
        return (ft_strcmp(s1, s2) > 0);
    return (ft_strcmp(s1, s2) < 0);
}

void        ft_arr_sort(void *arr_, int (*cmp_fn)(void *a, void *b, int rev), char options[6])
{
    void **arr;
    int i;
    int j;
    int len;
    int reverse;

    i = 0;
    arr = arr_;
    len = ft_tabcount((char **)arr);
    reverse = ft_strchr(options, 'r') == NULL ? 0 : 1;
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