void flood_fill(char **map, int x, int y)
{
    if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '\0' || map[y][x] == '1')
        return (NULL);
    if (map[y][x] == 'F')
        return (NULL);
    map[y][x] == 'F';
    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
}