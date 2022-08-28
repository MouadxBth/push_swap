/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:18:34 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/22 00:40:47 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chunk_size(t_stack *stack, int middle, int reverse)
{
	int	size;
	t_node	*index;

	if (!stack || !*stack || middle <= 0)
		return (0);
	size = 0;
	index = *stack;
	while (index)
	{
		if (!reverse && index->value < middle)
			size++;
		else if (reverse && index->value > middle)
			size++;
		index = index->next;
	}
	return (size);
}

t_chunk	*create_chunk(t_stack *stack, int middle)
{
	t_chunk	*chunk;

	if (!stack || !*stack || middle <= 0)
		return (NULL);
	chunk = (t_chunk *)malloc(sizeof(t_chunk));
	if (!chunk)
		return (NULL);
	chunk->size = ft_chunk_size(stack, middle, 0);
	chunk->middle = middle;
	chunk->elements = (int *)malloc(sizeof(int) * chunk->size);
	if (!chunk->elements)
		return (NULL);
	return (chunk);
}

void	count_chunks(t_info *info)
{
	int	chunks;
	float	index;
	float	chunk_size_step;

	chunks = 0;
	index = info->a_size / 2.0;
	chunk_size_step = index;
	while (index < info->a_size - 1)
	{
		chunks++;
		chunk_size_step /= 2;
		index += chunk_size_step;
	}
	info->chunk_count = chunks;
}

void	create_chunks(t_info *info)
{
	info->chunks = (t_chunk **)malloc(sizeof(t_chunk *) * info->chunk_count);
	if (!info->chunks)
		return ;
}

int	chunk_contains(t_chunk *chunk, int element)
{
	int	index;

	if (!chunk || element < 0)
		return (0);
	index = 0;
	while (index < chunk->size)
	{
		if (chunk->elements[index] == element)
			return (1);
		index++;
	}
	return (0);
}

void	free_chunks(t_info *info)
{
	int	index;

	index = 0;
	while (index < info->chunk_count)
	{
		free(info->chunks[index]->elements);
		free(info->chunks[index]);
		index++;
	}
	free(info->chunks);
}
