/*
** EPITECH PROJECT, 2024
** calculations
** File description:
** calc
*/

#include "my.h"
#include <ctype.h>

double calculate_determinant_3x3(matrix_t *matrix)
{
    double det = matrix->data[0][0] * (matrix->data[1][1] * matrix->data[2][2]
    - matrix->data[1][2] * matrix->data[2][1]) - matrix->data[0][1] *
    (matrix->data[1][0] * matrix->data[2][2] - matrix->data[1][2] *
    matrix->data[2][0]) + matrix->data[0][2] * (matrix->data[1][0] *
    matrix->data[2][1] - matrix->data[1][1] * matrix->data[2][0]);

    return det;
}

static int is_numeric_key(const char *str)
{
    int i = 0;

    if (str[0] == '-' && str[1] != '\0')
        i++;
    for (; str[i] != '\0'; i++) {
        if (!isdigit((unsigned char)str[i]))
            return 0;
    }
    return 1;
}

int calculate_key_size(char *key)
{
    int key_length;

    if (is_numeric_key(key)) {
        return 1;
    } else {
        key_length = (int)strlen(key);
        return (int)ceil(sqrt((double)key_length));
    }
}

int calculate_message_rows(char *message, int key_size)
{
    int num_integers;
    int message_rows;

    num_integers = count_integers_in_string(message);
    message_rows = (int)ceil((double)num_integers / key_size);
    return message_rows;
}

int count_integers_in_string(const char *str)
{
    int count = 0;
    char *copy = strdup(str);
    char *token = strtok(copy, " ");

    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    free(copy);
    return count;
}

void multiply_by_scalar(matrix_t *mat1,
    matrix_t *scalar_matrix, matrix_t *result)
{
    double scalar = scalar_matrix->data[0][0];

    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            result->data[i][j] = mat1->data[i][j] * scalar;
        }
    }
}
