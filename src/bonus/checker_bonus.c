/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:44:55 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/19 19:28:41 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*---------------------------------*/
/*  Recognizes given instructions  */
/*---------------------------------*/
void	cmd_recognition(char *cmd, t_stack **a, t_stack **b, int *error)
{
	if ((ft_strncmp(cmd, "sa\n", 3) == 0) && (ft_strlen(cmd) == 3))
		sa(a);
	else if ((ft_strncmp(cmd, "sb\n", 3) == 0) && (ft_strlen(cmd) == 3))
		sb(b);
	else if ((ft_strncmp(cmd, "ss\n", 3) == 0) && (ft_strlen(cmd) == 3))
		ss(a, b);
	else if ((ft_strncmp(cmd, "pa\n", 3) == 0) && (ft_strlen(cmd) == 3))
		pa(a, b);
	else if ((ft_strncmp(cmd, "pb\n", 3) == 0) && (ft_strlen(cmd) == 3))
		pb(b, a);
	else if ((ft_strncmp(cmd, "ra\n", 3) == 0) && (ft_strlen(cmd) == 3))
		ra(a);
	else if ((ft_strncmp(cmd, "rb\n", 3) == 0) && (ft_strlen(cmd) == 3))
		rb(b);
	else if ((ft_strncmp(cmd, "rr\n", 3) == 0) && (ft_strlen(cmd) == 3))
		rr(a, b);
	else if ((ft_strncmp(cmd, "rra\n", 4) == 0) && (ft_strlen(cmd) == 4))
		rra(a);
	else if ((ft_strncmp(cmd, "rrb\n", 4) == 0) && (ft_strlen(cmd) == 4))
		rrb(b);
	else if ((ft_strncmp(cmd, "rrr\n", 4) == 0) && (ft_strlen(cmd) == 4))
		rrr(a, b);
	else
		(*error)++;
}

/*-------------------------------------------------------------------*/
/*  Starts running all instructions recieved by standart input       */
/*  and checks if stack a is sorted and stack b is empty at the end  */
/*-------------------------------------------------------------------*/
void	command_handler(t_stack **a, t_stack **b)
{
	char	*command;
	int		error;

	error = 0;
	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
			break ;
		cmd_recognition(command, a, b, &error);
		free(command);
		if (error > 0)
		{
			free_stack(b);
			exit_failure(a);
		}
	}
	if (is_sorted(*a) && (count_elements(*b) == 0))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	input_handler(argc, argv, &a);
	command_handler(&a, &b);
	return (0);
}
