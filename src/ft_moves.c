/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:45:19 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/28 16:57:28 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*create_moves(int element)
{
	t_moves	*result;

	result = (t_moves *)malloc(sizeof(t_moves));
	if (!result)
		return (NULL);
	result->element = element;
	result->ra = 0;
	result->rb = 0;
	result->rra = 0;
	result->rrb = 0;
	result->rr = 0;
	result->rrr = 0;
	return (result);
}

t_moves	*compare_moves(t_moves *first, t_moves *second)
{
	if (first->total < second->total)
	{
		free(second);
		return (first);
	}
	free(first);
	return (second);
}

static void	helper(t_info *info, t_moves *moves)
{
	while (moves->rrr)
	{
		reverse_rotate(*(info->a), 0);
		reverse_rotate(*(info->b), 'r');
		moves->rrr--;
	}
	while (moves->rr)
	{
		rotate(*(info->a), 0);
		rotate(*(info->b), 'r');
		moves->rr--;
	}
}

void	push_moves(t_info *info, t_moves *moves)
{
	helper(info, moves);
	while (moves->rb)
	{
		rotate(*(info->b), 'b');
		moves->rb--;
	}
	while (moves->rrb)
	{
		reverse_rotate(*(info->b), 'b');
		moves->rrb--;
	}
	while (moves->ra)
	{
		rotate(*(info->a), 'a');
		moves->ra--;
	}
	while (moves->rra)
	{
		reverse_rotate(*(info->a), 'a');
		moves->rra--;
	}
	push(info->b, info->a, 'a');
	info->a_size++;
	info->b_size--;
}
