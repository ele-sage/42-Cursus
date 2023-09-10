/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:33:35 by ele-sage          #+#    #+#             */
/*   Updated: 2023/03/22 17:30:04 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Swap
void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

// swap a - Swap the first 2 elements at the top of stack A.
// Do nothing if there is only one or no elements.
void	sa(t_stack **a)
{
	write(1, "sa\n", 3);
	swap(*a);
}

// swap b - Swap the first 2 elements at the top of stack B.
// Do nothing if there is only one or no elements.
void	sb(t_stack **b)
{
	write(1, "sb\n", 3);
	swap(*b);
}

// sa and sb at the same time.
void	ss(t_stack **a, t_stack **b)
{
	write(1, "ss\n", 3);
	swap(*a);
	swap(*b);
}
