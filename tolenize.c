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
    int len = strlen(str);
    char **tokens = malloc(len * sizeof(char *));
    int index = 0;
    if (tokens == NULL)
    {
        printf("Error: malloc failed\n");
        free_stack(1);
        exit(EXIT_FAILURE);
    }
    int i = 0;
    tokens[0] = malloc(len * sizeof(char *));
    if (tokens[0] == NULL)
    {
        printf("Error: malloc failed\n");
        free_stack(1);
        exit(EXIT_FAILURE);
    }
    while (str[i] != '\0')
    {
        if (isspace(str[i]))
        {
            i++;
            tokens[0][index++] = '\0';
            break;
        }
        tokens[0][index++] = str[i];
        i++;
    }
    tokens[1] = malloc(len * sizeof(char *));
    if (tokens[1] == NULL)
    {
        printf("Error: malloc failed\n");
        free_stack(1);
        exit(EXIT_FAILURE);
    }
    index = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            break;
        tokens[1][index++] = str[i];
        i++;
    }
    tokens[1][index++] = '\0';
    return (tokens);
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
