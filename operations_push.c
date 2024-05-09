/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:25:42 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/09 19:47:44 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_indexes(t_stack *stack, int sign)
{
	while (stack)
	{
		stack->index += sign;
		stack = stack->next;
	}
}

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*src_top;
	t_stack	*dst_top;

	if (*src == NULL)
		return ;
	src_top = *src;
	dst_top = *dst;
	*src = src_top->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	update_indexes(*src, -1);
	update_indexes(*dst, 1);
	if (dst_top != NULL)
		dst_top->prev = src_top;
	src_top->next = dst_top;
	src_top->prev = NULL;
	*dst = src_top;
}

void	push_a(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	push_b(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_printf("pb\n");
}
