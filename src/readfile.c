/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:25:14 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/15 13:44:09 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	ft_allocation_matrices(t_data *data)
{
	int	i;

	i = 0;
	data->z_matrix = (int **)ft_calloc(data->height, sizeof(int *));
	data->color_matrix = (int **)ft_calloc(data->height, sizeof(int));
	if (!data->z_matrix || !data->color_matrix)
		error_print("Matrix was not memory allocated");
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)ft_calloc(data->width, sizeof(int));
		data->color_matrix[i] = (int *)ft_calloc(data->width, sizeof(int));
		i++;
	}

}

int	get_y(char *filename)
{
	int		fd;
	char	*line;
	int		counter;

	counter = 0;
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
		error_print("open function failed");
	while (get_next_line(fd, &line))
	{
		free(line);
		counter++;
	}
	close(fd);
	return (counter);
}

int	get_x(char *filename, int y)
{
	int		fd;
	char	*line;
	int		counter;
	int		*sizecheck;
	int		i;

	i = 0;
	sizecheck = (int *)malloc(sizeof(int) * y);
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
		error_print("open function failed");
	while (get_next_line(fd, &line))
	{
		counter = ft_wordcount(line, ' ');
		sizecheck[i] = counter;
		if (arraycmp(sizecheck, sizecheck[i], i))
			error_print("Map size error");
		free(line);
		i++;
	}
	free(sizecheck);
	free(line);
	close(fd);
	return (counter);
}

void	populate_matrix(char *line, int	*line_matrix, int *color_matrix)
{
	int		i;
	int		j;
	char	**s_array;

	i = 0;
	s_array = ft_split(line, ' ');
	while (s_array[i])
	{
		line_matrix[i] = ft_atoi(s_array[i]);
		j = 0;
		while (s_array[i][j] != ',' && s_array[i][j])
			j++;
		if (s_array[i][j++] == ',')
			color_matrix[i] = hextoint(&s_array[i][j]);
		else
			color_matrix[i] = def_color(line_matrix[i]);
		free(s_array[i]);
		i++;
	}
	free(s_array);
}

void	readfile(char *filename, t_data *data)
{
	// int		fd;
	// char	*line;

	// fd = open(filename, O_RDONLY, 0);
	// if (fd < 0)
	// 	error_print("open function failed");
	data->height = get_y(filename);
	printf("Value of Y: %d\n", data->height);
	data->width = get_x(filename, data->height);
	printf("Value of X: %d\n", data->width);
	ft_allocation_matrices(data);
	// i = 0;
	// while (get_next_line(fd, &line))
	// {
	// 	populate_matrix(line, data->z_matrix[i], data->color_matrix[i]);
	// 	free(line);
	// 	i++;
	// }
	// close(fd);
	return ;
}
