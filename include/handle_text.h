#ifndef ADDRESSES_H
#define ADDRESSES_H

#include "data_ctor.h"

struct StringParameters
{
    char* start;
    char* end;
};

struct TextAddrData
{
    StringParameters* addresses;  
    size_t str_amt;
};

int ctor_addresses(const Data *const original_text, TextAddrData *const text_for_sorting);
void dtor_addresses(TextAddrData* text_for_sorting);

#endif //ADDRESSES_H