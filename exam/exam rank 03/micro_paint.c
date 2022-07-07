#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void ft_putstr(char *str)
{
	int len = ft_strlen(str);
	write(1, str, len);
}

typedef struct s_info
{
	int map_width;
	int map_height;
	char map_char;
	char rect_type;
	float x;
	float y;
	float rect_width;
	float rect_height;
	char rect_char;
}	t_info;

int main(int argc, char **argv)
{
	FILE *file;
	char str[50];
	t_info info;
	if (argc != 2)
	{
		ft_putstr("Error: argument\n");
		return (1);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		ft_putstr("Error: Operation file corrupted\n");
		return (1);
	}
	int ret = fscanf(file, "%d %d %c\n", &info.map_width, &info.map_height, &info.map_char);
	printf("%d %d %c amount:%d\n", info.map_width, info.map_height, info.map_char, ret);
	ret = fscanf(file, "%c %f %f %f %f %c\n", &info.rect_type, &info.x, &info.y, &info.rect_width, &info.rect_height, &info.rect_char);
	printf("%c %f %f %f %f %c amount : %d\n", info.rect_type, info.x, info.y, info.rect_width, info.rect_height, info.rect_char, ret);
}
