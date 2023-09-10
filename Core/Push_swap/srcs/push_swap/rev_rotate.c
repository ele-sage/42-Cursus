/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:21:03 by ele-sage          #+#    #+#             */
/*   Updated: 2023/03/22 17:28:51 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Reverse rotate
void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*new_tail;

	if (*stack && (*stack)->next)
	{
		tail = get_last(*stack);
		new_tail = get_second_last(*stack);
		tmp = *stack;
		*stack = tail;
		(*stack)->next = tmp;
		new_tail->next = NULL;
	}
}

// Reverse rotate a - shift down all elements of stack A by 1.
// The last element becomes the first one.
void	rra(t_stack **a)
{
	write(1, "rra\n", 4);
	rev_rotate(a);
}

// Reverse rotate b - shift down all elements of stack B by 1.
// The last element becomes the first one.
void	rrb(t_stack **b)
{
	write(1, "rrb\n", 4);
	rev_rotate(b);
}

// rra and rrb at the same time.
void	rrr(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 4);
	rev_rotate(a);
	rev_rotate(b);
}
