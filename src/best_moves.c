/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:13:55 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/27 18:56:09 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_moves	*set_moves_to_bottom(t_info *info, t_moves *moves, int value)
{
	moves->rra = moves_to_bottom(info->a, info->a_size, value);
	return (moves);
}

static t_moves	*ft_position(t_info *info, t_moves *moves, int element)
{
	int	index;
	int	max;
	int	size;

	moves->rb = moves_to_top(info->b, info->b_size, element);
	if (element > ft_fetch(info->a, -1)->value && element < (*(info->a))->value)
		return (moves);
	size = info->a_size;
	max = ft_stack_max(info->a, size);
	if (element > max)
		return (set_moves_to_bottom(info, moves, max));
	index = -1;
	while (++index < size / 2)
	{
		if (element > info->array[index] && element < info->array[index + 1])
			return (set_moves_to_bottom(info, moves, info->array[index]));
		else if (element > info->array[size - index - 2] && element < info->array[size - index - 1])
			return (set_moves_to_bottom(info, moves, info->array[size - index - 2]));
	}
	return (moves);
}

static void	handle_rotates(t_moves *moves)
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

void	optimize_moves(t_moves *moves)
{
	handle_rotates(moves);
	moves->total = moves->ra + moves->rb + moves->rra
		+ moves->rrb + moves->rr + moves->rrr;
}

t_moves	*best_moves(t_info *info, int first, int second)
{
	t_moves	*a;
	t_moves	*b;

	a = create_moves(first);
	b = create_moves(second);
	ft_position(info, a, first);
	ft_position(info, b, second);
	optimize_moves(a);
	optimize_moves(b);
	return (compare_moves(a, b));
}
