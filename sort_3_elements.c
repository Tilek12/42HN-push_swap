/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:41:47 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/14 18:31:15 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*----------------------------------------------------*/
/*  Gets the value of the first element in the stack  */
/*----------------------------------------------------*/
int	first(t_stack *stack)
{
	int	first_value;

	first_value = stack->value;
	return (first_value);
}

/*-----------------------------------------------------*/
/*  Gets the value of the second element in the stack  */
/*-----------------------------------------------------*/
int	second(t_stack *stack)
{
	int	second_value;

	second_value = stack->next->value;
	return (second_value);
}

/*---------------------------------------------------*/
/*  Gets the value of the last element in the stack  */
/*---------------------------------------------------*/
int	last(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp->value);
}

/*--------------------------------------*/
/*  Sorts stack a with 3 elements only  */
/*--------------------------------------*/
void	sort_3_elements_in_a(t_stack **a)
{
	if ((first(*a) > second(*a)) && (second(*a) > last(*a)))
	{
		swap_a(a);
		rev_rotate_a(a);
	}
	else if ((first(*a) > last(*a)) && (last(*a) > second(*a)))
		rotate_a(a);
	else if ((first(*a) > last(*a)) && (second(*a) > last(*a)))
		rev_rotate_a(a);
	else if ((second(*a) > last(*a)) && (last(*a) > first(*a)))
	{
		rev_rotate_a(a);
		swap_a(a);
	}
	else if ((first(*a) > second(*a)) && (last(*a) > first(*a)))
		swap_a(a);
}
