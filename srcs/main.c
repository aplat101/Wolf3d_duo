/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplat <aplt@student.le-101.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:10:37 by ztrouill          #+#    #+#             */
/*   Updated: 2020/02/18 14:19:47 by aplat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int			quit_and_close_window(t_data *data)
{
	pthread_mutex_destroy(&data->lock);
	freedom((void **)data->map, ft_line_nb(data->map));
	freedom((void **)data->world.map, data->world.line_nb);
	mlx_destroy_image(data->mlx_ptr, data->image.image_ptr);
	mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	parsing(int argc, char *argv, t_data *data)
{
	if (argc != 2)
	{
		ft_putendl(PARAM);
		ft_putendl(USAGE);
		return (-1);
	}
	else
	{
		if (WIDTH < 800 || WIDTH > 1920 || HEIGHT < 600 || HEIGHT > 1080)
		{
			ft_putendl("Incorrect #define screen resolution values");
			if (data->map)
				freedom((void **)data->map, ft_line_nb(data->map));
			return (-1);
		}
		if ((check_ext(argv) == -1) ||
			(init(data, argv, open(argv, O_RDONLY)) == -1))
		{
			ft_putendl(USAGE);
			if (data->map)
				freedom((void **)data->map, ft_line_nb(data->map));
			return (-1);
		}
	}
	return (0);
}

t_data		*thread_manager(t_data *data)
{
	pthread_t	threads[THREAD_QNTY];
	t_data		thd_data[THREAD_QNTY];
	int			i;

	i = 0;
	while (i < THREAD_QNTY)
	{
		thd_data[i] = *data;
		thd_data[i].data_to_update = data;
		thd_data[i].thread_n = i;
		if (pthread_create(&threads[i], NULL, (void *)&render, &(thd_data[i])))
			return (0);
		i++;
	}
	while (--i >= 0)
		pthread_join(threads[i], NULL);
	return (data);
}

int			main(int argc, char **argv)
{
	t_data data;

	if ((parsing(argc, argv[1], &data) == -1))
		exit(EXIT_FAILURE);
	else
	{
		mlx_hook(data.window_ptr, 2, 0L, key_pressed, &data);
		mlx_hook(data.window_ptr, 3, 0L, key_released, &data);
		mlx_hook(data.window_ptr, 4, 0, mouse_pressed, &data);
		mlx_hook(data.window_ptr, 5, 0, mouse_released, &data);
		mlx_hook(data.window_ptr, 17, 0L, quit_and_close_window, &data);
		mlx_loop_hook(data.mlx_ptr, check_events, &data);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
