#include "so_long.h"

int handle_keypress(int keycode, t_map *map)
{
	if (keycode == 53) // ESC key
	{
		ft_putstr_fd("Exiting game...\n", 1);
		exit(0);
	}
	else if (keycode == 13) // W key
		ft_putstr_fd("Move up\n", 1);
	else if (keycode == 0) // A key
		ft_putstr_fd("Move left\n", 1);
	else if (keycode == 1) // S key
		ft_putstr_fd("Move down\n", 1);
	else if (keycode == 2) // D key
		ft_putstr_fd("Move right\n", 1);
	return (0);
}

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
