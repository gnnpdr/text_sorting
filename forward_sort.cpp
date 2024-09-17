#include <stdio.h>

#include "forward_sort.h"

void finding_start_address(char** address_str)
{   
    //printf("start address %p\n", *address_str);

    while (isalpha(**address_str) == 0)
    {
        //printf("next symb in address\n");
        *address_str = *address_str + sizeof(char);
    }

    //printf("end address %p\n", *address_str);
}


int comparing(Array* text_for_sorting, int string, int element)
{
    char* address_str1 = text_for_sorting->addresses[string];
    
    char* address_str2 = text_for_sorting->addresses[string+1];

    //printf("string %d\n", string);
    finding_start_address(&address_str1);

    //printf("string %d\n", string + 1);
    finding_start_address(&address_str2);

    if (tolower(*(address_str1 + element)) > tolower(*(address_str2 + element)))
    {
        //printf("string %d el %d swap because %c > %c\n", string, element, *(address_str1 + element), *(address_str2 + element));
        return GREATER;
    }
        
    else if (tolower(*(address_str1 + element)) == tolower(*(address_str2 + element)))
        return EQUAL;
    else
        return LESS;
}

void forward_sorting(Array* text_for_sorting) //надо сделать функцию, которая подает на выход адрес начала строки, т.е. учитывает пробелы
{
    for (int max_str = text_for_sorting->amount_of_strings - 1; max_str > 0; max_str--)
    {
        //printf("max str %d\n", max_str);
        for (int string = 0; string < max_str; string++)
        {
            //printf("string %d {%s} \n", string, text_for_sorting->addresses[string]);

            int element = 0;

            int difference = comparing(text_for_sorting, string, element);

            while (difference == 0)
            {
                //printf("next symb\n");
                element++;
                difference = comparing(text_for_sorting, string, element);
            }
            if (difference > 0)
            {
                //printf("swap str, element %d\n", element);
                swap_str(text_for_sorting, string);
            }
                
        }
    }
}

void swap_str(Array* text_for_sorting, int string)
{
    char* temp = 0;
    temp = text_for_sorting->addresses[string];
    text_for_sorting->addresses[string] = text_for_sorting->addresses[string+1];
    text_for_sorting->addresses[string+1] = temp;
}
