/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:09:56 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/09 10:45:22 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_own/libft.h"
# include "libft_own/ft_printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	input_handler(int argc, char **argv, t_stack **a);
int		count_numbers(char **str);
void	free_str(char **str);
long	ft_atol(char *str);

#endif
