/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:06:57 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/20 11:56:01 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*----------------------------------------------------------------*/
/*  In case of error shows the Error message, deallocates memory  */
/*  of the stack and exits the program with EXIT_FAILURE          */
/*----------------------------------------------------------------*/
void	exit_failure(t_stack **stack)
{
	t_stack	*temp;

	write(2, "Error\n", 6);
	if (*stack != NULL)
	{
		while (*stack)
		{
			temp = *stack;
			*stack = (*stack)->next;
			free(temp);
		}
	}
	*stack = NULL;
	exit(EXIT_FAILURE);
}

/*----------------------------------------------------------------*/
/*  In case of exiting program without error, deallocates memory  */
/*  of the stack and exits the program with EXIT_SUCCESS          */
/*----------------------------------------------------------------*/
void	exit_success(t_stack **stack)
{
	t_stack	*temp;

	if (*stack != NULL)
	{
		while (*stack)
		{
			temp = *stack;
			*stack = (*stack)->next;
			free(temp);
		}
	}
	*stack = NULL;
	exit(EXIT_SUCCESS);
}

/*-----------------------------------*/
/*  Deallocates memory of the stack  */
/*-----------------------------------*/
void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (*stack != NULL)
	{
		while (*stack)
		{
			temp = *stack;
			*stack = (*stack)->next;
			free(temp);
		}
	}
	*stack = NULL;
}
