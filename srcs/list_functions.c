//
// Created by Fernan MORALES on 10/9/16.
//

#include "../includes/ft_ls.h"

void        ft_list_swap(t_dir **tmp, t_dir **tmp_next)
{
    void    *buf;
    int     swap;

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
                ft_list_swap(&tmp, &tmp_next);
            tmp = tmp->next;
        }
        tmp = head;
//        ft_putstr(tmp_next->name);
        tmp_next = tmp_next->next;
    }
//    ft_putstr(" last ");
//    ft_putendl(tmp->next->name);
    return tmp ;
}