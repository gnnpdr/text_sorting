#include <stdio.h>

#include "filling_Data.h"

void finding_amount_file_symbols(Data* original_text)
{
    original_text->file_pointer = fopen("text.txt", "rb"); //надо сделать так, чтобы еще пользователь мог вводить название файла

    fseek(original_text->file_pointer , 0 , SEEK_END);  
    original_text->file_size = ftell(original_text->file_pointer); 
    rewind (original_text->file_pointer);

}

void filling_Data(Data* original_text)
{
    original_text->text = (char*)calloc(original_text->file_size, sizeof(char));
    fread (original_text->text, sizeof(char), original_text->file_size, original_text->file_pointer);

    fclose(original_text->file_pointer);
}
