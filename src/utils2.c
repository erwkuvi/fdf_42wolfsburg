/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:37:05 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/04 17:53:20 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	ft_zoom(t_data *data)
{
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	data->x2 *= data->zoom;
	data->y2 *= data->zoom;
}

int	assign_color(int z)
{
	if (z > 0)
		return (0xFF5733);
	return (0xFFFFFF);
}

void	ft_shift(t_data *data)
{
	data->x1 += data->shift_x;
	data->y1 += data->shift_y;
	data->x2 += data->shift_x;
	data->y2 += data->shift_y;
}

