/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:23:39 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/27 08:24:26 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *first, t_stack *second, int id)
{
	int	value;

	value = ft_pop(first);
	ft_push(second, value);
	//ft_printf("PUSHING: %i TO: %c\n", value, id);
	if (id)
		ft_printf("p%c\n", id);
}

void	swap(t_node *node, int id)
{
	int	temp;

	if (!node || !node->next)
		return ;
	temp = node->value;
	node->value = node->next->value;
	node->next->value = temp;
	if (id)
		ft_printf("s%c\n", id);
}

void	rotate(t_node *node, int id)
{
	if (!node || !node->next)
		return ;
	while (node)
	{
		swap(node, '\0');
		node = node->next;
	}
	if (id)
		ft_printf("r%c\n", id);
}

void	reverse_rotate(t_node *node, int id)
{
	if (!node || !node->next)
		return ;
	reverse_rotate(node->next, '\0');
	swap(node, '\0');
	if (id)
		ft_printf("rr%c\n", id);
}
