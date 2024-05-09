/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:26:28 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/09 18:16:25 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
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
	last->prev->next = NULL;
	temp = *stack;
	while (temp)
	{
		temp->index++;
		temp = temp->next;
	}
	last->next = first;
	last->prev = NULL;
	last->index = 0;
	*stack = last;
}

void	rev_rotate_a(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rev_rotate_b(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rev_rotate_a_and_b(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
