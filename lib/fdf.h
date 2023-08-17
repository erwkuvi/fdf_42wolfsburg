/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:51:07 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/17 18:48:38 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <math.h>
# include "minilibx_macos/mlx.h"
# include <stdio.h>

# define WIN_WIDTH		1920
# define WIN_HEIGHT		1080

# define MLX_ERROR		1
# define KY_ESC			53
# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124
# define HEIGHTUP		14
# define HEIGHTDOWN		12
# define WINDOW_CLOSE	17
# define KEY_PRESS		2
# define ARR_UP			13
# define ARR_DOWN		1
# define ARR_LEFT		0
# define ARR_RIGHT		2

# define BRICK_RED		0x003049
# define FLAMINGO		0xEAE2B7
# define DISCO			0xD62828 //red //0x40E0D0 //9A1F6A
# define JAFFA			0xF77F00 // orange 0xEF8633
# define SAFFRON		0xFCBF49 //Goldish//0x808080 //0xFFD700 //0xF3AF3D
# define EBONY			0x555D50
# define WHITE			0xFFFFFF
# define GREY			0x808080
# define BLUE			0x0000FF
# define MAROON			0x800000
# define BACKGROUND		0x222222

typedef struct s_img
{
	int		bpp;
	int		line_length;
	int		endian;
	char	*addr;
	void	*img_ptr;
}	t_img;

typedef struct s_data
{
	int		height;
	int		width;
	int		**z_matrix;
	int		z_min;
	int		z_max;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		shift_x;
	int		shift_y;

	float	zoom;
	float	height_zoom;
	int		color1;
	int		color2;
	float	angle;

	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

/* ----------- readfile.c -------------- */
void		readfile(char *filename, t_data *data);
void		error_print(char *s);
int			get_y(char *filename);
int			get_x(char *filename, int y);
int			get_color(int dx, int dy, t_data *data);

/* --------- utils.c ----------------- */
int			ft_wordcount(char *s, char c);
void		initialize_mlx(t_data *data);
void		initialize(t_data *data);
void		assign_val_x(t_data *data, int x, int y);
void		assign_val_y(t_data *data, int x, int y);
int			arraycmp(int *array, int current, int index);

/* --------- draw.c ----------------- */
void		bresenham_line(t_data *data);
void		img_pix_put(t_img *img, int x, int y, int color);
int			ft_draw(t_data *data);
void		render_background(t_img *img, int color);
int			get_default_color(int z, t_data *data);

/*--------- isometric.c --------------*/
void		assign_val_x(t_data *data, int val1, int val2);
void		assign_val_y(t_data *data, int val1, int val2);

/*--------- hooks.c ----------------*/
int			deal_key(int key, t_data *data);
int			close_win(t_data *data);

#endif
