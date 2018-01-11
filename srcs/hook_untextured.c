/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_untextured.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 06:02:56 by kmjaku            #+#    #+#             */
/*   Updated: 2017/05/18 21:17:55 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		key_hook_r_left_right(int key, t_data *data)
{
	if (key == R_RIGHT)
	{
		data->t_d = data->dir_x;
		data->dir_x = data->dir_x * cos(-data->rot) - data->dir_y *
			sin(-data->rot);
		data->dir_y = data->t_d * sin(-data->rot) + data->dir_y *
			cos(-data->rot);
		data->t_p = data->plane_x;
		data->plane_x = data->plane_x * cos(-data->rot) - data->plane_y *
			sin(-data->rot);
		data->plane_y = data->t_p * sin(-data->rot) + data->plane_y *
			cos(-data->rot);
	}
	else if (key == R_LEFT)
	{
		data->t_d = data->dir_x;
		data->dir_x = data->t_d * cos(data->rot) - data->dir_y * sin(data->rot);
		data->dir_y = data->t_d * sin(data->rot) + data->dir_y * cos(data->rot);
		data->t_p = data->plane_x;
		data->plane_x = data->t_p * cos(data->rot) - data->plane_y *
			sin(data->rot);
		data->plane_y = data->t_p * sin(data->rot) + data->plane_y *
			cos(data->rot);
	}
	return (0);
}

int		key_hook_left_right(int key, t_data *data)
{
	if (key == RIGHT)
	{
		if (map_untextured(data->pos_x + data->plane_x * data->speed,
					data->pos_y) == 0)
			data->pos_x += data->plane_x * data->speed;
		if ((map_untextured(data->pos_x, data->pos_y + data->plane_y
					* data->speed) == 0))
			data->pos_y += data->plane_y * data->speed;
	}
	else if (key == LEFT)
	{
		if (map_untextured(data->pos_x - data->plane_x * data->speed,
					data->pos_y) == 0)
			data->pos_x -= data->plane_x * data->speed;
		if (map_untextured(data->pos_x, data->pos_y - data->plane_y
					* data->speed) == 0)
			data->pos_y -= data->plane_y * data->speed;
	}
	return (0);
}

int		key_hook_stop_hit(int key, t_data *data)
{
	if (key == UP)
	{
		if (map_untextured(data->pos_x + data->dir_x * data->speed,
					data->pos_y) == 0)
			data->pos_x += data->dir_x * data->speed;
		if (map_untextured(data->pos_x,
					data->pos_y + data->dir_y * data->speed) == 0)
			data->pos_y += data->dir_y * data->speed;
	}
	else if (key == DOWN)
	{
		if (map_untextured(data->pos_x - data->dir_x * data->speed,
					data->pos_y) == 0)
			data->pos_x -= data->dir_x * data->speed;
		if (map_untextured(data->pos_x, data->pos_y - data->dir_y *
					data->speed) == 0)
			data->pos_y -= data->dir_y * data->speed;
	}
	return (0);
}
