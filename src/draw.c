/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:45:32 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/04 18:03:23 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	p_factor(int p, int dx, int dy, int *y)
{
	if (p < 0)
		return (2 * dy);
	else
	{
		*y = *y + 1;
		return ((2 * dy) - (2 * dx));
	}
}

void	loop_y(t_data *data, int dx, int dy, int color)
{
	int	p;

	p = (2 * dx) - dy;
	while (data->y1 <= data->y2)
	{
		img_pix_put(&data->img, data->x1, data->y1++, color);
		p += p_factor(p, dy, dx, &data->x1);
	}
}

void	loop_x(t_data *data, int dx, int dy, int color)
{
	int	p;

	p = (2 * dy) - dx;
	while (data->x1 <= data->x2)
	{
		img_pix_put(&data->img, data->x1++, data->y1, color);
		p += p_factor(p, dx, dy, &data->y1);
		printf("Value of x1 %d\n", data->x1);
		printf("Value of y1 %d\n", data->y1);
		printf("\n");
	}
}

void	bresen_algo(t_data *data, int color)
{
	int	dx;
	int	dy;
	int	z1;
	int	z2;

	// z1 = data->z_matrix[data->y1][data->x1];
	// z2 = data->z_matrix[data->y2][data->x2];
	ft_zoom(data);
	// data->color = assign_color(z1);
	ft_shift(data);
	isometric(&data->x1, &data->y1, z1, data);
	isometric(&data->x2, &data->y2, z2, data);
	dx = data->x2 - data->x1;
	dy = data->y2 - data->y1;
	if (dy > dx)
		loop_y(data, dx, dy, color);
	else
		loop_x(data, dx, dy, color);
}

void	ft_draw(t_data *data)
{
	int	y;
	int	x;
	render_background(&data->img, EBONY);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				assign_val_x(data, x, y);
			if (y < data->height - 1)
				assign_val_y(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}
