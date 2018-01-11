/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_textured.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 01:53:41 by kmjaku            #+#    #+#             */
/*   Updated: 2017/05/22 22:28:20 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		key_hook_r_left_right_tex(int key, t_data *data)
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

int		key_hook_left_right_tex(int key, t_data *data)
{
	if (key == RIGHT)
	{
		if (map_textured(data->pos_x + data->plane_x * data->speed,
					data->pos_y) == 0)
			data->pos_x += data->plane_x * data->speed;
		if ((map_textured(data->pos_x, data->pos_y + data->plane_y
					* data->speed) == 0))
			data->pos_y += data->plane_y * data->speed;
	}
	if (key == LEFT)
	{
		if (map_textured(data->pos_x - data->plane_x * data->speed,
					data->pos_y) == 0)
			data->pos_x -= data->plane_x * data->speed;
		if (map_textured(data->pos_x, data->pos_y - data->plane_y
					* data->speed) == 0)
			data->pos_y -= data->plane_y * data->speed;
	}
	return (0);
}

int		key_hook_stop_hit_tex(int key, t_data *data)
{
	if (key == UP)
	{
		if (map_textured(data->pos_x + data->dir_x * data->speed,
					data->pos_y) == 0)
			data->pos_x += data->dir_x * data->speed;
		if (map_textured(data->pos_x,
					data->pos_y + data->dir_y * data->speed) == 0)
			data->pos_y += data->dir_y * data->speed;
	}
	else if (key == DOWN)
	{
		if (map_textured(data->pos_x - data->dir_x * data->speed,
					data->pos_y) == 0)
			data->pos_x -= data->dir_x * data->speed;
		if (map_textured(data->pos_x, data->pos_y - data->dir_y *
					data->speed) == 0)
			data->pos_y -= data->dir_y * data->speed;
	}
	return (0);
}
