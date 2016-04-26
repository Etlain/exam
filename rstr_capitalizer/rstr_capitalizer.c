/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:34:02 by exam              #+#    #+#             */
/*   Updated: 2016/03/29 23:11:00 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>
void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_init(char *str, int *i, int *j)
{
	int lgt;

	*i = 0;
	*j = 0;
	lgt = 0;
	while (str[*i] == '\0' && str[*i] == ' ' && str[*i] == '\t')
	{
		(*i)++;
		lgt++;
	}
	i++;
	while (str[lgt] != '\0')
		lgt++;
	while (lgt > 0 && (str[lgt] == '\0' || str[lgt] == ' ' || str[lgt] == '\t'))
		lgt--;
	return (lgt);
}

int		word_end(char *str, int i, int lgt)
{
	int j;
	char *tmp;

	tmp = str;
	j = i;
	while (tmp[j] != '\0' && tmp[j] != ' ' && tmp[j] != '\t')
	{
		if (tmp[j] <= 'Z' && tmp[j] >= 'A')
			tmp[j] = tmp[j] + 32;
		/*if (j > 0 && (tmp[j] == '\0' && tmp[j] == ' ' && tmp[j] == '\t'))
		{
			if (tmp[j - 1] <= 'z' && tmp[j - 1] >= 'a')
				tmp[j] = tmp[j] - 32;
		}*/
		j++;
	}
	if (j > 0 && (tmp[j] == '\0' || tmp[j] == ' ' || tmp[j] == '\t'))
	{
		if (tmp[j - 1] <= 'z' && tmp[j - 1] >= 'a')
			tmp[j - 1] = tmp[j - 1] - 32;
	}
	if (tmp[j] == '\0' || j == lgt + 1)
		j = j * -1;
	return (j);
}

void	last_word(char *str)
{
	int i;
	int j;
	int lgt;

	lgt = ft_init(str, &i, &j);
	while (i <= lgt)
	{
		j = word_end(str, i, lgt);
		if (j < 0)
			break ;
		else
			i = j;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
	}
	ft_putstr(str);
	ft_putstr("\n");
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2 || argv[1][0] == '\0')
		ft_putstr("\n");
	else
	{
		while (i < argc)
		{
			last_word(argv[i]);
			i++;
		}
	}
	return (0);
}
