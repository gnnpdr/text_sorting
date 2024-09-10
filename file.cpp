#include <stdio.h>
#include <stdlib.h>
//const int AMOUNT_OF_STR = 14;
//const int AMOUNT_OF_ELEMENTS_IN_STR = 200;

void print(char* text, long file_size);

int main()
{
    FILE* file_pointer = fopen("text.txt", "r");

    fseek(file_pointer , 0 , SEEK_END);  
    long file_size = ftell(file_pointer); 
    rewind (file_pointer);

    char* text = (char*)calloc(file_size, sizeof(char));
    
    fread (text, sizeof(char), file_size, file_pointer);

    print(text, file_size);
    free(text);
    return 0;
}

void print(char* text, long file_size)
{
    size_t element = 0;
    while (element < file_size)
    {
        char* ch = text + element;
        printf("%c", *ch);
        element++;
    }
}