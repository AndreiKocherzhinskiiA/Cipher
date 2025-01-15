/*
** EPITECH PROJECT, 2024
** cipher
** File description:
** cipher
*/

#include "my.h"

void free_decryption_matrices(matrix_t *key_matrix, matrix_t *encrypted_matrix,
    matrix_t *decrypted_matrix, matrix_t *inverse_key_matrix)
{
    free_matrix(*key_matrix);
    free_matrix(*encrypted_matrix);
    free_matrix(*decrypted_matrix);
    free_matrix(*inverse_key_matrix);
}

void initialize_message_matrices(char *message,
    int key_size, matrix_t *encrypted_matrix, matrix_t *decrypted_matrix)
{
    int num_integers;
    int message_rows;

    num_integers = count_integers_in_string(message);
    message_rows = (int)ceil((double)num_integers / key_size);
    *encrypted_matrix = create_matrix(message_rows, key_size);
    *decrypted_matrix = create_matrix(message_rows, key_size);
    parse_encrypted_message(message, encrypted_matrix);
}

static void print_usage(void)
{
    printf("USAGE:\n");
    printf("\t./103cipher message key flag\n");
    printf("\nDESCRIPTION:\n");
    printf("\tmessage\tA string message to encrypt or decrypt\n");
    printf("\tkey\tAn encryption key (ASCII string)\n");
    printf("\tflag\t0 for encryption, 1 for decryption\n");
}

void initialize_and_invert_key(char *key, matrix_t *key_matrix,
    matrix_t *inverse_key_matrix)
{
    initialize_key_matrix(key, key_matrix);
    *inverse_key_matrix = invert_matrix(key_matrix);
}

static int validate_arguments(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        print_usage();
        exit(0);
    }
    if (argc != 4) {
        fprintf(stderr,
        "Error: Wrong number of arguments. Use -h for help.\n");
        return 84;
    }
    return 0;
}

static void process_flag(char *message, char *key, int flag)
{
    if (flag == 0) {
        encrypt_message(message, key);
    } else if (flag == 1) {
        decrypt_message(message, key);
    } else {
        fprintf(stderr,
        "Invalid flag. Use 0 for encryption or 1 for decryption.\n");
        exit(84);
    }
}

void fill_matrix_row_from_tokens(char **token, double *row, int cols)
{
    for (int j = 0; j < cols; j++) {
        row[j] = (*token != NULL) ? atof(*token) : 0.0;
        *token = (*token != NULL) ? strtok(NULL, " ") : NULL;
    }
}

int main(int argc, char **argv)
{
    int flag;
    char *message;
    char *key;

    if (validate_arguments(argc, argv) != 0) {
        return 84;
    }
    message = argv[1];
    key = argv[2];
    flag = atoi(argv[3]);
    process_flag(message, key, flag);
    return 0;
}
