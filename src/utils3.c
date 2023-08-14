/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:53:11 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/12 22:45:04 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	initialize_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit(MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		exit(MLX_ERROR);
	}
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_length, &data->img.endian);
}

void	initialize(t_data *data)
{
	data->zoom = WIN_HEIGHT / data->height / 4;
	if (data->zoom <= 0)
		error_print("Error while calculating zoom!");
	data->height_zoom = 3;
	data->color = WHITE;
	data->angle = 0.523599;
	data->shift_x = (WIN_WIDTH / 2) - (data->width * data->zoom) / 2;
	data->shift_y = (WIN_HEIGHT / 2) - (data->height * data->zoom) / 2;
	if (data->shift_x < 0 || data->shift_y < 0)
		error_print("Error while calculating shift!");
	data->color_matrix = NULL;
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	hextoint(const char *str)
{
	int	num;
	int	i;
	int	dig;

	num = 0;
	i = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			dig = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			dig = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			dig = str[i] - 'A' + 10;
		else
			return (WHITE);
		num = (num << 4) | dig;
		i++;
	}
	return (num);
}

