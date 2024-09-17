#include <stdio.h>

#include "free.h"

void free_arrays(Array* text_for_sorting, Data* original_text)
{
    free(text_for_sorting->addresses);
    free(original_text->text);
}