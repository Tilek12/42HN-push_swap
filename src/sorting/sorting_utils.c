/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:20:13 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/17 20:29:31 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*----------------------------------------*/
/*  Counts the square root of the number  */
/*----------------------------------------*/
int	ft_sqrt(int n)
{
	int	start;
	int	mid;
	int	end;
	int	result;

	if (n <= 1)
		return (n);
	start = 1;
	end = n;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if ((mid * mid) == n)
			return (mid);
		if (mid <= (n / mid))
		{
			start = mid + 1;
			result = mid;
		}
		else
			end = mid - 1;
	}
	return (result);
}

/*------------------------------------*/
/*  Counts the elements in the stack  */
/*------------------------------------*/
int	count_elements(t_stack *stack)
{
	t_stack	*temp;
	int		counter;

	temp = stack;
	counter = 0;
	while (temp)
	{
		counter++;
		temp = temp->next;
	}
	return (counter);
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
