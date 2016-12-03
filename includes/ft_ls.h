

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <locale.h>
# include <langinfo.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>


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
    char            *gr_name;
    char            *perms;
    int             st_size;
    int             blocks;
    char            *time;
    long long       st_mtimespec;
    long            tv_nsec;
    char            *timestamp;
    char            *linkname;
    struct s_dir    *next;
}                   t_dir;

void                display_dir_entries(char *dir, char options[6]);
int                 sanitize_standard_input(char **av, int ac, char options[6]);
int                 check_errors(char option[5], char **av);
t_dir               *set_dir(char *dir, t_dir *dr, char options[6], struct stat st);
void                ft_arr_sort(void *arr_, int (*fn)(void *a, void *b, int rev), char options[6]);
int                 sort_strcmp(void *s1_, void *s2_, int reverse);
void                ft_arr_swap(void *arr_, int i, int j);
void                iterative_display_mode(char **dirs, char options[6]);
void                recursive_display_mode(char **dirs, char options[6]);
t_dir               *sort_list(t_dir *head, int rev);
t_dir               *sort_list_time(t_dir *head, int rev);
void                ft_list_swap(t_dir **tmp, t_dir **tmp_next);
char        		*lower_str(char *s);
int                 sort_time(t_dir *tmp_next, t_dir *tmp, int reverse);
int                 sort_dir_time(void *s1_, void *s2_, int reverse);
void                set_sorting_rules(t_dir **directory, char options[6]);
char                *get_timestamp(char *dir);
char                *get_nano_seconds(long int tv_nsec);
int                 check_dir(char *dir);
void                display_dir_errors(char **dirs);
void                display_dir_osx(t_dir *dir, char opt[6], int len, int max_links);
t_dir               *rec_entries(char *dir, char options[6]);
char                **get_dirs(t_dir *dir, char *root);
int                 display_total_blocks(t_dir *buf, char options[6]);
int                 get_links_len(t_dir *buf, char options[6]);
char                *set_dir_perms(struct stat st);
char                *set_pw_name(struct stat st);
char                *set_time(struct stat st);
char                *set_gr_name(struct stat st);

#endif
