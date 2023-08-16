/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:22:57 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/16 17:34:23 by ekuchel          ###   ########.fr       */
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







