/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:33:37 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/18 11:20:50 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	ft_fdf(char *argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	readfile(argv, data);
	// data->z_max = 15;
	// data->z_min = 0;
	// data->color1 = get_default_color(0, data);
	// printf("Color1: %08X\n", data->color1);
	// data->color2 = get_default_color(15, data);
	// printf("Color2: %08X\n", data->color2);
	// data->x1 = 5;
	// data->x2 = 8;
	// data->y1 = 2;
	// data->y2 = 5;
	// int printed_c = get_color(5, 4, data);
	// printf("Printed color: %08X\n", printed_c);
	initialize_mlx(data);
	initialize(data);
	ft_draw(data);
	mlx_hook(data->win_ptr, KEY_PRESS, 0, deal_key, data);
	mlx_hook(data->win_ptr, WINDOW_CLOSE, 0, close_win, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Wrong arguments\n", 2);
		return (1);
	}
	ft_fdf(argv[1]);
	return (0);
}

