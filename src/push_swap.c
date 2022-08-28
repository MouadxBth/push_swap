/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:51:12 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/28 02:58:11 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_array(int *array, int size)
{
	int	index;

	index = -1;
	while (++index < size)
		ft_printf("%i ", array[index]);
	ft_printf("\n");
}

void	print_stack(t_stack *base)
{
	t_node	*temp;

	if (!base)
		return ;
	if (!*base)
		return ;
	temp = *base;
	while (temp)
	{
		printf("%i\n", temp->value);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack b;

	a = NULL;
	b = NULL;
	if (!ft_fill(&a, argc, argv))
	{
		ft_free(&a);
		ft_printf("Error!\n");
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
