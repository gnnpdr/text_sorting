#ifndef SORT_H
#define SORT_H

#include <ctype.h>
#include "handle_text.h"

enum ResultOfComparing
{
    LESS = -1,
    EQUAL = 0,
    GREATER = 1
};

typedef int (*comparing_t) (StringParameters* const string1, StringParameters* const string2); 

void sorting(comparing_t comparing, TextAddrData* const text_for_sorting);

int forward_comparing(StringParameters* const str1, StringParameters* const str2);
int reverse_comparing(StringParameters* const str1, StringParameters* const str2);

#endif //SORT_H