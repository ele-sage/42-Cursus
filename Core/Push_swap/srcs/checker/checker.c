/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:59:39 by ele-sage          #+#    #+#             */
/*   Updated: 2023/03/22 18:28:07 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	stack_a = parse(ac, av);
	stack_b = NULL;
	if (!stack_a)
		exit_error(&stack_a, &stack_b);
	execute_instructions(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
