/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:16:25 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/24 16:19:13 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lst_push_params(int argc, char **argv);
t_list				*ft_lst_last(t_list *lst);
int					ft_lst_size(t_list *lst);
void				ft_lst_add_end(t_list **lst, t_list *mew);
void				ft_swap_str(char *a, char *b);
void				ft_is_negative(int n);
int					*ft_range(int min, int max);
int					ft_recursive_factorial(int nb);
void				ft_sort_params(int argc, char **argv);
void				ft_print_params(int argc, char **argv);
int					ft_sqrt(int nb);
void				ft_swap(int *a, int *b);
void				ft_display_file(int argc, char **argv);
char				**ft_create_chartab(int size, int sizelittle);
void				ft_rchar_tab(char **tab);
int					ft_isprint(int c);
t_list				*ft_lsti_map(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lst_add(t_list **alst, t_list *mew);
void				ft_lst_del(t_list **alst, void (*del)(void *, size_t));
void				ft_lst_del_one(t_list **alst, void (*del)(void*, size_t));
t_list				*ft_lst_new(void const *content, size_t content_size);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
char				*ft_strstr(const char *haystack, const char *needle);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_memdel(void **ap);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				*ft_memalloc(size_t size);
int					ft_isalpha(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
char				*ft_ststr(const char *haystack, const char *needle);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack,
					const char*needle, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strncpy(char *dest, const char *src, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char(*f)(char));
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strdup(const char *s1);
void				ft_strdel(char **as);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strclr(char *s);
char				*ft_strchr(const char *s, int c);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);

#endif
