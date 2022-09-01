/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:21:41 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/01 12:45:04 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_stack *stack, int value)
{
	t_node	*new_element;

	new_element = (t_node *)malloc(sizeof(t_node));
	if (!new_element)
		return (0);
	new_element->value = value;
	if (!stack)
	{
		new_element->next = NULL;
		stack = &new_element;
	}
	else
	{
		new_element->next = *stack;
		*stack = new_element;
	}
	return (1);
}

int	ft_pop(t_stack *stack)
{
	int		result;
	t_node	*temp;

	if (!stack)
		return (-1);
	if (!*stack)
		return (-1);
	result = (*stack)->value;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	return (result);
}

void	ft_free(t_stack *stack)
{
	t_node	*index;
	t_node	*temp;

	if (!stack)
		return ;
	if (!*stack)
		return ;
	index = *stack;
	while (index)
	{
		temp = index;
		index = index->next;
		free(temp);
	}
}

t_node	*ft_fetch(t_stack *stack, int value)
{
	t_node	*index;

	if (!stack || !*stack)
		return (NULL);
	index = *stack;
	while (index)
	{
		if (index->value == value)
			return (index);
		index = index->next;
	}
	return (NULL);
}
