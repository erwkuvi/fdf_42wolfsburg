/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:57:13 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/01 17:31:36 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft/libft.h"
#include <stdio.h>

int hex_to_color(const char *str)
{
    int color;
    int i;
    int digit;

    color = 0;
    i = 0;

    while (str[i])
    {
        // Convert the character to its hexadecimal digit value
        if (str[i] >= '0' && str[i] <= '9')
            digit = str[i] - '0';
        else if (str[i] >= 'a' && str[i] <= 'f')
            digit = str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            digit = str[i] - 'A' + 10;
        else
            return (0); // Invalid character, return a default color (GREY)

        // Shift the current color left by 4 bits and add the new digit
        color = (color << 4) | digit;

        i++;
    }

    return color; // Return the final color value
}


int	main(int argc, char **argv)
{
	char	*line;

	line = "ffffff";
	printf("%d\n", hex_to_color(line));
	return (0);
}
