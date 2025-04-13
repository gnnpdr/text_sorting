#include <stdio.h>

#include "../include/print_text.h"

int print_text(const TextAddrData *const text_for_sorting) 
{                                                                                                               
    assert(text_for_sorting);

    FILE* file;
    file = fopen(FINAL_FILE_NAME, "w");
    if (!file)
    {
        printf("file open error\n");
        return ERR_VAL;
    }

    size_t string_index = 0;
    size_t str_amt = text_for_sorting->str_amt;
    StringParameters* addresses = text_for_sorting->addresses;

    for (size_t ind = 0; ind < str_amt; ind++)
        fprintf(file, "%s\n", addresses[ind].start);

    fclose(file);

    return 0;
}