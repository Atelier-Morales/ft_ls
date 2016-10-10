//
// Created by Fernan MORALES on 10/9/16.
//

#include "../includes/ft_ls.h"

void ft_list_swap(t_dir **tmp, t_dir **tmp_next)
{
    void *buf;

    buf = (*tmp)->name;
    (*tmp)->name = (*tmp_next)->name;
    (*tmp_next)->name = buf;
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