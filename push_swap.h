/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:09:56 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/10 18:54:13 by tkubanyc         ###   ########.fr       */
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
	struct s_stack	*prev;
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
int		count_elements(t_stack *stack);
int		is_sorted(t_stack *stack);
int		last_value(t_stack *stack);

#endif
