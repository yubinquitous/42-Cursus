#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_zone
{
	int width;
	int height;
	char bg;
} t_zone;

typedef struct s_shape
{
	char type;
	float x;
	float y;
	float width;
	float height;
	char color;
} t_shape;

int ft_strerr(char *msg)
{
	int len = 0;

	while (msg && msg[len])
		++len;
	write(1, msg, len);
	return 1;
}

int clear_all(FILE *file, char *drawing, char *msg)
{
	fclose(file);
	free(drawing);
	if (msg)
		ft_strerr(msg);
	return 1;
}

char get_zone(FILE *file, t_zone *zone)
{
	if (fscanf(file, "%d %d %c\n",
				&(zone->width), &(zone->height), &(zone->bg)) != 3)
		return 1;
	if (zone->width <= 0 || zone->width > 300 || zone->height <= 0 || zone->height > 300)
		return 1;
	return 0;
}

char *get_drawing(t_zone zone)
{
	char *ret;
	int i = -1;

	ret = malloc(zone.height * zone.width);
	if (!ret)
		return 0;
	while (++i < zone.height*zone.width)
		ret[i] = zone.bg;
	return ret;
}

int is_rectangle(t_shape shape, float x, float y)
{
	if (shape.x <= x && x <= shape.x + shape.width
			&& shape.y <= y && y <= shape.y + shape.height)
	{
		if (x-shape.x < 1. || shape.x+shape.width-x < 1.
				|| y-shape.y < 1. || shape.y+shape.height-y < 1.)
			return 2;
		return 1;
	}
	return 0;
}

void get_shape(t_zone zone, t_shape shape, char *drawing)
{
	int x, y, is_it;

	y = -1;
	while (++y < zone.height)
	{
		x = -1;
		while (++x < zone.width)
		{
			is_it = is_rectangle(shape, (float)x, (float)y);
			if ((shape.type == 'r' && is_it == 2) || (shape.type == 'R' && is_it))
				drawing[zone.width * y + x] = shape.color;
		}
	}
}

char get_shapes(FILE *file, t_zone zone, char *drawing)
{
	int n;
	t_shape shape;

	while ((n = fscanf(file, "%c %f %f %f %f %c\n",
					&shape.type, &shape.x, &shape.y, &shape.width, &shape.height, &shape.color)) == 6)
	{
		if (shape.width <= 0. || shape.height <= 0. || !(shape.type == 'r' || shape.type == 'R'))
			return 1;
		get_shape(zone, shape, drawing);
	}
	if (n != -1)
		return 1;
	return 0;
}

void draw_drawing(t_zone zone, char *drawing)
{
	int i = -1;

	while (++i < zone.height)
	{
		write(1, drawing + zone.width*i, zone.width);
		write(1, "\n", 1);
	}
}

int main(int ac, char **av)
{
	FILE *file;
	t_zone zone;
	char *drawing;

	if (ac != 2)
		return (ft_strerr("Error: argument\n"));
	zone.width = 0;
	zone.height = 0;
	zone.bg = 0;
	drawing = 0;
	if (!(file = fopen(av[1], "r")))
		return (ft_strerr("Error: argument\n"));
	if (get_zone(file, &zone))
		return (clear_all(file, NULL, "Error: Operation file corrupted\n"));
	if (!(drawing = get_drawing(zone)))
		return (clear_all(file, NULL, "Error: Operation file corrupted\n"));
	if (get_shapes(file, zone, drawing))
		return (clear_all(file, drawing, "Error: Operation file corrupted\n"));
	draw_drawing(zone, drawing);
	clear_all(file, drawing, NULL);
	return 0;
}
