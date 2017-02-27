/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:40:19 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/12 14:04:42 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	int i;

	i = 0;
	if (!s || !*s)
		return ;
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
}