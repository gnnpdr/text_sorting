#include <stdio.h>

#include "reverse_sort.h"

void reverse_finding_start_address(char** address_str)
{
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

int reverse_comparing(Array* text_for_sorting, int string, int element)
{
    //printf("string in comparing %d\n", string);

    char* address_str1 = text_for_sorting->addresses[string];
    char* address_str2 = text_for_sorting->addresses[string+1];

    //printf("string %d\n", string);
    reverse_finding_start_address(&address_str1);    //меняет адрес, переносит его к первому непробельному символу
    //printf("string %d\n", string + 1);
    reverse_finding_start_address(&address_str2);

    if (tolower(*(address_str1 - element)) > tolower(*(address_str2 - element)))
    {
        //printf("string %d el %d swap because %c > %c\n", string, element, *(address_str1 + element), *(address_str2 + element));
        return GREATER;
    }
        
    else if (tolower(*(address_str1 - element)) == tolower(*(address_str2 - element)))
        return EQUAL;
    else
        return LESS;
}
void reverse_sorting(Array* text_for_sorting) 
{
    for (int max_str = text_for_sorting->amount_of_strings - 1; max_str > 0; max_str--)
    {
        //printf("max str %d\n", max_str);
        for (int string = 0; string < max_str; string++)
        {
            //printf("string %d {%s} \n", string, text_for_sorting->addresses[string]);
            int element = 0;
            
            int difference = reverse_comparing(text_for_sorting, string, element);

            while (difference == 0)
            {
                //printf("next symb\n");
                element++;
                difference = reverse_comparing(text_for_sorting, string, element);
            }
            if (difference > 0)
            {
                //printf("swap str, element %d\n", element);
                rev_swap_str(text_for_sorting, string);
            }
        }
    }
}

void rev_swap_str(Array* text_for_sorting, int string)
{
    char* temp = 0;
    temp = text_for_sorting->addresses[string];
    //printf("\nstring before [%s]\n", text_for_sorting->addresses[string]);
    text_for_sorting->addresses[string] = text_for_sorting->addresses[string+1];
    //printf("string after [%s]\n", text_for_sorting->addresses[string]);
    text_for_sorting->addresses[string+1] = temp;
}