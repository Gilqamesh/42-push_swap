#include <stdio.h>
#include <stdlib.h>

# ifndef T_2_INT
#  define T_2_INT
typedef struct s_2_int
{
	int	a;
	int	b;
}	t_2_int;
# endif
# ifndef T_3_INT
#  define T_3_INT
typedef struct s_3_int
{
	int	a;
	int	b;
	int	c;
}	t_3_int;
# endif

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

static void	ft_merge_sort_copy(char **in, t_2_int start_end_indexes,
char **out)
{
	int	i;

	i = start_end_indexes.a - 1;
	while (++i < start_end_indexes.b)
		out[i] = in[i];
}

static void	ft_merge_sort_comb(char **in, t_3_int start_mid_end_indexes,
char **out)
{
	int	i;
	int	j;
	int	k;

	i = start_mid_end_indexes.a;
	j = start_mid_end_indexes.b;
	k = i - 1;
	while (++k < start_mid_end_indexes.c)
	{
		if (i < start_mid_end_indexes.b && (j >= start_mid_end_indexes.c
			|| ft_strcmp(in[i], in[j]) <= 0))
		{
			out[k] = in[i];
			i++;
		}
		else
		{
			out[k] = in[j];
			j++;
		}
	}
}

void	ft_merge_sort_str(char **array, t_2_int start_end_indexes,
char **helper_array)
{
	int	middle;

	if (start_end_indexes.b - start_end_indexes.a < 2)
		return ;
	middle = (start_end_indexes.a + start_end_indexes.b) / 2;
	ft_merge_sort_str(array, (t_2_int){start_end_indexes.a, middle},
		helper_array);
	ft_merge_sort_str(array, (t_2_int){middle, start_end_indexes.b},
		helper_array);
	ft_merge_sort_comb(array, (t_3_int){start_end_indexes.a, middle,
		start_end_indexes.b}, helper_array);
	ft_merge_sort_copy(helper_array, (t_2_int){start_end_indexes.a,
		start_end_indexes.b}, array);
}

int main(void)
{
	char *words[10] = {
		(char *){"12345"},
		(char *){"23554"},
		(char *){"23443"},
		(char *){"43289"},
		(char *){"34242"},
		(char *){"43242"},
		(char *){"asdds"},
		(char *){"43243"},
		(char *){"sdfad"},
		(char *){"23142"}
	};
	char *helper[10];
	ft_merge_sort_str(words, (t_2_int){0, 10}, helper);
	for (int i = 0; i < 10; i++)
		printf("%s\n", words[i]);
	return (0);
}
