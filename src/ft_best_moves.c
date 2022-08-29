/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:40:20 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/28 17:07:30 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_correct_rotations(t_moves *moves)
{
	int	rra;
	int	rrb;

	rra = moves->rra;
	rrb = moves->rrb;
	if (moves->ra < 0)
	{
		moves->rra = -moves->ra;
		moves->ra = 0;
	}
	if (moves->rb < 0)
	{
		moves->rrb = -moves->rb;
		moves->rb = 0;
	}
	if (rra < 0)
	{
		moves->ra += -rra;
		moves->rra = 0;
	}
	if (rrb < 0)
	{
		moves->rb += -rrb;
		moves->rrb = 0;
	}
}

static void	ft_optimize_rotations(t_moves *moves)
{
	ft_correct_rotations(moves);
	while (moves->ra && moves->rb)
	{
		moves->rr++;
		moves->ra--;
		moves->rb--;
	}
	while (moves->rra && moves->rrb)
	{
		moves->rrr++;
		moves->rra--;
		moves->rrb--;
	}
}

static t_moves	*ft_optimize_moves(t_info *info, t_moves *moves, int value)
{
	moves->rra = ft_moves_to_bottom(info->a, info->a_size, value);
	ft_optimize_rotations(moves);
	moves->total = moves->ra + moves->rb + moves->rra
		+ moves->rrb + moves->rr + moves->rrr;
	return (moves);
}

static t_moves	*ft_correct_position(t_info *info, int element)
{
	t_moves	*moves;
	int		size;
	int		max;
	int		index;

	moves = create_moves(element);
	moves->rb = ft_moves_to_top(info->b, info->b_size, element);
	if (element > ft_fetch(info->a, -1)->value && element < (*(info->a))->value)
		return (ft_optimize_moves(info, moves, element));
	size = info->a_size;
	max = ft_stack_max(info->a, size);
	if (element > max)
		return (ft_optimize_moves(info, moves, max));
	index = -1;
	while (++index < size / 2)
	{
		if (element > info->array[index] && element < info->array[index + 1])
			return (ft_optimize_moves(info, moves, info->array[index]));
		else if (element > info->array[size - index - 2]
			&& element < info->array[size - index - 1])
			return (ft_optimize_moves(info, moves,
					info->array[size - index - 2]));
	}
	return (NULL);
}

t_moves	*ft_best_moves(t_info *info, int first, int second)
{
	t_moves	*a;
	t_moves	*b;

	a = ft_correct_position(info, first);
	b = ft_correct_position(info, second);
	return (compare_moves(a, b));
}
