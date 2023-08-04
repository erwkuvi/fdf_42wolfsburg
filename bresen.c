void	bresen_algo(t_data *data)
{
	int	dx;
	int	dy;
	int	p;
	int	z1;
	int	z2;

	// z1 = data->z_matrix[data->y1][data->x1];
	// z2 = data->z_matrix[data->y2][data->x2];
	// ft_zoom(data);
	// data->color = assign_color(z1);
	// isometric(&data->x1, &data->y1, z1);
	// isometric(&data->x2, &data->y2, z2);
	// ft_shift(&data->x1, &data->y1, &data->x2, &data->y2);
	// data->flag = 0;
	dx = data->x2 - data->x1;
	dy = data->y2 - data->y1;
	if (dy > dx)
		swap_xy(data, &dx, &dy);
	p = (2 * dy) - dx;
	while (data->x1 <= data->x2)
	{
		my_mlx_pixel_put(data, data->x1, data->y1, data->color);
		data->x1++;
		p += p_factor(p, dx, dy, &data->y1);
	}
}
	p = (2 * dx) - dy;
	while (data->y1 <= data->y2)
	{
		my_mlx_pixel_put(data, data->x1, data->y1, data->color);
		data->y1++;
		p += p_factor(p, dy, dx, &data->x1);
	}


