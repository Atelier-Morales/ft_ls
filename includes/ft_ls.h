

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>

typedef struct		s_node
{
	int             key;
    struct          node *left;
    struct          node *right;
}					t_node;

void                display_dir_entries(char *dir);
int                 sanitize_standard_input(char **av);
int                 check_errors(char option[5], char *av);
char                **set_directory_structure(char *dir);
void                ft_arr_sort(void *arr_, int (*cmp_fn)(void *a, void *b, int rev), int reverse);
int                 sort_strcmp(void *s1_, void *s2_, int reverse);
void                ft_arr_swap(void *arr_, int i, int j);
void                iterative_display_mode(char **dirs, char options[6]);

#endif
