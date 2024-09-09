#include <stdio.h>
#include <locale.h>
#include "caesar.h"
#include "cipher.h"

int main()
{
    setlocale(LC_ALL, "");
    print_welcome();

    int choice = get_choice("Choose: ");
    while(choice != 3){
        int shift_value = get_choice("Enter amount to shift: ");
        char s[255];
        get_string(s, choice);
        printf("String: %s\n", s);
        switch (choice)
        {
        case 1:
            encrypt(s, shift_value);
            break;
        case 2:
            decrypt(s, shift_value);
            break;
        default:
            break;
        }
        print_result(s);
        print_menu();
        choice = get_choice("Choose: ");
    }

    return 0;
}

void print_welcome()
{
    printf("\n");
    printf("-------------------------------\n");
    printf("Welcome to the Caesarian cipher\n");
    print_menu();
    printf("\n");
}

void print_menu()
{
    printf("-------------------------------\n");
    printf("\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Exit\n");
    printf("\n");
    printf("--------------------------------\n");
}

void print_result(char* s)
{
    printf("\n");
    printf("--------------------------------\n");
    printf("Result: %s\n", s);
}

int get_choice(char* message)
{
    printf(message);
    int c;
    scanf(" %d", &c);
    return c;
}

void get_string(char s[255], int is_encrypt)
{
    if(is_encrypt == 1){
        printf("Enter string to be encrypted: ");
    } else {
        printf("Enter string to be decrypted: ");
    }
    scanf("%c", (char *) stdin);
    fgets(s, 255, stdin);
}