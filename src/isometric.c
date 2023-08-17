/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:44:05 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/17 17:24:08 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

static int	x_isometric(float x, float y, t_data *data)
{
	return ((x - y) * cos(data->angle));
}

static int	y_isometric(int x, int y, int z, t_data *data)
{
	return ((x + y) * sin(data->angle) - z);
}

void	assign_val_x(t_data *data, int x1, int y1)
{
	int		x2;
	int		y2;
	int		z1;
	int		z2;

	x2 = x1 + 1;
	y2 = y1;
	z1 = data->z_matrix[y1][x1];
	z2 = data->z_matrix[y2][x2];
	x1 *= data->zoom;
	y1 *= data->zoom;
	x2 *= data->zoom;
	y2 *= data->zoom;
	z1 *= data->height_zoom;
	z2 *= data->height_zoom;
	data->x1 = x_isometric(x1, y1, data);
	data->y1 = y_isometric(data->x1, y1, z1, data);
	data->x2 = x_isometric(x2, y2, data);
	data->y2 = y_isometric(data->x2, y2, z2, data);
	data->color1 = get_default_color(z1, data);
	data->color2 = get_default_color(z2, data);
	bresenham_line(data);
}

void	assign_val_y(t_data *data, int x1, int y1)
{
	int		x2;
	int		y2;
	int		z1;
	int		z2;

	x2 = x1;
	y2 = y1 + 1;
	z1 = data->z_matrix[y1][x1];
	z2 = data->z_matrix[y2][x2];
	x1 *= data->zoom;
	y1 *= data->zoom;
	x2 *= data->zoom;
	y2 *= data->zoom;
	z1 *= data->height_zoom;
	z2 *= data->height_zoom;
	data->x1 = x_isometric(x1, y1, data);
	data->y1 = y_isometric(data->x1, y1, z1, data);
	data->x2 = x_isometric(x2, y2, data);
	data->y2 = y_isometric(data->x2, y2, z2, data);
	data->color1 = get_default_color(z1, data);
	data->color2 = get_default_color(z2, data);
	bresenham_line(data);
}
