/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:45:32 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/08 21:31:06 by ekuchel          ###   ########.fr       */
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

	// p = (2 * dx) - dy;
	p = 0;
	while (data->y1 <= data->y2)
	{
		p += p_factor(p, dy, dx, &data->x1);
		img_pix_put(&data->img, (data->shift_x + data->x1),
			(data->shift_y + data->y1++), color);

	}
}

void	loop_x(t_data *data, int dx, int dy, int color)
{
	int	p;

	p = 0;
	while (data->x1 <= data->x2)
	{
		p += p_factor(p, dx, dy, &data->y1);
		img_pix_put(&data->img, (data->shift_x + data->x1++),
			(data->shift_y + data->y1), color);

	}
}

float	mod(float val)
{
	if (val < 0)
		return (val * -1);
	return (val);
}

int	max_val(float dx, float dy)
{
	if (dx > dy)
		return ((int)dx);
	return ((int)dy);

}

void	bresenham_line(t_data *data, int color)
{
	float	dx;
	float	dy;
	float	x_pos;
	float	y_pos;
	int		max;

	dx = data->x2 - data->x1;
	dy = data->y2 - data->y1;
	max = max_val(mod(dx), mod(dy));
	dx /= max;
	dy /= max;
	x_pos = data->x1;
	y_pos = data->y1;
	while ((int)(x_pos - data->x2) || (int)(y_pos - data->y2))
	{
		img_pix_put(&data->img, (data->shift_x + (int)x_pos),
			(data->shift_y + (int)y_pos), color);
		x_pos += dx;
		y_pos += dy;
	}
}

void	ft_draw(t_data *data)
{
	int	y;
	int	x;

	if (data->img.img_ptr)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	}
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
