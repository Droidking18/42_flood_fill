/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 15:05:44 by dkaplan           #+#    #+#             */
/*   Updated: 2018/07/05 16:07:11 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "flood_fill.h"

void putc(char c)
{
	write(1, &c, 1);
}

char **tab_dup(char **tab, int h)
{
	int i;
	char **ret;

	i = 0;
	ret = malloc(sizeof(char*) * h);
	while (i < h)
	{
		ret[i] = strdup(tab[i]);
		i++;
	}
	return ret;
}

void print_tab(char **tab, t_point size)
{
	int x;
	int y;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			putc(tab[y][x]);
			putc(' ');
			x++;
		}
		putc('\n');
		y++;
	}
	putc('\n');
}

int main(void)
{
	t_point size = { 8, 5 };
	t_point begin = { 0, 0 };
	char *area[5];
	area[0] = "11111111";
	area[1] = "10001001";
	area[2] = "10010001";
	area[3] = "10010001";
	area[4] = "11100001";

	char **map = tab_dup(area, size.y);
	print_tab(map, size);
	flood_fill(map, size, begin);
	putc('\n');
	print_tab(map, size);
	return (0);
}
