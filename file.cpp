#include <stdio.h>
#include <stdlib.h>
const int AMOUNT_OF_STR = 14;

void print(char** addresses, int AMOUNT_OF_STR);
void finding_str(char* text, long file_size, char** addresses);

int main()
{
    FILE* file_pointer = fopen("text.txt", "r");

    fseek(file_pointer , 0 , SEEK_END);  
    long file_size = ftell(file_pointer); 
    rewind (file_pointer);

    char* text = (char*)calloc(file_size, sizeof(char));
    char** addresses = (char**)calloc(AMOUNT_OF_STR, sizeof(char*));
    finding_str(text, file_size, addresses);
    
    fread (text, sizeof(char), file_size, file_pointer);

    print(addresses, file_size);
    free(text);
    return 0;
}

void print(char** addresses, int AMOUNT_OF_STR)
{
    size_t str = 0;
    while (str < AMOUNT_OF_STR)
    {
        //printf("new str\n");
        char* s = *(addresses + str);
        printf("%s", s);
        str++;
    }
}

void finding_str(char* text, long file_size, char** addresses)
{
    size_t element = 0;

    int i = 0;
    *(addresses + i) = text + element;

    while (element < file_size)
    {
        char* ch = text + element;
        if (*ch == '\n')
        {
            *(addresses + i) = text + element + 1;
            i++;
        }
        element++;
    }
}