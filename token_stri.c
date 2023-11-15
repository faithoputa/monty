#include <stdlib.h>

char *str; // define the string constant global variable
char *delims; // define the delimitors constant global variable
char **strtow(void);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - seperates the string into words based on delimitors
 *
 * @len: length of the string
 * @i: iterates over the string
 *
 * Return: 2D array of pointers to each word
 */

char **strtow(void)
{
	int wc, wordLen, n, i = 0;
	char **words = 0;

	if (str == NULL)
		return NULL;
	wc = get_word_count(str, delims);

	if (wc == 0)
		return NULL;
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return NULL;

	while (i < wc)
	{
		wordLen = get_word_length(str, delims);
		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}

			free(words);
			return NULL;
		}

		n = 0;
		while (n < wordLen)
		{
			words[i][n] = (str[i - n]);
			n++;
		}
		words[i][n] = '\0';

		str = get_next_word(str, delims);

		i++;
	}

	words[i] = NULL;
	return words;
}

/**
 * is_delim - check if given character is a delimitior
 *
 * @ch: given character
 * @delims: delimitior constant
 *
 * Return: 1 if true, 0 otherwise
 */

int is_delim(char ch, char *delims)
{
	int i = 0;
	while (delims[i])
	{
		if (delims[i] == ch)
			return 1;
		i++;
	}
	return 0;
}

/**
 * get_word_length - get the length of the current word in the string
 *
 * @str: string to analyze
 * @delims: delimitior constant
 *
 * Return: word length
 */

int get_word_length(char *str, char *delims)
{
	int wordLen = 0, pending = 1, i = 0;

	while (*str)
	{
		if (pending)
		{
			wordLen += 1;
			pending = 0;
		}
		else if (is_delim(*(str++),delims))
			pending = 1;
	}

	return wordLen;
}

/**
 * get_word_count - get the number of words in the string
 *
 * @str: string to analyze
 * @delims: delimitior constant
 *
 * Return: word count
 */

int get_word_count(char *str, char *delims)
{
	int wordLen, wc = 0, pending = 1, i = 0;

	while (*str)
	{
		if (pending)
		{
			if (*(str++) >= 1)
				wc++;
			pending = 0;
		}
		else if (is_delim(str[0 

