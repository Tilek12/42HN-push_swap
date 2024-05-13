/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:16:11 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/13 14:29:40 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*--------------------------------------*/
/*  Sorts stack a with 3 elements only  */
/*--------------------------------------*/
void	sort_3_elements_in_a(t_stack **a)
{
	if ((first(*a) > second(*a)) && (second(*a) > last(*a))) // "3 2 1"
	{
		swap_a(a);
		rev_rotate_a(a);
	}
	else if ((first(*a) > last(*a)) && (last(*a) > second(*a))) // "3 1 2"
		rotate_a(a);
	else if ((first(*a) > last(*a)) && (second(*a) > last(*a))) // "2 3 1"
		rev_rotate_a(a);
	else if ((second(*a) > last(*a)) && (last(*a) > first(*a))) // "1 3 2"
	{
		rev_rotate_a(a);
		swap_a(a);
	}
	else if ((first(*a) > second(*a)) && (last(*a) > first(*a))) // "2 1 3"
		swap_a(a);
}

int	find_index_of_smallest(t_stack *a)
{
	t_stack	*temp;
	int		min_value;
	int		min_index;

	temp = a;
	min_value = INT_MAX;
	min_index = 0;
	while (temp)
	{
		if (temp->value < min_value)
		{
			min_value = temp->value;
			min_index = temp->index;
		}
		temp = temp->next;
	}
	return (min_index);
}

int	find_value_of_smallest(t_stack *a)
{
	t_stack	*temp;
	int		min_value;

	temp = a;
	min_value = INT_MAX;
	while (temp)
	{
		if (temp->value < min_value)
		{
			min_value = temp->value;
		}
		temp = temp->next;
	}
	return (min_value);
}

int	is_min_closer_to_top(int index_of_min, int elements)
{
	if (index_of_min <= (elements / 2))
		return (1);
	else
		return (0);
}

// A modified version of Selection Sort:
// 1. Finds the smallest number in stack a and bring it to the top using ra operation.
// 2. Pushes it to stack b using the pb operation.
// 3. Repeats steps 1-2 until 3 elements stay in stack a.
// 4. Sorts 3 lements in stack a.
// 5. Pushes all elements from stack b back to stack a using pa operation.
void	sort(t_stack **a, t_stack **b, int elements)
{
	int	value_of_min;
	int	index_of_min;

	while (elements > 3)
	{
		value_of_min = find_value_of_smallest(*a);
		index_of_min = find_index_of_smallest(*a);
		while ((*a)->value != value_of_min)
		{
			if (is_min_closer_to_top(index_of_min, elements) == 1)
				rotate_a(a);
			else
				rev_rotate_a(a);
		}
		push_b(b, a);
		elements--;
	}
	sort_3_elements_in_a(a);
	while (count_elements(*b) > 0)
		push_a(a, b);
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
			sort_3_elements_in_a(a);
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
