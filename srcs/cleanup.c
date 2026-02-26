/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:13:49 by akonstan          #+#    #+#             */
/*   Updated: 2026/02/26 18:13:55 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

void	free_array(char ***array, int rows)
{
	int	i;

	i = rows - 1;
	while (i != 0)
	{
		free((*array)[i]);
		(*array)[i] = NULL;
		i--;
	}
}

void	clean_game_data(t_game_data *game)
{
	free_array(&game->map.array, game->map.rows);
	clean_image(&game->img, game->mlx);
	clean_textures(game->textures, 4, game->mlx);
	mlx_destroy_window(game->mlx, game->screen);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

void	clean_textures(t_texture *textures, int amount, void *mlx)
{
	int i;

	i = 0;
	while (i < amount)
	{
		clean_image(&textures[i].img, mlx);
		i++;
	}
}

void	clean_image(t_image *img, void *mlx)
{
	mlx_destroy_image(mlx, img->img);
}
