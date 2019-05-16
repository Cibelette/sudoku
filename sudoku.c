/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 17:09:23 by lomoulin          #+#    #+#             */
/*   Updated: 2019/02/17 02:03:19 by lomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		is_square_safe(int map[N][N], int line, int col, int nb)
{
	int i;
	int j;
	int max_i;
	int max_j;

	if (!is_column_and_line_safe(map, line, col, nb))
		return (0);
	i = (line / 3) * 3;
	j = (col / 3) * 3;
	max_i = i + 3;
	max_j = j + 3;
	while (i < max_i)
	{
		j = (col / 3) * 3;
		while (j < max_j)
		{
			if (i != line && j != col && map[i][j] == nb)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		is_column_and_line_safe(int map[N][N], int line, int col, int nb)
{
	int i;

	i = 0;
	while (i < N)
	{
		if (i != col && map[line][i] == nb)
			return (0);
		if (i != line && map[i][col] == nb)
			return (0);
		i++;
	}
	return (1);
}

int		solve(int map[N][N], int line, int col, t_result *result)
{
	int nb;

	nb = 0;
	if (line == N)
	{
		if (result->solutions == 0)
			save_map(map, result);
		result->solutions++;
		if (result->solutions > 1)
			return (1);
	}
	else if (map[line][col] != 0 && col < N)
		return (solve(map, line, col + 1, result));
	else if (col == N)
		return (solve(map, line + 1, 0, result));
	else
		while (++nb <= N)
			if (is_square_safe(map, line, col, nb))
			{
				map[line][col] = nb;
				if (solve(map, line, col + 1, result))
					return (1);
				map[line][col] = 0;
			}
	return (0);
}

void	save_map(int map[N][N], t_result *result)
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			result->map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
}
