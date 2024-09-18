#include <stdio.h>

#include "print.h"

void print_text(Array* text_for_sorting)
{
    assert(text_for_sorting != nullptr);
    
    size_t str = 0;
    while (str < text_for_sorting->amount_of_strings)
    {
        char* s = *(text_for_sorting->addresses + str);
        printf("%s\n", s);
        str++;
    }
}