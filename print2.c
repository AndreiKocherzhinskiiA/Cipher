/*
** EPITECH PROJECT, 2024
** print2
** File description:
** print2
*/

#include "my.h"

void print_matrix_row_with_format(double *row, int cols)
{
    double val;

    for (int j = 0; j < cols; j++) {
        val = row[j];
        if (fabs(val) < 1e-9) {
            printf("0.0");
        } else {
            printf("%.3f", val);
        }
        if (j < cols - 1) {
            printf(" ");
        }
    }
}

void print_inverse_key_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->rows; i++) {
        print_matrix_row_with_format(matrix->data[i], matrix->cols);
        printf("\n");
    }
}

void print_char(char c)
{
    if (c != 0) {
        printf("%c", c);
    }
}

void print_decrypted_row(double *row, int cols)
{
    double val;
    char c;

    for (int j = 0; j < cols; j++) {
        val = row[j];
        if (fabs(val) > 0.5) {
            c = (char)round(val);
            print_char(c);
        }
    }
}

void print_decrypted_message(matrix_t *matrix)
{
    int i;

    for (i = 0; i < matrix->rows; i++) {
        print_decrypted_row(matrix->data[i], matrix->cols);
    }
    printf("\n");
}
