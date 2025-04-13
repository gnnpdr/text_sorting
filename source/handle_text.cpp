#include <stdio.h>

#include "../include/handle_text.h"

static void sep_strs(const Data *const original_text, TextAddrData *const text_for_sorting);

void sep_strs(const Data *const original_text, TextAddrData *const text_for_sorting)
{
    assert(original_text);
    assert(text_for_sorting);

    size_t symbol = 0;
    size_t cnt = 0;
    size_t file_size = original_text->file_size;
    char* text = original_text->text;

    while (symbol < file_size)
    {
        char* ch = text + symbol;

        //if (*ch == '\r')
        //    *ch = '\0';
        if (*ch == '\n')
        {
            *ch = '\0';
            cnt++;
        }
        symbol++;
    }

    text_for_sorting->str_amt = cnt + 1;
}

int ctor_addresses(const Data *const original_text, TextAddrData *const text_for_sorting)
{   
    assert(original_text);
    assert(text_for_sorting);

    char* text = original_text->text;
    
    size_t file_size = original_text->file_size;

    sep_strs(original_text, text_for_sorting);
    size_t str_amt = text_for_sorting->str_amt;


    text_for_sorting->addresses = (StringParameters*)calloc(str_amt, sizeof(StringParameters));
    if (!text_for_sorting->addresses) 
    {
        printf("allocation error\n");
        return ERR_VAL;
    }

    size_t element = 0;
    int str_index = 0;

    text_for_sorting->addresses[str_index].start = text + element;

    while (element < file_size)
    {
        char* ch = text + element;

        if (*ch == '\0')
        {
            text_for_sorting->addresses[str_index].end = text + element;
            str_index++;
            element++;
            text_for_sorting->addresses[str_index].start = text + element;
        }
        element++;
    }
    
    text_for_sorting->addresses[str_index].end = text + element - 1;


    return 0;
}

void dtor_addresses(TextAddrData* text_for_sorting)
{
    free(text_for_sorting->addresses);
}