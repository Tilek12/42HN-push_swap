/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:16:42 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/13 14:31:04 by tkubanyc         ###   ########.fr       */
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

/*----------------------------------------------------*/
/*  Gets the value of the first element in the stack  */
/*----------------------------------------------------*/
int	first(t_stack *stack)
{
	int	first_value;

	first_value = stack->value;
	return (first_value);
}

/*----------------------------------------------------*/
/*  Updates the indexes of all elements in the stack  */
/*----------------------------------------------------*/
void	update_indexes(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		stack->index = index++;
		stack = stack->next;
	}
}
