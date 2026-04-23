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

void	free_array(void **array, int rows)
{
	int	i;

	if (!array || rows == 0)
		return ;
	i = rows - 1;
	while (i >= 0)
	{
		free(array[i]);
		array[i] = NULL;
		i--;
	}
	free(array);
}

void	free_textures(t_texture *textures)
{
	int	i;

	i = 0;
	while (i < 4)
		free(textures[i++].path);
}

int	clean_game_data(t_game_data *game)
{
	free_array((void **)game->map.array, game->map.rows);
	free_array((void **)game->map.visited, game->map.rows);
	free_textures(game->wall_tex);
	if (game->mlx)
	{
		mlx_do_key_autorepeaton(game->mlx);
		mlx_mouse_show(game->mlx, game->screen);
		clean_image(&game->img, game->mlx);
		clean_textures(game->wall_tex, 4, game->mlx);
		clean_textures(game->door_tex, 2, game->mlx);
		mlx_destroy_window(game->mlx, game->screen);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (1);
}

void	clean_textures(t_texture *textures, int amount, void *mlx)
{
	int	i;

	i = 0;
	if (!textures)
		return ;
	while (i < amount)
	{
		clean_image(&textures[i].img, mlx);
		i++;
	}
}

void	clean_image(t_image *img, void *mlx)
{
	if (img)
		mlx_destroy_image(mlx, img->img);
}
