/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:13:24 by ele-sage          #+#    #+#             */
/*   Updated: 2023/09/04 20:11:59 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Get last element of the stack.
t_stack	*get_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/* get_stack_before_bottom:
*	Returns the second to last element of the stack.
*/
t_stack	*get_second_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

// Set the index of each number in the stack.
void	set_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->data == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->data > value && ptr->index == 0)
			{
				value = ptr->data;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

int	*mid_point(t_stack *stack)
{
	int		*array;
	float	mid;
	int		i;

	mid = stack_size(stack) / 2;
	i = 2;
	while (mid > 3)
	{
		i++;
		mid /= 2;
	}
	array = malloc(sizeof(int) * i);
	if (!array)
		return (NULL);
	mid = stack_size(stack) / 2;
	array[0] = i;
	i = 1;
	while (mid > 3)
	{
		array[i] = mid;
		i++;
		mid /= 2;
	}
	array[i] = mid;
	return (array);
}

// Print the stack.
void	print_stacks(t_stack *stack, t_stack *stack2)
{
	int	i;
	int	j;

	i = stack_size(stack);
	j = stack_size(stack2);
	while (i || j)
	{
		if (i)
		{
			ft_printf("%d %d", stack->data, stack->index);
			stack = stack->next;
			i--;
		}
		ft_printf("\t");
		if (j)
		{
			ft_printf("%d %d", stack2->data, stack2->index);
			stack2 = stack2->next;
			j--;
		}
		ft_printf("\n");
	}
	ft_printf("_\t_\na\tb\n");
}
// Exit with error.
void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}



int *sort_array(t_stack *stack)
{	
	t_stack *ptr;
	int *array;
	int size = stack_size(stack);
	array = malloc(sizeof(int) * stack_size(stack));
	if (!array)
		return (NULL);
	ptr = stack;
	// copy stack to array
	while (ptr)
	{
		array[--size] = ptr->data;
		ptr = ptr->next;
	}
	size = stack_size(stack);
	// sort array
	for (int i = 0; i < size; i++)
	{
		printf("i = %d\n", i);
		for (int j = 0; j < size - i -1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
				printf("swapped %d and %d\n", array[j], array[j+1]);
			}
		}
	}
	return (array);
}