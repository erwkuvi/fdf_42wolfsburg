/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:25:14 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/01 12:54:24 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

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

int	get_x(char *filename)
{
	int		fd;
	char	*line;
	int		counter;

	counter = 0;
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
		error_print("open function failed");
	get_next_line(fd, &line);
	counter = ft_wordcount(line, ' ');
	free(line);
	close(fd);
	return (counter);
}

void	populate_matrix(char *line, int	*line_matrix)
{
	int		i;
	char	**s_array;

	i = 0;
	s_array = ft_split(line, ' ');
	while (s_array[i])
	{
		line_matrix[i] = ft_atoi(s_array[i]);
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

	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
		error_print("open function failed");
	data->height = get_y(filename);
	data->width = get_x(filename);
	data->z_matrix = (int **)malloc(data->height * sizeof(int *));
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(data->width * sizeof(int));
		i++;
	}
	i = 0;
	while (get_next_line(fd, &line))
	{
		populate_matrix(line, data->z_matrix[i]);
		free(line);
		i++;
	}
	close(fd);
	return ;
}
