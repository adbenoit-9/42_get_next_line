/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:17:42 by adbenoit          #+#    #+#             */
/*   Updated: 2021/01/08 14:47:15 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_gnl
{
	int		fd;
	size_t	len;
}				t_gnl;

int				get_next_line(int fd, char **line);
char			*ft_strndup(const char *s1, size_t n);
t_list			*ft_lstnew(void *content);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstadd_back(t_list **alst, t_list *new);
char			*ft_strcat(char *dest, const char *src);

#endif
