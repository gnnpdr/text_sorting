#include <stdio.h>

#include "include/data_ctor.h"
#include "include/handle_text.h"
#include "include/sorting.h"
#include "include/print_text.h"

int main()
{
    
    Data original_text = {};
    int err = data_ctor(&original_text);
    if (err)  return ERR_VAL;

    TextAddrData text_for_sorting = {};
    err = ctor_addresses(&original_text, &text_for_sorting);
    if (err) return ERR_VAL;

    //sorting(forward_comparing, &text_for_sorting);
    //print_text(&text_for_sorting);

    sorting(reverse_comparing, &text_for_sorting);
    print_text(&text_for_sorting);

    data_dtor(&original_text);
    dtor_addresses(&text_for_sorting);

    return 0;
}

