/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operateur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 10:56:38 by exam              #+#    #+#             */
/*   Updated: 2016/04/26 15:20:59 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_op(char *str, int **tab, int *i)
{
	if (str[*i] == '>')
		(*tab)++;
	else if (str[*i] == '<')
		(*tab)--;
	else if (str[*i] == '+')
		(**tab)++;
	else if (str[*i] == '-')
		(**tab)--;
	else if (str[*i] == '.')
		write(1, *tab, 1);
	else
		return ;
	(*i)++;
}

void	ft_boucle(char *str, int **tab, int *i)
{
	int *condition;
	int begin;

	condition = *tab;
	begin = *i;
	if (str[*i] == '[')
		begin++;
	while (str[*i] != ']')
		(*i)++;
	while (*condition != 0)
	{
		if (str[*i] == ']')
			*i = begin;
		ft_op(str, tab, i);
		if (str[*i] == '[')
			ft_boucle(str, tab, i);
	}
	if (str[*i] == ']')
			(*i)++;
}

void	brainfuck(char *str, int **tab)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_op(str, tab, &i);
		if (str[i] == '[')
			ft_boucle(str, tab, &i);
	}
}

int	main(int argc, char **argv)
{
	char c;
	int *tab;
	int *tmp;
	int i;

	if (argc != 2)
	{
		c = '\n';
		write(1, &c, 1);
		return (-1);
	}
	tab = (int *)malloc(sizeof(int) * 2048);
	i = 0;
	while (i < 2048)
	{
		tab[i] = 0;
		i++;
	}
	tmp = tab;
	brainfuck(argv[1], &tab);
	i = 0;
	free(tmp);
	return (0);
}
