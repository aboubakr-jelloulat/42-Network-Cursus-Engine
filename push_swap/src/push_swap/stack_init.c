/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:07:03 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/27 15:31:00 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	curr = *stack;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	*stack = NULL;
}

void	fail(t_stack **a, char *content, char **args)
{
	free_2d(args);
	free_stack(a);
	fail_push_swap(content, 1);
}

static bool	check_digits(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (!str[i + 1] || !ft_isdigit(str[i + 1]))
			return (false);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	check_duplicate(t_stack *stack, int nb)
{
	if (!stack)
		return (true);
	while (stack)
	{
		if (stack->data == nb)
		{
			return (false);
		}
		stack = stack->next;
	}
	return (true);
}

void	stack_init(t_stack **a, char **args)
{
	int		i;
	long	nb;

	i = 0;
	while (args[i])
	{
		if (!check_digits(args[i]))
		{
			fail(a, "Error", args);
		}
		if (!long_length(args[i]))
			fail(a, "Error", args);
		nb = ft_atol(args[i]);
		if (nb > INT_MAX || nb < INT_MIN)
		{
			fail(a, "Error", args);
		}
		if (!check_duplicate(*a, (int)nb))
			fail(a, "Error", args);
		push_back(a, (int)nb);
		i++;
	}
}
