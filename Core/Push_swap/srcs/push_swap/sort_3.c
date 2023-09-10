/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:17:13 by ele-sage          #+#    #+#             */
/*   Updated: 2023/03/22 18:23:50 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Sort a stack of 2 or 3 numbers.
void	sort_2(t_stack **a)
{
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

// Find the highest index in a stack.
static int	find_highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

// Sort a stack of 3 numbers.
void	sort_3(t_stack **a)
{
	int	highest;

	if (is_sorted(*a))
		return ;
	highest = find_highest_index(*a);
	if ((*a)->index == highest)
		ra(a);
	else if ((*a)->next->index == highest)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}
