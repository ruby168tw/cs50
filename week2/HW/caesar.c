#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    int wrong = 0;
    string message = "";
    
    if (argc != 2) //if the "key" is not put in.
    {
        printf("Usage: ./caesar key\n");
        return 1;      
    }
    else //if the "key" is put in.
    {
        int len = strlen(argv[1]);
        for (int i = 0; i < len; i++) // count the number of non-digit
        {
            if (48 > argv[1][i] || argv[1][i] > 57)
            {
                wrong++;
            }
        }
        
        if (wrong > 0) //if the key is not a decimal digit
        {
            printf("Usage: ./caesar key\n");
        }
        else //if the key is a decimal digit
        {
            int key = atoi(argv[1]); //transfer "key"`s type from string to int
            message = get_string("plaintext: "); //ask for the plaintext
            int use_key = key % 26; //which is used to add with plaintext
            printf("ciphertext: ");
            
            for (int j = 0, msg_len = strlen(message); j < msg_len; j++)
            {
                int a = message[j];
                
                if (a >= 97 && a <= 122)
                {
                    if (a + use_key > 122)
                    {
                        a = 97 + (a + use_key - 97) % 26;
                    }
                    else
                    {
                        a = a + use_key;
                    }
                }
                
                if (a >= 65 && a <= 90)
                {
                    if (a + use_key > 90)
                    {
                        a = 65 + (a + use_key - 65) % 26;
                    }
                    else
                    {
                        a = a + use_key;
                    }
                }
                printf("%c", a);
            }
            printf("\n");
        }
    }
}
