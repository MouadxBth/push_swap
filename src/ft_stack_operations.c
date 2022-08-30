/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:14:43 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/28 06:37:23 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *first, t_stack *second, int id)
{
	ft_push(second, ft_pop(first));
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
