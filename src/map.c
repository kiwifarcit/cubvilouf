#include "cub3d.h"

void	map_height(t_game *game)
{
	int		fd;
	char	*tmp;

	fd = open (game->argv[1], O_RDWR);
	if (game->argc < 2)
	{
		printf("MAP1 ERROR\n");
		exit(EXIT_FAILURE);
	}
	if (fd == -1)
	{
		printf("MAP2 ERROR\n");
		exit(EXIT_FAILURE);
	}
	tmp = get_next_line(fd);
	while (tmp)
	{
		write(1, "test\n", 5);
		game->map->y_size++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close (fd);
}

void	map(t_game *game)
{
	char	*tmp;
	int		i;
	int		fd;

	i = 0;
	fd = open(game->argv[1], O_RDONLY);
	map_height(game);
	game->map->map = malloc ((game->map->y_size + 1) * sizeof(char *));
	if (!game->map->map)
		exit(EXIT_FAILURE);
	tmp = get_next_line(fd);
	if (tmp == 0)
		/*error(game, 8)*/printf("ERROR\n");
	game->map->x_size = (int) ft_strlen(tmp);
	while (tmp)
	{
		game->map->map[i++] = tmp;
		if ((int) ft_strlen(tmp) != game->map->x_size)
		{
			printf("ERROR MAP SIZE\n");
			exit(EXIT_FAILURE);
		}
		tmp = get_next_line(fd);
	}
	game->map->map[i] = NULL;
	free(tmp);
	close(fd);
}