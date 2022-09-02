/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:51:12 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/02 18:02:08 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_array(int *array, int size)
{
	int	index;

	index = -1;
	while (++index < size)
		ft_printf("%i ", array[index]);
}

void	print_stack(t_stack *stack)
{
	t_node	*index;

	index = *stack;
	while (index)
	{
		ft_printf("%i\n", index->value);
		index = index->next;
	}
}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;

	first = *a;
	second = *b;
	ft_printf("a\t\tb\n_\t\t_\n");
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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a = NULL;
	b = NULL;
	if (!ft_fill(&a, argc, argv))
	{
		ft_free(&a);
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	if (ft_is_stack_sorted(&a, 0))
	{
		ft_free(&a);
		return (0);
	}
	sort(&a, &b);
	ft_free(&a);
	return (0);
}
