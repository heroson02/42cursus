#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct s_rect
{
	char 	type;
	float 	x;
	float 	y;
	float 	height;
	float 	width;
	char	rect_char;
}	t_rect;

typedef struct s_info
{
	int width;
	int height;
	char bg_char;
}	t_info;

t_info info;

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int len = ft_strlen(str);
	
	for (int i = 0; i < len ; i++)
	{
		write(1, &str[i], 1);
	}
}

int	argError()
{
	ft_putstr("Error: argument\n");
	return (1);
}

int	fileError()
{
	ft_putstr("Error: Operation file corrupted\n");
	return (1);
}

int	is_in_rect(int x, int y, t_rect *r)
{
	if (x < r->x || y < r->y || r->x + r->width < x || r->y + r->height < y)
		return (0);
	if (x - r->x < (float)1 || y - r->y < (float)1 || r->x + r->width - x < (float)1 || r->y + r->height - y < (float)1)
		return (2);
	return (1);
}

void	micro_paint(char **map, t_rect *rect)
{
	int ret;

	for (int i = 0; i < info.height; i++)
	{
		for (int j = 0; j < info.width; j++)
		{
			ret = is_in_rect(j, i, rect);
			if ((ret == 2 && rect->type == 'r') || (ret && rect->type == 'R'))
				map[i][j] = rect->rect_char;
		}
	}
}

void	map_print(char **map)
{
	for (int i = 0; i < info.height; i++)
	{
		for (int j = 0; j < info.width; j++)
		{
			write(1, &map[i][j], 1);
		}
		write(1, "\n", 1);
	}
}

int main(int argc, char **argv)
{
	t_rect rect;
	char **map;
	FILE *file;
	int	i, j, ret;
	
	if (argc != 2)
		return (argError());
	file = fopen(argv[1], "r");
	if (!file)
		return (fileError());
	if (fscanf(file, "%d %d %c\n", &info.width, &info.height, &info.bg_char) != 3)
		return (fileError());
	if (!(info.width <= 300 && info.width > 0 && info.height <= 300 && info.height > 0))
		return (fileError());
	map = malloc(sizeof(char *) * (info.height + 1));
	if (!map)
		return (1);
	for (i = 0; i < info.height; i++)
	{
		map[i] = malloc(info.width + 1);
		for (j = 0; j < info.width; j++)
		{
			map[i][j] = info.bg_char;
		}
		map[i][j] = 0;
	}
	map[i] = 0;

	while ((ret = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.width, &rect.height, &rect.rect_char)) == 6)
	{
		if (rect.width <= (float)0 || rect.height <= (float)0 || (rect.type == 'r' || rect.type == 'R'))
			return (fileError());
		micro_paint(map, &rect);
	}
	if (ret != -1)
		return (fileError());
	map_print(map);
	for (i = 0; i < info.height; i++)
		free(map[i]);
	free(map);
	fclose(file);
	return (0);
}