/*
** EPITECH PROJECT, 2024
** cipher
** File description:
** MY_H
*/

#ifndef MY_H
    #define MY_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>

typedef struct {
    int rows;
    int cols;
    double **data;
} matrix_t;

typedef struct {
    char *string;
    int length;
    int index;
} StringData_t;

matrix_t create_matrix(int rows, int cols);
void free_matrix(matrix_t matrix);
void fill_matrix_row(double *row, int cols, StringData_t *string_data);
void str_to_ascii_matrix(char *string, matrix_t *matrix);
double calculate_dot_product(int size, double *row, double *col);
void print_matrix_row(long *row, int cols);
void print_encrypted_matrix(matrix_t *encrypted_matrix);
void print_key_matrix(matrix_t *key_matrix);
void error_matrix_invertible(double det, int print);
void decrypt_and_print_results(matrix_t *encrypted_matrix,
    matrix_t *inverse_key_matrix, matrix_t *decrypted_matrix);
void print_matrix_row_with_format(double *row, int cols);
void print_inverse_key_matrix(matrix_t *matrix);
void print_char(char c);
void print_decrypted_row(double *row, int cols);
void print_decrypted_message(matrix_t *matrix);
void encrypt_message(char *message, char *key);
void decrypt_message(char *message, char *key);
void initialize_and_invert_key(char *key, matrix_t *key_matrix,
    matrix_t *inverse_key_matrix);
void initialize_key_matrix(char *key, matrix_t *key_matrix);
void parse_encrypted_message(char *message, matrix_t *matrix);
void fill_matrix_row_from_tokens(char **token, double *row, int cols);
void free_decryption_matrices(matrix_t *key_matrix, matrix_t *encrypted_matrix,
    matrix_t *decrypted_matrix, matrix_t *inverse_key_matrix);
void initialize_message_matrices(char *message,
    int key_size, matrix_t *encrypted_matrix, matrix_t *decrypted_matrix);
void extract_column(matrix_t *matrix, int col_index, double *col);
void exit_if_not_square(matrix_t *matrix);
void fill_inverse_3x3(matrix_t *matrix, matrix_t *inverse, double det);
void fill_inverse_2x2(matrix_t *matrix, matrix_t *inverse, double det);
matrix_t invert_matrix(matrix_t *matrix);
double calculate_determinant_3x3(matrix_t *matrix);
int calculate_key_size(char *key);
int calculate_message_rows(char *message, int key_size);
int count_integers_in_string(const char *str);
void multiply_matrices(matrix_t *mat1, matrix_t *mat2, matrix_t *result);
void multiply_by_scalar(matrix_t *mat1,
    matrix_t *scalar_matrix, matrix_t *result);
void standard_matrix_multiplication(matrix_t *mat1,
    matrix_t *mat2, matrix_t *result);
void decrypt_scalar_message(char *message, char *key);
void process_matrix_decryption(char *message, char *key,
    int key_size, int message_rows);
void decrypt_scalar_values(matrix_t *encrypted_matrix,
    matrix_t *inverse_key_matrix, matrix_t *decrypted_matrix);

#endif /* !MY_H */
