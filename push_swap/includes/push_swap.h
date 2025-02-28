/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:49:37 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/27 15:55:24 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4

# endif

typedef struct s_stack
{
	struct s_stack	*next;
	int				data;
	int				index;
}					t_stack;

typedef enum e_part
{
	bonus,
	mandatory
}	t_part;

t_stack	*lstnew(int content);
t_stack	*iteration(t_stack *head);
void	fail_push_swap(char *content, int status);
char	**parsing_args(int ac, char **av);
char	*get_next_line(int fd);
void	free_2d(char **str);
void	free_stack(t_stack **stack);
void	fail(t_stack **a, char *content, char **args);
void	stack_init(t_stack **a, char **args);
void	push_back(t_stack **head, int data);
int		lstsize(t_stack	*head);
void	assigning_indexes(t_stack **stack, int len);
int		is_only_spaces(char *str);
int		is_sorted(t_stack *stack, t_part part);
bool	long_length(const char *str);
bool	pa(t_stack **a, t_stack **b);
bool	pb(t_stack **a, t_stack **b);
bool	sa(t_stack **a);
bool	sb(t_stack **b);
bool	ss(t_stack **a, t_stack **b);
bool	ra(t_stack **a);
bool	rb(t_stack **b);
bool	rr(t_stack **a, t_stack **b);
bool	rra(t_stack **a);
bool	rrb(t_stack **b);
bool	rrr(t_stack **a, t_stack **b);
bool	swap(t_stack **stack);
bool	push(t_stack **from, t_stack **to);
bool	rotate(t_stack	**stack);
bool	reverse_rotate(t_stack **stack);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	shift_min_to_front(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	chuncking(t_stack **a, t_stack **b, int end);
void	algorithme(t_stack **a, t_stack **b);

#endif