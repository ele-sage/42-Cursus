/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:10:21 by ele-sage          #+#    #+#             */
/*   Updated: 2023/03/22 18:27:52 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Does the instruction given in the line.
// Either swap or push.
static int	push_swap_instruction(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line, "sa", 2))
		swap(*a);
	else if (!ft_strncmp(line, "sb", 2))
		swap(*b);
	else if (!ft_strncmp(line, "ss", 2))
	{
		swap(*a);
		swap(*b);
	}
	else if (!ft_strncmp(line, "pa", 2))
		push(b, a);
	else if (!ft_strncmp(line, "pb", 2))
		push(a, b);
	return (1);
}

// Does the instruction given in the line.
// Either rotate or reverse rotate.
static int	rotate_instruction(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line, "rra", 3))
		rev_rotate(a);
	else if (!ft_strncmp(line, "rrb", 3))
		rev_rotate(b);
	else if (!ft_strncmp(line, "rrr", 3))
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else if (!ft_strncmp(line, "ra", 2))
		rotate(a);
	else if (!ft_strncmp(line, "rb", 2))
		rotate(b);
	else if (!ft_strncmp(line, "rr", 2))
	{
		rotate(a);
		rotate(b);
	}
	return (1);
}

// Execute the instruction.
static int	execute_instruction(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line, "sa", 2) || !ft_strncmp(line, "sb", 2)
		|| !ft_strncmp(line, "ss", 2) || !ft_strncmp(line, "pa", 2)
		|| !ft_strncmp(line, "pb", 2))
		return (push_swap_instruction(line, a, b));
	else if (!ft_strncmp(line, "rra", 3) || !ft_strncmp(line, "rrb", 3)
		|| !ft_strncmp(line, "rrr", 3) || !ft_strncmp(line, "ra", 2)
		|| !ft_strncmp(line, "rb", 2) || !ft_strncmp(line, "rr", 2))
		return (rotate_instruction(line, a, b));
	else
		return (0);
}

// Execute the instructions given by the user.
void	execute_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
		{
			free(line);
			break ;
		}
		if (!execute_instruction(line, a, b))
		{
			free(line);
			exit_error(a, b);
		}
		free(line);
	}
}
