/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:25:17 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/11 13:46:20 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*-------------------------------------------------------*/
/*  Swap operation:                                      */
/*  Swaps the first 2 elements at the top of the stack.  */
/*  Does nothing if there is only one or no elements.    */
/*-------------------------------------------------------*/
static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->index = 1;
	first->next = second->next;
	first->prev = second;
	second->index = 0;
	second->next = first;
	second->prev = NULL;
	if (first->next != NULL)
		first->next->prev = first;
	*stack = second;
}

/*----------------------------------------------------*/
/*  Swaps the first 2 elements at the top of stack a  */
/*----------------------------------------------------*/
void	swap_a(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

/*----------------------------------------------------*/
/*  Swaps the first 2 elements at the top of stack b  */
/*----------------------------------------------------*/
void	swap_b(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

/*----------------------------------------------------------------*/
/*  Swaps the first 2 elements at the top of stack a and stack b  */
/*----------------------------------------------------------------*/
void	swap_a_and_b(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
