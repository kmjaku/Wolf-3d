/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 02:04:11 by kmjaku            #+#    #+#             */
/*   Updated: 2017/05/26 02:54:44 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void		err_exit(char *str, t_data data)
{
	(void)data.mlx;
	ft_putendl(str);
	exit(1);
}

void		usage(void)
{
	ft_putendl("usage : ./wolf3d [name]");
	ft_putendl("\nname :");
	ft_putendl("1. untextured or 1");
	ft_putendl("2. textured or 2");
	ft_putendl("\nMOVE :");
	ft_putendl("1. Right      D");
	ft_putendl("2. Left       A");
	ft_putendl("3. Forward    W");
	ft_putendl("4. Backward   S");
	exit(1);
}
