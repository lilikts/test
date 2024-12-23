#include "so_long.h"

bool    player_position(t_map, t_game)
{
    int x;
    int y;

    x = 0;
    y = 0;

    while (y < map-> height)
    {
        while (x < map-> width)
        {
            if (grid[y][x] == 'P')
            {
                game-> player_position_x = x;
                game-> player_position_y = y;
                return (true)
            }
            x++;
        }
        y++;
    }
    return (false);
}