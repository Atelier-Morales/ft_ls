//
// Created by Fernan MORALES on 10/9/16.
//

#include "../includes/ft_ls.h"
#include <stdlib.h>

static void ft_list_swap_bis(t_dir **tmp, t_dir **tmp_next)
{
    void    *buf;
    int     swap;
    long    nano_sec;

    buf = (*tmp)->pw_name;
    (*tmp)->pw_name = (*tmp_next)->pw_name;
    (*tmp_next)->pw_name = buf;
    buf = (*tmp)->gr_name;
    (*tmp)->gr_name = (*tmp_next)->gr_name;
    (*tmp_next)->gr_name = buf;
    swap = (*tmp)->st_size;
    (*tmp)->st_size = (*tmp_next)->st_size;
    (*tmp_next)->st_size = swap;
    buf = (*tmp)->time;
    (*tmp)->time = (*tmp_next)->time;
    (*tmp_next)->time = buf;
    swap = (*tmp)->blocks;
    (*tmp)->blocks = (*tmp_next)->blocks;
    (*tmp_next)->blocks = swap;
    nano_sec = (*tmp)->tv_nsec;
    (*tmp)->tv_nsec = (*tmp_next)->tv_nsec;
    (*tmp_next)->tv_nsec = nano_sec;
    buf = (*tmp)->linkname;
    (*tmp)->linkname = (*tmp_next)->linkname;
    (*tmp_next)->linkname = buf;
}

void            ft_list_swap(t_dir **tmp, t_dir **tmp_next)
{
    void        *buf;
    int         swap;
    long long   time;

    buf = (*tmp)->name;
    (*tmp)->name = (*tmp_next)->name;
    (*tmp_next)->name = buf;
    swap = (*tmp)->st_mode;
    (*tmp)->st_mode = (*tmp_next)->st_mode;
    (*tmp_next)->st_mode = swap;
    buf = (*tmp)->perms;
    (*tmp)->perms = (*tmp_next)->perms;
    (*tmp_next)->perms = buf;
    swap = (*tmp)->st_nlink;
    (*tmp)->st_nlink = (*tmp_next)->st_nlink;
    (*tmp_next)->st_nlink = swap;
    time = (*tmp)->st_mtimespec;
    (*tmp)->st_mtimespec = (*tmp_next)->st_mtimespec;
    (*tmp_next)->st_mtimespec = time;
    buf = (*tmp)->timestamp;
    (*tmp)->timestamp = (*tmp_next)->timestamp;
    (*tmp_next)->timestamp = buf;
}

t_dir       *sort_list(t_dir *head, int rev)
{
    t_dir   *tmp;
    t_dir   *tmp_next;

    tmp = head;
    tmp_next = head->next;
    while (tmp_next->next != NULL)
    {
        while (tmp_next != tmp)
        {
            if (sort_strcmp(tmp_next->name, tmp->name, rev))
            {
                ft_list_swap(&tmp, &tmp_next);
                ft_list_swap_bis(&tmp, &tmp_next);
            }
            tmp = tmp->next;
        }
        tmp = head;
        tmp_next = tmp_next->next;
    }
    return tmp ;
}

t_dir       *sort_list_time(t_dir *head, int rev)
{
    t_dir   *tmp;
    t_dir   *tmp_next;

    tmp = head;
    tmp_next = head->next;
    while (tmp_next->next != NULL)
    {
        while (tmp_next != tmp)
        {
            if (sort_time(tmp_next, tmp, rev))
            {
                ft_list_swap(&tmp, &tmp_next);
                ft_list_swap_bis(&tmp, &tmp_next);
            }
            tmp = tmp->next;
        }
        tmp = head;
        tmp_next = tmp_next->next;
    }
    return tmp ;
}