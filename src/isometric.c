/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:44:05 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/04 18:24:22 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

static int	x_isometric(int x, int y, t_data *data)
{
	return ((x - y) * cos(data->anglex));
}

static int	y_isometric(int x, int y, int z, t_data *data)
{
	return ((x + y) * sin(data->angley) - z);
}

// void	isometric(int *x, int *y, int z, t_data *data)
// {
// 	int	previous_x;
// 	int	previous_y;

// 	previous_x = *x;
// 	previous_y = *y;
// 	*x = (previous_x - previous_y) * cos(data->anglex);
// 	*y = (previous_x + previous_y) * sin(data->angley) - z;
// }

void	assign_val_x(t_data *data, int x, int y)
{
	int		x1;
	int		y1;
	int		z;
	int		z1;
	int		color;

	x1 = x + 1;
	y1 = y;
	z = data->z_matrix[y][x];
	z1 = data->z_matrix[y1][x1];
	color = data->color_matrix[y][x];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	z *= data->height_zoom;
	z1 *= data->height_zoom;
	data->x1 = x_isometric(x, y, data);
	data->x2 = x_isometric(data->x1, y1, data);
	data->y1 = y_isometric(data->x1, y, z, data);
	data->y2 = y_isometric(data->x2, y1, z1, data);
	bresen_algo(data, color);
}

void	assign_val_y(t_data *data, int x, int y)
{
	int	color;

	data->x1 = x;
	data->x2 = x;
	data->y1 = y;
	data->y2 = y + 1;
	bresen_algo(data, color);
}
