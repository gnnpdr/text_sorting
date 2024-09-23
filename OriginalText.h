#ifndef DATA_H
#define DATA_H

#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <sys/stat.h>

struct Data
{
    FILE* file_pointer;
    long file_size;
    char* text;
};

int get_size(const char* filename); 
void filling_Data(Data* const original_text, bool* const right_enter);
void free_text(Data* original_text);

#endif //DATA_H