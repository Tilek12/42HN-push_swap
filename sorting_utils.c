/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:16:42 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/11 13:56:13 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*-----------------------------------------*/
/*  Counts how many elements in the stack  */
/*-----------------------------------------*/
int	count_elements(t_stack *stack)
{
	t_stack	*temp;
	int		counter;

	temp = stack;
	counter = 0;
	while(temp)
	{
		counter++;
		temp = temp->next;
	}
	return (counter);
}

/*---------------------------------*/
/*  Checks if the stack is sorted  */
/*---------------------------------*/
int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (stack == NULL || stack->next == NULL)
		return (1);
	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

/*----------------------------------------------*/
/*  Gets the last element's value in the stack  */
/*----------------------------------------------*/
int	last_value(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp->value);
}
