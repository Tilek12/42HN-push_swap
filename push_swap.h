/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:09:56 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/14 18:33:43 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_own/libft.h"
# include "libft_own/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	input_handler(int argc, char **argv, t_stack **a);
int		count_numbers(char **str);
void	free_str(char **str);
long	ft_atol(char *str);
void	exit_failure(t_stack **stack);
void	exit_success(t_stack **stack);
void	free_stack(t_stack **stack);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **b, t_stack **a);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_a_and_b(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_a_and_b(t_stack **a, t_stack **b);
void	rev_rotate_a(t_stack **a);
void	rev_rotate_b(t_stack **b);
void	rev_rotate_a_and_b(t_stack **a, t_stack **b);
void	sorting(t_stack **a, t_stack **b);
void	sort_3_elements_in_a(t_stack **a);
void	sort_big_stack(t_stack **a, t_stack **b, int elements);
void	sort_small_stack(t_stack **a, t_stack **b, int elements);
int		is_element_closer_to_top(int index, int elements);
int		count_elements(t_stack *stack);
void	update_indexes(t_stack *stack);
int		is_sorted(t_stack *stack);
int		ft_sqrt(int n);
int		find_index_of_smallest(t_stack *stack);
int		find_value_of_smallest(t_stack *stack);
int		find_index_of_biggest(t_stack *stack);
int		find_value_of_biggest(t_stack *stack);
void	move_to_b(t_stack **a, t_stack **b, int elements);
void	move_to_a(t_stack **a, t_stack **b);

#endif
