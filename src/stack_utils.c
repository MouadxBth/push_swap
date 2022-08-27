/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:24:51 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/24 06:28:07 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	t_node	*index;
	int		size;

	if (!stack || !*stack)
		return (0);
	index = *stack;
	size = 0;
	while (index)
	{
		index = index->next;
		size++;
	}
	return (size);
}

int	ft_stack_min(t_stack *stack, int elements)
{
	t_node	*index;
	int		result;
	int		current;

	if (!stack || !*stack)
		return (-1);
	index = *stack;
	result = (*stack)->value;
	current = 0;
	while (index)
	{
		if (elements > 0 && current >= elements)
			break ;
		if (index->value < result)
			result = index->value;
		index = index->next;
		if (current >= 0)
			current++;
	}
	return (result);
}

int	ft_stack_max(t_stack *stack, int elements)
{
	t_node	*index;
	int		result;
	int		current;

	if (!stack || !*stack)
		return (-1);
	index = *stack;
	result = 0;
	current = 0;
	while (index)
	{
		if (elements > 0 && current >= elements)
			break ;
		if (index->value > result)
			result = index->value;
		index = index->next;
		if (current >= 0)
			current++;
	}
	return (result);
}

int	ft_is_stack_sorted(t_stack *stack, int reverse)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !*stack || !(*stack)->next)
		return (1);
	current = *stack;
	next = current->next;
	while (current)
	{
		if (!reverse && current->value > next->value)
			return (0);
		else if (reverse && current->value < next->value)
			return (0);
		current = current->next;
		next = next->next;
		if (!next)
			return (1);
	}
	return (1);
}
