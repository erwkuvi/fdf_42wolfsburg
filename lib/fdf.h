/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:51:07 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/08 21:02:52 by ekuchel          ###   ########.fr       */
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
# define WINDOW_CLOSE	17


/*W = 13 A = 0  S = 1 Q = 12*/

# define EBONY			0x555D50
# define WHITE			0xFFFFFF
# define GREY			0x808080
# define BLUE			0x0000FF
# define MAROON			0x800000

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

	float		zoom;
	float		height_zoom;
	int		color;
	float	angle;
	int		**color_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

/* ----------- readfile.c -------------- */
void		readfile(char *filename, t_data *data);
void		error_print(char *s);
int			get_y(char *filename);
int			get_x(char *filename);

/* ---------utils.c ----------------- */
int			ft_wordcount(char *s, char c);
void		free_int_array(int **array);
int			assign_color(int z);
void		ft_zoom(t_data *data);
void		initialize_mlx(t_data *data);
void		initialize(t_data *data);
void		ft_shift(t_data *data);
void		assign_val_x(t_data *data, int x, int y);
void		assign_val_y(t_data *data, int x, int y);

/* ---------draw.c ----------------- */
void		bresenham_line(t_data *data, int color);
void		img_pix_put(t_img *img, int x, int y, int color);
void		ft_draw(t_data *data);
void		ft_zoom(t_data *data);
void		ft_shift(t_data *data);
void		render_background(t_img *img, int color);
// int			render_rect(t_img *img, t_rect rect);

/*----------isometric.c---------------*/
void		isometric(int *x, int *y, int z, t_data *data);
void		assign_val_x(t_data *data, int val1, int val2);
void		assign_val_y(t_data *data, int val1, int val2);

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
