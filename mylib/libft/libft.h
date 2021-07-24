/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:05:13 by edavid            #+#    #+#             */
/*   Updated: 2021/07/24 15:44:49 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
// Writes 'n' bytes of value 'c' to the string 's'
void	*ft_memset(void *s, int c, size_t n);
// Writes 'n' zeroed bytes to the string 's'
void	ft_bzero(void *s, size_t n);
// Copies 'n' bytes from memory area 'src' to memory area 'dest'.
// If 'dest' and 'src' overlap, behavior is undefined.
void	*ft_memcpy(void *dest, const void *src, size_t n);
// Copies bytes from string 'src' to string 'dest'. If the character 'c' occurs
// in the string 'src', the copy stops and a pointer to the byte after the copy
// of 'c' in the string 'dest' is returned. Otherwise, 'n' bytes are copied,
// and a NULL pointer is returned.
// If 'dest' and 'src' overlap, behavior is undefined.
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
// Copies 'n' bytes from string 'src' to string 'dest'. The two strings may
// overlap; the copy is always done in a non-destructive manner.
void	*ft_memmove(void *dest, const void *src, size_t n);
// 
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);
int		ft_isalpha(int c);
// Returns 1 if c is a digit, 0 otherwise.
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_calloc(size_t nelem, size_t elsize);
char	*ft_strdup(const char *s);
// Allocates and returns a substring from the string 's'
// The substring begins at the index 'start' and is of maximum size 'len'.
char	*ft_substr(char const *s, unsigned int start, size_t len);
// Allocates and returns a new string, which is the result of the
// concatenation of 's1' and 's2'.
char	*ft_strjoin(char const *s1, char const *s2);
// Allocates and returns a copy of 's1' with the characters specified in 'set'
// removed from the beginning and the end of the string.
char	*ft_strtrim(char const *s1, char const *set);
// Allocates and returns an array of strings obtained by splitting 's' using the
// character 'c' as a delimeter. The array ends with a NULL pointer.
char	**ft_split(char const *s, char c);
// Allocates and returns a string representing the integer received as an
// argument.
char	*ft_itoa(int n);
// Applies the function 'f' to each character of the string 's' to create a new
// string resulting from successive application of 'f'.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// Outputs the character 'c' to the given file descriptor.
void	ft_putchar_fd(char c, int fd);
// Outputs the string 's' to the given file descriptor.
void	ft_putstr_fd(char *s, int fd);
// Outputs the string 's' to the given file descriptor, followed by a newline.
void	ft_putendl_fd(char *s, int fd);
// Outputs the integer 'n' to the given file descriptor.
void	ft_putnbr_fd(int n, int fd);
# ifndef T_LIST
#  define T_LIST
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
# endif
// Allocates and returns a new element. The variable 'content' is initialized
// with the value of the parameter 'content'. The variable 'next' is
// initialized to NULL.
t_list	*ft_lstnew(void *content);
// Adds the element 'new' at the beginning of the list.
void	ft_lstadd_front(t_list **lst, t_list *new);
// Counts the number of elements in the list.
int		ft_lstsize(t_list *lst);
// Returns the last element of the list.
t_list	*ft_lstlast(t_list *lst);
// Adds the element 'new' at the end of the list.
void	ft_lstadd_back(t_list **lst, t_list *new);
// Takes as a parameter an element and frees the memory of the element's
// content using the function 'del' given as a parameter and free the element.
// The memory of 'next' is not freed.
void	ft_lstdelone(t_list *lst, void (*del)(void *));
// Deletes and frees the given element and every successor of that element,
// using the function 'del' and free.
// Finally, the pointer to the list is set to NULL.
void	ft_lstclear(t_list **lst, void (*del)(void *));
// Iterates the list 'lst' and applies the function 'f' to the content of each
// element.
void	ft_lstiter(t_list *lst, void (*f)(void *));
// Iterates the list 'lst' and applies the function 'f' to the content of each
// element. Creates a new list resulting of the successive application of the
// function 'f'. The 'del' function is used to delete the content of an element
// if needed.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// only works when size >= size of allocated memory src point to
// also frees src in case the malloc for the new content fails, which is
// problematic if src was pointing to other pointers that were previously
// malloced -> it has to do a recursive freeing for src before returning null
void	*ft_realloc(void *src, size_t size);

#endif
