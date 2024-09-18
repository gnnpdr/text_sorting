#ifndef FORW_SORT_H
#define FORW_SORT_H

#include <ctype.h>
#include "print.h"

enum ResultOfComparing
{
    LESS = -1,
    EQUAL = 0,
    GREATER = 1
};

void forward_sorting(Array* text_for_sorting);
void finding_start_address(char** address_str);
int comparing(Array* text_for_sorting, const int string, const int element);
void swap_str(Array* text_for_sorting, const int string);

#endif //FORW_SORT_H