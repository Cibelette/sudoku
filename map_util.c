/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:44:11 by lomoulin          #+#    #+#             */
/*   Updated: 2019/02/17 01:01:04 by lomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		is_invalid_char(char c)
{
	if ((c < '0' && c > '9') && (c != '.'))
		return (1);
	return (0);
}

int		has_input_error(char **lines)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < N)
	{
		j = 0;
		if (ft_strlen(lines[i + 1]) != 9)
			return (1);
		while (j < 9)
		{
			c = lines[i + 1][j];
			if ((c < '0' && c > '9') && (c != '.'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	parse_map(char **lines, int map[N][N])
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (lines[i + 1][j] == '.')
				map[i][j] = 0;
			else
				map[i][j] = lines[i + 1][j] - 48;
			j++;
		}
		i++;
	}
}

int		is_map_invalid(int map[N][N])
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (map[i][j] != 0 && !is_square_safe(map, i, j, map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	print_map(int map[N][N])
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			ft_putchar('0' + map[i][j]);
			if (j < N - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
