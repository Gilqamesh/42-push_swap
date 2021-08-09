#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*s++)
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	if (!src)
		return (0);
	len = ft_strlen(src);
	if (size)
	{
		while (--size && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s);
	new = (char *)malloc(len + 1);
	if (!new)
		return ((char *)0);
	ft_strlcpy(new, s, len + 1);
	return (new);
}

typedef struct s_2_int
{
	int	a;
	int	b;
}	t_2_int;

typedef struct s_lststr
{
	char			**content;
	struct s_lststr	*next;
}	t_lststr;

typedef struct s_node_binary
{
	void					*content;
	struct s_node_binary	*next;
	struct s_node_binary	*prev;
}	t_node_binary;

static void	ft_nodbindel(void *node)
{
	if (!node)
		return ;
	if (((t_node_binary *)node)->content)
		free(((t_node_binary *)node)->content);
	free(node);
}

static char	**ft_free(char ***s, int i)
{
	while (i--)
		free(*(*s + i));
	free(*s);
	return ((char **)0);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c)
		return ((char *)0);
	return ((char *)s);
}

static char	*empty_str(void)
{
	char	*empty;

	empty = (char *)malloc(1);
	if (!empty)
		return ((char *)0);
	*empty = '\0';
	return (empty);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*new;

	if (!s)
		return ((char *)0);
	s_len = ft_strlen(s);
	if (s_len <= (size_t)start)
		return (empty_str());
	if (s_len < (size_t)start + len)
		len = s_len - (size_t)start;
	new = (char *)malloc(len + 1);
	if (!new)
		return ((char *)0);
	ft_strlcpy(new, s + start, len + 1);
	return (new);
}

static char	**split_fn(char **splits_array, int n_of_splits,
char const *s, int c)
{
	int	i;

	i = -1;
	while (++i <= n_of_splits)
	{
		while (*s == c)
			s++;
		if (i < n_of_splits || ft_strchr(s, c))
			*(splits_array + i) = ft_substr(s, 0,
					(size_t)(ft_strchr(s, c) - s));
		else
			*(splits_array + i) = ft_strdup(s);
		if (!*(splits_array + i))
			return (ft_free(&splits_array, i));
		s = ft_strchr(s, c);
	}
	return (splits_array);
}

int	ft_n_of_words_by_delim(char *s, char c)
{
	int	in_word;
	int	n_of_words;

	n_of_words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!in_word)
			{
				in_word = 1;
				n_of_words++;
			}
		}
		else
			in_word = 0;
		s++;
	}
	return (n_of_words);
}

char	**ft_split(char const *s, char c)
{
	int		n_of_splits;
	char	**splits_array;

	if (!s)
		return ((char **)0);
	n_of_splits = ft_n_of_words_by_delim((char *)s, c) - 1;
	splits_array = (char **)malloc((n_of_splits + 2) * sizeof(*splits_array));
	if (!splits_array)
		return ((char **)0);
	*(splits_array + n_of_splits + 1) = (char *)0;
	return (split_fn(splits_array, n_of_splits, s, c));
}

