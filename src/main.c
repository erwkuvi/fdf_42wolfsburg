/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:33:37 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/08 21:42:27 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	cleanup(t_data *data)
{
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->img.img_ptr);
	// free(data->mlx_ptr);
	if (data->z_matrix)
		free_int_array(data->z_matrix);
	free(data);
	exit(0);
}

int	deal_key(int key, t_data *data)
{
	// printf("%d\n", key);
	// mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (key == UP)
		data->shift_y -= 10;
	if (key == DOWN)
		data->shift_y += 10;
	if (key == LEFT)
		data->shift_x -= 10;
	if (key == RIGHT)
		data->shift_x += 10;
	if (key == KY_ESC)
		return (cleanup(data));
	ft_draw(data);
	return (0);
}

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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	mlx_hook(data->win_ptr, WINDOW_CLOSE, 0, &cleanup, data);
	mlx_hook(data->win_ptr, 2, 0, &deal_key, data);
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
