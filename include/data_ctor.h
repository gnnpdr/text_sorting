#ifndef DATA_H
#define DATA_H

#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>

static const int ERR_VAL = -228;
static const char* ORIGINAL_FILE_NAME = "text.txt";

struct Data
{
    FILE* file_pointer;
    size_t file_size;
    char* text;
};

int data_ctor(Data *const original_text);
void data_dtor(Data* original_text);

#endif //DATA_H