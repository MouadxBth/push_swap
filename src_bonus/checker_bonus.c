/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:52:07 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/02 20:51:12 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_operation(char *s)
{
	return (!ft_strncmp(s, "sa", 2) || !ft_strncmp(s, "sb", 2)
		|| !ft_strncmp(s, "ss", 2) || !ft_strncmp(s, "pa", 2)
		|| !ft_strncmp(s, "pb", 2) || !ft_strncmp(s, "ra", 2)
		|| !ft_strncmp(s, "rb", 2) || !ft_strncmp(s, "rr", 2)
		|| !ft_strncmp(s, "rra", 3) || !ft_strncmp(s, "rrb", 3)
		|| !ft_strncmp(s, "rrr", 3));
}

void	execute_operation(t_stack *a, t_stack *b, char *operation)
{
	if (ft_strlen(operation) == 4)
	{
		if (!ft_strncmp(operation, "rra", 3)
			|| !ft_strncmp(operation, "rrr", 3))
			reverse_rotate(*a, 0);
		if (!ft_strncmp(operation, "rrb", 3)
			|| !ft_strncmp(operation, "rrr", 3))
			reverse_rotate(*b, 0);
		return ;
	}
	if (!ft_strncmp(operation, "sa", 2) || !ft_strncmp(operation, "ss", 2))
		swap(*a, 0);
	if (!ft_strncmp(operation, "sb", 2) || !ft_strncmp(operation, "ss", 2))
		swap(*b, 0);
	if (!ft_strncmp(operation, "ra", 2) || !ft_strncmp(operation, "rr", 2))
		rotate(*a, 0);
	if (!ft_strncmp(operation, "rb", 2) || !ft_strncmp(operation, "rr", 2))
		rotate(*b, 0);
	if (!ft_strncmp(operation, "pa", 2))
		push(b, a, 0);
	if (!ft_strncmp(operation, "pb", 2))
		push(a, b, 0);
}

int	execute_operations(t_stack *a, t_stack *b)
{
	char	*operation;

	while (1)
	{
		operation = get_next_line(0);
		if (!operation)
			return (1);
		if (!is_operation(operation))
		{
			ft_putendl_fd("Error", 2);
			free(operation);
			return (0);
		}
		execute_operation(a, b, operation);
		free(operation);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!ft_fill(&a, argc, argv))
	{
		ft_free(&a);
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if (!execute_operations(&a, &b))
		return (ft_free(&a), ft_free(&b), 0);
	else
	{
		if (ft_is_stack_sorted(&a, 0))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 2);
	}
	ft_free(&a);
	ft_free(&b);
}
