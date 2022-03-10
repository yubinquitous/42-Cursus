#include <stdio.h>
#include <stdlib.h>
#include "../mlx/mlx.h"

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_release		3
#define X_EVENT_KEY_EXIT		17 //exit key code

//Mac key code example
//All the key code example other than below is described on the site linked in READEME.md
#define KEY_ESC			53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;
	char		*src;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

//Since key_press() can recieve only one argument, all the argument shold be gathered in one structure
//x,y and str are meaningless variables.
typedef struct s_param{
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	t_img	img;
	char	str[3];
}				t_param;

//Only param->x will be used. 
void			param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int		draw_map(t_param param) {
	mlx_clear_window(param.mlx, param.win);
	param.img.ptr = mlx_xpm_file_to_image(param.mlx, param.img.src, &param.img.width, &param.img.height);
	param.img.data = (int *)mlx_get_data_addr(param.img.ptr, &param.img.bpp, &param.img.size_l, &param.img.endian);
	mlx_put_image_to_window(param.mlx, param.win, param.img.ptr, param.x, param.y);
	return (0);
}

int				key_press(int keycode, t_param *param)
{
	static int a = 0;

	if (keycode == KEY_D)//Action when W key pressed
	{
		param->x +=60;
		param->img.src = "../asset/kirby.xpm";
		draw_map(*param);
	}
	else if (keycode == KEY_A) //Action when S key pressed
	{
		param->x -=60;
		param->img.src = "../asset/kirby_reverse.xpm";
		draw_map(*param);
	}
	else if (keycode == KEY_S)
	{
		param->y +=60;
		draw_map(*param);
	}
	else if (keycode == KEY_W)
	{
		param->y -= 60;
		draw_map(*param);
	}
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed 
		exit(0);
	else
		;
	printf("x: %d\ty: %d\n", param->x, param->y);
	return (0);
}

int			main(void)
{
	t_param		param;

	param_init(&param);
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 800, 600, "yubchoi");
	printf("-------------------------------\n");
	printf("'W key': Add 1 to x.\n");
	printf("'S key': Subtract 1 from x\n");
	printf("'ESC key': Exit this program\n");
	printf("'Other keys': print current x \n");
	printf("-------------------------------\n");
	printf("Current x = 0\n");
	param.img.src = "../asset/kirby.xpm";
	param.img.ptr = mlx_xpm_file_to_image(param.mlx, param.img.src, &param.img.width, &param.img.height);
	param.img.data = (int *)mlx_get_data_addr(param.img.ptr, &param.img.bpp, &param.img.size_l, &param.img.endian);
	mlx_put_image_to_window(param.mlx, param.win, param.img.ptr, param.x, param.y);
	mlx_hook(param.win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(param.mlx);
}
