/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:41:24 by adbenoit          #+#    #+#             */
/*   Updated: 2021/01/06 17:45:38 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bufcpy(char *buf)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		++i;
	++i;
	j = 0;
	while (buf[i])
	{
		buf[j] = buf[i];
		++i;
		++j;
	}
	buf[j] = 0;
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i] && i < n)
		++i;
	if (!(copy = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s1[i] && i < n)
	{
		copy[i] = s1[i];
		++i;
	}
	copy[i] = 0;
	return (copy);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (*lst)
	{
		while ((*lst)->next)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(tmp, del);
		}
		(*del)((*lst)->content);
		free(*lst);
		*lst = NULL;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t i;

	if (!(mem = (char *)malloc(count * size)))
		return (0);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *)mem)[i] = 0;
		++i;
	}
	return ((void *)mem);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
			ft_lstlast(*alst)->next = new;
	}
}

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	if (!src || !dest)
		return (dest);
	i = 0;
	while (dest[i])
		++i;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = 0;
	return (dest);
}
