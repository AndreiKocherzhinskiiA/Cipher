/*
** EPITECH PROJECT, 2024
** print
** File description:
** print
*/

#include "my.h"

void print_matrix_row(long *row, int cols)
{
    for (int j = 0; j < cols; j++) {
        printf("%ld", row[j]);
        if (j < cols - 1)
            printf(" ");
    }
}

void print_encrypted_matrix(matrix_t *encrypted_matrix)
{
    long row[encrypted_matrix->cols];

    for (int i = 0; i < encrypted_matrix->rows; i++) {
        for (int j = 0; j < encrypted_matrix->cols; j++) {
            row[j] = (long)round(encrypted_matrix->data[i][j]);
        }
        print_matrix_row(row, encrypted_matrix->cols);
        printf(" ");
    }
    printf("\n");
}

void print_key_matrix(matrix_t *key_matrix)
{
    long row[key_matrix->cols];

    printf("Key matrix:\n");
    for (int i = 0; i < key_matrix->rows; i++) {
        for (int j = 0; j < key_matrix->cols; j++) {
            row[j] = (long)key_matrix->data[i][j];
        }
        print_matrix_row(row, key_matrix->cols);
        printf("\n");
    }
}

void error_matrix_invertible(double det, int print)
{
    if (det == 0) {
        fprintf(stderr, "Error: Matrix is not invertible.\n");
        exit(84);
    }
    if (print == 0) {
        fprintf(stderr, "Error: Matrix inversion is ");
        fprintf(stderr, "implemented only for 2x2 and 3x3 matrices.\n");
        exit(84);
    }
}

void decrypt_and_print_results(matrix_t *encrypted_matrix,
    matrix_t *inverse_key_matrix, matrix_t *decrypted_matrix)
{
    multiply_matrices(encrypted_matrix, inverse_key_matrix, decrypted_matrix);
    printf("Key matrix:\n");
    print_inverse_key_matrix(inverse_key_matrix);
    printf("Decrypted message:\n");
    print_decrypted_message(decrypted_matrix);
}
