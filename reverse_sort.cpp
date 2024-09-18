#include <stdio.h>

#include "reverse_sort.h"

void reverse_finding_start_address(char** address_str)
{
    assert(address_str != nullptr);

    //printf("start address %p\n", *address_str);
    while (**address_str != '\0')
        *address_str = *address_str + sizeof(char);

    while (isalpha(**address_str) == 0)
    {
        //printf("symb [%c]", **address_str);
        //printf("next symb in address\n");
        *address_str = *address_str - sizeof(char);
    }
    //printf("symb [%c]", **address_str);
    //printf("end address %p\n", *address_str);
}

int reverse_comparing(char* string1, char* string2)
{
    assert(string1 != nullptr);
    assert(string2 != nullptr);

    //printf("string %d\n", string);
    reverse_finding_start_address(&string1);    //меняет адрес, переносит его к первому непробельному символу
    //printf("string 2\n");
    reverse_finding_start_address(&string2);

    if (tolower(*string1) > tolower(*string2))
    {
        //printf("swap because %c > %c\n", *string1, *string2);
        return GREATER;
    }
        
    else if (tolower(*string1) == tolower(*string2))
        return EQUAL;
    else
        return LESS;
}

void reverse_sorting(Array* text_for_sorting) 
{
    assert(text_for_sorting != nullptr);

    for (int max_str = text_for_sorting->amount_of_strings - 1; max_str > 0; max_str--)
    {
        //printf("max str %d\n", max_str);
        for (int string = 0; string < max_str; string++)
        {
            //printf("string %d {%s} \n", string, text_for_sorting->addresses[string]);
            int element = 0;

            char* string1 = &text_for_sorting->addresses[string][element];
    
            char* string2 = &text_for_sorting->addresses[string+1][element];

            int difference = reverse_comparing(string1, string2);

            while (difference == 0)
            {
                //printf("next symb\n");

                string1--;
                string2--;

                difference = reverse_comparing(string1, string2);
            }
            if (difference > 0)
            {
                string1 = text_for_sorting->addresses[string];
                string2 = text_for_sorting->addresses[string+1];

                //printf("swap str, element %d\n", element);
                swap_str(&string1, &string2);

                text_for_sorting->addresses[string] = string1;
                text_for_sorting->addresses[string+1] = string2;
            }
        }
    }
}