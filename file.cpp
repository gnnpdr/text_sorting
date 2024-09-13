#include <stdio.h>
#include <stdlib.h>
const int AMOUNT_OF_STR = 14;

void finding_amount_of_elements(long* file_size, FILE* file_pointer);

void print_text(char** addresses);
void filling_the_array_of_addresses(char* text, long file_size, char** addresses);
void free_arrays(char** addresses, char* text);

int main()
{
    FILE* file_pointer = fopen("text.txt", "rb");

    long file_size = 0;
    finding_amount_of_elements(&file_size, file_pointer);

    char* text = (char*)calloc(file_size, sizeof(char));
    char** addresses = (char**)calloc(AMOUNT_OF_STR, sizeof(char*));
    
    fread (text, sizeof(char), file_size, file_pointer);

    filling_the_array_of_addresses(text, file_size, addresses);
    print_text(addresses);

    free_arrays(addresses, text);

    return 0;
}

void print_text(char** addresses)
{
    size_t str = 0;
    while (str < AMOUNT_OF_STR)
    {
        char* s = *(addresses + str);
        printf("%s\n", s);
        str++;
    }
}

void filling_the_array_of_addresses(char* text, long file_size, char** addresses)
{
    size_t element = 0;

    int index_of_first_element_in_string = 0;

    *(addresses + index_of_first_element_in_string) = text + element;

    while (element < file_size)
    {
        char* ch = text + element;

        if (*ch == '\r')
            *ch = '\0';

        else if (*ch == '\n' || *ch == EOF)
        {
            *ch = '\0';
            //printf("there is symbol\n");
            
            index_of_first_element_in_string++;
            *(addresses + index_of_first_element_in_string) = text + element + 1;
        }
        element++;
    }
}

void finding_amount_of_elements(long* file_size, FILE* file_pointer)
{
    fseek(file_pointer , 0 , SEEK_END);  
    *file_size = ftell(file_pointer); 
    rewind (file_pointer);
}

void free_arrays(char** addresses, char* text)
{
    free(addresses);
    free(text);
}