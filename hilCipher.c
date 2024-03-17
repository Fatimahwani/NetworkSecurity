#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//i made encryption work! decryption i will ask sir if we have to do!

// Function to calculate the modular inverse of a number
int modInverse(int a, int m)
{
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

// Function to encrypt a message using Hill cipher
void encrypt(int key[2][2], char *message)
{
    int len = strlen(message);

    for (int i = 0; i < len; i++)
    {
        message[i]=toupper(message[i]);
        printf("%c", message[i]);
        
    }

    // Pad the message with 'X' if its length is odd
    if (len % 2 != 0)
    {
        message[len] = 'X';
        message[len + 1] = '\0';
        len++;
    }

    for (int i = 0; i < len; i += 2)
    {
       
        int block[2] = {message[i] - 65, message[i + 1] - 'A'};
        int result[2] = {0, 0};
        printf("block[i]= %c\n", block[0]);
        printf("block[i]= %c", block[1]);
        printf("\n");

        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                result[j] += key[k][j] * block[k];
            }
            result[j] %= 26;
        }
        printf("res[0] = %d", result[0]);
        printf("\n");
        printf("res[1]= %d", result[1]);
        printf("\n");
        message[i] = result[0] + 'A';
        message[i + 1] = result[1] + 'A';
    }
}


int main()
{
    int key[2][2] = {
        {2, 7},
        {2, 8}};

    char message[] = "aima";

    printf("Original Message: %s\n", message);

    // Encrypt the message
    encrypt(key, message);
    printf("Encrypted Message: %s\n", message);

   

    return 0;