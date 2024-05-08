/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:29:24 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/08 11:08:21 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In case of error shows the Error message and deallocates memory of stack a
void	error_handler(t_stack **a)
{
	t_stack	*temp;

	ft_printf("Error\n");
	if (*a != NULL)
	{
		while (*a)
		{
			temp = *a;
			*a = (*a)->next;
			free(temp);
			*a = NULL;
		}
	}
	exit(EXIT_FAILURE);
}

// Checkes for repeating the number in stack a
int	repeat_check(t_stack *a, int num)
{
	while (a)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}
