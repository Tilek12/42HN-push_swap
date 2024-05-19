/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:26:28 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/17 20:12:02 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*----------------------------------------------*/
/*  Reverse rotate operation:                   */
/*  Shift down all elements of the stack by 1.  */
/*  The last element becomes the first one.     */
/*----------------------------------------------*/
void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	int		index_of_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	index_of_last = last->index;
	last->next = *stack;
	*stack = last;
	while (last->index != (index_of_last - 1))
		last = last->next;
	last->next = NULL;
	update_indexes(*stack);
}

/*-------------------------------------------*/
/*  Reverse rotate elements of stack a by 1  */
/*-------------------------------------------*/
void	rev_rotate_a(t_stack **a)
{
	ft_printf("rra\n");
	reverse_rotate(a);
}

/*-------------------------------------------*/
/*  Reverse rotate elements of stack b by 1  */
/*-------------------------------------------*/
void	rev_rotate_b(t_stack **b)
{
	ft_printf("rrb\n");
	reverse_rotate(b);
}

/*-------------------------------------------------------*/
/*  Reverse rotate elements of stack a and stack b by 1  */
/*-------------------------------------------------------*/
void	rev_rotate_a_and_b(t_stack **a, t_stack **b)
{
	ft_printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
}
