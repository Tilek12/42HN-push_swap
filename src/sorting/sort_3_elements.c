/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:41:47 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/15 15:13:21 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*----------------------------------------------------*/
/*  Gets the value of the first element in the stack  */
/*----------------------------------------------------*/
static int	first(t_stack *stack)
{
	return (stack->value);
}

/*-----------------------------------------------------*/
/*  Gets the value of the second element in the stack  */
/*-----------------------------------------------------*/
static int	second(t_stack *stack)
{
	return (stack->next->value);
}

/*----------------------------------------------------*/
/*  Gets the value of the third element in the stack  */
/*----------------------------------------------------*/
static int	third(t_stack *stack)
{
	return (stack->next->next->value);
}

/*--------------------------------------*/
/*  Sorts stack a with 3 elements only  */
/*--------------------------------------*/
void	sort_3_elements_in_a(t_stack **a)
{
	if ((first(*a) > second(*a)) && (second(*a) > third(*a)))
	{
		swap_a(a);
		rev_rotate_a(a);
	}
	else if ((first(*a) > third(*a)) && (third(*a) > second(*a)))
		rotate_a(a);
	else if ((first(*a) > third(*a)) && (second(*a) > third(*a)))
		rev_rotate_a(a);
	else if ((second(*a) > third(*a)) && (third(*a) > first(*a)))
	{
		rev_rotate_a(a);
		swap_a(a);
	}
	else if ((first(*a) > second(*a)) && (third(*a) > first(*a)))
		swap_a(a);
}
