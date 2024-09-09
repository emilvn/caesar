#include <ctype.h>
#include <stdio.h>
#include "cipher.h"

const char alphabet[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z'
};
const int alphabet_size = sizeof(alphabet);

int letter_to_number(char letter)
{
    for (int i = 0; i < alphabet_size; i++) {
        if (letter == alphabet[i] || letter == tolower((unsigned char) alphabet[i])) {
            return i;
        }
    }
    return -1;
}

char number_to_letter(int number, int is_lower)
{
    if (number >= alphabet_size || number < 0) {
        return '\0'; // Invalid number';
    }
    
    char result = alphabet[number];

    if (is_lower) {
        return tolower((unsigned char) result);
    }
    
    return result;
}

int shift(int number, int shift_value)
{
    int shifted = (number + shift_value) % alphabet_size;
    if (shifted < 0) {
        shifted += alphabet_size;
    }
    return shifted;
}

void encrypt(char text[], int shift_value)
{
    int length = len(text);

    for (int i = 0; i < length; i++) {
        char letter = text[i];
        int is_lower = islower((unsigned char) letter);
        int index_of_curr_letter = letter_to_number(letter);
        
        if (index_of_curr_letter == -1) {
            continue;
        }

        int shifted = shift(index_of_curr_letter, shift_value);
        const char new_char = number_to_letter(shifted, is_lower);
        
        if (new_char == '\0') {
            printf("Error: Invalid character conversion at index %d\n", i);
            continue;
        }
        
        text[i] = new_char; 
    }
    printf("Final encrypted text: %s\n", text);
}

int len(char* text)
{
    int length = 0;
    while (text[length] != '\0') {
        length++;
    }
    printf("Length of text: %d\n", length);
    return length;
}

void decrypt(char* text, int shift_value)
{
    encrypt(text, -shift_value);
}