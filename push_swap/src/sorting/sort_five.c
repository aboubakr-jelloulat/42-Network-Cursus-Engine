/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:11:00 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/06 12:16:03 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_five(t_stack **a, t_stack **b)
{
	shift_min_to_front(a);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
