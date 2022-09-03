/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_mutate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:54:44 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/02 19:54:53 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_element_index(t_stack *stack, int element)
{
	int		result;
	t_node	*index;

	if (!stack || !*stack)
		return (-1);
	result = 0;
	index = *stack;
	while (index)
	{
		if (index->value == element)
			return (result);
		index = index->next;
		result++;
	}
	return (-1);
}

void	ft_float_element(t_stack *stack, int size, int id, int value)
{
	int	element_index;

	element_index = ft_element_index(stack, value);
	while ((*stack)->value != value)
	{
		if (element_index > size / 2)
		{
			reverse_rotate(*stack, id);
			element_index++;
		}
		else
		{
			rotate(*stack, id);
			element_index--;
		}
	}
}

int	*ft_stack_to_array(t_stack *stack, int size)
{
	int		*result;
	int		r_index;
	t_node	*s_index;

	result = (int *)malloc(sizeof(int) * size);
	if (!result)
		return (NULL);
	r_index = 0;
	s_index = *stack;
	while (s_index)
	{
		result[r_index] = s_index->value;
		r_index++;
		s_index = s_index->next;
	}
	return (result);
}

t_stack	*ft_array_to_stack(int *array, int size)
{
	t_stack	*result;
	int		index;

	result = (t_stack *)malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	*result = NULL;
	index = size;
	while (--index >= 0)
		ft_push(result, array[index]);
	return (result);
}