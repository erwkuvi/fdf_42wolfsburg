/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:51:07 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/14 12:26:06 by ekuchel          ###   ########.fr       */
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

# define EBONY			0x555D50
# define WHITE			0xFFFFFF
# define GREY			0x808080
# define BLUE			0x0000FF
# define MAROON			0x800000
# define HEXADEC		16

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
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		shift_x;
	int		shift_y;
	// float	dx;
	// float	dy;

	float	zoom;
	float	height_zoom;
	int		color;
	float	angle;
	int		**color_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

/* ----------- readfile.c -------------- */
void		readfile(char *filename, t_data *data);
void		error_print(char *s);
int			get_y(char *filename);
int			get_x(char *filename, int y);
int			atoi_base(char *str, int base);
int			hextoint(const char *str);

/* --------- utils.c ----------------- */
int			ft_wordcount(char *s, char c);
void		free_int_array(int **array);
int			assign_color(int z);
void		ft_zoom(t_data *data);
void		initialize_mlx(t_data *data);
void		initialize(t_data *data);
void		ft_shift(t_data *data);
void		assign_val_x(t_data *data, int x, int y);
void		assign_val_y(t_data *data, int x, int y);
int			arraycmp(int *array, int current, int index);

/* --------- draw.c ----------------- */
void		bresenham_line(t_data *data, int color);
void		img_pix_put(t_img *img, int x, int y, int color);
int			ft_draw(t_data *data);
void		ft_zoom(t_data *data);
void		ft_shift(t_data *data);
void		render_background(t_img *img, int color);

/*--------- isometric.c --------------*/
void		assign_val_x(t_data *data, int val1, int val2);
void		assign_val_y(t_data *data, int val1, int val2);

/*--------- hooks.c ----------------*/
// void		free_ptr(void *ptr);
int			deal_key(int key, t_data *data);
int			close_win(t_data *data);

#endif
/*
------------ mlx_function usage --------------
void *mlx_ptr;
void *win_prt;

mlx_ptr = mlx_init();
win_prt = mlx_new_window(mlx_ptr, 1000, 1000, "FDF");

mlx_pixel_put (mlx_ptr, win_ptr, (int)x, (int)y, #color);

mlx_key_hook (win_ptr, deal_key, NULL);
mlx_loop (mlx_ptr);

------------- deal_key prototype ---------------
int deal_key(int key, void *data);

-----------------------------------------------
colors:
	white = 0xffffff
	red = 0xe80сос
------------------------------------------------
frameworks:
-framework OpenGL -framework Appkit
*/
