/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:22:57 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/09 18:23:24 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

static void	free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
}

int	cleanup(t_data *data)
{
	if (data->z_matrix)
		free_int_array(data->z_matrix);
	if (data->mlx_ptr && data->img.img_ptr)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		free_ptr(data->img.img_ptr);
	}
	if (data->win_ptr && data->mlx_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->img.img_ptr);
		free_ptr(data->win_ptr);
	}
	free_ptr(data->mlx_ptr);
	free_ptr(data->img.addr);
	free_ptr(data);
	exit(0);
	return (0);
}
