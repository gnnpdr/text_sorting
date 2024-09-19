#ifndef ADDRESSES_H
#define ADDRESSES_H

#include "filling_Data.h"

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

void processing_text(Data* original_text, Array* text_for_sorting);
void filling_addresses(Data* original_text, Array* text_for_sorting, bool* right_enter);

#endif //ADDRESSES_H