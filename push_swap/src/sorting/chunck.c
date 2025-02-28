/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:57:03 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/27 15:57:57 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	chuncking(t_stack **a, t_stack **b, int end)
{
	int	start;

	start = 0;
	while (*a)
	{
		if ((*a)->index >= start && (*a)->index <= end)
		{
			pb(a, b);
			start++;
			end++;
		}
		else if ((*a)->index < start)
		{
			pb(a, b);
			rb(b);
			start++;
			end++;
		}
		else
			ra(a);
	}
}
