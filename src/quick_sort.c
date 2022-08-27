/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:37:37 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/17 18:47:46 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int *array, int start, int end)
{
	int	pivot;
	int	result;
	
	pivot = array[end];
	result = start - 1;
	while (start < end)
	{
		if (array[start] < pivot)
		{
			result++;
			ft_swap(&array[start], &array[result]);
		}
		start++;
	}
	ft_swap(&array[result + 1], &array[end]);
	return (result + 1);
}

void	quick_sort(int *array, int start, int end)
{
	int	pivot;

	if (start >= end)
		return ;
	pivot = partition(array, start, end);
	quick_sort(array, start, pivot - 1);
	quick_sort(array, pivot + 1, end);
}
