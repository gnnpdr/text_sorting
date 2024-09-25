#include <stdio.h>

#include "sorting.h"

void sorting(comparing_t comparing, Array* const text_for_sorting)
{
    assert(text_for_sorting != nullptr);
    assert(comparing != nullptr);

    for (int max_str = text_for_sorting->amount_of_strings - 1; max_str > 0; max_str--)
    {
        for (int string_index = 0; string_index < max_str; string_index++)
        {
            struct StringParametres string_1 = text_for_sorting->addresses[string_index];
            struct StringParametres string_2 = text_for_sorting->addresses[string_index + 1];

            int difference = comparing(&string_1, &string_2); 

            if (difference == GREATER)
            {

                string_1 = text_for_sorting->addresses[string_index];
                string_2 = text_for_sorting->addresses[string_index + 1];

                swap(&string_1, &string_2);

                text_for_sorting->addresses[string_index] = string_1;
                text_for_sorting->addresses[string_index + 1] = string_2;
            }
        }
    }
}

void finding_start_address(char** address_str)
{   
    assert(address_str != nullptr);

    while (isalpha(**address_str) == 0)
        *address_str = *address_str + sizeof(char);
}


int forward_comparing(StringParametres* const string_1, StringParametres* const string_2)
{
    assert(string_1 != nullptr);
    assert(string_2 != nullptr);

    char* string1 = string_1->start;
    char* string2 = string_2->start;

    finding_start_address(&string1);
    finding_start_address(&string2);

    if (tolower(*string1) == tolower(*string2))
    {
        while(tolower(*string1) == tolower(*string2))
        {  
            string1++;
            string2++;
        } 
    }
    if (tolower(*string1) > tolower(*string2))
        return GREATER;
}

void reverse_finding_start_address(char** address_str)
{
    assert(address_str != nullptr);

    while (isalpha(**address_str) == 0)
        *address_str = *address_str - sizeof(char);
}

int reverse_comparing(StringParametres* const string_1, StringParametres* const string_2)
{
    assert(string_1 != nullptr);
    assert(string_2 != nullptr);

    char* string1 = string_1->end;
    char* string2 = string_2->end;

    reverse_finding_start_address(&string1); 
    reverse_finding_start_address(&string2);
    
    if (tolower(*string1) == tolower(*string2))
    {
        while(tolower(*string1) == tolower(*string2))
        {
            string1--;
            string2--;
        }
    }

    if (tolower(*string1) > tolower(*string2))
        return GREATER;
}

void swap(StringParametres* const string1, StringParametres* const string2)
{
    assert(string1 != nullptr);
    assert(string2 != nullptr);

    StringParametres temp = {};
    temp = *string1;
    *string1 = *string2;
    *string2 = temp;
}
