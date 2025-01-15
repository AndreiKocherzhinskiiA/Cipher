/*
** EPITECH PROJECT, 2024
** matrix
** File description:
** matrix
*/

#include "my.h"

matrix_t create_matrix(int rows, int cols)
{
    matrix_t matrix;

    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = malloc(rows * sizeof(double *));
    if (!matrix.data) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(84);
    }
    for (int i = 0; i < rows; i++) {
        matrix.data[i] = malloc(cols * sizeof(double));
        if (!matrix.data[i]) {
            fprintf(stderr, "Error: Memory allocation failed.\n");
            exit(84);
        }
        for (int j = 0; j < cols; j++) {
            matrix.data[i][j] = 0.0;
        }
    }
    return matrix;
}

void free_matrix(matrix_t matrix)
{
    for (int i = 0; i < matrix.rows; i++) {
        free(matrix.data[i]);
    }
    free(matrix.data);
}

void fill_matrix_row(double *row, int cols, StringData_t *string_data)
{
    for (int j = 0; j < cols; j++) {
        if (string_data->index < string_data->length) {
            row[j] = (double)string_data->string[string_data->index];
            string_data->index++;
        } else {
            row[j] = 0.0;
        }
    }
}

void str_to_ascii_matrix(char *string, matrix_t *matrix)
{
    StringData_t string_data = {string, (int)strlen(string), 0};

    for (int i = 0; i < matrix->rows; i++) {
        fill_matrix_row(matrix->data[i], matrix->cols, &string_data);
    }
}

double calculate_dot_product(int size, double *row, double *col)
{
    double sum = 0.0;

    for (int k = 0; k < size; k++) {
        sum += row[k] * col[k];
    }
    return sum;
}
