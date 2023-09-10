/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:38:15 by ele-sage          #+#    #+#             */
/*   Updated: 2023/03/22 17:30:59 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Check if the string is a duplicate.
static int	ft_isduplicate(t_stack *stack, int nb)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->data == nb)
		{
			free_stack(&stack);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

// Create a new node.
static t_stack	*ft_newnode(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = nb;
	new->index = 0;
	new->pos = -1;
	new->target = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

// Add a new node at the end of the stack.
static void	ft_addnode(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!tmp)
		*stack = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

// Create the stack a.
static t_stack	*ft_createstack(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;
	int		nb;

	stack = NULL;
	i = 0;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
		{
			free_stack(&stack);
			return (NULL);
		}
		nb = ft_atoi(argv[i]);
		if (ft_isduplicate(stack, nb))
			return (NULL);
		new = ft_newnode(nb);
		if (!new)
			return (NULL);
		ft_addnode(&stack, new);
		i++;
	}
	return (stack);
}

// Parse the arguments and create the stack a.
t_stack	*parse(int argc, char **argv)
{
	t_stack	*stack;
	int		split;

	split = 0;
	if (argc < 2)
		return (NULL);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (NULL);
		split = 1;
		argc = ft_splitlen(argv);
	}
	else
	{
		argv++;
		argc--;
	}
	stack = ft_createstack(argc, argv);
	if (!stack)
		free_stack(&stack);
	if (split)
		ft_free_split(argv);
	return (stack);
}
