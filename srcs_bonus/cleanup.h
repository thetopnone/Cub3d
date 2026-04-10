/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:13:58 by akonstan          #+#    #+#             */
/*   Updated: 2026/04/10 16:55:39 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CLEANUP_H
# define CLEANUP_H
# include "game_data.h"
# include <stdlib.h>

void	free_array(void **array, int rows);
void	free_textures(t_texture *textures);
int		clean_game_data(t_game_data *game);
void	clean_textures(t_texture *textures, int amount, void *mlx);
void	clean_image(t_image *img, void *mlx);
#endif
