/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:50:46 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/16 19:14:31 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*create_array(int *array, int start, int length)
{
	int	*result;
	int	index;

	result = (int *)malloc(sizeof(int) * length);
	if (!result)
		return (NULL);
	index = -1;
	while (++index < length)
		result[index] = array[index + start];
	return (result;
}

static void	merge(int *array, int start, int middle, int end)
{
	int	*left;
	int	*right;
	int	i;
	int	j;

	left = create_array(array, start, middle - start + 1);
	right = create_array(array, middle + 1, end - start);
	i = 0;
	j = 0;
	while (i < (middle - start + 1) && j < (end - start))
	{
		if (left[i] <= right[j])
			array[start] = left[i++];
		else
			array[start] = right[j++];
		start++;
	}
	while (i < (middle - start + 1))
		array[start++] = left[i++];
	while (j < (end - start))
		array[start++] = right[j++];
	free(left);
	free(right);
}

void	merge_sort(int *array, int start, int end)
{
	int	middle;

	if (end <= start)
		return ;
	middle = start + (end - start) / 2;
	merge_sort(array, start, middle);
	merge_sort(array, middle + 1, end);
	merge(array, start, middle, end);
}
