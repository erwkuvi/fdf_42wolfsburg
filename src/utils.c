/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:57:48 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/17 18:42:06 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	error_print(char *s)
{
	perror(s);
	exit (1);
}

int	ft_wordlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	ft_wordcount(char *s, char c)
{
	int			count;
	int			i;

	count = 0;
	while (*s)
	{
		i = 0;
		while (*s && (*s == c))
			s++;
		i = ft_wordlen(s, c);
		s += i;
		if (i)
			count++;
	}
	return (count);
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
