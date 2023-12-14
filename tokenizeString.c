#include <stdlib.h>
int get_word_count(char *str, char *delimiters);

char **strtow(char *str, char *delimiters);
int get_word_len(char *str, char *delimiters);
char *get_next_word(char *str, char *delimiters);
int is_delim(char ch, char *delimiters);


/**
 * strtow - takes a string and seperates its words
 *
 * @str: string to seperate into words
 * @delimiters: delimiters to use to delimit words
 *
 * Return: 2D array of pointers to each word
 */

char **strtow(char *str, char *delimiters)
{
	char **words = NULL;
	int w_count, wordLength = 0;
int f, r = 0;

	if (str == NULL || !*str)
		return (NULL);
	w_count = get_word_count(str, delimiters);


	if (w_count == 0)
		return (NULL);
	words = malloc((w_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (r < w_count)
	{
		wordLength = get_word_len(str, delimiters);
		if (is_delim(*str, delimiters))
		{
			str = get_next_word(str, delimiters);
		}
		words[r] = malloc((wordLength + 1) * sizeof(char));
		if (words[r] == NULL)
		{
			while (r >= 0)
			{
				r--;
				free(words[r]);
			}
			free(words);
			return (NULL);
		}
		f = 0;
		while (f < wordLength)
		{
			words[r][f] = *(str + f);
			f++;
		}
		words[r][f] = '\0'; /* set end of str */
		str = get_next_word(str, delimiters);
		r++;
	}
	words[r] = NULL; /* last element is null for iteration */
	return (words);
}

/**
 * is_delim - checks if stream has delimitor char
 *
 * @ch: character in stream
 *
 * @delimiters: Pointer to null terminated array of delimitors
 *
 * Return: 1 (success) 0 (failure)
 */

int is_delim(char ch, char *delimiters)
{
	int y = 0;

	while (delimiters[y])
	{
		if (delimiters[y] == ch)
			return (1);
		y++;
	}
	return (0);
}

/**
 * get_word_len - gets the word length of cur word in str
 *
 * @str: string to get word length from current word
 * @delimiters: delimitors to use to delimit words
 *
 * Return: word length of current word
 */

int get_word_len(char *str, char *delimiters)
{
	int wLen = 0, on_pending = 1;
int u = 0;

	while (*(str + u))
	{
		if (is_delim(str[u], delimiters))
			on_pending = 1;
		else if (on_pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[u], delimiters))
			break;
		u++;
	}
	return (wLen);
}

/**
 * get_word_count - gets the word count of a string
 *
 * @str: string to get word count from
 * @delimiters: delimitors to use to delimit words
 *
 * Return: the word count of the string
 */

int get_word_count(char *str, char *delimiters)
{
	int w_count = 0, on_pending = 1;
int j = 0;

	while (*(str + j))
	{
		if (is_delim(str[j], delimiters))
			on_pending = 1;
		else if (on_pending)
		{
			on_pending = 0;
			w_count++;
		}
		j++;
	}
	return (w_count);
}

/**
 * get_next_word - gets the next word in a string
 *
 * @str: string to get next word from
 * @delimiters: delimitors to use to delimit words
 *
 * Return: pointer to first char of next word
 */

char *get_next_word(char *str, char *delimiters)
{
	int on_pending = 0;
	int y = 0;

	while (*(str + y))
	{
		if (is_delim(str[y], delimiters))
			on_pending = 1;
		else if (on_pending)
			break;
		y++;
	}
	return (str + y);
}
