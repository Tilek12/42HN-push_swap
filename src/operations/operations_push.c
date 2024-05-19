/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:25:42 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/17 20:11:56 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*------------------------------------------------------*/
/*  Push operation:                                     */
/*  Takes the first element at the top of source stack  */
/*  and puts it to the top of the destination stack.    */
/*  Does nothing if the source stack is empty.          */
/*------------------------------------------------------*/
void	push(t_stack **dst, t_stack **src)
{
	t_stack	*src_top;
	t_stack	*dst_top;

	if (*src == NULL)
		return ;
	src_top = *src;
	dst_top = *dst;
	*src = src_top->next;
	src_top->next = dst_top;
	*dst = src_top;
	update_indexes(*dst);
	update_indexes(*src);
}

/*---------------------------------------------------*/
/*  Pushes the top of stack b to the top of stack a  */
/*---------------------------------------------------*/
void	push_a(t_stack **a, t_stack **b)
{
	ft_printf("pa\n");
	push(a, b);
}

/*---------------------------------------------------*/
/*  Pushes the top of stack a to the top of stack b  */
/*---------------------------------------------------*/
void	push_b(t_stack **b, t_stack **a)
{
	ft_printf("pb\n");
	push(b, a);
}
