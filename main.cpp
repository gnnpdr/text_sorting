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

void finding_amount_file_symbols(Data* original_text);
void filling_Data(Data* original_text);

void processing_text(Data* original_text, Array* text_for_sorting);
void filling_addresses(Data* original_text, Array* text_for_sorting);

void print_text(Array* text_for_sorting);

void forward_sorting(Array* text_for_sorting);
void finding_start_address(char** address_str);
int comparing(Array* text_for_sorting, int string, int element);
void swap_str(Array* text_for_sorting, int string);

void reverse_sorting(Array* text_for_sorting);
int reverse_comparing(Array* text_for_sorting, int string, int element);
void rev_swap_str(Array* text_for_sorting, int string);
void reverse_finding_start_address(char** address_str); 

void free_arrays(Array* text_for_sorting, Data* original_text);

int main()
{
    Data original_text = {};
    Array text_for_sorting = {};

    finding_amount_file_symbols(&original_text);
    filling_Data(&original_text);
    
    processing_text(&original_text, &text_for_sorting);
    filling_addresses(&original_text, &text_for_sorting);

    print_text(&text_for_sorting);
    printf("\n");

    printf("print forward sorting\n");
    forward_sorting(&text_for_sorting);
    print_text(&text_for_sorting);
    printf("\n");

    printf("print reverse sorting\n");
    reverse_sorting(&text_for_sorting);
    print_text(&text_for_sorting);

    free_arrays(&text_for_sorting, &original_text);

    return 0;
}


void finding_amount_file_symbols(Data* original_text)
{
    original_text->file_pointer = fopen("text1.txt", "rb"); //надо сделать так, чтобы еще пользователь мог вводить название файла

    fseek(original_text->file_pointer , 0 , SEEK_END);  
    original_text->file_size = ftell(original_text->file_pointer); 
    rewind (original_text->file_pointer);

}

void filling_Data(Data* original_text)
{
    original_text->text = (char*)calloc(original_text->file_size, sizeof(char));
    fread (original_text->text, sizeof(char), original_text->file_size, original_text->file_pointer);

    fclose(original_text->file_pointer);
}

void processing_text(Data* original_text, Array* text_for_sorting) //name
{
    size_t symbol = 0;
    size_t cnt = 0;
    //printf("start of string %d - %p\n", cnt, original_text->text);

    while (symbol < original_text->file_size)
    {
        char* ch = original_text->text + symbol;

        if (*ch == '\r')
            *ch = '\0';

        else if (*ch == '\n')
        {
            *ch = '\0';
            cnt++;
            //printf("start of string %d - %p\n", cnt, original_text->text + symbol + 1);
        }
        symbol++;
        
    }
    text_for_sorting->amount_of_strings = cnt + 1;
}

