/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:08:15 by kanye             #+#    #+#             */
/*   Updated: 2025/08/06 14:06:43 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include "minilibx/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define ERROR 0
# define SUCCESS 1
# define TILE_SIZE 64

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		moves;
	int		position_x;
	int		position_y;
	int		coins_total;
	int		collected_coins;
	int		x_tile;
	int		y_tile;
	int		reachable_coins;
	int		reachable_exit;

	void	*mlx;
	void	*win;
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*coins;
}			t_game;

int			check_if_ber_file(char *filename);
void		check_ber_rectangular_and_assign_width(t_game *game,
				char *filename);
void		assign_dimensions(char *filename, t_game *reference);
void		error_message(char *message, t_game *game);
void		check_walls(t_game game);
void		read_map(char *filename, t_game *game);
void		free_map(char **map, int height);
void		check_sprites(t_game *game);
void		check_args_and_init(char **argv, t_game *game);
void		load_map(t_game *game);
int			valid_move(char tile, t_game *game);
void		w_key(t_game *game);
void		s_key(t_game *game);
void		a_key(t_game *game);
void		d_key(t_game *game);
void		get_player_position(t_game *game);
void		get_total_coins(t_game *game);
void		update_player(t_game *game, int x, int y);
int			key_pressed(int keycode, t_game *game);
int			count_lines(char *filename);
void		possible_path(t_game *game);
void		clean_up_game(t_game *game);
int			close_window_hook(t_game *game);
void		load_all_sprites(t_game *game);
#endif