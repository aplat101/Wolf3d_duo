/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplat <aplt@student.le-101.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:20:52 by aplat             #+#    #+#             */
/*   Updated: 2020/02/18 14:20:53 by aplat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int				check_ext(char *argv)
{
	size_t		i;
	int			j;
	char		*str;

	str = "pam.";
	i = ft_strlen(argv);
	if (i < 5)
		return (-1);
	i -= 1;
	j = 0;
	while (i >= ft_strlen(argv) - 3)
	{
		if (argv[i] != str[j])
			return (-1);
		i--;
		j++;
	}
	return (0);
}

int				**create_basic_map(void)
{
	int		i;
	int		j;
	int		**map;

	i = 0;
	j = 0;
	map = init_tab_2d_int(6, 6);
	while (i <= 5)
	{
		while (j <= 5)
		{
			if (i == 0 || i == 5 || j == 0 || j == 5)
				map[i][j] = 1;
			else
				map[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

void			secure_map(t_world *world, char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (i < world->line_nb)
	{
		j = 0;
		while (j < world->row_nb)
		{
			world->map[0][j] = 5;
			world->map[world->line_nb - 1][j] = 5;
			world->map[i][world->row_nb - 1] = 5;
			world->map[i][0] = 5;
			if (i != 0 && i != world->line_nb - 1)
			{
				if (j >= ft_count_col(tab[i - 1]) + 1)
					world->map[i][j] = 5;
			}
			j++;
		}
		i++;
	}
}

int				stock_points(t_world *world, char **tab)
{
	int				i[4];
	int				minimal_space;

	i[1] = 0;
	i[3] = 1;
	minimal_space = 0;
	while (i[3] <= ft_line_nb(tab))
	{
		i[0] = 0;
		i[2] = 1;
		while (i[2] <= ft_count_col(tab[i[1]]))
		{
			if (tab[i[1]][i[0]] == ' '
			&& tab[i[1]][i[0]] != '\0')
				i[0] += 1;
			world->map[i[3]][i[2]] = ft_atoi(&tab[i[1]][i[0]]);
			if (world->map[i[3]][i[2]] == 0)
				minimal_space++;
			i[0] += 1;
			i[2] += 1;
		}
		i[1] += 1;
		i[3] += 1;
	}
	return (minimal_space > 5 ? 1 : 0);
}

int				check_tab(char **tab)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]) == 1 || tab[i][j] == ' ')
				j++;
			else
				return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}
