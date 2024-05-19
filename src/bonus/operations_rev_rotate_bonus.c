/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:26:28 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/17 19:58:56 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*-------------------------------------------*/
/*  Reverse rotate elements of stack a by 1  */
/*-------------------------------------------*/
void	rra(t_stack **a)
{
	reverse_rotate(a);
}

/*-------------------------------------------*/
/*  Reverse rotate elements of stack b by 1  */
/*-------------------------------------------*/
void	rrb(t_stack **b)
{
	reverse_rotate(b);
}

/*-------------------------------------------------------*/
/*  Reverse rotate elements of stack a and stack b by 1  */
/*-------------------------------------------------------*/
void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
