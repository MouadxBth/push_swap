/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 06:51:31 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/28 06:55:16 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_sort(t_stack *stack, int id, int elements)
{
	long	max;

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

static void	large_sort(t_info *info)
{
	int		index;
	t_moves	*current_best;
	t_moves	*best;

	ft_push_non_lis_elements(info);
	while (*(info->b))
	{
		index = -1;
		info->array = ft_stack_to_array(info->a, info->a_size);
		info->b_array = ft_stack_to_array(info->b, info->b_size);
		best = create_moves(-1);
		best->total = info->a_size;
		while (++index < info->b_size)
		{
			current_best = ft_best_moves(info, info->b_array[index],
					info->b_array[info->b_size - index - 1]);
			best = compare_moves(best, current_best);
		}
		free(info->array);
		free(info->b_array);
		push_moves(info, best);
		free(best);
	}
	ft_float_element(info->a, info->a_size, 'a', ft_stack_min(info->a, -1));
}

static void	generate_lis(t_info *info)
{
	t_stack	*temp;
	int		*temp_array;

	temp_array = ft_stack_to_array(info->a, info->a_size);
	temp = ft_array_to_stack(temp_array, info->a_size);
	ft_float_element(temp, info->a_size, 0, ft_stack_min(temp, -1));
	free(temp_array);
	temp_array = ft_stack_to_array(temp, info->a_size);
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
		large_sort(&info);
		free(info.lis);
	}
}
