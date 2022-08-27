/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:52:12 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/27 08:42:48 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void	npush(t_stack *a, t_stack *b, int order, int size)
{
	int	index;

	if (size < 0)
	{
		if (order)
			while (*b)
				push(b, a, 'a');
		else
			while (*a)
				push(a, b, 'b');
		return ;
	}
	index = -1;
	if (order)
		while (++index < size)
			push(b, a, 'a');
	else
		while (++index < size)
			push(a, b, 'b');
}*/

static void	small_sort(t_stack *stack, int id, int elements)
{
	int	max;

	if (!stack ||!*stack)
		return ;
	max = ft_stack_max(stack, elements);
	if ((*stack)->value == max)
		rotate(*stack, id);
	else if ((*stack)->next->value == max)
		reverse_rotate((*stack), id);
	if ((*stack)->value > (*stack)->next->value)
		swap(*stack, id);
}

static void	medium_sort(t_stack *a, t_stack *b, int size)
{

	if (!a || !*a)
		return ;
	while (!ft_is_stack_sorted(a, 0) && size > 3)
	{
		ft_float_element(a, size, 'a', ft_stack_min(a, -1));
		push(a, b, 'b');
		size--;
	}
	small_sort(a, 'a', -1);
	while (*b)
		push(b, a, 'a');
}

void	optimize_moves(t_moves *moves)
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
	moves->total = moves->ra + moves->rb + moves->rra + moves->rrb + moves->rr + moves->rrr;
}

void	ft_position(t_info *info, t_moves *moves, int element)
{
	int	index;
	int	max;
	int	size;

	moves->rb = moves_to_top(info->b, info->b_size, element);
	if (element > ft_fetch(info->a, -1)->value && element < (*(info->a))->value)
		return ;
	size = info->a_size;
	max = ft_stack_max(info->a, size);
	if (element > max)
	{
		moves->rra = moves_to_bottom(info->a, size, max);
		return ;
	}
	index = -1;
	while (++index < size / 2)
	{
		if (element > info->array[index] && element < info->array[index + 1])
		{
			moves->rra = moves_to_bottom(info->a, size, info->array[index]);
			return ;
		}
		else if (element > info->array[size - index - 2] && element < info->array[size - index - 1])
		{
			moves->rra = moves_to_bottom(info->a, size, info->array[size - index - 2]);
			return ;
		}
	}
}

void	compare_moves(t_moves *first, t_moves *second)
{
	if (first->total < second->total)
	{
		second->total = first->total;
		second->element = first->element;
		second->ra = first->ra;
		second->rb = first->rb;
		second->rr = first->rr;
		second->rra = first->rra;
		second->rrb = first->rrb;
		second->rrr = first->rrr;
	}
}

void	push_moves(t_info *info, t_moves *moves)
{
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
		reverse_rotate(*(info->a), 'b');
		moves->rra--;
	}
	push(info->b, info->a, 'a');
	info->a_size++;
	info->b_size--;
}

void	reset_moves(t_moves *moves, int element)
{
	moves->element = element;
	moves->ra = 0;
	moves->rb = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rr = 0;
	moves->rrr = 0;
}

void	sort_stacks(t_info *info)
{
	int	current_lis_size;
	int	index;
	t_moves	best;
	t_moves	moves;

	current_lis_size = info->a_size - info->lis_size;
	while (current_lis_size)
	{
		if (binary_search(info->lis,
				info->lis_size,
				(*(info->a))->value) < 0)
		{
			push(info->a, info->b, 'b');
			info->a_size--;
			info->b_size++;
			current_lis_size--;
		}
		else
			rotate(*(info->a), 'a');
	}
	info->b_array = stack_to_array(info->b, info->b_size);
	while (*(info->b))
	{
		index = -1;
		free(info->array);
		free(info->b_array);
		info->array = stack_to_array(info->a, info->a_size);
		info->b_array = stack_to_array(info->b, info->b_size);
		best.total = info->a_size;
		while (++index < info->b_size)
		{
			reset_moves(&moves, info->b_array[index]);
			ft_position(info, &moves, info->b_array[index]);
			optimize_moves(&moves);
			compare_moves(&moves, &best);
			if (!best.total)
				break ;
			reset_moves(&moves, info->b_array[info->b_size - index - 1]);
			ft_position(info, &moves, info->b_array[info->b_size - index - 1]);
			compare_moves(&moves, &best);
		}
		//print_stacks(info->a, info->b);
		push_moves(info, &best);
		//print_stacks(info->a, info->b);
	}
	ft_float_element(info->a, info->a_size, 'a', ft_stack_min(info->a, -1));
	//ft_printf("is sorted: %i\n", ft_is_stack_sorted(info->a, 0));
}

void	sort(t_stack *a, t_stack *b)
{
	t_info	info;

	if (!a || !*a)
		return ;
	info.a = a;
	info.b = b;
	info.a_size = ft_stack_size(a);
	info.b_size = 0;
	if (info.a_size <= 3)
		small_sort(a, 'a', -1);
	else if (info.a_size <= 5)
		medium_sort(a, b, info.a_size);
	else
	{
		info.temp = NULL;
		info.array = stack_to_array(a, info.a_size);
		info.temp = array_to_stack(info.array, info.a_size);

		ft_float_element(info.temp,
				info.a_size, 0,
				ft_stack_min(info.temp, -1));

		info.lis = ft_lis(stack_to_array(info.temp, info.a_size),
				info.a_size,
				&info.lis_size);

		ft_printf("LIS:\n");
		//print_array(info.lis, info.lis_size);

		sort_stacks(&info);

		//print_stacks(info.a, info.b);

		ft_printf("is sorted: %i\n", ft_is_stack_sorted(info.a, 0));

		free(info.array);
		ft_free(info.temp);
		free(info.temp);
	}
}
