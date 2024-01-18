#include "monty.h"

/**
 * removeWhiteSpace - helper function used to remove white space
 * @str: the string passed
 * Return: void
 */
void removeWhiteSpace(char *str)
{
	char *p1 = str; /* pointer to iterate through the input string */
	char *p2 = str; /* pointer to write the non-space characters to */
	bool space = false;

	while (isspace(*p1))
	{
		p1++;
	}

	while (*p1 != '\0')
	{
		if (isspace(*p1))
		{
			if (!space)
			{
				*p2 = *p1;
				p2++;
				space = true;
			}
		}
		else
		{
			*p2 = *p1;
			p2++;
			space = false;
		}
		p1++;
	}

	if (isspace(*(p2 - 1)))
	{
		*(p2 - 1) = '\0';
	}

	*p2 = '\0';
}

/**
 * nod_len - returns the number of elements in a linked  list.
 * @stack: double node
 * Return: size_t
 */
int nod_len(stack_t **stack)
{
	int count = 0;
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

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