void	ft_lststradd_back(t_lststr **lst, t_lststr *new)
{
	t_lststr	*cur;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

t_lststr	*ft_lststrnew(char **content)
{
	t_lststr	*new_el;

	new_el = (t_lststr *)malloc(sizeof(*new_el));
	if (!new_el)
		return ((t_lststr *)0);
	new_el->content = content;
	new_el->next = (t_lststr *)0;
	return (new_el);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_lststrexcludenode(t_lststr **head, t_lststr *begin)
{
	t_lststr	*prev;
	t_lststr	*tmp;

	// PRINT_HERE();
	// printf("%s %p, %s %p\n", *(*head)->content, (*head)->content,
		// *begin->content, begin->content);
	if (!begin)
		return ;
	if (!head || !*head)
		return ;
	prev = begin;
	// printf("prev: %p, begin: %p, head: %p\n", prev, begin, *head);
	if (prev == *head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		// printf("Head: %p\n", *head);
		// PRINT_HERE();
		return ;
	}
	while (prev->next != *head)
		prev = prev->next;
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
	prev->next = *head;
	// PRINT_HERE();
}

void	ft_lststrnullboth(t_lststr **head, char **compared_str_ptr, t_lststr *begin)
{
	// PRINT_HERE();
	free(*(*head)->content);
	*(*head)->content = ft_strdup("");
	ft_lststrexcludenode(head, begin);
	free(*compared_str_ptr);
	*compared_str_ptr = ft_strdup("");
	*head = NULL;
	// PRINT_HERE();
}

void	ft_lststrreplace(t_lststr ***head, char ***compared_str_ptr,
t_lststr **operation_flags, char *op)
{
	// PRINT_HERE();
	free(*(**head)->content);
	*(**head)->content = ft_strdup(op);
	free(**compared_str_ptr);
	**compared_str_ptr = ft_strdup("");
	*compared_str_ptr = (**head)->content;
	*head = operation_flags;
	// PRINT_HERE();
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	if (!s1 || !s2)
		return ((char *)0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(s1_len + s2_len + 1);
	if (!new)
		return ((char *)0);
	ft_strlcpy(new, s1, s1_len + 1);
	ft_strlcpy(new + s1_len, s2, s2_len + 1);
	return (new);
}

void	ft_nodbindelone(t_node_binary *lst, void (*del)(void *))
{
	(*del)(lst);
}

void	ft_nodbinclear(t_node_binary **lst, void (*del)(void *), int n)
{
	t_node_binary	*tmp;

	if (!lst)
		return ;
	while (*lst && n)
	{
		tmp = (*lst)->next;
		ft_nodbindelone(*lst, del);
		*lst = (t_node_binary *)0;
		*lst = tmp;
		if (n > 0 && !--n)
			break ;
	}
}

t_node_binary	*ft_nodbinnew(void *content)
{
	t_node_binary	*new_el;

	new_el = (t_node_binary *)malloc(sizeof(*new_el));
	if (!new_el)
		return ((t_node_binary *)0);
	new_el->content = content;
	new_el->next = (t_node_binary *)0;
	new_el->prev = (t_node_binary *)0;
	return (new_el);
}

char	*ft_nodbinstrjoin_from_back(t_node_binary *list)
{
	int				len;
	t_node_binary	*cur;
	char			*result;
	t_2_int			index_res_tmp;

	if (!list)
		return (ft_strdup(""));
	len = 0;
	cur = list;
	while (cur)
	{
		len += ft_strlen((char *)cur->content);
		if (cur->next)
			cur = cur->next;
		else
			break ;
	}
	result = malloc(len + 1);
	result[len] = '\0';
	index_res_tmp.a = -1;
	while (cur)
	{
		index_res_tmp.b = -1;
		while (((char *)cur->content)[++index_res_tmp.b])
			result[++index_res_tmp.a] = ((char *)cur->content)[index_res_tmp.b];
		cur = cur->prev;
	}
	return (result);
}

void	ft_nodbinadd_front(t_node_binary **lst, t_node_binary *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
	if (new->next)
		new->next->prev = new;
	new->prev = (t_node_binary *)0;
}

char	*crunch_sequence(char **sequence_arr)
{
	t_lststr		*operation_flags;
	t_lststr		**head;
	t_lststr		*tmp;
	char			**compared_str_ptr;
	int				index;
	t_node_binary	*result_lst;
	char			*result_str;

	if (!sequence_arr)
		return (ft_strdup(""));
	operation_flags = NULL;
	index = 0;
	ft_lststradd_back(&operation_flags,
		ft_lststrnew(sequence_arr + index));
	while (sequence_arr[++index])
	{
		if (!operation_flags && sequence_arr[index + 1])
			ft_lststradd_back(&operation_flags,
				ft_lststrnew(sequence_arr + index++));
		head = &operation_flags;
		compared_str_ptr = sequence_arr + index;
		while (*head && (*head)->content != compared_str_ptr)
		{
			if (!ft_strcmp(*(*head)->content, "ra"))
			{
				if (!ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb")
					|| !ft_strcmp(*compared_str_ptr, "sa")
					|| !ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrexcludenode(head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rra"))
					ft_lststrnullboth(head, compared_str_ptr, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rrr"))
					ft_lststrreplace(&head, &compared_str_ptr, &operation_flags, "rrb");
				else if (!ft_strcmp(*compared_str_ptr, "rb"))
					ft_lststrreplace(&head, &compared_str_ptr, &operation_flags, "rr");
				else
					head = &(*head)->next;
			}
			else if (!ft_strcmp(*(*head)->content, "rb"))
			{
				if (!ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb")
					|| !ft_strcmp(*compared_str_ptr, "sa")
					|| !ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrexcludenode(head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rrb"))
					ft_lststrnullboth(head, compared_str_ptr, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rrr"))
					ft_lststrreplace(&head, &compared_str_ptr, &operation_flags, "rra");
				else if (!ft_strcmp(*compared_str_ptr, "ra"))
					ft_lststrreplace(&head, &compared_str_ptr, &operation_flags, "rr");
				else
					head = &(*head)->next;
			}
			else if (!ft_strcmp(*(*head)->content, "rr"))
			{
				if (!ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb")
					|| !ft_strcmp(*compared_str_ptr, "sa")
					|| !ft_strcmp(*compared_str_ptr, "sb")
					|| !ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrexcludenode(head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rrr"))
					ft_lststrnullboth(head, compared_str_ptr, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rra"))
					ft_lststrreplace(&head, &compared_str_ptr, &operation_flags, "rb");
				else if (!ft_strcmp(*compared_str_ptr, "rrb"))
					ft_lststrreplace(&head, &compared_str_ptr, &operation_flags, "ra");
				else
					head = &(*head)->next;
			}
			else if (!ft_strcmp(*(*head)->content, "rrr"))
			{
				if (!ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb")
					|| !ft_strcmp(*compared_str_ptr, "sa")
					|| !ft_strcmp(*compared_str_ptr, "sb")
					|| !ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrexcludenode(head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rr"))
					ft_lststrnullboth(head, compared_str_ptr, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "ra"))
					ft_lststrreplace(&head, &compared_str_ptr, &operation_flags, "rrb");
				else if (!ft_strcmp(*compared_str_ptr, "rb"))
					ft_lststrreplace(&head, &compared_str_ptr, &operation_flags, "rra");
				else
					head = &(*head)->next;
			}
			else if (!ft_strcmp(*(*head)->content, "rra"))
			{
				if (!ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb")
					|| !ft_strcmp(*compared_str_ptr, "sa")
					|| !ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrexcludenode(head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "ra"))
					ft_lststrnullboth(head, compared_str_ptr, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rrb"))
					ft_lststrreplace(&head, &compared_str_ptr, &operation_flags, "rrr");
				else
					head = &(*head)->next;
			}
			else if (!ft_strcmp(*(*head)->content, "rrb"))
			{
				if (!ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb")
					|| !ft_strcmp(*compared_str_ptr, "sb")
					|| !ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrexcludenode(head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rb"))
					ft_lststrnullboth(head, compared_str_ptr, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "rra"))
					ft_lststrreplace(&head, &compared_str_ptr, &operation_flags, "rrr");
				else
					head = &(*head)->next;
			}
			else if (!ft_strcmp(*(*head)->content, "pa"))
			{
				if (!ft_strcmp(*compared_str_ptr, "ra")
					|| !ft_strcmp(*compared_str_ptr, "rr")
					|| !ft_strcmp(*compared_str_ptr, "rrr")
					|| !ft_strcmp(*compared_str_ptr, "rb")
					|| !ft_strcmp(*compared_str_ptr, "rra")
					|| !ft_strcmp(*compared_str_ptr, "rrb")
					|| !ft_strcmp(*compared_str_ptr, "sa")
					|| !ft_strcmp(*compared_str_ptr, "sb")
					|| !ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrexcludenode(head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "pb"))
					ft_lststrnullboth(head, compared_str_ptr, operation_flags);
				else
					head = &(*head)->next;
			}
			else if (!ft_strcmp(*(*head)->content, "pb"))
			{
				if (!ft_strcmp(*compared_str_ptr, "ra")
					|| !ft_strcmp(*compared_str_ptr, "rr")
					|| !ft_strcmp(*compared_str_ptr, "rrr")
					|| !ft_strcmp(*compared_str_ptr, "rb")
					|| !ft_strcmp(*compared_str_ptr, "rra")
					|| !ft_strcmp(*compared_str_ptr, "rrb")
					|| !ft_strcmp(*compared_str_ptr, "sa")
					|| !ft_strcmp(*compared_str_ptr, "sb")
					|| !ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrexcludenode(head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "pa"))
					ft_lststrnullboth(head, compared_str_ptr, operation_flags);
				else
					head = &(*head)->next;
			}
			else if (!ft_strcmp(*(*head)->content, "sa"))
			{
				if (!ft_strcmp(*compared_str_ptr, "ra")
					|| !ft_strcmp(*compared_str_ptr, "rr")
					|| !ft_strcmp(*compared_str_ptr, "rra")
					|| !ft_strcmp(*compared_str_ptr, "rrr")
					|| !ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb"))
					ft_lststrexcludenode(head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "sa"))
					ft_lststrnullboth(head, compared_str_ptr, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrreplace(&head, &compared_str_ptr, &operation_flags, "sb");
				else
					head = &(*head)->next;
			}
			else if (!ft_strcmp(*(*head)->content, "sb"))
			{
				if (!ft_strcmp(*compared_str_ptr, "ra")
					|| !ft_strcmp(*compared_str_ptr, "rr")
					|| !ft_strcmp(*compared_str_ptr, "rrb")
					|| !ft_strcmp(*compared_str_ptr, "rrr")
					|| !ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb"))
					ft_lststrexcludenode(head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "sb"))
					ft_lststrnullboth(head, compared_str_ptr, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrreplace(&head, &compared_str_ptr, &operation_flags, "sa");
				else
					head = &(*head)->next;
			}
			else if (!ft_strcmp(*(*head)->content, "ss"))
			{
				if (!ft_strcmp(*compared_str_ptr, "ra")
					|| !ft_strcmp(*compared_str_ptr, "rb")
					|| !ft_strcmp(*compared_str_ptr, "rr")
					|| !ft_strcmp(*compared_str_ptr, "rra")
					|| !ft_strcmp(*compared_str_ptr, "rrb")
					|| !ft_strcmp(*compared_str_ptr, "rrr")
					|| !ft_strcmp(*compared_str_ptr, "pa")
					|| !ft_strcmp(*compared_str_ptr, "pb"))
					ft_lststrexcludenode(head, operation_flags);
				else if (!ft_strcmp(*compared_str_ptr, "sa"))
					ft_lststrreplace(&head, &compared_str_ptr, &operation_flags, "sb");
				else if (!ft_strcmp(*compared_str_ptr, "sb"))
					ft_lststrreplace(&head, &compared_str_ptr, &operation_flags, "sa");
				else if (!ft_strcmp(*compared_str_ptr, "ss"))
					ft_lststrnullboth(head, compared_str_ptr, operation_flags);
				else
					head = &(*head)->next;
			}
		}
		if (ft_strcmp("", sequence_arr[index]))
		{
			ft_lststradd_back(&operation_flags,
				ft_lststrnew(sequence_arr + index));
		}
	}
	while (operation_flags)
	{
		tmp = operation_flags;
		operation_flags = operation_flags->next;
		free(tmp);
	}
	result_lst = NULL;
	index = -1;
	while (sequence_arr[++index])
		if (ft_strcmp("", sequence_arr[index]))
			ft_nodbinadd_front(&result_lst, ft_nodbinnew(
				ft_strjoin(" ", sequence_arr[index])));
	result_str = ft_nodbinstrjoin_from_back(result_lst);
	ft_nodbinclear(&result_lst, ft_nodbindel, -1);
	return (result_str);
}

typedef struct s_stack
{
	t_node_binary	*head;
	int				n;
}	t_stack;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_relative_pos
{
	t_2_int	*number_pos;
	int		n;
}	t_relative_pos;

typedef struct s_push_swap
{
	t_stack			a;
	t_stack			b;
	t_list			*sorted;
	t_relative_pos	relative_pos;
}	t_push_swap;

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = (unsigned char)0;
}

void	initialize_struct(t_push_swap *mystruct, int argc)
{
	ft_bzero(mystruct, sizeof(*mystruct));
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	contains_non_numeric(char *str)
{
	while (*str)
		if (!ft_isdigit(*str++))
			return (1);
	return (0);
}

#include <limits.h>
#include <unistd.h>

void	ft_lstdel(void *node)
{
	if (!node)
		return ;
	if (((t_list *)node)->content)
		free(((t_list *)node)->content);
	free(node);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

static void	free_mystruct(t_push_swap *mystruct)
{
	ft_nodbinclear(&mystruct->a.head, ft_nodbindel, mystruct->a.n);
	ft_nodbinclear(&mystruct->b.head, ft_nodbindel, mystruct->b.n);
	ft_lstclear(&mystruct->sorted, ft_lstdel);
}

void	ft_error(t_push_swap *mystruct)
{
	write(2, "Error\n", 6);
	free_mystruct(mystruct);
	exit(EXIT_FAILURE);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (n-- && *s1 && *s2)
	{
		if (!n || *s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static int	ft_isspace(const char c)
{
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int			is_negative;
	long int	result;

	if (ft_isspace(*nptr))
		return (ft_atoi(nptr + 1));
	is_negative = 0;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			is_negative = 1;
	result = 0;
	while (*nptr && ft_isdigit(*nptr))
	{
		if (result >= LONG_MAX / 10)
		{
			if (is_negative)
				result = LONG_MIN;
			else
				result = LONG_MAX;
			return (result);
		}
		result = result * 10 + (*nptr++ - '0');
	}
	if (is_negative)
		return (-result);
	return (result);
}

static void	test_is_str_valid_int(t_push_swap *mystruct, char *str)
{
	int	res;

	if (*str == '+')
		str++;
	if (*str == '-')
	{
		if (!*str || contains_non_numeric(str + 1))
			ft_error(mystruct);
	}
	else if (!*str || contains_non_numeric(str))
		ft_error(mystruct);
	res = ft_atoi(str);
	if (res == INT_MIN && ft_strncmp(str, "-2147483648", 11))
		ft_error(mystruct);
	if (res == INT_MAX && ft_strncmp(str, "2147483647", 10))
		ft_error(mystruct);
}

void	ft_lstsortedinsert_int(t_list **lst, t_list *new)
{
	t_list	**tail;

	if (!new || !lst)
		return ;
	tail = lst;
	while (*tail && *(int *)new->content > *(int *)(*tail)->content)
		tail = &(*tail)->next;
	new->next = (*tail);
	(*tail) = new;
}

int	*ft_intdup(int d)
{
	int	*result;

	result = malloc(sizeof(*result));
	if (!result)
		return ((int *)0);
	*result = d;
	return (result);
}

void	ft_nodbinadd_back(t_node_binary **lst, t_node_binary *new)
{
	t_node_binary	*cur;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	new->prev = cur;
}

void	ft_destroy_str_arr(char ***str)
{
	int	i;

	i = -1;
	while ((*str)[++i])
		free((*str)[i]);
	free(*str);
	*str = (char **)0;
}

static void	test_for_duplicates(t_push_swap *mystruct)
{
	t_list	*head;
	t_list	**lst;

	lst = &mystruct->sorted;
	if (!lst || !*lst)
		return ;
	head = *lst;
	while (head->next)
	{
		if (*(int *)(head->content) == *(int *)(head->next->content))
			ft_error(mystruct);
		head = head->next;
	}
}

static void	initialize_relative_positions(t_push_swap *mystruct)
{
	t_list			*cur_sorted;
	t_node_binary	*cur_stack;
	int				cur_stack_index;
	int				cur_sorted_index;

	mystruct->relative_pos.number_pos = malloc(mystruct->a.n
		* sizeof(*mystruct->relative_pos.number_pos));
	mystruct->relative_pos.n = mystruct->a.n;
	cur_sorted = mystruct->sorted;
	cur_sorted_index = 0;
	while (cur_sorted)
	{
		cur_stack_index = 0;
		cur_stack = mystruct->a.head;
		while (1)
		{
			if (*(int *)cur_stack->content == *(int *)cur_sorted->content)
			{
				mystruct->relative_pos.number_pos[cur_stack_index].a
					= *(int *)cur_stack->content;
				mystruct->relative_pos.number_pos[cur_stack_index].b
					= cur_sorted_index;
				break ;
			}
			cur_stack_index++;
			cur_stack = cur_stack->next;
		}
		cur_sorted_index++;
		cur_sorted = cur_sorted->next;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new_el;

	new_el = (t_list *)malloc(sizeof(*new_el));
	if (!new_el)
		return ((t_list *)0);
	new_el->content = content;
	new_el->next = (t_list *)0;
	return (new_el);
}

void	parse_input(t_push_swap *mystruct, int argc, char **argv)
{
	int				i;
	int				j;
	int				*nptr;
	t_list			*sorted;
	t_node_binary	*new;
	char			**str_arr;

	i = 1;
	sorted = (t_list *)0;
	while (i < argc)
	{
		str_arr = ft_split(argv[i], ' ');
		j = -1;
		while (str_arr[++j])
		{
			test_is_str_valid_int(mystruct, str_arr[j]);
			nptr = malloc(sizeof(*nptr));
			if (!nptr)
				ft_error(mystruct);
			*nptr = ft_atoi(str_arr[j]);
			ft_lstsortedinsert_int(&sorted, ft_lstnew(nptr));
			new = ft_nodbinnew(ft_intdup(*nptr));
			if (!new)
				ft_error(mystruct);
			ft_nodbinadd_back(&mystruct->a.head, new);
			mystruct->a.n++;
		}
		ft_destroy_str_arr(&str_arr);
		if (++i == argc)
		{
			new->next = mystruct->a.head;
			mystruct->a.head->prev = new;
		}
	}
	mystruct->sorted = sorted;
	test_for_duplicates(mystruct);
	initialize_relative_positions(mystruct);
}

static int	reset_ret(char **line, int ret, char **buf_p)
{
	if (!ret && line)
	{
		*line = malloc(1);
		**line = '\0';
	}
	if (buf_p)
	{
		free(*buf_p);
		*buf_p = (char *)0;
	}
	return (ret);
}

#define BUFFER_SIZE 40

int	contains_newline(char *str, size_t n)
{
	size_t	index_of_newline;

	index_of_newline = 0;
	while (index_of_newline < n)
	{
		if (str[index_of_newline] == '\n')
			return ((int)index_of_newline);
		index_of_newline++;
	}
	return (index_of_newline);
}

static char	*strjoin_return_helper(char *s1, char *s2)
{
	if (!s1 && s2)
		return (s2);
	if (s1 && !s2)
		return (s1);
	return ((char *)0);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;
	char	*r;
	char	*tmp;

	if (!s1 || !s2)
		return (strjoin_return_helper(s1, s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(s1_len + s2_len + 1);
	if (!new)
		return ((char *)0);
	r = new;
	tmp = s1;
	while (s1_len--)
		*r++ = *tmp++;
	free(s1);
	tmp = s2;
	while (s2_len--)
		*r++ = *tmp++;
	free(s2);
	*r = '\0';
	return (new);
}

char	*ft_strdup_v2(const char *s, int n)
{
	char	*new;
	char	*r;

	new = (char *)malloc(n + 1);
	if (!new)
		return ((char *)0);
	r = new;
	while (n--)
		*new++ = *s++;
	*new = '\0';
	return (r);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*r;

	if (!dest && !src)
		return (dest);
	r = dest;
	while (n--)
	{
		if (src > dest)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
		else
			*((unsigned char *)dest + n) = *((unsigned char *)src + n);
	}
	return (r);
}

int	get_next_line(int fd, char **line)
{
	int				tmp_index;
	int				buf_len;
	static char		*buffers[OPEN_MAX] = {0};

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!buffers[fd])
	{
		buffers[fd] = malloc(BUFFER_SIZE + 1);
		if (!buffers[fd])
			return (-1);
		buf_len = BUFFER_SIZE;
		tmp_index = read(fd, buffers[fd], BUFFER_SIZE);
		if (tmp_index <= 0)
			return (reset_ret(line, tmp_index, &buffers[fd]));
		buffers[fd][tmp_index] = '\0';
		return (get_next_line(fd, line));
	}
	buf_len = ft_strlen(buffers[fd]);
	tmp_index = contains_newline(buffers[fd], buf_len);
	if (tmp_index == buf_len)
	{
		char	*tmp_str;
		int		tmp_index;

		tmp_str = ft_strdup_v2(buffers[fd], buf_len);
		free(buffers[fd]);
		buf_len += BUFFER_SIZE;
		buffers[fd] = malloc(buf_len + 1);
		tmp_index = read(fd, buffers[fd], BUFFER_SIZE);
		if (tmp_index <= 0)
		{
			if (tmp_index == 0)
				*line = tmp_str;
			else
				free(tmp_str);
			return (reset_ret((char **)0, tmp_index, &buffers[fd]));
		}
		buffers[fd][tmp_index] = '\0';
		buffers[fd] = ft_strjoin_free(tmp_str, buffers[fd]);
		return (get_next_line(fd, line));
	}
	*line = ft_strdup_v2(buffers[fd], tmp_index);
	ft_memmove(buffers[fd], buffers[fd] + tmp_index + 1, buf_len - tmp_index);
	return (1);
}

static void	destroy_operations(t_push_swap *mystruct, char ***operations,
int index)
{
	while (index--)
		free((*operations)[index]);
	free(*operations);
	ft_error(mystruct);
}

void	swap_nodbin_ptrs(t_node_binary **a, t_node_binary **b)
{
	t_node_binary	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_helper_case_3(t_stack *stack)
{
	t_node_binary	*cur_head;
	t_node_binary	*after_head;
	t_node_binary	*before_head;
	t_node_binary	*before_before_head;

	cur_head = stack->head;
	before_head = cur_head->prev;
	after_head = cur_head->next;
	cur_head->next = before_head;
	cur_head->prev = after_head;
	before_head->next = after_head;
	before_head->prev = cur_head;
	after_head->next = cur_head;
	after_head->prev = before_head;
	swap_nodbin_ptrs(&stack->head, &stack->head->prev);
}

void	swap_helper_case_g3(t_stack *stack)
{
	t_node_binary	*cur_head;
	t_node_binary	*after_head;
	t_node_binary	*before_head;
	t_node_binary	*after_after_head;

	cur_head = stack->head;
	after_head = cur_head->next;
	before_head = cur_head->prev;
	after_after_head = after_head->next;
	after_after_head->prev = cur_head;
	before_head->next = after_head;
	cur_head->next = after_after_head;
	cur_head->prev = after_head;
	after_head->next = cur_head;
	after_head->prev = before_head;
	swap_nodbin_ptrs(&stack->head, &stack->head->prev);
}

static void	remove_head_helper(t_stack *stack)
{
	t_node_binary	*after_head;
	t_node_binary	*prev_head;

	after_head = stack->head->next;
	prev_head = stack->head->prev;
	prev_head->next = after_head;
	after_head->prev = prev_head;
	stack->head = after_head;
}

t_node_binary	*remove_head_from_stack(t_stack *stack)
{
	t_node_binary	*r;

	if (!stack->n)
		return ((t_node_binary *)0);
	r = stack->head;
	if (stack->n == 1)
		stack->head = (t_node_binary *)0;
	else if (stack->n == 2)
	{
		stack->head = stack->head->prev;
		stack->head->next = stack->head;
		stack->head->prev = stack->head;
	}
	else
		remove_head_helper(stack);
	stack->n--;
	r->next = r;
	r->prev = r;
	return (r);
}

void	push_helper(t_stack *pushed, t_stack *popped)
{
	t_node_binary	*prev_head;
	t_node_binary	*cur_head;

	prev_head = pushed->head->prev;
	cur_head = pushed->head;
	pushed->head = remove_head_from_stack(popped);
	cur_head->prev = pushed->head;
	prev_head->next = pushed->head;
	pushed->head->prev = prev_head;
	pushed->head->next = cur_head;
}

void	stack_sa(t_push_swap *mystruct)
{
	if (mystruct->a.n < 2)
		return ;
	if (mystruct->a.n == 2)
		mystruct->a.head = mystruct->a.head->next;
	else if (mystruct->a.n == 3)
		swap_helper_case_3(&mystruct->a);
	else
		swap_helper_case_g3(&mystruct->a);
}

void	stack_sb(t_push_swap *mystruct)
{
	if (mystruct->b.n < 2)
		return ;
	if (mystruct->b.n == 2)
		mystruct->b.head = mystruct->b.head->next;
	else if (mystruct->b.n == 3)
		swap_helper_case_3(&mystruct->b);
	else
		swap_helper_case_g3(&mystruct->b);
}

void	stack_ss(t_push_swap *mystruct)
{
	stack_sa(mystruct);
	stack_sb(mystruct);
}

void	stack_pa(t_push_swap *mystruct)
{
	t_node_binary	*cur_head;

	if (!mystruct->b.n)
		return ;
	if (!mystruct->a.n)
		mystruct->a.head = remove_head_from_stack(&mystruct->b);
	else if (mystruct->a.n == 1)
	{
		cur_head = mystruct->a.head;
		mystruct->a.head = remove_head_from_stack(&mystruct->b);
		cur_head->next = mystruct->a.head;
		cur_head->prev = mystruct->a.head;
		mystruct->a.head->next = cur_head;
		mystruct->a.head->prev = cur_head;
	}
	else
		push_helper(&mystruct->a, &mystruct->b);
	mystruct->a.n++;
}

void	stack_pb(t_push_swap *mystruct)
{
	t_node_binary	*cur_head;

	if (!mystruct->a.n)
		return ;
	if (!mystruct->b.n)
		mystruct->b.head = remove_head_from_stack(&mystruct->a);
	else if (mystruct->b.n == 1)
	{
		cur_head = mystruct->b.head;
		mystruct->b.head = remove_head_from_stack(&mystruct->a);
		cur_head->next = mystruct->b.head;
		cur_head->prev = mystruct->b.head;
		mystruct->b.head->next = cur_head;
		mystruct->b.head->prev = cur_head;
	}
	else
		push_helper(&mystruct->b, &mystruct->a);
	mystruct->b.n++;
}

void	stack_ra(t_push_swap *mystruct)
{
	if (mystruct->a.n > 1)
		mystruct->a.head = mystruct->a.head->next;
}

void	stack_rb(t_push_swap *mystruct)
{
	if (mystruct->b.n > 1)
		mystruct->b.head = mystruct->b.head->next;
}

void	stack_rr(t_push_swap *mystruct)
{
	stack_ra(mystruct);
	stack_rb(mystruct);
}

void	stack_rra(t_push_swap *mystruct)
{
	if (mystruct->a.n > 1)
		mystruct->a.head = mystruct->a.head->prev;
}

void	stack_rrb(t_push_swap *mystruct)
{
	if (mystruct->b.n > 1)
		mystruct->b.head = mystruct->b.head->prev;
}

void	stack_rrr(t_push_swap *mystruct)
{
	stack_rra(mystruct);
	stack_rrb(mystruct);
}

void	execute_operations(t_push_swap *mystruct, char **operations,
int number_of_ops)
{
	static	void	(*functions[])(t_push_swap *) = {stack_sa, stack_sb,
		stack_ss, stack_pa, stack_pb, stack_ra, stack_rb, stack_rr, stack_rra,
		stack_rrb, stack_rrr};
	static char		*operation_names[] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr", (char *)0};
	char			*str;
	int				str_index;
	int				i;

	i = -1;
	while (++i < number_of_ops)
	{
		str_index = -1;
		while (ft_strncmp(operations[i], operation_names[++str_index], 3))
			;
		(*functions[str_index])(mystruct);
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;

	if (size && nmemb > (size_t)(-1) / size)
		return ((void *)0);
	size *= nmemb;
	r = malloc(size);
	if (!r)
		return ((void *)0);
	ft_bzero(r, size);
	return (r);
}


void	*ft_realloc(void *src, size_t size)
{
	void	*new;

	new = ft_calloc(1, size);
	if (!new)
	{
		if (src)
			free(src);
		return ((void *)0);
	}
	if (!src)
		return (new);
	// Wrong
	ft_memmove(new, src, size);
	free(src);
	return (new);
}

static int	valid_function_name(char *str)
{
	int			i;
	static char	*operation_names[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr", (char *)0};

	if (!str)
		return (0);
	i = -1;
	while (operation_names[++i])
		if (!ft_strncmp(str, operation_names[i], 3))
			return (1);
	return (0);
}

void	read_operations(t_push_swap *mystruct)
{
	char		**operations;
	int			op_index;
	int			read_bytes;

	op_index = 0;
	operations = (char **)0;
	while (1)
	{
		operations = ft_realloc(operations, ++op_index * sizeof(*operations));
		read_bytes = get_next_line(0, operations + op_index - 1);
		if (read_bytes < 0)
			destroy_operations(mystruct, &operations, op_index - 1);
		if (!read_bytes)
			break ;
	}
	while (read_bytes < op_index - 1)
		if (!valid_function_name(operations[read_bytes++]))
			destroy_operations(mystruct, &operations, op_index);
	int i = -1;
	while (operations[++i])
		printf("%s ", operations[i]);
	printf("\nNumber of operations before crunching: %d\n", i);
	char *sequence = crunch_sequence(operations);
	printf("Sequence: %s\n", sequence);
	printf("Number of operations after crunching: %d\n", ft_n_of_words_by_delim(sequence, ' '));
	execute_operations(mystruct, operations, op_index - 1);
	ft_destroy_str_arr(&operations);
}

int	calc_entropy(t_stack *stack)
{
	int				entropy;
	int				i;
	t_node_binary	*cur;

	cur = stack->head;
	entropy = 0;
	i = -1;
	while (++i < stack->n - 1)
	{
		if (*(int *)(cur->content) > *(int *)(cur->next->content))
			entropy++;
		cur = cur->next;
	}
	if (stack->n > 2 && *(int *)(stack->head->content)
		> *(int *)(stack->head->prev->content))
		entropy++;
	return (entropy);
}

void	update_entropies(t_push_swap *mystruct, int *entr_a, int *entr_b)
{
	*entr_a = calc_entropy(&mystruct->a);
	*entr_b = calc_entropy(&mystruct->b);
}

int	is_solution(t_push_swap *mystruct)
{
	int				entr_a;
	int				entr_b;
	int				i;
	t_node_binary	*cur;

	update_entropies(mystruct, &entr_a, &entr_b);
	if (entr_a || entr_b || mystruct->b.n)
		return (0);
	cur = mystruct->a.head;
	i = -1;
	while (++i < mystruct->a.n - 1)
	{
		if (*(int *)(cur->content) > *(int *)(cur->next->content))
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_push_swap	mystruct;

	if (argc < 2)
		return (0);
	initialize_struct(&mystruct, argc);
	parse_input(&mystruct, argc, argv);
	read_operations(&mystruct);
	if (is_solution(&mystruct))
		printf("OK\n");
	else
		printf("KO\n");
	return (0);
}
