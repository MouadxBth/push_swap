/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:14:43 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/27 19:18:41 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_move(char *action, t_stack *a, t_stack *b)
{
	if (ft_strlen(action) == 4)
	{
		if (ft_memcmp(action, "rra", 3) || ft_memcmp(action, "rrr", 3))
			reverse_rotate(*a, 0);
		if (ft_memcmp(action, "rrb", 3) || ft_memcmp(action, "rrr", 3))
			reverse_rotate(*b, 0);
		return ;
	}
	if (ft_memcmp(action, "sa", 2) || ft_memcmp(action, "ss", 2))
		swap(a, 0);
	if (ft_memcmp(action, "sb", 2) || ft_memcmp(action, "ss", 2))
		swap(b, 0);
	if (ft_memcmp(action, "pa", 2))
		push(b, a, 0);
	if (ft_memcmp(action, "pb", 2))
		push(a, b, 0);
	if (ft_memcmp(action, "ra", 2) || ft_memcmp(action, "rr", 2))
		rotate(*a, 0);
	if (ft_memcmp(action, "rb", 2) || ft_memcmp(action, "rr", 2))
		rotate(*b, 0);
}

bool	is_action(char *s)
{
	return (ft_memcmp(s, "sa", 2) || ft_memcmp(s, "ss", 2)
		|| ft_memcmp(s, "sb", 2) || ft_memcmp(s, "ra", 2)
		|| ft_memcmp(s, "rb", 2) || ft_memcmp(s, "rr", 2)
		|| ft_memcmp(s, "pb", 2) || ft_memcmp(s, "pa", 2)
		|| ft_memcmp(s, "rra", 3) || ft_memcmp(s, "rrb", 3)
		|| ft_memcmp(s, "rrr", 3));
}

void	apply_actions(t_stack *a, t_stack *b)
{
	char	*action;

	while (true)
	{
		action = get_next_line(0);
		if (!action)
			break ;
		if (!is_action(action))
		{
			print("Error");
			free(action);
			exit(0);
		}
		execute_action(action, a, b);
		free(action);
	}
}
