/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:11:04 by lomoulin          #+#    #+#             */
/*   Updated: 2019/02/17 10:42:36 by lomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H
# include "ft_lib.h"
# define N 9

typedef struct {
	int solutions;
	int map[N][N];
}		t_result;

int		is_invalid_char(char c);

int		has_input_error(char **lines);

void	parse_map(char **lines, int map[N][N]);

int		is_map_invalid(int map[N][N]);

void	print_map(int map[N][N]);

int		is_square_safe(int map[N][N], int line, int col, int nb);

int		is_column_and_line_safe(int map[N][N], int line, int col, int nb);

int		solve(int map[N][N], int line, int col, t_result *result);

void	save_map(int map[N][N], t_result *result);
#endif
