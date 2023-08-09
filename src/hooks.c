/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:38:30 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/09 18:23:35 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	close_win(t_data *data)
{
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->z_matrix)
		free_int_array(data->z_matrix);
	if (data->color_matrix)
		free_int_array(data->color_matrix);
	free(data);
	exit(0);
}

void deal_shift(int	key, t_data *data)
{
	if (key == UP)
		data->shift_y -= 10;
	else if (key == DOWN)
		data->shift_y += 10;
	else if (key == LEFT)
		data->shift_x -= 10;
	else if (key == RIGHT)
		data->shift_x += 10;
	ft_draw(data);
}

void	deal_zoom(int key, t_data *data)
{
	if (key == ZOOMIN)
		data->height_zoom += 0.3;
	if (key == ZOOMOUT)
		data->height_zoom -= 0.3;
	if (key == ARR_DOWN)
	{
		if (data->zoom > 0.3)
			data->zoom -= 0.3;
	}
	if (key == ARR_UP)
		data->zoom += 0.3;
	ft_draw(data);
}

void	deal_key_rotation(int key, t_data *data)
{
	if (key == ARR_LEFT)
		data->angle += 0.03;
	if (key == ARR_RIGHT)
		data->angle -= 0.03;
	ft_draw(data);
}

int	deal_key(int key, t_data *data)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		deal_shift (key, data);
	else if (key == KY_ESC)
		cleanup(data);
	else if (key == ARR_UP || key == ARR_DOWN || key == ZOOMIN || key == ZOOMOUT)
		deal_zoom(key, data);
	return (0);
}

