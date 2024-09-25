#include <stdio.h>

#include "Addresses.h"

void processing_text(Data* const original_text, Array* const text_for_sorting)
{
    assert(original_text != nullptr);
    assert(text_for_sorting != nullptr);

    size_t symbol = 0;
    size_t cnt = 0;

    while (symbol < original_text->file_size)
    {
        char* ch = original_text->text + symbol;

        if (*ch == '\r')
            *ch = '\0';

        else if (*ch == '\n')
        {
            *ch = '\0';
            cnt++;
        }
        symbol++;
    }

    text_for_sorting->amount_of_strings = cnt + 1;
}

void filling_addresses(Data* const original_text, Array* const text_for_sorting, bool* const right_enter)
{   
    assert(original_text != nullptr);
    assert(text_for_sorting != nullptr);
    assert(right_enter != nullptr);

    processing_text(original_text, text_for_sorting);
    
    text_for_sorting->addresses = (StringParametres*)calloc(text_for_sorting->amount_of_strings, sizeof(StringParametres));
    if (text_for_sorting->addresses == nullptr)
    {
        printf("not enough space for the program to run\n");
        *right_enter = false;
        return;
    }

    size_t element = 0;
    int string_index = 0;

    text_for_sorting->addresses[string_index].start = original_text->text + element;

    while (element < original_text->file_size)
    {
        char* ch = original_text->text + element;

        if (*ch == '\0')
        {
            text_for_sorting->addresses[string_index].end = original_text->text + element;
            string_index++;
            text_for_sorting->addresses[string_index].start = original_text->text + element + 2;
            element++;
        }
        element++;
    }
    
    text_for_sorting->addresses[string_index].end = original_text->text + element - 1;
}

void free_addresses(Array* text_for_sorting)
{
    assert(text_for_sorting != nullptr);

    free(text_for_sorting->addresses);
}