/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:50:22 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/27 08:07:36 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct	s_node
{
	int		value;
	struct s_node	*next;
}	t_node;


typedef struct	s_chunk
{
	int	size;
	int	middle;
	int	*elements;
}	t_chunk;

typedef struct	s_moves
{
	int	element;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	total;
}	t_moves;

typedef struct	s_lis
{
	int	*array;
	int	*lis;
	int	size;
	int	lis_size;
}	t_lis;

typedef struct	s_info
{
	t_node	**a;
	t_node	**b;
	t_node	**temp;
	t_chunk	**chunks;
	int	a_size;
	int	b_size;
	int	*array;
	int	*b_array;
	int	*lis;
	int	lis_size;
}	t_info;

typedef t_node *t_stack;

int	ft_max(int a, int b);
int	ft_is_array_sorted(int *array, int size);

int	ft_push(t_stack *stack, int value);
int	ft_pop(t_stack *stack);
int	ft_fill(t_stack *stack, int argc, char **argv);
void	ft_free(t_stack *stack);
t_node	*ft_fetch(t_stack *stack, int value);

void	push(t_stack *first, t_stack *second, int id);
void	swap(t_node *node, int id);
void	rotate(t_node *node, int id);
void	reverse_rotate(t_node *node, int id);

int	ft_stack_size(t_stack *stack);
int	ft_stack_min(t_stack *stack, int elements);
int	ft_stack_max(t_stack *stack, int elements);
int	ft_is_stack_sorted(t_stack *stack, int reverse);

void	ft_float_element(t_stack *stack, int size, int id, int value);
void	ft_sink_element(t_stack *stack, int size, int id, int value);
int	*stack_to_array(t_stack *stack, int size);
t_stack	*array_to_stack(int *array, int size);

/*
int	ft_chunk_size(t_stack *stack, int middle, int reverse);
t_chunk	*create_chunk(t_stack *stack, int middle);
void	count_chunks(t_info *info);
void	create_chunks(t_info *info);
int	chunk_contains(t_chunk *chunk, int element);
void	free_chunks(t_info *info);*/

int	binary_search(int *array, int size, int target);

void	print_array(int *array, int size);

void	quick_sort(int *array, int start, int end);

int	*ft_lis(int *array, int size, int *lis_size);

void	sort(t_stack *a, t_stack *b);

int	moves_to_top(t_stack *stack, int size, int element);
int	moves_to_bottom(t_stack *stack, int size, int element);

#endif
