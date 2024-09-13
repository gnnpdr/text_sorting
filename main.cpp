#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

enum ResultOfComparing
{
    LESS = -1,
    EQUAL = 0,
    GREATER = 1
};

/*struct Data
{
    char* text;
    long file_size;
    char** addresses;
};*/

const int AMOUNT_OF_STR = 15;

void finding_amount_of_elements(long* file_size, FILE* file_pointer);
void filling_the_array_of_addresses(char* text, long file_size, char** addresses);

void print_text(char** addresses);

void sorting(char** addresses);
int comparing(char** addresses, int* el1, int* el2, int* string);
void change_str(char** addresses, int* string);

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
    sorting(addresses);
    print_text(addresses);

    free_arrays(addresses, text);

    return 0;
}

void sorting(char** addresses)
{
    for (int str = AMOUNT_OF_STR-1; str > 0; str--)
    {
        for (int string = 0; string < str; string++)
        {
            int el1 = 0;
            int el2 = 0;

            int difference = comparing(addresses, &el1, &el2, &string);

            if (difference > 0)
                change_str(addresses, &string);
            else if (difference == 0)
            {
                while (difference == 0)
                {
                    el1++;
                    el2++;
                    difference = comparing(addresses, &el1, &el2, &string);
                }
                if (difference > 0)
                    change_str(addresses, &string);
            }
        }
    }
}

int comparing(char** addresses, int* el1, int* el2, int* string)
{
    if (tolower(addresses[*string][*el1]) > tolower(addresses[*string+1][*el2]))
        return GREATER;
    else if (tolower(addresses[*string][*el1]) == tolower(addresses[*string+1][*el2]))
        return EQUAL;
    else
        return LESS;
}

void change_str(char** addresses, int* string)
{
    char* temp = 0;
    temp = addresses[*string];
    addresses[*string] = addresses[*string+1];
    addresses[*string+1] = temp;
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