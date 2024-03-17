#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a message using Rail Fence Row Transformation
void railFenceEncryptRow(char *plaintext, int rails) {
    int len = strlen(plaintext);
    char ciphertext[len];

    for (int i = 0, k = 0; i < rails; ++i) {
        for (int j = i; j < len; j += rails) {
            ciphertext[k++] = plaintext[j];
        }
    }

    ciphertext[len] = '\0';
    strcpy(plaintext, ciphertext);
}

// Function to decrypt a message using Rail Fence Row Transformation
void railFenceDecryptRow(char *ciphertext, int rails) {
    int len = strlen(ciphertext);
    char plaintext[len];

    for (int i = 0, k = 0; i < rails; ++i) {
        for (int j = i; j < len; j += rails) {
            plaintext[j] = ciphertext[k++];
        }
    }

    plaintext[len] = '\0';
    strcpy(ciphertext, plaintext);
}

// Function to encrypt a message using Rail Fence Column Transformation
void railFenceEncryptColumn(char *plaintext, int rails) {
    int len = strlen(plaintext);
    char ciphertext[len];
    int k = 0;

    for (int i = 0; i < rails; ++i) {
        for (int j = i; j < len; j += rails) {
            ciphertext[k++] = plaintext[j];
        }
    }

    ciphertext[len] = '\0';
    strcpy(plaintext, ciphertext);
}

// Function to decrypt a message using Rail Fence Column Transformation
void railFenceDecryptColumn(char *ciphertext, int rails) {
    int len = strlen(ciphertext);
    char plaintext[len];
    int k = 0;

    for (int i = 0; i < rails; ++i) {
        for (int j = i; j < len; j += rails) {
            plaintext[j] = ciphertext[k++];
        }
    }

    plaintext[len] = '\0';
    strcpy(ciphertext, plaintext);
}

int main() {
    int choice;
    char message[100];
    int rails;

    printf("Enter the message: ");
    scanf("%s", message);

    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    printf("Choose Transformation:\n");
    printf("1. Rail Fence Row Transformation (Encryption)\n");
    printf("2. Rail Fence Row Transformation (Decryption)\n");
    printf("3. Rail Fence Column Transformation (Encryption)\n");
    printf("4. Rail Fence Column Transformation (Decryption)\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            railFenceEncryptRow(message, rails);
            printf("Encrypted Message: %s\n", message);
            break;
        case 2:
            railFenceDecryptRow(message, rails);
            printf("Decrypted Message: %s\n", message);
            break;
        case 3:
            railFenceEncryptColumn(message, rails);
            printf("Encrypted Message: %s\n", message);
            break;
        case 4:
            railFenceDecryptColumn(message, rails);
            printf("Decrypted Message: %s\n", message);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}