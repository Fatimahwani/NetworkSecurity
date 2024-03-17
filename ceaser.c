#include <stdio.h>
#include <string.h>

int main()
{
    char pt[100];
    char ct[100];
    int key = 3;
    printf("Enter the plain text");
    gets(pt);
    for (int i = 0; i < strlen(pt); i++)
    {

        if (pt[i] >= 65 && pt[i] <= 90)
        {
            ct[i] = (pt[i] + key - 'A') % 26 + 'A';
        }

        if (pt[i] >= 97 && pt[i] <= 122)
        {
            ct[i] = (pt[i] + key - 'a') % 26 + 'a';
        }
    }
    for (int i = 0; i < strlen(pt); i++)
    {
        printf("%c", ct[i]);
    }
    return 0;

}