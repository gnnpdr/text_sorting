#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

enum ResultOfComparing
{
    LESS = -1,
    EQUAL = 0,
    GREATER = 1
};

struct Data
{
    FILE* file_pointer;
    long file_size;
    char* text;
};

struct Array
{
    char** addresses;  
    int amount_of_strings;
};

void finding_amount_of_elements_in_the_file(Data* the_text);
void filling_the_struct_Data (Data* the_text);

void change_text_finding_amount_of_str(Data* the_text, Array* text_for_sorting);
void filling_the_array_of_addresses(Data* the_text, Array* text_for_sorting);

void print_text(Array* text_for_sorting);

void forward_sorting(Array* text_for_sorting);
void finding_address_of_start(Array* text_for_sorting, int string);
int comparing(Array* text_for_sorting, int string, int element);
void change_str(Array* text_for_sorting, int string);

void free_arrays(Array* text_for_sorting, Data* the_text);

int main()
{
    Data the_text = {};
    Array text_for_sorting = {};

    finding_amount_of_elements_in_the_file(&the_text);
    filling_the_struct_Data(&the_text);
    
    change_text_finding_amount_of_str(&the_text, &text_for_sorting);
    filling_the_array_of_addresses(&the_text, &text_for_sorting);

    print_text(&text_for_sorting);
    forward_sorting(&text_for_sorting);
    print_text(&text_for_sorting);

    free_arrays(&text_for_sorting, &the_text);

    return 0;
}


void finding_amount_of_elements_in_the_file(Data* the_text)
{
    the_text->file_pointer = fopen("text.txt", "rb"); //надо сделать так, чтобы еще пользователь мог вводить название файла

    fseek(the_text->file_pointer , 0 , SEEK_END);  
    the_text->file_size = ftell(the_text->file_pointer); 
    rewind (the_text->file_pointer);
}

void filling_the_struct_Data (Data* the_text)
{
    the_text->text = (char*)calloc(the_text->file_size, sizeof(char));
    fread (the_text->text, sizeof(char), the_text->file_size, the_text->file_pointer);
}

void change_text_finding_amount_of_str(Data* the_text, Array* text_for_sorting)
{
    size_t element = 0;
    size_t cnt = 0;

    while (element < the_text->file_size)
    {
        char* ch = the_text->text + element;

        if (*ch == '\r')
            *ch = '\0';

        else if (*ch == '\n')
        {
            *ch = '\0';
            cnt++;
        }
        element++;
    }
    text_for_sorting->amount_of_strings = cnt;
}

void filling_the_array_of_addresses(Data* the_text, Array* text_for_sorting)
{   
    text_for_sorting->addresses = (char**)calloc(text_for_sorting->amount_of_strings, sizeof(char*)); // добавить ошибки при ненахождении места, выделить эти фии в отдельные, добавить их в структуру
    
    size_t element = 0;
    int index_of_first_element_in_string = 0;

    *(text_for_sorting->addresses + index_of_first_element_in_string) = the_text->text + element;

    while (element < the_text->file_size)
    {
        char* ch = the_text->text + element;

        if (*ch == '\0')
        {
            index_of_first_element_in_string++;
            *(text_for_sorting->addresses + index_of_first_element_in_string) = the_text->text + element + 1;

            element++;
        }
        element++;
    }
}

void print_text(Array* text_for_sorting)
{
    size_t str = 0;
    while (str < text_for_sorting->amount_of_strings)
    {
        char* s = *(text_for_sorting->addresses + str);
        printf("%s\n", s);
        str++;
    }
}

void forward_sorting(Array* text_for_sorting) //надо сделать функцию, которая подает на выход адрес начала строки, т.е. учитывает пробелы
{
    for (int str = text_for_sorting->amount_of_strings-1; str > 0; str--)
    {
        for (int string = 0; string < str; string++)
        {
            int element = 0;

            int difference = comparing(text_for_sorting, element, string);

            if (difference > 0)
                change_str(text_for_sorting, string);
            else if (difference == 0)
            {
                while (difference == 0)
                {
                    element++;
                    difference = comparing(text_for_sorting, element, string);
                }
                if (difference > 0)
                    change_str(text_for_sorting, string);
            }
        }
    }
}

void finding_address_of_start(Array* text_for_sorting, int string)
{
    if (isspace(*(text_for_sorting->addresses[string])) != 0)
        text_for_sorting->addresses[string] = text_for_sorting->addresses[string] + 1;
}

int comparing(Array* text_for_sorting, int string, int element)
{
    finding_address_of_start(text_for_sorting, string);    //меняет адрес, переносит его к первому непробельному символу
    finding_address_of_start(text_for_sorting, (string+1));

    if (tolower(text_for_sorting->addresses[string][element]) > tolower(text_for_sorting->addresses[string+1][element]))
        return GREATER;
    else if (tolower(text_for_sorting->addresses[string][element]) == tolower(text_for_sorting->addresses[string+1][element]))
        return EQUAL;
    else
        return LESS;
}

void change_str(Array* text_for_sorting, int string)
{
    char* temp = 0;
    temp = text_for_sorting->addresses[string];
    text_for_sorting->addresses[string] = text_for_sorting->addresses[string+1];
    text_for_sorting->addresses[string+1] = temp;
}

void free_arrays(Array* text_for_sorting, Data* the_text)
{
    free(text_for_sorting->addresses);
    free(the_text->text);
}