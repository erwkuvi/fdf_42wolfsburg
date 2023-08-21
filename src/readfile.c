/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:25:14 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/21 16:29:21 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	ft_allocation_matrices(t_data *data)
{
	int	i;

	i = 0;
	data->z_matrix = (int **)ft_calloc(data->height, sizeof(int *));
	if (!data->z_matrix)
		error_print("Matrix was not memory allocated");
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)ft_calloc(data->width, sizeof(int));
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

void	populate_matrix(char *line, int	*line_matrix, t_data *data)
{
	int		i;
	char	**s_array;

	i = 0;
	s_array = ft_split(line, ' ');
	while (s_array[i])
	{
		if (!ft_isdigit(s_array[i][0]))
			error_print("Wrong input");
		line_matrix[i] = ft_atoi(s_array[i]);
		if (line_matrix[i] > data->z_max)
			data->z_max = line_matrix[i];
		if (line_matrix[i] < data->z_min)
			data->z_min = line_matrix[i];
		free(s_array[i]);
		i++;
	}
	free(s_array);
}

void	readfile(char *filename, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || check_dir(filename))
		error_print("open did not work");
	data->height = get_y(filename);
	data->width = get_x(filename, data->height);
	ft_allocation_matrices(data);
	i = 0;
	while (get_next_line(fd, &line))
	{
		populate_matrix(line, data->z_matrix[i], data);
		free(line);
		i++;
	}
	close(fd);
	return ;
}
