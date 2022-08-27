/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:21:41 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/24 23:34:16 by mbouthai         ###   ########.fr       */
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
	int	result;
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

static int	ft_isdigits(char *word)
{
	size_t	length;
	size_t	index;

	if (!word)
		return (0);
	length = ft_strlen(word);
	index = 0;
	while (index < length)
	{
		if (!ft_isdigit(word[index]))
			return (0);
		index++;
	}
	return (1);
}

static int	ft_fill_stack(t_stack *stack, char **elements)
{
	int	index;
	int	value;

	index = 0;
	while (elements[index])
		index++;
	while (--index >= 0)
	{
		if (!ft_isdigits(elements[index]))
			return (0);
		value = ft_atoi(elements[index]);
		if (value < 0)
			return (0);
		if (ft_fetch(stack, value))
			return (0);
		ft_push(stack, value);
	}
	index = -1;
	while (elements[++index])
		free(elements[index]);
	free(elements);
	return (1);
}

int	ft_fill(t_stack *stack, int argc, char **argv)
{
	if (!stack)
		return (0);
	if (argc <= 1 || !argv)
		return (0);
	while (--argc > 0)
		if (!ft_fill_stack(stack, ft_split(argv[argc], ' ')))
			return (0);
	return (1);
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
	t_node	*temp;

	if (!stack || !*stack)
		return (NULL); 
	index = *stack;
	while (index)
	{
		if (index->value == value)
			return (index);
		if (!index->next)
			temp = index;
		index = index->next;
	}
	if (value == -1)
		return (temp);
	return (NULL);
}
