#include <stdio.h>

#include "../include/data_ctor.h"

static int get_size(const char* filename); 

int get_size(const char *const filename) 
{
    assert(filename);

    struct stat st = {};

    if(stat(filename, &st) != 0) 
    {
        printf("stat error\n");
        return ERR_VAL;
    }
    return st.st_size;   
}

int data_ctor(Data *const original_text)
{
    assert(original_text);

    original_text->file_pointer = fopen(ORIGINAL_FILE_NAME, "r");
    if (!original_text->file_pointer)
    {
        printf("file opening error\n");
        return ERR_VAL;
    }

    original_text->file_size = get_size(ORIGINAL_FILE_NAME);
    if (original_text->file_size == ERR_VAL) return ERR_VAL;

    original_text->text = (char*)calloc(original_text->file_size, sizeof(char));
    if (!original_text->text)
    {
        printf("allocation error\n");
        return ERR_VAL;
    }

    fread(original_text->text, sizeof(char), original_text->file_size, original_text->file_pointer);

    fclose(original_text->file_pointer);

    return 0;
}

void data_dtor(Data* original_text)
{
    free(original_text->text);
}