/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:16:11 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/14 18:33:17 by tkubanyc         ###   ########.fr       */
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
	while(temp)
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

/*----------------------------*/
/*  Starts sorting algorithm  */
/*----------------------------*/
void	sorting(t_stack **a, t_stack **b)
{
	int	elements;

	elements = count_elements(*a);
	if (is_sorted(*a) == 1)
		exit_success(a);
	else
	{
		if (elements == 2)
			swap_a(a);
		else if (elements == 3)
			sort_3_elements_in_a(a);
		else if (elements <= 10)
			sort_small_stack(a, b, elements);
		else
			sort_big_stack(a, b, elements);
	}
	if (is_sorted(*a) == 0)
	{
		free_stack(b);
		exit_failure(a);
	}
	else
		free_stack(a);
	free_stack(b);
}
