/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:09:56 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/20 12:03:31 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				real_value;
	struct s_stack	*next;
}	t_stack;

void	input_handler(int argc, char **argv, t_stack **a);
void	update_stack_values(t_stack **stack, int elements);
int		is_number(char *str);
int		count_numbers(char **str);
void	free_str(char **str);
long	ft_atol(char *str);
void	exit_failure(t_stack **stack);
void	exit_success(t_stack **stack);
void	free_stack(t_stack **stack);
void	push(t_stack **dst, t_stack **src);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **b, t_stack **a);
void	swap(t_stack **stack);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_a_and_b(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_a_and_b(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **stack);
void	rev_rotate_a(t_stack **a);
void	rev_rotate_b(t_stack **b);
void	rev_rotate_a_and_b(t_stack **a, t_stack **b);
void	sorting(t_stack **a, t_stack **b);
int		ft_sqrt(int n);
int		count_elements(t_stack *stack);
void	update_indexes(t_stack *stack);
int		is_sorted(t_stack *stack);
void	sort_3_elements_in_a(t_stack **a);
void	sort_small_stack(t_stack **a, t_stack **b, int elements);
int		is_element_closer_to_top(int index, int elements);
int		find_index_of_smallest(t_stack *stack);
int		find_value_of_smallest(t_stack *stack);
void	sort_big_stack(t_stack **a, t_stack **b, int elements);

#endif
