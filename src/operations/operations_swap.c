/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:25:17 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/17 20:12:21 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*-------------------------------------------------------*/
/*  Swap operation:                                      */
/*  Swaps the first 2 elements at the top of the stack.  */
/*  Does nothing if there is only one or no elements.    */
/*-------------------------------------------------------*/
void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	*stack = second->next;
	second->next = first;
	first->next = *stack;
	*stack = second;
	second->index = 0;
	first->index = 1;
}

/*----------------------------------------------------*/
/*  Swaps the first 2 elements at the top of stack a  */
/*----------------------------------------------------*/
void	swap_a(t_stack **a)
{
	ft_printf("sa\n");
	swap(a);
}

/*----------------------------------------------------*/
/*  Swaps the first 2 elements at the top of stack b  */
/*----------------------------------------------------*/
void	swap_b(t_stack **b)
{
	ft_printf("sb\n");
	swap(b);
}

/*----------------------------------------------------------------*/
/*  Swaps the first 2 elements at the top of stack a and stack b  */
/*----------------------------------------------------------------*/
void	swap_a_and_b(t_stack **a, t_stack **b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
}
