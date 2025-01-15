/*
** EPITECH PROJECT, 2025
** B-MAT-100-BAR-1-1-103cipher-andrei.kocherzhinskii
** File description:
** calc2
*/

#include <ctype.h>
#include "my.h"

double compute_dot_product(matrix_t *mat1,
    matrix_t *mat2, int row, int col)
{
    double sum = 0;

    for (int k = 0; k < mat1->cols; k++) {
        sum += mat1->data[row][k] * mat2->data[k][col];
    }
    return sum;
}

void multiply_matrices(matrix_t *mat1, matrix_t *mat2, matrix_t *result)
{
    if (mat2->rows == 1 && mat2->cols == 1) {
        multiply_by_scalar(mat1, mat2, result);
    } else {
        standard_matrix_multiplication(mat1, mat2, result);
    }
}

void standard_matrix_multiplication(matrix_t *mat1,
    matrix_t *mat2, matrix_t *result)
{
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            result->data[i][j] = 0;
            result->data[i][j] = compute_dot_product(mat1, mat2, i, j);
        }
    }
}

void initialize_key_matrix(char *key, matrix_t *key_matrix)
{
    int key_size;

    if (isdigit(key[0])) {
        key_size = 1;
        *key_matrix = create_matrix(1, 1);
        key_matrix->data[0][0] = (double)atoi(key);
    } else {
        key_size = (int)ceil(sqrt((double)strlen(key)));
        *key_matrix = create_matrix(key_size, key_size);
        str_to_ascii_matrix(key, key_matrix);
    }
}

void parse_encrypted_message(char *message, matrix_t *matrix)
{
    char *copy = strdup(message);
    char *token = strtok(copy, " ");

    for (int i = 0; i < matrix->rows; i++) {
        fill_matrix_row_from_tokens(&token, matrix->data[i], matrix->cols);
    }
    free(copy);
}
