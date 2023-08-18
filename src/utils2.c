/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:53:11 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/18 18:13:32 by ekuchel          ###   ########.fr       */
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

void	min_max_z(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	data->z_min = data->z_matrix[i][j];
	data->z_max = data->z_matrix[i][j];
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->z_matrix[i][j] < data->z_min)
				data->z_min = data->z_matrix[i][j];
			if (data->z_matrix[i][j] > data->z_max)
				data->z_max = data->z_matrix[i][j];
			j++;
		}
		i++;
	}
}

void	initialize(t_data *data)
{
	data->zoom = (float)WIN_HEIGHT / (float)data->height / (float)4;
	if (data->zoom <= 0)
		error_print("Error while calculating zoom!");
	data->height_zoom = 3;
	data->color1 = WHITE;
	data->color2 = WHITE;
	data->angle = 0.523599;
	data->shift_x = (WIN_WIDTH / 2) - (data->width * data->zoom) / 2;
	data->shift_y = (WIN_HEIGHT / 2) - (data->height * data->zoom) / 2;
	if (data->shift_x < 0 || data->shift_y < 0)
		error_print("Error while calculating shift!");
	min_max_z(data);
}

void	free_intarray(int **array, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
