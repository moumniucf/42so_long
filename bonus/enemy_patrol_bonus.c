/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:58:15 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/19 16:45:11 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    find_enemy(t_game *game)
{
    int i;
    int j;
    i = 0;
    while(i < game->height)
    {
        j = 0;
        while(j < game->width)
        {
            if(game->map[i][j] == 'H')
            {
                game->enmx = i;
                game->enmy = j;
                return ;
            }
            j++;
        }
        i++;
    }
}
int move_ene_my(t_game *game)
{
    int i;
    int j;
    find_enemy(game);
    i = game->enmx;
    j = game->enmy;
    if(game->map[i + 1][j] != '1' && game->map[i + 1][j] != 'E')
    {
        game->map[i][j] = '0';
        game->map[i + 1][j] = 'E';
        game->enmx = i + 1;
    }
    if(game->map[i - 1][j] != '1' && game->map[i - 1][j] != 'E')
    {
        game->map[i][j] = '0';
        game->map[i - 1][j] = 'E';
        game->enmx = i - 1;
    }
    animation(game);
    return (0);
}
