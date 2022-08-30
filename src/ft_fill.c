/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:10:26 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/30 21:38:25 by mbouthai         ###   ########.fr       */
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
	if (word[index] == '-' || word[index] == '+')
	{
		if (length < 2)
			return (0);
		index++;
	}
	while (index < length)
	{
		if (!ft_isdigit(word[index]))
			return (0);
		index++;
	}
	return (1);
}

static int	validate_input(char *str)
{
	int	misc;
	int	index;

	misc = 0;
	index = -1;
	while (str[++index])
	{
		if (!ft_isdigit(str[index]))
		{
			if (misc > 1)
				return (0);
			misc++;
		}
		else
			misc = 0;
	}
	return (1);
}

static int	ft_fill_stack(t_stack *stack, char *input, char **elements)
{
	int	index;
	long	value;

	index = 0;
	while (elements[index])
		index++;
	while (--index >= 0)
	{
		if (!validate_input(input))
			return (0);
		if (!ft_isdigits(elements[index]))
			return (0);
		value = ft_atol(elements[index]);
		if (value > 0x7FFFFFFF || value < -2147483648)
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
	char	*result;
	int	index;

	if (!stack)
		return (0);
	if (argc < 1 || !argv)
		return (0);
	result = NULL;
	index = 0;
	while (++index < argc)
		result = ft_strjoin_del(result, argv[index], ' ');
	return (ft_fill_stack(stack, result, ft_split(result, ' ')));
}
