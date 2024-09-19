#include <stdio.h>

#include "print.h"

void print_text(Array* text_for_sorting)
{
    assert(text_for_sorting != nullptr);
    
    size_t string_index = 0;
    while (string_index < text_for_sorting->amount_of_strings)
    {
        char* s = text_for_sorting->addresses[string_index].start;
        printf("%s\n", s);
        string_index++;
    }
}