/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:52:12 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/25 04:03:55 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void	print_array(int *array, int length)
{
	int	index;

	index = -1;
	while (++index < length)
		printf("%i ", array[index]);
	printf("\n");
}*/

/*
static void	handle_stack_b(t_info *info)
{
	int	index;
	int	chunk_size;

	index = info->b_size;
	middle = 0;
	chunk_size = ft_chunk_size(info->b, middle);
	if (!chunk_size && (*(info->b))->value == middle)
		push(info->b, info->a, 'a');
	while (--index >= 0 && chunk_size > 0)
	{
		if ((*(info->b))->value > middle)
		{
			push(info->b, info->a, 'a');
			info->b_size--;
			chunk_size--;
		}
		else
			rotate(*(info->b), 'b');
	}
}*/

static void	npush(t_stack *a, t_stack *b, int order, int size)
{
	int	index;

	if (size < 0)
	{
		if (order)
			while (*b)
				push(b, a, 'a');
		else
			while (*a)
				push(a, b, 'b');
		return ;
	}
	index = -1;
	if (order)
		while (++index < size)
			push(b, a, 'a');
	else
		while (++index < size)
			push(a, b, 'b');
}

static void	small_sort(t_stack *stack, int id, int elements)
{
	int	max;

	if (!stack ||!*stack)
		return ;
	max = ft_stack_max(stack, elements);
	if ((*stack)->value == max)
		rotate(*stack, id);
	else if ((*stack)->next->value == max)
		reverse_rotate((*stack), id);
	if ((*stack)->value > (*stack)->next->value)
		swap(*stack, id);
}

static void	medium_sort(t_stack *a, t_stack *b, int size)
{

	if (!a || !*a)
		return ;
	while (!ft_is_stack_sorted(a, 0) && size > 3)
	{
		ft_float_element(a, size, 'a', ft_stack_min(a, -1));
		push(a, b, 'b');
		size--;
	}
	small_sort(a, 'a', -1);
	while (*b)
		push(b, a, 'a');
}

static void	calibrate_chunk(t_chunk *chunk)
{
	quick_sort(chunk->elements, 0, chunk->size - 1);
	chunk->middle = chunk->elements[chunk->size / 2];
}

static void	calibrate_chunks(t_info *info)
{
	int	index;

	index = 0;
	while (index < info->chunk_index)
	{
		calibrate_chunk(info->chunks[index]);
		index++;
	}
}

static void	print_stack(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;

	first = *a;
	second = *b;

	while (first || second)
	{
		if (first)
		{
			ft_printf("%i", first->value);
			first = first->next;
		}
		if (second)
		{
			ft_printf("\t\t%i", second->value);
			second = second->next;
		}
		ft_printf("\n");
	}
}

static void	handle_stack_a(t_info *info)
{
	int	index;
	int	element_index;
	t_chunk	*chunk;

	index = 0;
	element_index = 0;
	chunk = info->chunks[info->chunk_index];
	ft_printf("CHUNK SIZE: %i\nCHUNK MIDDLE: %i\n", chunk->size, chunk->middle);
	while (index < info->a_size && element_index < chunk->size)
	{
		if ((*(info->a))->value < chunk->middle)
		{
			chunk->elements[element_index] = (*(info->a))->value;
			push(info->a, info->b, 'b');
			info->a_size--;
			info->b_size++;
			element_index++;
		}
		else
			rotate(*(info->a), 'a');
	}
}

static void	handle_stack_b(t_info *info)
{
	int	element_index;
	int	chunk_size;
	int	chunk_reverse_size;
	int	rrb;
	t_chunk	*chunk;

	chunk = info->chunks[info->chunk_index];
	if (chunk->size == 1 && chunk->elements[0] == (*(info->b))->value)
	{
		push(info->b, info->a, 'a');
		return ;
	}
	element_index = 0;
	chunk_size = chunk->size;
	chunk_reverse_size = ft_chunk_size(info->b, chunk->middle, 1);
	rrb = 0;
	while (element_index < chunk_size)
	{
		if (chunk->size < 3)
		{
			while (rrb > 0 && info->chunk_index > 0)
			{
				reverse_rotate(*(info->b), 'b');
				rrb--;
			}

			if ((*(info->b))->value < (*(info->b))->next->value)
				swap(*(info->b), 'b');
			npush(info->a, info->b, 1, chunk->size);
			break ;
		}
		if (element_index >= chunk_reverse_size)
		{
			calibrate_chunk(chunk);
		}
		if ((*(info->b))->value > chunk->middle)
		{
			push(info->b, info->a, 'a');
			info->b_size--;
			chunk->size--;
			element_index++;
			while (rrb > 0 && info->chunk_index > 0)
			{
				reverse_rotate(*(info->b), 'b');
				rrb--;
			}
		}
		else if (ft_fetch(info->b, -1)->value > chunk->middle)
			reverse_rotate(*(info->b), 'b');
		else
		{
			rotate(*(info->b), 'b');
			rrb++;
		}
	}
}

static void	mid_point(t_info *info)
{
	float	chunk_middle_index;
	float	chunk_size_step;

	chunk_middle_index = info->a_size / 2;
	chunk_size_step = chunk_middle_index;
	while (info->chunk_index < info->chunk_count)
	{
		info->chunks[info->chunk_index] = create_chunk(info->a, info->array[(int)(chunk_middle_index)]);
		handle_stack_a(info);
		info->chunk_index++;
		chunk_size_step /= 2;
		chunk_middle_index += chunk_size_step;
		ft_printf("STACK A:\t STACK B:\n");
		print_stack(info->a, info->b);
		ft_printf("--------------------------------------------------\n");
	}
	if (!ft_is_stack_sorted(info->a, 0))
		small_sort(info->a, 'a', -1);
	if (ft_is_stack_sorted(info->b, 1))
	{
		npush(info->a, info->b, 1, -1);
		return ;
	}
	calibrate_chunks(info);
	while (--info->chunk_index >= 0)
	{
		handle_stack_b(info);
		ft_printf("--------------------------------------------------\n");
	}
}
static void	print_stacky(t_stack *base)
{
	t_node	*temp;

	if (!base)
		return ;
	if (!*base)
		return ;
	temp = *base;
	while (temp)
	{
		printf("%-3i\n", temp->value);
		temp = temp->next;
	}
}

void	sort(t_stack *a, t_stack *b)
{
	t_info	info;

	if (!a || !*a)
		return ;
	info.a = a;
	info.b = b;
	info.a_size = ft_stack_size(a);
	info.b_size = 0;
	if (info.a_size <= 3)
		small_sort(a, 'a', -1);
	else if (info.a_size <= 5)
		medium_sort(a, b, info.a_size);
	else
	{
		info.temp = NULL;
		info.array = stack_to_array(a, info.a_size);
		info.temp = array_to_stack(info.array, info.a_size);
		ft_printf("MIN: %i\n", ft_stack_min(info.temp, -1));
		print_stacky(info.temp);
		ft_printf("----------\n");
		ft_float_element(info.temp, info.a_size, 0, ft_stack_min(info.temp, - 1));
		print_stacky(info.temp);
		//quick_sort(info.array, 0, info.a_size - 1);
		//count_chunks(&info);
		//create_chunks(&info);
		mid_point(&info);
		//free_chunks(&info);
		free(info.array);
		ft_free(info.temp);
	}
}
