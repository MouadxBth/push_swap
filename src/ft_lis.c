/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 04:13:41 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/28 06:44:34 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max_element(int *array, int size)
{
	int	index;
	int	result;

	index = -1;
	result = array[0];
	while (++index < size)
	{
		if (array[index] > result)
			result = array[index];
	}
	return (result);
}

static int	*ft_new_array(int size, int init)
{
	int	*result;
	int	index;

	result = (int *) malloc(sizeof(int) * size);
	if (!result)
		return (NULL);
	index = -1;
	while (++index < size)
		result[index] = init;
	return (result);
}

static int	*ft_lis_sizes(int *array, int size)
{
	int	*result;
	int	i;
	int	j;

	result = ft_new_array(size, 1);
	i = size;
	while (--i >= 0)
	{
		j = i;
		while (++j < size)
		{
			if (array[i] < array[j])
			{
				if (result[i] > (1 + result[j]))
					result[i] = result[i];
				else
					result[i] = result[j] + 1;
			}
		}
	}
	return (result);
}

static int	get_smallest(t_lis *info, int element, int previous)
{
	int	index;
	int	result;

	index = -1;
	result = 0x7FFFFFFF;
	while (++index < info->size)
	{
		if (info->lis[index] == element
			&& info->array[index] < result
			&& info->array[index] > previous)
			result = info->array[index];
	}
	return (result);
}

int	*ft_lis(int *array, int size, int *lis_size)
{
	t_lis	info;
	int		*result;
	int		index;
	int		previous;

	if (!array || size <= 0 || !lis_size)
		return (NULL);
	info.array = array;
	info.size = size;
	info.lis = ft_lis_sizes(array, size);
	info.lis_size = ft_max_element(info.lis, size);
	result = ft_new_array(info.lis_size, -1);
	*lis_size = info.lis_size;
	index = -1;
	previous = -1;
	while (++index < info.lis_size)
	{
		result[index] = get_smallest(&info, info.lis_size - index, previous);
		previous = result[index];
	}
	free(info.lis);
	return (result);
}
