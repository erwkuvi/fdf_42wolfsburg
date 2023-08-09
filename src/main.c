/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:33:37 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/09 13:53:00 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"


void	ft_fdf(char *argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	readfile(argv, data);
	initialize_mlx(data);
	initialize(data);
	render_background(&data->img, EBONY);
	ft_draw(data);
	// mlx_loop_hook(data->mlx_ptr, ft_draw, data);
	// mlx_key_hook(data->win_ptr, deal_key, data);

	mlx_hook(data->win_ptr, KEY_PRESS, 0, &deal_key, data);
	mlx_hook(data->win_ptr, WINDOW_CLOSE, (1L << 17), &close_win, data);
	// mlx_hook(data->win_ptr, 4, 0, &mouse_press, data);
	//int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Correct argument is needed\n", 2);
		return (1);
	}
	ft_fdf(argv[1]);
}
