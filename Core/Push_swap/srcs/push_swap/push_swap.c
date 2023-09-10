/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:26:20 by ele-sage          #+#    #+#             */
/*   Updated: 2023/09/04 22:08:37 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_all(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	set_index(*a, size);
	if (is_sorted(*a))
		return ;
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size <= 10)
		sort_10_or_less(a, b);
	else
		sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int *array;

	if (ac == 1)
		return (0);
	a = parse(ac, av);
	b = NULL;
	if (!a)
		exit_error(&a, &b);
	sort_all(&a, &b);
	free_stack(&a);
	return (0);
}
