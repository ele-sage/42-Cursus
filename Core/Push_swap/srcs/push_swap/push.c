/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:36:46 by ele-sage          #+#    #+#             */
/*   Updated: 2023/03/22 17:28:43 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Push
void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
	}
}

// Push a - take the first element at the top of b and put it at the top of a.
// Do nothing if B is empty.
void	pa(t_stack **a, t_stack **b)
{
	write(1, "pa\n", 3);
	push(b, a);
}

// Push b - take the first element at the top of a and put it at the top of b.
// Do nothing if A is empty.
void	pb(t_stack **a, t_stack **b)
{
	write(1, "pb\n", 3);
	push(a, b);
}
