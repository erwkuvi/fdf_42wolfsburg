/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:33:37 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/14 12:26:45 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	noevent(void)
{
	return (0);
}

void	ft_fdf(char *argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	readfile(argv, data);
	// initialize_mlx(data);
	// initialize(data);
	// printf("Render BG\n");
	// render_background(&data->img, EBONY);

	// ft_draw(data);
	// // mlx_loop_hook(data->mlx_ptr, ft_draw, data);
	// // mlx_key_hook(data->win_ptr, deal_key, data);
	// // mlx_loop_hook(data->mlx_ptr, &close_win, data);
	// printf("MLX HOOK\n");
	// mlx_hook(data->win_ptr, KEY_PRESS, 0, &deal_key, data);
	// mlx_hook(data->win_ptr, WINDOW_CLOSE, 0, &close_win, data);
	// printf("after MLX_HOOK\n");
	// // mlx_hook(data->win_ptr, 4, 0, &mouse_press, data);
	// //int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
	// mlx_loop(data->mlx_ptr);
	// printf("AFTERLOOP_________");
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Correct argument is needed\n", 2);
		return (1);
	}
	ft_fdf(argv[1]);
	printf("atoi_base = %d\n", hextoint("FF0000"));
	printf("atoi_base = %d\n", atoi_base("FF0000", HEXADEC));
	return (0);
}
