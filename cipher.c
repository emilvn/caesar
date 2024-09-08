#include<stdio.h>
#include "cipher.h"

const char *alphabet[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P", "Q","R","S","T","U","V","W","X","Y","Z"};
const int alphabetSize = 26;


int main()
{
    encrypt("Yeet Skeet", 2);

    return 0;
}

int letterToNumber(char letter)
{
    for (int i = 0; i < alphabetSize - 1; i++) {
        if(*alphabet[i] == letter){
            return i;
        }
    }
    return - 1;
}

char numberToLetter(int number)
{
    if(number > alphabetSize - 1){
        return "";
    }
    return alphabet[number];
}
int shift(int number, int shiftvalue)
{
    if(number + shiftvalue > alphabetSize - 1) {
        return number + shiftvalue - alphabetSize; 
    }
    return number + shiftvalue;
}
void encrypt(char* text, int shift)
{
    int length = len(text);

    for(int i = 0; i < length; i++){
        char indexOfCurrentLetter = letterToNumber(text[i]);
        
    }
}
int len(char* s)
{
    int length = 0;
    while(length < 10000){//make sure it doesnt run forever
        if(s[length] == *"\0" ){ // \0 character ends all string literals
            break;
        }
        length++;
    }
    return length;
}
void decrypt(char* text, int shift);
void init(char* holder[]);
