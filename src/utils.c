/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 04:30:23 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/28 02:57:41 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	binary_search(int *array, int size, int target)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (array[mid] == target)
			return (mid);
		else if (array[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (-1);
}

int	moves_to_top(t_stack *stack, int size, int element)
{
	t_node	*index;
	int	current;

	index = *stack;
	current = 0;
	while (index && index->value != element)
	{
		index = index->next;
		current++;
	}
	(void) size;
	if (current > (size / 2))
		current = -(size - current);
	return (current);
}

int	moves_to_bottom(t_stack *stack, int size, int element)
{
	int	*array;
	int	index;
	int	current;

	array = stack_to_array(stack, size);
	index = size;
	current = 0;
	while (--index >= 0)
	{
		if (array[index] == element)
			break ;
		current++;
	}
	(void) size;
	if (current > (size / 2))
		current = -(size - current);
	free(array);
	return (current);
}

void	push_non_lis_elements(t_info *info)
{
	int	current_lis_size;

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
}
