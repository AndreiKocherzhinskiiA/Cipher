/*
** EPITECH PROJECT, 2024
** inverse
** File description:
** inverse
*/

#include "my.h"

void extract_column(matrix_t *matrix, int col_index, double *col)
{
    for (int i = 0; i < matrix->rows; i++) {
        col[i] = matrix->data[i][col_index];
    }
}

void exit_if_not_square(matrix_t *matrix)
{
    if (matrix->rows != matrix->cols) {
        fprintf(stderr, "Error: Only square matrices can be inverted.\n");
        exit(84);
    }
}

void fill_inverse_3x3(matrix_t *matrix, matrix_t *inverse, double det)
{
    inverse->data[0][0] = ((matrix->data[1][1] * matrix->data[2][2]) -
    (matrix->data[1][2] * matrix->data[2][1])) / det;
    inverse->data[0][1] = ((matrix->data[0][2] * matrix->data[2][1]) -
    (matrix->data[0][1] * matrix->data[2][2])) / det;
    inverse->data[0][2] = ((matrix->data[0][1] * matrix->data[1][2]) -
    (matrix->data[0][2] * matrix->data[1][1])) / det;
    inverse->data[1][0] = ((matrix->data[1][2] * matrix->data[2][0]) -
    (matrix->data[1][0] * matrix->data[2][2])) / det;
    inverse->data[1][1] = ((matrix->data[0][0] * matrix->data[2][2]) -
    (matrix->data[0][2] * matrix->data[2][0])) / det;
    inverse->data[1][2] = ((matrix->data[0][2] * matrix->data[1][0]) -
    (matrix->data[0][0] * matrix->data[1][2])) / det;
    inverse->data[2][0] = ((matrix->data[1][0] * matrix->data[2][1]) -
    (matrix->data[1][1] * matrix->data[2][0])) / det;
    inverse->data[2][1] = ((matrix->data[0][1] * matrix->data[2][0]) -
    (matrix->data[0][0] * matrix->data[2][1])) / det;
    inverse->data[2][2] = ((matrix->data[0][0] * matrix->data[1][1]) -
    (matrix->data[0][1] * matrix->data[1][0])) / det;
}

void fill_inverse_2x2(matrix_t *matrix, matrix_t *inverse, double det)
{
    inverse->data[0][0] = matrix->data[1][1] / det;
    inverse->data[0][1] = -matrix->data[0][1] / det;
    inverse->data[1][0] = -matrix->data[1][0] / det;
    inverse->data[1][1] = matrix->data[0][0] / det;
}

static matrix_t invert_1x1_matrix(matrix_t *matrix)
{
    matrix_t inverse = create_matrix(1, 1);

    if (matrix->data[0][0] == 0) {
        fprintf(stderr, "Error: Matrix is not invertible (0 determinant).\n");
        exit(84);
    }
    inverse.data[0][0] = 1.0 / matrix->data[0][0];
    return inverse;
}

static matrix_t invert_2x2_matrix(matrix_t *matrix)
{
    matrix_t inverse = create_matrix(2, 2);
    double det = matrix->data[0][0] *matrix->data[1][1] -
    matrix->data[0][1] * matrix->data[1][0];

    if (det == 0) {
        fprintf(stderr, "Error: Matrix is not invertible.\n");
        exit(84);
    }
    inverse.data[0][0] = matrix->data[1][1] / det;
    inverse.data[0][1] = -matrix->data[0][1] / det;
    inverse.data[1][0] = -matrix->data[1][0] / det;
    inverse.data[1][1] = matrix->data[0][0] / det;
    return inverse;
}

static matrix_t invert_3x3_matrix(matrix_t *matrix)
{
    matrix_t inverse = create_matrix(3, 3);
    double det = calculate_determinant_3x3(matrix);

    if (det == 0) {
        fprintf(stderr, "Error: Matrix is not invertible.\n");
        exit(84);
    }
    fill_inverse_3x3(matrix, &inverse, det);
    return inverse;
}

matrix_t invert_matrix(matrix_t *matrix)
{
    int size = matrix->rows;
    matrix_t inverse;

    if (size == 1) {
        return invert_1x1_matrix(matrix);
    }
    if (size == 2) {
        return invert_2x2_matrix(matrix);
    }
    if (size == 3) {
        return invert_3x3_matrix(matrix);
    }
    fprintf(stderr,
    "Error: Matrix inversion is only 1x1, 2x2,3x3 matrices.\n");
    exit(84);
}
