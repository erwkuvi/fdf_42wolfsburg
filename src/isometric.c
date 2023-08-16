/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:44:05 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/16 21:16:49 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

static int	x_isometric(float x, float y, t_data *data)
{
	return ((x - y) * cos(data->angle));
	// y = 0;
	// data->color_matrix = NULL;
	// return (x);
}

static int	y_isometric(int x, int y, int z, t_data *data)
{
	return ((x + y) * sin(data->angle) - z);
	// x = 0;
	// z = 0;
	// data->color_matrix = NULL;
	// return (y);
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
	bresenham_line(data);
}

// void	assign_val_y(t_data *data, int x1, int y1)
// {
// 	t_data	delta;
// 	t_data	curr;
// 	t_data	sign;
// 	int		x2;
// 	int		y2;
// 	int		z1;
// 	int		z2;

// 	x2 = x1;
// 	y2 = y1 + 1;
// 	z1 = data->z_matrix[y1][x1];
// 	z2 = data->z_matrix[y2][x2];
// 	// color = data->color_matrix[y1][x1];
// 	// color = 8388608;
// 	x1 *= data->zoom;
// 	y1 *= data->zoom;
// 	x2 *= data->zoom;
// 	y2 *= data->zoom;
// 	z1 *= data->height_zoom;
// 	z2 *= data->height_zoom;
// 	data->x1 = x_isometric(x1, y1, data);
// 	data->y1 = y_isometric(data->x1, y1, z1, data);
// 	data->x2 = x_isometric(x2, y2, data);
// 	data->y2 = y_isometric(data->x2, y2, z2, data);
// 	bresenham_line(data, get_color(curr, ));
// }

void	assign_val_y(t_data *data, int x1, int y1)
{
	int		x2;
	int		y2;
	int		z1;
	int		z2;

	x2 = x1;
	y2 = y1 + 1;//end point
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
	bresenham_line(data);
}
