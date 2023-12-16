/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:05:51 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/01 09:05:56 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../mlx/mlx.h"

# define IMG_W 32
# define IMG_H 32
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

typedef struct s_img
{
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*background;
}				t_img;

typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		prizes;
}				t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	t_map	*map;
	t_img	*img;
}				t_data;

void	ft_window_size(t_data *data, char **argv);
int		ft_key_event_handler(int keycode, t_data *data);
void	ft_init_map(t_data *data);
void	ft_put_object(t_data *data, char *relative_path);
void	ft_put_player(t_data *data);
void	ft_analyze_input(t_data *data, char **argv, int argc);
void	ft_put_background(t_data *data);
void	ft_win(t_data *data);
void	ft_move(t_data *data, char position, int direction);
int		ft_exit(t_data *data);
void	ft_init_data(t_data *data, t_map *map);
int		ft_count_specific_c(char *s, char c);
int		ft_count_lines(int fd, int line_length, int img_w);
int		ft_line_length(int fd);
void	ft_exit_error(void);

#endif
