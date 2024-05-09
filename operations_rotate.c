/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:26:00 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/09 18:00:48 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = first;
	while (last->next != NULL)
		last = last->next;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp = *stack;
	while (temp)
	{
		temp->index--;
		temp = temp->next;
	}
	last->next = first;
	first->prev = last;
	first->next = NULL;
	first->index = last->index + 1;
}

void	rotate_a(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rotate_a_and_b(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
