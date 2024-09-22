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

void forward_sorting(Array* const text_for_sorting);
void finding_start_address(char** address_str);
int comparing(char* string1, char* string2);
void swap(StringParametres* const string1, StringParametres* const string2);

#endif //FORW_SORT_H