#include <stdio.h>

#include "filling_Data.h"

void finding_amount_file_symbols(Data* const original_text)
{
    assert(original_text != nullptr);

    fseek(original_text->file_pointer , 0 , SEEK_END);  
    original_text->file_size = ftell(original_text->file_pointer); 
    rewind (original_text->file_pointer);
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
        
    finding_amount_file_symbols(original_text);

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
