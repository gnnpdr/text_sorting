#ifndef DATA_H
#define DATA_H

#include <stdlib.h>
#include <assert.h>
#include <math.h>

struct Data
{
    FILE* file_pointer;
    long file_size;
    char* text;
};

void finding_amount_file_symbols(Data* const original_text);
void filling_Data(Data* const original_text, bool* const right_enter);

#endif //DATA_H