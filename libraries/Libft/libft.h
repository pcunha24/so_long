/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 00:38:54 by pedalexa          #+#    #+#             */
/*   Updated: 2023/10/05 19:06:47 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

char	*ft_strjoin(const char *s1, const char *s2);
void	ft_bzero_buffer(char *ptr);
size_t	gnl_strlen(const char *str);
char	*ft_strjoin_line(char *s1, char *s2);
int		check_endl(char *line);
char	*ft_bzero_line(char *ptr, int flag);
char	*get_next_line(int fd);
char	*ft_strdup(const char *string);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
