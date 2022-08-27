/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:51:12 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/28 00:38:42 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_stack *base)
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
//	print_stack(&a);
//	ft_printf("\n%i\n\n", ft_fetch(&a, -1)->value);
//	ft_float_element(&a, '\0', ft_fetch(&a, -1)->value);

	sort(&a, &b);
	print_stack(&a);
	ft_free(&a);
	return (0);
}
