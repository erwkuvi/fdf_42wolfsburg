/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:37:05 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/17 19:44:59 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(int *)pixel = color;
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (!distance)
		return (1.0);
	return (placement / distance);
}

int	get_default_color(int z, t_data *data)
{
	double	percentage;
	int		z_min;
	int		z_max;

	z_min = data->z_min;
	z_max = data->z_max;
	// z_min *= data->height_zoom;
	// z_max *= data->height_zoom;
	percentage = percent(z_min, z_max, z);
	if (percentage < 0.2)
		return (DISCO);
	else if (percentage < 0.4)
		return (BRICK_RED);
	else if (percentage < 0.6)
		return (FLAMINGO);
	else if (percentage < 0.8)
		return (JAFFA);
	else
		return (SAFFRON);
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(int dx, int dy, t_data *data)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (data->color1 == data->color2)
		return (data->color1);
	if (dx > dy)
		percentage = percent(data->x1, data->x2, data->x1);
	else
		percentage = percent(data->y1, data->y2, data->y1);
	red = get_light((data->color1 >> 16) & 0xFF,
			(data->color2 >> 16) & 0xFF, percentage);
	green = get_light((data->color2 >> 8) & 0xFF,
			(data->color2 >> 8) & 0xFF, percentage);
	blue = get_light(data->color1 & 0xFF, data->color2 & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
