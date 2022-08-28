/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:52:12 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/27 22:21:15 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	sort_stacks(t_info *info)
{
	int	index;
	t_moves	*current_best;
	t_moves	*best;

	push_non_lis_elements(info);
	while (*(info->b))
	{
		index = -1;
		info->array = stack_to_array(info->a, info->a_size);
		info->b_array = stack_to_array(info->b, info->b_size);
		best = create_moves(-1);
		best->total = info->a_size;
		while (++index < info->b_size)
		{
			current_best = best_moves(info, info->b_array[index], info->b_array[info->b_size - index - 1]);
			best = compare_moves(best, current_best);
		}
		free(info->array);
		free(info->b_array);
		push_moves(info, best);
		free(best);
	}
}

static void	generate_lis(t_info *info)
{
	t_stack	*temp;
	int	*temp_array;

	temp_array = stack_to_array(info->a, info->a_size);
	temp = array_to_stack(temp_array, info->a_size);
	ft_float_element(temp, info->a_size, 0, ft_stack_min(temp, -1));

	free(temp_array);
	temp_array = stack_to_array(temp, info->a_size);
	info->lis = ft_lis(temp_array, info->a_size, &info->lis_size);
	free(temp_array);
	ft_free(temp);
	free(temp);
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
		generate_lis(&info);
		sort_stacks(&info);
		ft_float_element(info.a, info.a_size, 'a', ft_stack_min(info.a, -1));
		free(info.lis);
	}
}
