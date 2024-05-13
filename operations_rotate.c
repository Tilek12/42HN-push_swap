/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:26:00 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/13 11:47:23 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*--------------------------------------------*/
/*  Rotate operation:                         */
/*  Shift up all elements of the stack by 1.  */
/*  The first element becomes the last one.   */
/*--------------------------------------------*/
static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
	update_indexes(*stack);
}

/*-----------------------------------*/
/*  Rotate elements of stack a by 1  */
/*-----------------------------------*/
void	rotate_a(t_stack **a)
{
	ft_printf("ra\n");
	rotate(a);
}

/*-----------------------------------*/
/*  Rotate elements of stack b by 1  */
/*-----------------------------------*/
void	rotate_b(t_stack **b)
{
	ft_printf("rb\n");
	rotate(b);
}

/*-----------------------------------------------*/
/*  Rotate elements of stack a and stack b by 1  */
/*-----------------------------------------------*/
void	rotate_a_and_b(t_stack **a, t_stack **b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}
