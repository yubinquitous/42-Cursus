#include <stdio.h>
#include "mlx.h"

int	main(void)
{
	void	*window;
	void	*mlx;
	void	*img;
	int		width;
	int		height;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "yubin");
	img = mlx_xpm_file_to_image(mlx, "./kirby.xpm", &width, &height);
	mlx_put_image_to_window(mlx, window, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
