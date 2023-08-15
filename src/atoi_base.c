/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:03:27 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/15 14:00:20 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	get_digit(char c, int base, int *digit)
{
	char	*base_str;
	int		i;

	base_str = "0123456789abcdef";
	i = 0;
	while (base_str[i])
	{
		if (base_str[i] == c)
			break ;
		i++;
	}
	if (i >= base)
		return (0);
	*digit = i;
	return (1);
}

int	atoi_base(char *str, int base)
{
	int	res;
	int	digit;
	int	posneg;
	int	i;

	i = 0;
	res = 0;
	posneg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			posneg *= -1;
		i++;
	}
	while ((get_digit(ft_tolower(str[i]), base, &digit)))
	{
		res *= base;
		res += (digit % base);
		i++;
	}
	// if (str[i] != ' ' && str[i] != ',' && str[i] != '\0' && str[i] != '\n')
	// 	error_print("Error: Map contains invalid non-digit characters j");
	return (res * posneg);
}
