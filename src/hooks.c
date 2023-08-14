/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:38:30 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/12 21:56:02 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void deal_shift(int	key, t_data *data)
{
	if (key == UP)
		data->shift_y -= 10;
	else if (key == DOWN)
		data->shift_y += 10;
	else if (key == LEFT)
		data->shift_x -= 10;
	else if (key == RIGHT)
		data->shift_x += 10;
	ft_draw(data);
}

void	deal_zoom(int key, t_data *data)
{
	if (key == HEIGHTUP)
		data->height_zoom += 0.3;
	if (key == HEIGHTDOWN)
		data->height_zoom -= 0.3;
	if (key == ARR_DOWN)
	{
		if (data->zoom > 0.3)
			data->zoom -= 0.3;
	}
	if (key == ARR_UP)
		data->zoom += 0.3;
	ft_draw(data);
}

void	deal_key_rotation(int key, t_data *data)
{
	if (data->angle < 1.543598)
	{
		if (key == ARR_LEFT)
		data->angle += 0.03;
	}
	if (data->angle > -1.2)
	{
		if (key == ARR_RIGHT)
			data->angle -= 0.03;
	}
	printf("Value of angle %f\n", data->angle);
	ft_draw(data);
}

int	deal_key(int key, t_data *data)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		deal_shift (key, data);
	else if (key == KY_ESC)
		close_win(data);
	else if (key == ARR_UP || key == ARR_DOWN || key == HEIGHTUP || key == HEIGHTDOWN)
		deal_zoom(key, data);
	else if (key == ARR_LEFT || key == ARR_RIGHT )
		deal_key_rotation(key, data);
	return (0);
}

