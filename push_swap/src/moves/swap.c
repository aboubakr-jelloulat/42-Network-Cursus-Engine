/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:16:37 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/11 12:09:27 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	swap(t_stack **stack)
{
	t_stack	*st;
	t_stack	*nd;

	if (!stack || !*stack || !(*stack)->next)
		return (false);
	st = *stack;
	nd = (*stack)->next;
	st->next = nd->next;
	nd->next = st;
	*stack = nd;
	return (true);
}

bool	sa(t_stack **a)
{
	if (!swap(a))
		return (false);
	ft_putendl_fd("sa", 1);
	return (true);
}

bool	sb(t_stack **b)
{
	if (!swap(b))
		return (false);
	ft_putendl_fd("sb", 1);
	return (true);
}

bool	ss(t_stack **a, t_stack **b)
{
	if (!swap(a) || !swap(b))
		return (false);
	ft_putendl_fd("ss", 1);
	return (true);
}
