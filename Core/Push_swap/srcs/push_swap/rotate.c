/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:20:38 by ele-sage          #+#    #+#             */
/*   Updated: 2023/03/22 17:28:58 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Rotate
void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tail = get_last(*stack);
		tmp->next = NULL;
		tail->next = tmp;
	}
}

// Rotate a - shift up all elements of stack a by 1. The first element becomes
// the last one.
void	ra(t_stack **a)
{
	write(1, "ra\n", 3);
	rotate(a);
}

// Rotate b - shift up all elements of stack b by 1. The first element becomes
// the last one.
void	rb(t_stack **b)
{
	write(1, "rb\n", 3);
	rotate(b);
}

// ra and rb at the same time.
void	rr(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	rotate(a);
	rotate(b);
}
