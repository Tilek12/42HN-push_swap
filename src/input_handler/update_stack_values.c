/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stack_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:15:58 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/18 13:21:14 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*---------------------------------------------------------------*/
/*  Finds the index of the element with the smallest real_value  */
/*---------------------------------------------------------------*/
static int	find_min_index(t_stack *stack)
{
	t_stack	*temp;
	int		min_real_value;
	int		min_index;

	temp = stack;
	min_real_value = INT_MAX;
	min_index = -1;
	while (temp)
	{
		if ((temp->value == 0) && (temp->real_value <= min_real_value))
		{
			min_real_value = temp->real_value;
			min_index = temp->index;
		}
		temp = temp->next;
	}
	return (min_index);
}

/*------------------------------------*/
/*  Updates the value of the element  */
/*------------------------------------*/
static void	update_value(t_stack *stack, int min_index, int *i)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->index == min_index)
		{
			temp->value = (*i)++;
			break ;
		}
		temp = temp->next;
	}
}

/*---------------------------------------------------*/
/*  Updates the values of all elements in the stack  */
/*---------------------------------------------------*/
void	update_stack_values(t_stack **stack, int elements)
{
	int	min_index;
	int	i;

	i = 1;
	while (i <= elements)
	{
		min_index = find_min_index(*stack);
		if (min_index == (-1))
			break ;
		update_value(*stack, min_index, &i);
	}
}
