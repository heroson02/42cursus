/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:48:28 by hyojlee           #+#    #+#             */
/*   Updated: 2022/05/19 15:28:06 by hyojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_info	*get_info(void)
{
	static t_info	info;

	return (&info);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	len;

	len = ft_strlen(s1);
	if (len < ft_strlen(s2))
		len = ft_strlen(s2);
	return (ft_memcmp(s1, s2, len));
}

int	ft_isblank(char c)
{
	if (c == ' ' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == '\t')
		return (1);
	return (0);
}

char	*get_env(char *name)
{
	t_list	*cur;
	t_info	*info;

	info = get_info();
	cur = info->env_list;
	while (cur)
	{
		if (!ft_strcmp(((t_enode *)cur->content)->key, name))
			return (((t_enode *)cur->content)->value);
		cur = cur->next;
	}
	return ("");
}
