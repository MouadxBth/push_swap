/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:59:16 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/02 19:59:21 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

long	ft_stack_min(t_stack *stack, int elements)
{
	t_node	*index;
	long	result;
	int		current;

	if (!stack || !*stack)
		return (-1);
	index = *stack;
	result = index->value;
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

long	ft_stack_max(t_stack *stack, int elements)
{
	t_node	*index;
	long	result;
	int		current;

	if (!stack || !*stack)
		return (-1);
	index = *stack;
	result = index->value;
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

t_node	*ft_stack_last(t_stack *stack)
{
	t_node	*index;

	if (!stack)
		return (NULL);
	index = *stack;
	while (index)
	{
		if (!index->next)
			return (index);
		index = index->next;
	}
	return (index);
}