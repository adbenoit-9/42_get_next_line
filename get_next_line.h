/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:17:42 by adbenoit          #+#    #+#             */
/*   Updated: 2021/01/06 17:43:49 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 4097

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_gnl
{
	int		fd;
	size_t	len;
}				t_gnl;

int				get_next_line(int fd, char **line);
void			ft_bufcpy(char *buf);
char			*ft_strndup(const char *s1, size_t n);
t_list			*ft_lstnew(void *content);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			*ft_calloc(size_t count, size_t size);
void			ft_lstadd_back(t_list **alst, t_list *new);
char			*ft_strcat(char *dest, const char *src);
t_list			*ft_lstlast(t_list *lst);

#endif
