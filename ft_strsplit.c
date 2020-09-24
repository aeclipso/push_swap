#include <stdlib.h>
// #include <unistd.h>

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*arr;
	size_t			i;
	size_t			j;

	if (!s || !(arr = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	j = start;
	while (i < len && s[j])
	{
		arr[i] = s[j];
		i++;
		j++;
	}
	arr[i] = 0;
	return (arr);
}


static size_t			ft_counterwords(char const *s, char c)
{
	size_t		quantity_words;
	size_t		iter_letter;

	quantity_words = 0;
	iter_letter = 0;
	if (!s)
		return (0);
	while (s[iter_letter])
	{
		if (s[iter_letter] != c && (s[iter_letter + 1] == c
		|| s[iter_letter + 1] == 0))
			quantity_words++;
		iter_letter++;
	}
	return (quantity_words);
}

static size_t				ft_lengthcounter(char const *s, char c)  //оставить, но убрать из файла
{
	size_t			length;
	static size_t	iter_letter;		// iter_words++;

	length = 0;
	if (!s)
		return (0);
	while (s[iter_letter] == c)
		iter_letter++;
	while (s[iter_letter] && s[iter_letter] != c)
	{
		length++;
		iter_letter++;
	}
	return (length);
}

static void				ft_copyword(char **word, char const *s, char c) //оставить но убрать из файла
{
	static size_t	next_word;
	size_t			i;

	i = 0;
	while (s[next_word] == c)
		next_word++;
	while (s[next_word] != c && s[next_word] != 0)
	{
		(*word)[i] = s[next_word];
		i++;
		next_word++;
	}
	(*word)[i] = 0;
}

static void			*ft_deleter(size_t iter_words, char **result_arr)
{
	iter_words--;
	while (iter_words >= 0)
	{
		free(result_arr[iter_words]);
		result_arr[iter_words] = NULL;
		iter_words--;
	}
	free(result_arr);
	result_arr = NULL;
	return (NULL);
}

static size_t		ft_finddelim(char const *s, char c)
{
	size_t			i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

#include <stdio.h>

char			**ft_strsplit(char const *s, char c)
{
	size_t		quantity_words;
	size_t		quantity_letter;
	size_t		iter_words;
	char		**result_arr;

	iter_words = 0;
	quantity_words = ft_counterwords(s, c);
	if(!quantity_words
	|| !(result_arr = (char **)malloc(sizeof(char *) * (quantity_words + 1))))
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		quantity_letter = ft_finddelim(s, c);
		if (!(result_arr[iter_words++] = ft_strsub(s, 0, quantity_letter)))
			return(ft_deleter(quantity_words, result_arr));
		s += quantity_letter;
	}
	result_arr[iter_words] = NULL;
	return (result_arr);
}
