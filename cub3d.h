/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:44:25 by lukarape          #+#    #+#             */
/*   Updated: 2022/02/15 20:44:28 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "mlx/mlx.h"
# define TEXSIDE 64

struct s_map
{
	char	*fd_no;
	char	*fd_so;
	char	*fd_we;
	char	*fd_ea;
	int		f;
	int		c;
	int		floor;
	int		ceiling;
	int		height;
	int		width;	
	char	**map;
	int		count;
	int		gnl;
}	map;

struct s_player
{
	double	x;
	double	y;
	double	dir;
	char	dir_symb;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		count;
}		player;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

struct	s_win
{
	void	*mlx;
	void	*win;
	int		screen_width;
	int		screen_height;
	t_data	data;
	t_data	north;
	t_data	south;
	t_data	west;
	t_data	east;
	double	time;
	double	old_time;
}		win;

typedef struct s_vars
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;
}				t_vars;

//utils.c
int				ft_strlen(char *str);
int				get_next_line(int fd, char **line);
int				my_rgb(int r, int g, int b);
int				empty_line(char *str);

//errors.c
void			error_exit(int code);

//parsing.c
int				parse_format(char *str);
int				parse_line(char *str, int line_num);
void			read_file(char *str);
int				parse_colors(char **spl);
int				parse_map(void);
void			map_size(char *fd);
int				parse_colors_1(char **spl);
int				parse_elements(char *str);

//parsing1.c
int				is_opened(char **spl);
int				parse_color(char **spl);
void			read_file_1(char *str, int line_num, int fd);

//parsing2.c
void			parse_map_1(int i, int j);
void			map_size_1(char *str, int *flag, int *line_num);

//split.c
int				get_cnt(char const *s, char c);
char			**free_machine(char **s, int idx);
char			**free_matrix(char **s);
char			**ft_split(char const *s, char c);
char			**ft_split(char const *s, char c);

//utils1.c
int				ft_atoi(const char *str);
char			*ft_substr(char const *s, unsigned int start, int len);
int				check_zero(char *str);
int				check_neighbours(int i, int j);
char			*ft_strdup(char *str);

//utils2.c
int				get_count(char const *s, char c);
void			fill_map(char *str, int line_num);
int				check_validity(char c);
int				open_fd(char *f);

//raycaster.c
void			start(void);
void			draw_map(void);
void			distance(t_vars *v);
void			perform_dda(t_vars *v);
void			step_calculation(t_vars *v);
void			init_vars(t_vars *v, int *x);

//key_hook.c
int				close_win(void);
int				key_hook(int keycode);
void			turn_left(double r);

//player_dir.c
void			set_player_direction(void);

//raycaster1.c
void			fill_colors(t_vars *v, int *x, int *y);
void			attach_textures(t_vars *v, int *x, int *y);
void			get_image(void);

//pixel.c
unsigned int	get_pixel(t_data *data, int x, int y);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

//key_hook1.c
void			move_forward(double s);
void			move_back(double s);
void			move_left(double s);
void			move_right(double s);
void			turn_right(double r);

#endif
