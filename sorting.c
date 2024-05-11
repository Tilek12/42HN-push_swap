/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:16:11 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/11 11:47:27 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a_and_b(t_stack **a, t_stack **b)
{

}

/*----------------------------------------------------*/
/*  Moves half elements from stack a to stack b and   */
/*  puts the highest element at the top of the stack  */
/*----------------------------------------------------------------------*/
/*  Compares the first, the second and the last element in stack a and  */
/*  moves the element with highest value to stack b                     */
/*----------------------------------------------------------------------*/
/*  Compares if it's necessary to do swap, rotate and reverse rotate  */
/*  operations in both of stacks at the same time (ss, rr, rrr)       */
/*--------------------------------------------------------------------*/
static void	move_half_to_b(t_stack **a, t_stack **b, int elements)
{
	int	i;

	i = 0;
	ft_printf("Elements in a: %d\n", elements);
	while (i < (elements / 2))
	{
		if (((*a)->value > (*a)->next->value)
				&& ((*a)->next->value > last_value(*a))) // "3 2   1"
			push_b(b, a);
		else if (((*a)->value > last_value(*a))
				&& (last_value(*a) > (*a)->next->value)) // "3 1   2"
			push_b(b, a);
		else if (((*a)->value > last_value(*a))
				&& ((*a)->next->value > last_value(*a))) // "2 3   1"
		{
			if ((*b != NULL)
				&& ((*b)->value > last_value(*b))
					&& ((*b)->next->value > last_value(*b)))
				swap_a_and_b(a, b);
			else
				swap_a(a);
			push_b(b, a);
		}
		else if (((*a)->next->value > last_value(*a))
				&& (last_value(*a) > (*a)->value)) // "1 3   2"
		{
			if ((*b != NULL)
				&& ((*b)->next->value > last_value(*b))
					&& (last_value(*b) > (*b)->value))
				rotate_a_and_b(a, b);
			else
				rotate_a(a);
			push_b(b, a);
		}
		else if (((*a)->value > (*a)->next->value)
				&& (last_value(*a) > (*a)->value)) // "2 1   3"
		{
			if ((*b != NULL)
				&& ((*b)->value > (*b)->next->value)
					&& (last_value(*b) > (*b)->value))
				rev_rotate_a_and_b(a, b);
			else
				rev_rotate_a(a);
			push_b(b, a);
		}
		else
			push_b(b, a);
		i++;
	}
}

/*--------------------------------------------------*/
/*  Sorts stack a and stack b with over 3 elements  */
/*--------------------------------------------------*/
static void	sort(t_stack **a, t_stack **b, int elements)
{
	if (elements < 6)
		sort_a_and_b(a, b);
	else
		move_half_to_b(a, b, elements);
}

/*--------------------------------------*/
/*  Sorts stack a with 3 elements only  */
/*--------------------------------------*/
static void	sort_3_elements(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if ((first > second) && (second > third))
	{
		swap_a(stack);
		rev_rotate_a(stack);
	}
	else if ((first > third) && (third > second))
		rotate_a(stack);
	else if ((first > third) && (second > third))
		rev_rotate_a(stack);
	else if ((second > third) && (third > first))
	{
		rev_rotate_a(stack);
		swap_a(stack);
	}
	else if ((first > second) && (third > first))
		swap_a(stack);
}

/*----------------------------*/
/*  Starts sorting algorithm  */
/*----------------------------*/
void	sorting(t_stack **a, t_stack **b)
{
	int	elements;

	elements = count_elements(*a);
	if (elements == 2)
	{
		if (is_sorted(*a) == 0)
			swap_a(a);
		else if (is_sorted(*a) == 1)
			exit_success(a);
	}
	else if (elements == 3)
	{
		if (is_sorted(*a) == 0)
			sort_3_elements(a);
		else if (is_sorted(*a) == 1)
			exit_success(a);
	}
	else
	{
		if (is_sorted(*a) == 0)
			sort(a, b, elements);
		else
			exit_success(a);
	}
}
