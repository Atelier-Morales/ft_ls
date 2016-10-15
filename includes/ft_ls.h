

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>

#define OS_MODE 1

typedef struct		s_node
{
	int             key;
    struct          node *left;
    struct          node *right;
}					t_node;

typedef struct      s_dir {
    char            *name;
    int             st_mode;
    int             st_nlink;
    char            *pw_name;
    char            *perms;
    struct s_dir    *next;
}                   t_dir;

void                display_dir_entries(char *dir, char options[6]);
int                 sanitize_standard_input(char **av, int ac, char options[6]);
int                 check_errors(char option[5], char **av);
t_dir               *set_directory_structure(char *dir, t_dir *directory, char options[6]);
void                ft_arr_sort(void *arr_, int (*cmp_fn)(void *a, void *b, int rev), int reverse);
int                 sort_strcmp(void *s1_, void *s2_, int reverse);
void                ft_arr_swap(void *arr_, int i, int j);
void                iterative_display_mode(char **dirs, char options[6]);
t_dir               *sort_list(t_dir *head, int rev);
void                ft_list_swap(t_dir **tmp, t_dir **tmp_next);
char        		*lower_str(char *s);

#endif
