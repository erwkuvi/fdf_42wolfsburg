/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:45:32 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/18 12:07:11 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
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

void	bresenham_line(t_data *data)
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
			(data->shift_y + (int)y_pos), get_color(dx, dy, data));
		x_pos += dx;
		y_pos += dy;
	}
}

int	ft_draw(t_data *data)
{
	int	y;
	int	x;

	render_background(&data->img, BACKGROUND);
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
	return (0);
}
