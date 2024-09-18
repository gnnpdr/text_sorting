#include <stdio.h>

#include "filling_Data.h"
#include "filling_Addresses.h"
#include "print.h"
#include "forward_sort.h"
#include "reverse_sort.h"
#include "free.h"

int main()
{
    bool right_enter = true;

    Data original_text = {};
    Array text_for_sorting = {};

    filling_Data(&original_text, &right_enter);
    if (right_enter == false)
    {
        printf("there is problem with capacity\n");
        return 1;
    }
    
    processing_text(&original_text, &text_for_sorting);
    filling_addresses(&original_text, &text_for_sorting, &right_enter);
    if (right_enter == false)
    {
        printf("there is problem with capacity\n");
        return 1;
    }

    //print_text(&text_for_sorting);
    //printf("\n");

    printf("print forward sorting\n\n");
    forward_sorting(&text_for_sorting);
    print_text(&text_for_sorting);
    printf("\n");

    printf("print reverse sorting\n\n");
    reverse_sorting(&text_for_sorting);
    print_text(&text_for_sorting);

    free_arrays(&text_for_sorting, &original_text);

    return 0;
}