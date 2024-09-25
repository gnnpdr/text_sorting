#include <stdio.h>

#include "OriginalText.h"

int get_size(const char* filename) 
{
    struct stat st = {};

    if(stat(filename, &st) != 0) {
        return 0;
    }
    return st.st_size;   
}

void filling_Data(Data* const original_text, bool* const right_enter)
{
    assert(original_text != nullptr);
    assert(right_enter != nullptr);

    original_text->file_pointer = fopen("text.txt", "rb");
    if (original_text->file_pointer == nullptr)
    {
        *right_enter = false;
        printf("file wasn't opened\n");
        return;
    }

    original_text->file_size = get_size("text.txt");

    original_text->text = (char*)calloc(original_text->file_size, sizeof(char));
    if (original_text->text == nullptr)
    {
        printf("not enough space for the program to run\n");
        *right_enter = false;
        return;
    }

    fread(original_text->text, sizeof(char), original_text->file_size, original_text->file_pointer);

    fclose(original_text->file_pointer);
}

void free_text(Data* original_text)
{
    assert(original_text != nullptr);

    free(original_text->text);
}