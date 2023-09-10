/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:29:12 by ele-sage          #+#    #+#             */
/*   Updated: 2023/09/04 21:30:09 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				index;
	int				data;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

int *sort_array(t_stack *stack);

t_stack				*parse(int argc, char **argv);
void				set_index(t_stack *stack_a, int stack_size);
int					is_sorted(t_stack *stack);
int					stack_size(t_stack *stack);
t_stack				*get_last(t_stack *stack);
t_stack				*get_second_last(t_stack *stack);
int					ft_isnumber(char *str);
void				free_stack(t_stack **stack);
void				print_stacks(t_stack *stack, t_stack *stack2);

void				get_target_position(t_stack **a, t_stack **b);
int					get_lowest_index_position(t_stack **stack);
void				get_cost(t_stack **stack_a, t_stack **stack_b);
void				do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void				do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
int					*mid_point(t_stack *stack);

void				sort_2(t_stack **a);
void				sort_3(t_stack **a);
void				sort_10_or_less(t_stack **a, t_stack **b);
void				sort(t_stack **a, t_stack **b);

void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

void				push(t_stack **src, t_stack **dst);
void				swap(t_stack *stack);
void				rotate(t_stack **stack);
void				rev_rotate(t_stack **stack);

void				execute_instructions(t_stack **stack_a, t_stack **stack_b);
void				exit_error(t_stack **stack_a, t_stack **stack_b);
#endif