#include "main.h"
#include "lists.h"

/**
 * @brief 
 * 
 * @param str 
 * @return char** 
 */
char **tokenize(char *str)
{
    char **matrix, *tmp;
	int i, k = 0, len = 0, words, c = 0, start, end;

	len = strlen(str);
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (isspace(str[i]) || str[i] == '\0' || str[i] == '\n')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
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
 * @brief 
 * 
 * @param str 
 * @return int 
 */
int convert(char *str)
{
    int i = 0;
    int len = strlen(str);
    if (len == 0)
    {
        printf("L%d: usage: %s integer\n", data.line_count, data.word[0]);
        free_stack(1);
        exit(EXIT_FAILURE);
    }
    while (str[i] != '\0')
    {
        if (!isdigit(str[i]))
        {
            printf("L%d: usage: %s integer\n", data.line_count, data.word[0]);
            free_stack(1);
            exit(EXIT_FAILURE);
        }
        i++;
    }
    return (atoi(str));
}
