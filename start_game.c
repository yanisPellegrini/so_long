#include "so_long.h"


int handle_close(t_map *map)
{
	ft_putstr_fd("Window closed. Exiting game...\n", 1);
	exit(0);
	return (0);
}

int start_game(t_map *map)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "So Long");
	mlx_hook(win, 2, 1L << 0, handle_keypress, map);
	mlx_hook(win, 17, 0, handle_close, map);
	mlx_loop(mlx);
	return (0);
}
