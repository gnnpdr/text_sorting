#include <stdio.h>

#include "filling_Addresses.h"

void processing_text(Data* original_text, Array* text_for_sorting) //name
{
    assert(original_text != nullptr);

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
    assert(original_text != nullptr);
    
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