/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:22:57 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/16 21:50:57 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

static void	free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
}

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
	free_ptr(data->mlx_ptr);
	free_ptr(data);
	return (0);
}

int	arraycmp(int *array, int current, int index)
{
	if (!index)
		return (0);
	while (--index)
	{
		if (array[index] != current)
			return (1);
	}
	return (0);
}

double percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(t_data current, t_data start, t_data end, t_data delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x1 > delta.y1)
		percentage = percent(start.x1, start.x2, current.x1);
	else
		percentage = percent(start.y1, start.y2, current.y1);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

// int get_color(t_point current, t_point start, t_point end, t_point delta)
// {
//     int     red;
//     int     green;
//     int     blue;
//     double  percentage;

//     if (current.color == end.color)
//         return (current.color);
//     if (delta.x > delta.y)
//         percentage = percent(start.x, end.x, current.x);
//     else
//         percentage = percent(start.y, end.y, current.y);
//     red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
//     green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
//     blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
//     return ((red << 16) | (green << 8) | blue);
// }

// int	cleanup(t_data *data)
// {
// 	if (data->z_matrix)
// 		free_int_array(data->z_matrix);
// 	if (data->mlx_ptr && data->img.img_ptr)
// 	{
// 		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
// 		free_ptr(data->img.img_ptr);
// 	}
// 	if (data->win_ptr && data->mlx_ptr)
// 	{
// 		mlx_destroy_window(data->mlx_ptr, data->img.img_ptr);
// 		free_ptr(data->win_ptr);
// 	}
// 	free_ptr(data->mlx_ptr);
// 	free_ptr(data->img.addr);
// 	free_ptr(data);
// 	exit(0);







