/*
** EPITECH PROJECT, 2024
** deencrypt
** File description:
** deencrypt
*/

#include "my.h"

void encrypt_message(char *message, char *key)
{
    int key_length = (int)strlen(key);
    int key_size = (int)ceil(sqrt((double)key_length));
    int message_length = (int)strlen(message);
    int message_rows = (int)ceil((double)message_length / key_size);
    matrix_t key_matrix = create_matrix(key_size, key_size);
    matrix_t message_matrix = create_matrix(message_rows, key_size);
    matrix_t encrypted_matrix = create_matrix(message_rows, key_size);

    str_to_ascii_matrix(key, &key_matrix);
    str_to_ascii_matrix(message, &message_matrix);
    print_key_matrix(&key_matrix);
    multiply_matrices(&message_matrix, &key_matrix, &encrypted_matrix);
    printf("Encrypted message:\n");
    print_encrypted_matrix(&encrypted_matrix);
    free_matrix(key_matrix);
    free_matrix(message_matrix);
    free_matrix(encrypted_matrix);
}

void decrypt_message(char *message, char *key)
{
    int key_size = calculate_key_size(key);
    int message_rows;

    if (key_size == 1) {
        decrypt_scalar_message(message, key);
        return;
    }
    message_rows = calculate_message_rows(message, key_size);
    process_matrix_decryption(message, key, key_size, message_rows);
}

void decrypt_scalar_message(char *message, char *key)
{
    int message_rows = count_integers_in_string(message);
    matrix_t key_matrix = create_matrix(1, 1);
    matrix_t inverse_key_matrix = create_matrix(1, 1);
    matrix_t encrypted_matrix = create_matrix(message_rows, 1);
    matrix_t decrypted_matrix = create_matrix(message_rows, 1);

    key_matrix.data[0][0] = (double)atoi(key);
    if (key_matrix.data[0][0] == 0.0) {
        exit(84);
    }
    inverse_key_matrix.data[0][0] = 1.0 / key_matrix.data[0][0];
    parse_encrypted_message(message, &encrypted_matrix);
    decrypt_scalar_values(&encrypted_matrix,
    &inverse_key_matrix, &decrypted_matrix);
    printf("Key matrix:\n");
    print_inverse_key_matrix(&inverse_key_matrix);
    printf("Decrypted message:\n");
    print_decrypted_message(&decrypted_matrix);
    free_decryption_matrices(&key_matrix, &encrypted_matrix,
    &decrypted_matrix, &inverse_key_matrix);
}

void decrypt_scalar_values(matrix_t *encrypted_matrix,
    matrix_t *inverse_key_matrix, matrix_t *decrypted_matrix)
{
    for (int i = 0; i < encrypted_matrix->rows; i++) {
        decrypted_matrix->data[i][0] =
        encrypted_matrix->data[i][0] * inverse_key_matrix->data[0][0];
    }
}

void process_matrix_decryption(char *message, char *key,
    int key_size, int message_rows)
{
    matrix_t key_matrix;
    matrix_t inverse_key_matrix;
    matrix_t encrypted_matrix;
    matrix_t decrypted_matrix;

    initialize_and_invert_key(key, &key_matrix,
    &inverse_key_matrix);
    initialize_message_matrices(message, key_size,
    &encrypted_matrix, &decrypted_matrix);
    decrypt_and_print_results(&encrypted_matrix,
    &inverse_key_matrix, &decrypted_matrix);
    free_decryption_matrices(&key_matrix,
    &encrypted_matrix, &decrypted_matrix, &inverse_key_matrix);
}
