#include <stdio.h>

#include "forward_sort.h"

void finding_start_address(char** address_str)
{   
    assert(address_str != nullptr);

    //printf("start address %p\n", *address_str);

    while (isalpha(**address_str) == 0)
    {
        printf("next symb in address\n");
        *address_str = *address_str + sizeof(char);
    }

    //printf("end address %p\n", *address_str);
}


int comparing(char* string1, char* string2)
{
    assert(string1 != nullptr);
    assert(string2 != nullptr);

    //printf("string 1 %d\n", &string1);

    finding_start_address(&string1);

    //printf("string 2 %d\n", &string2);
    finding_start_address(&string2);

    if (tolower(*string1) > tolower(*string2))
    {
        printf("swap because %c > %c\n", *string1, *string2);
        return GREATER;
    }
        
    else if (tolower(*string1) == tolower(*string2))
        return EQUAL;
    else
        return LESS;
}

void forward_sorting(Array* text_for_sorting) //надо сделать функцию, которая подает на выход адрес начала строки, т.е. учитывает пробелы
{
    assert(text_for_sorting != nullptr);

    for (int max_str = text_for_sorting->amount_of_strings - 1; max_str > 0; max_str--)
    {
        printf("max str %d\n", max_str);
        for (int string = 0; string < max_str; string++)
        {
            printf("string %d {%s} \n", string, text_for_sorting->addresses[string]);

            int element = 0;

            char* string1 = &text_for_sorting->addresses[string][element];
            printf("string address %p\n, address text %p\n, string %p string, '%s'", &string1, text_for_sorting->addresses[string], string1, string1);
    
            char* string2 = &text_for_sorting->addresses[string+1][element];

            int difference = comparing(string1, string2);

            while (difference == 0)
            {
                printf("next symb\n");

                string1++;
                string2++;

                difference = comparing(string1, string2);
            }
            if (difference > 0)
            {
                string1 = text_for_sorting->addresses[string];
    
                string2 = text_for_sorting->addresses[string+1];

                printf("swap str, element %d\n", element);

                //printf("string1 %p\n", &string1);
                //printf("string2 %p\n", &string2);

                //printf("string1 [%s]\n", string1);
                //printf("string2 [%s]\n", string2);

                swap_str(&string1, &string2);

                text_for_sorting->addresses[string] = string1;
    
                text_for_sorting->addresses[string+1] = string2;
            }
                
        }
    }
}

void swap_str(char** string1, char** string2)
{
    assert(string1 != nullptr);
    assert(string2 != nullptr);

    //printf("string 2 before [%s]\n", *string2);
    char* temp = 0;
    temp = *string1;
    //printf("temp %s\n", temp);
    *string1 = *string2;
    //printf("string1 %s\n", *string1);
    *string2 = temp;
    //printf("string 1 after [%s]\n", *string1);
    //printf("string 2 after [%s]\n\n", *string2);
}