void filling_addresses(Data* original_text, Array* text_for_sorting)
{   
    text_for_sorting->addresses = (char**)calloc(text_for_sorting->amount_of_strings, sizeof(char*)); // добавить ошибки при ненахождении места, выделить эти фии в отдельные, добавить их в структуру
    
    size_t element = 0;
    int index_of_first_element_in_string = 0;

    *(text_for_sorting->addresses + index_of_first_element_in_string) = original_text->text + element;

    while (element < original_text->file_size)
    {
        char* ch = original_text->text + element;

        if (*ch == '\0')
        {
            index_of_first_element_in_string++;
            *(text_for_sorting->addresses + index_of_first_element_in_string) = original_text->text + element + 2;
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

void finding_start_address(char** address_str)
{   
    //printf("start address %p\n", *address_str);

    while (isalpha(**address_str) == 0)
    {
        //printf("next symb in address\n");
        *address_str = *address_str + sizeof(char);
    }

    //printf("end address %p\n", *address_str);
}


int comparing(Array* text_for_sorting, int string, int element)
{
    char* address_str1 = text_for_sorting->addresses[string];
    
    char* address_str2 = text_for_sorting->addresses[string+1];

    //printf("string %d\n", string);
    finding_start_address(&address_str1);

    //printf("string %d\n", string + 1);
    finding_start_address(&address_str2);

    if (tolower(*(address_str1 + element)) > tolower(*(address_str2 + element)))
    {
        //printf("string %d el %d swap because %c > %c\n", string, element, *(address_str1 + element), *(address_str2 + element));
        return GREATER;
    }
        
    else if (tolower(*(address_str1 + element)) == tolower(*(address_str2 + element)))
        return EQUAL;
    else
        return LESS;
}

void forward_sorting(Array* text_for_sorting) //надо сделать функцию, которая подает на выход адрес начала строки, т.е. учитывает пробелы
{
    for (int max_str = text_for_sorting->amount_of_strings - 1; max_str > 0; max_str--)
    {
        //printf("max str %d\n", max_str);
        for (int string = 0; string < max_str; string++)
        {
            //printf("string %d {%s} \n", string, text_for_sorting->addresses[string]);

            int element = 0;

            int difference = comparing(text_for_sorting, string, element);

            while (difference == 0)
            {
                //printf("next symb\n");
                element++;
                difference = comparing(text_for_sorting, string, element);
            }
            if (difference > 0)
            {
                //printf("swap str, element %d\n", element);
                swap_str(text_for_sorting, string);
            }
                
        }
    }
}


void reverse_finding_start_address(char** address_str)
{
    //printf("start address %p\n", *address_str);
    while (**address_str != '\0')
        *address_str = *address_str + sizeof(char);

    while (isalpha(**address_str) == 0)
    {
        //printf("symb [%c]", **address_str);
        //printf("next symb in address\n");
        *address_str = *address_str - sizeof(char);
    }
    //printf("symb [%c]", **address_str);
    //printf("end address %p\n", *address_str);
}

int reverse_comparing(Array* text_for_sorting, int string, int element)
{
    //printf("string in comparing %d\n", string);

    char* address_str1 = text_for_sorting->addresses[string];
    char* address_str2 = text_for_sorting->addresses[string+1];

    //printf("string %d\n", string);
    reverse_finding_start_address(&address_str1);    //меняет адрес, переносит его к первому непробельному символу
    //printf("string %d\n", string + 1);
    reverse_finding_start_address(&address_str2);

    if (tolower(*(address_str1 - element)) > tolower(*(address_str2 - element)))
    {
        //printf("string %d el %d swap because %c > %c\n", string, element, *(address_str1 + element), *(address_str2 + element));
        return GREATER;
    }
        
    else if (tolower(*(address_str1 - element)) == tolower(*(address_str2 - element)))
        return EQUAL;
    else
        return LESS;
}
void reverse_sorting(Array* text_for_sorting) 
{
    for (int max_str = text_for_sorting->amount_of_strings - 1; max_str > 0; max_str--)
    {
        //printf("max str %d\n", max_str);
        for (int string = 0; string < max_str; string++)
        {
            //printf("string %d {%s} \n", string, text_for_sorting->addresses[string]);
            int element = 0;
            
            int difference = reverse_comparing(text_for_sorting, string, element);

            while (difference == 0)
            {
                //printf("next symb\n");
                element++;
                difference = reverse_comparing(text_for_sorting, string, element);
            }
            if (difference > 0)
            {
                //printf("swap str, element %d\n", element);
                rev_swap_str(text_for_sorting, string);
            }
        }
    }
}

void rev_swap_str(Array* text_for_sorting, int string)
{
    char* temp = 0;
    temp = text_for_sorting->addresses[string];
    //printf("\nstring before [%s]\n", text_for_sorting->addresses[string]);
    text_for_sorting->addresses[string] = text_for_sorting->addresses[string+1];
    //printf("string after [%s]\n", text_for_sorting->addresses[string]);
    text_for_sorting->addresses[string+1] = temp;
}

void swap_str(Array* text_for_sorting, int string)
{
    char* temp = 0;
    temp = text_for_sorting->addresses[string];
    text_for_sorting->addresses[string] = text_for_sorting->addresses[string+1];
    text_for_sorting->addresses[string+1] = temp;
}

void free_arrays(Array* text_for_sorting, Data* original_text)
{
    free(text_for_sorting->addresses);
    free(original_text->text);
}