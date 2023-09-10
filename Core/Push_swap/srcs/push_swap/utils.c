/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:13:01 by ele-sage          #+#    #+#             */
/*   Updated: 2023/03/28 15:29:03 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Check if the stack is sorted.
int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// Check stack size.
int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	number_in_range(char *str)
{
	if (str[0] == '-')
		return (ft_strncmp(str, "-2147483648", 11) <= 0);
	else if (ft_strlen(str) == 10)
		return (ft_strncmp(str, "2147483647", 10) <= 0);
	return (0);
}

// Check if the string is a number.
int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!str[i] || ft_strlen(str) > 11)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i == 10 || i == 11)
		return (number_in_range(str));
	return (1);
}

// free the stack.
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
