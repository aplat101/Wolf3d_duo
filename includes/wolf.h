/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplat <aplt@student.le-101.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:52:58 by widrye            #+#    #+#             */
/*   Updated: 2020/02/18 14:25:33 by aplat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx_macos/mlx.h"
# include "wolf_struct.h"
# include "wolf_define.h"
# include "x.h"

# include <pthread.h>
# include <fcntl.h>
# include <math.h>

/*
 ** Initialization **
*/
int			init(t_data *data, char *argv, int fd);
void		init_struct_values(t_data *data);
int			init_struct(t_data *data);
int			init_str_textures_a(t_texture *txt);
int			init_str_textures_b(t_texture *txt);
int			load_xpm(t_texture *texture, void *mlx_ptr);

/*
 ** Parsing and Check **
*/
int			stock_points(t_world *world, char **tab);
int			check_ext(char *argv);
int			check_tab(char **tab);
int			**create_basic_map(void);
void		secure_map(t_world *world, char **tab);
/*
 ** Render **
*/
t_data		*thread_manager(t_data *datatorender);
t_data		*render(t_data *data);
void		draw_floor(t_data *data);
int			get_gradient_color(int range, int n, int start, int end);
void		texture_wall(t_data *data);
void		texellit(t_data *data, int64_t y, int64_t x);
void		apply_end_screen(t_data *data);
void		apply_sky(t_data *data);
void		shade_area(t_data *data, int x, int y);
void		draw_menu(t_data *data);
/*
 ** Events **
*/

void		move_front(t_data *data);
void		rotate(t_data *data);
int			texture_clicks(t_data *data, int x, int y);
int			menu_clicks(t_data *data, int x, int y);
int			options_clicks(t_data *data, int x, int y);
int			check_mouse_events(t_data *data);
int			mouse_pressed(int keycode, int x, int y, t_data *data);
int			mouse_released(int keycode, int x, int y, t_data *data);
void		options_buttons(t_data *data);
int			check_events(t_data *data);
int			quit_and_close_window(t_data *data);
int			mouse_pos(int x, int y, t_data *data);
int			key_pressed(int keycode, t_data *data);
int			key_released(int keycode, t_data *data);

#endif
