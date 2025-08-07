/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:03:19 by kanye             #+#    #+#             */
/*   Updated: 2025/08/07 13:28:50 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("\nTHE ARGUMENTS ARE INVALID\n");
		return (1);
	}
	ft_bzero(&game, sizeof(t_game));
	game.moves = 0;
	game.collected_coins = 0;
	game.reachable_coins = 0;
	game.reachable_exit = 0;
	check_args_and_init(argv, &game);
	ft_printf("Total coins %d\n", game.coins_total);
	game.mlx = mlx_init();
	load_all_sprites(&game);
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, game.width * TILE_SIZE, game.height
			* TILE_SIZE, "so_long");
	load_map(&game);
	mlx_key_hook(game.win, key_pressed, &game);
	mlx_hook(game.win, 17, 0, close_window_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
