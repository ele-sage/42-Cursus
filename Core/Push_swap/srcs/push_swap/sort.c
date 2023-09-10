/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:10:47 by ele-sage          #+#    #+#             */
/*   Updated: 2023/09/04 22:26:29 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Pushes the lowest half of the stack A to stack B
static int	push_half_low(t_stack **a, t_stack **b, int size)
{
	if ((*a)->index <= size)
	{
		pb(a, b);
		return (1);
	}
	else
	{
		ra(a);
		return (0);
	}
}

// Pushes the highest half of the stack B to stack A
static int	push_half_high(t_stack **a, t_stack **b, int size)
{
	if ((*b)->index >= size)
	{
		pa(a, b);
		return (1);
	}
	else
	{
		rb(b);
		return (0);
	}
}

// Pushes all lowest half of the stack A to stack B
static void	push_to_b(t_stack **a, t_stack **b)
{
	int	stacksize;
	int	pushed;
	int	*mid_points;
	int	i;

	stacksize = stack_size(*a);
	mid_points = mid_point(*a);
	if (!mid_points)
		return ;
	i = 1;
	while (i < mid_points[0])
	{
		pushed = 0;
		while (pushed < mid_points[i])
		{
			pushed += push_half_low(a, b, stacksize - mid_points[i]);
		}
		i++;
	}
	free(mid_points);
	while (*a)
		pb(a, b);
}

// Pushes all highest half of the stack B to stack A
static void	push_to_a(t_stack **a, t_stack **b)
{
	int	stacksize;
	int	pushed;
	int	*mid_points;
	int	i;

	stacksize = stack_size(*b);
	mid_points = mid_point(*b);
	if (!mid_points)
		return ;
	i = 1;
	while (i < mid_points[0])
	{
		pushed = 0;
		while (pushed < mid_points[i])
		{
			pushed += push_half_high(a, b, stacksize - mid_points[i]);
		}
		i++;
	}
	free(mid_points);
	while (*b)
		pa(a, b);
}

// Pushes all elements of the stack A to stack B
static void	push_all_on_b(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
		pb(a, b);
}

// Shifts the stack A to the lowest index element
static void	shift_stack(t_stack **a)
{
	int	lowest_pos;
	int	size;

	size = stack_size(*a);
	lowest_pos = get_lowest_index_position(a);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			rra(a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(a);
			lowest_pos--;
		}
	}
}

// Sort the stack for 10 or less elements
void	sort_10_or_less(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
		pb(a, b);
	sort_3(a);
	while (*b)
	{
		get_target_position(a, b);
		get_cost(a, b);
		do_cheapest_move(a, b);
	}
	if (!is_sorted(*a))
		shift_stack(a);
}

// Sort the stack for more than 10 elements
void	sort(t_stack **a, t_stack **b)
{
	push_to_b(a, b);
	push_to_a(a, b);
	push_all_on_b(a, b);
	sort_3(a);
	while (*b)
	{
		get_target_position(a, b);
		get_cost(a, b);
		do_cheapest_move(a, b);
	}
	if (!is_sorted(*a))
		shift_stack(a);
}
