#include "main.h"
#include "monty.h"

/**
 * tokenize - used to tokenize the argument that is passed
 *
 * @str: the string passed to tokenize
 * Return: char**
 */
char **tokenize(char *str)
{
	char **matrix, *tmp;
	int i, k = 0, len = 0, words, c = 0, start, end;

	len = strlen(str);
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **)malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (isspace(str[i]) || str[i] == '\0' || str[i] == '\n')
		{
			if (c)
			{
				end = i;
				tmp = (char *)malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;

	return (matrix);
}

/**
 * convert - check each character and convert to integer
 *
 * @str: the string passed to convert
 * Return: int
 */
int convert(char *str)
{
	int i = 0;
	int len = strlen(str);

	if (len == 0)
	{
		fprintf(stderr, "L%d: usage: %s integer\n",
		data.line_count, data.word[0]);
		free_stack(1);
		exit(EXIT_FAILURE);
	}
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
		{
			fprintf(stderr, "L%d: usage: %s integer\n",
			data.line_count, data.word[0]);
			free_stack(1);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (atoi(str));
}

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int flag, c, w;

	flag = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}

/**
 * get_line - Get the line object
 * @line_ptr: double pointer
 * @n: unsigned int
 * @stream: file stream
 * Return: ssize_t
 */
ssize_t get_line(char **line_ptr, size_t *n, FILE *stream)
{
	size_t len = 0;
	int c;
	char *temp, *line = NULL;

	if (line_ptr == NULL || n == NULL)
		return (-1);
	do {
		c = fgetc(stream);
		if (c == EOF)
			break;
		if (len == 0)
		{
			*n = 16;
			line = malloc(*n);
			if (line == NULL)
				return (-1);
		}
		line[len++] = c;
		if (c == '\n')
			break;
		if (len == *n)
		{
			*n *= 2;
			temp = realloc(line, *n);
			if (temp == NULL)
			{
				free(line);
				return (-1);
			}
			line = temp;
		}
	} while (1);
	if (len == 0)
	{
		free(line);
		return (-1);
	}
	line[len] = '\0';
	*line_ptr = line;
	return (len);
}
