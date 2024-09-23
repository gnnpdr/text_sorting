#ifndef SORT_H
#define SORT_H

#include <ctype.h>
#include "print.h"

enum ResultOfComparing
{
    LESS = -1,
    EQUAL = 0,
    GREATER = 1
};

typedef int (*comparing_t) (StringParametres* const string1, StringParametres* const string2); 

void sorting(comparing_t comparing, Array* const text_for_sorting);

void finding_start_address(char** address_str);
int forward_comparing(StringParametres* const string_1, StringParametres* const string_2);

void reverse_finding_start_address(char** address_str);
int reverse_comparing(StringParametres* const string_1, StringParametres* const string_2);

void swap(StringParametres* const string1, StringParametres* const string2);

#endif //SORT_H