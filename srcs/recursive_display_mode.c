//
// Created by Fernan MORALES on 11/12/16.
//

#include "../includes/ft_ls.h"

void    recursive_display(char **dir, char options[6], int len)
{

	if (check_dir(*dir) != 0)
	{
		if (len > 1)
			ft_putendl(ft_strjoin(*dir, ":"));
		display_dir_entries(*dir, options);
		if (ft_tabcount(dir) > 1)
			ft_putchar('\n');
	}
	if (ft_tabcount(dir) >= 1)
		recursive_display(++dir, options, len);
}

void    recursive_display_mode(char **dirs, char options[6])
{
	int len;

	len = ft_tabcount(dirs);
	if (len > 0)
	{
		if (ft_strchr(options, 't') == NULL)
			ft_arr_sort(dirs, sort_strcmp, options);
		else
			ft_arr_sort(dirs, sort_dir_time, options);
		display_dir_errors(dirs);
//		while (i < ft_tabcount(dirs) && check_dir(dirs[i]) != 0)
//		{
//			if (ft_tabcount(dirs) > 1)
//				ft_putendl(ft_strjoin(dirs[i], ":"));
//			display_dir_entries(dirs[i], options);
//			if (i + 1 != ft_tabcount(dirs))
//				ft_putchar('\n');
//			i++;
//		}
		recursive_display(dirs, options, len);
	}
	else
		display_dir_entries(".", options);

	return ;
}
