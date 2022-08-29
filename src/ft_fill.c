/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:10:26 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/28 21:26:37 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (argc < 1 || !argv)
		return (0);
	while (--argc)
		if (!ft_fill_stack(stack, ft_split(argv[argc], ' ')))
			return (0);
	return (1);
}
