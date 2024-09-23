#ifndef ADDRESSES_H
#define ADDRESSES_H

#include "OriginalText.h"

struct Array
{
    struct StringParametres* addresses;  
    int amount_of_strings;
};

struct StringParametres
{
    char* start;
    char* end;
};

void processing_text(Data* const original_text, Array* const text_for_sorting);
void filling_addresses(Data* const original_text, Array* const text_for_sorting, bool* const right_enter);
void free_addresses(Array* text_for_sorting);

#endif //ADDRESSES_H