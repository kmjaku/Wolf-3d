/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 00:46:53 by kmjaku            #+#    #+#             */
/*   Updated: 2017/05/26 02:55:09 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void		chosem_map(t_data *data, char *str)
{
	if (ft_strcmp(str, "untextured") == 0 || ft_strcmp(str, "1") == 0)
	{
		init_1(data);
		set_image_untextured(data);
		data->val = 1;
	}
	else if (ft_strcmp(str, "textured") == 0 || ft_strcmp(str, "2") == 0)
	{
		init_2(data);
		set_texture(data);
		data->val = 2;
	}
}

int			main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		usage();
	if (!(ft_strcmp("untextured", argv[1]) == 0 ||
				ft_strcmp("textured", argv[1]) == 0 ||
			ft_strcmp(argv[1], "1") == 0 || ft_strcmp(argv[1], "2") == 0))
		err_exit("Wrong Name, Launch Program Without Argument To See Usage",
				data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "wolf3d");
	chosem_map(&data, argv[1]);
	after_val(&data);
	mlx_hook(data.win, 17, 18, exit_program, &data);
	mlx_hook(data.win, 2, 3, key_hook, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img);
	return (0);
}
