/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:51:12 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/02 18:28:55 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
