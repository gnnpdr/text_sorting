#include <stdio.h>

#include "filling_Data.h"

void finding_amount_file_symbols(Data* original_text)
{
    fseek(original_text->file_pointer , 0 , SEEK_END);  
    original_text->file_size = ftell(original_text->file_pointer); 
    rewind (original_text->file_pointer);

    //printf("%d\n", original_text->file_size);
}

void filling_Data(Data* original_text, bool* right_enter)
{
    original_text->file_pointer = fopen("text1.txt", "rb");

    finding_amount_file_symbols(original_text);

    //printf("%d\n", original_text->file_size);

    original_text->text = (char*)calloc(original_text->file_size, sizeof(char));
    if (original_text->text == nullptr)
    {
        *right_enter = false;
    }

    //printf("%p\n", original_text->text);

    fread (original_text->text, sizeof(char), original_text->file_size, original_text->file_pointer);

    fclose(original_text->file_pointer);
}
