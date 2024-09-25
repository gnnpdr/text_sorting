#include <stdio.h>

#include "OriginalText.h"
#include "Addresses.h"
#include "print.h"
#include "sorting.h"

int main()
{
    bool right_enter = true;

    int opening_cnt = 0;
    int cnt = 0;

    Data original_text = {};
    Array text_for_sorting = {};

    filling_Data(&original_text, &right_enter);
    if (right_enter == false)
    {
        printf("there is problem\n");
        return 1;
    }
    
    filling_addresses(&original_text, &text_for_sorting, &right_enter);
    if (right_enter == false)
    {
        printf("there is problem\n");
        return 1;
    }

    //print_text(&text_for_sorting);
    //printf("\n");

    sorting(forward_comparing, &text_for_sorting);
    print_text(&text_for_sorting, &opening_cnt, &cnt, &right_enter);

    sorting(reverse_comparing, &text_for_sorting);
    print_text(&text_for_sorting, &opening_cnt, &cnt, &right_enter);

    free_text(&original_text);
    free_addresses(&text_for_sorting);

    printf("oh no, here we go again\n");

    return 0;
}

