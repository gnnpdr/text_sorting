#include <stdio.h>

#include "free.h"

void free_arrays(Array* text_for_sorting, Data* original_text)
{
    assert(original_text != nullptr);
    assert(text_for_sorting != nullptr);

    free(text_for_sorting->addresses);
    free(original_text->text);
}