/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:50:22 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/02 18:29:12 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_moves
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

typedef struct s_lis
{
	int	*array;
	int	*lis;
	int	size;
	int	lis_size;
}	t_lis;

typedef struct s_info
{
	t_node	**a;
	t_node	**b;
	int		*array;
	int		*b_array;
	int		*lis;
	int		a_size;
	int		b_size;
	int		lis_size;
}	t_info;

typedef t_node	*t_stack;

int		ft_moves_to_top(t_stack *stack, int size, int element);
int		ft_moves_to_bottom(t_stack *stack, int size, int element);
void	ft_push_non_lis_elements(t_info *info);

int		ft_stack_size(t_stack *stack);
long	ft_stack_min(t_stack *stack, int elements);
long	ft_stack_max(t_stack *stack, int elements);
int		ft_is_stack_sorted(t_stack *stack, int reverse);
t_node	*ft_stack_last(t_stack *stack);

int		*ft_lis(int *array, int size, int *lis_size);

t_moves	*create_moves(int element);
t_moves	*compare_moves(t_moves *first, t_moves *second);
void	push_moves(t_info *info, t_moves *moves);

t_moves	*ft_best_moves(t_info *info, int first, int second);

int		ft_push(t_stack *stack, int value);
int		ft_pop(t_stack *stack);
int		ft_fill(t_stack *stack, int argc, char **argv);
void	ft_free(t_stack *stack);
t_node	*ft_fetch(t_stack *stack, int value);

void	push(t_stack *first, t_stack *second, int id);
void	swap(t_node *node, int id);
void	rotate(t_node *node, int id);
void	reverse_rotate(t_node *node, int id);

void	ft_float_element(t_stack *stack, int size, int id, int value);
int		*ft_stack_to_array(t_stack *stack, int size);
t_stack	*ft_array_to_stack(int *array, int size);

void	sort(t_stack *a, t_stack *b);

#endif
