#include <stdio.h>

#include "sorting.h"

static void swap(StringParameters* const str1, StringParameters* const str2);

static void finding_start_address(char** address_str);
static void reverse_finding_start_address(char** address_str);

void sorting(comparing_t comparing, TextAddrData* const text_for_sorting)
{
    assert(text_for_sorting);
    assert(comparing);

    size_t str_amt = text_for_sorting->str_amt;
    StringParameters* addresses = text_for_sorting->addresses;

    for (int max_str = str_amt - 1; max_str > 0; max_str--)
    {
        for (size_t string_index = 0; string_index < max_str; string_index++)
        {
            StringParameters str1 = addresses[string_index];
            StringParameters str2 = addresses[string_index + 1];

            int difference = comparing(&str1, &str2); 

            if (difference == GREATER)
            {

                str1 = addresses[string_index];
                str2 = addresses[string_index + 1];

                swap(&str1, &str2);

                addresses[string_index] = str1;
                addresses[string_index + 1] = str2;
            }
        }
    }
}

void finding_start_address(char** address_str)
{   
    assert(address_str);

    while (isalpha(**address_str) == 0)
        *address_str = *address_str + sizeof(char);
}

int forward_comparing(StringParameters* const str1, StringParameters* const str2)
{
    assert(str1);
    assert(str2);

    char* str1_start = str1->start;
    char* str2_start = str2->start;

    finding_start_address(&str1_start);
    finding_start_address(&str2_start);

    if (tolower(*str1_start) == tolower(*str2_start))
    {
        while(tolower(*str1_start) == tolower(*str2_start))
        {  
            str1_start++;
            str2_start++;
        } 
    }

    if (tolower(*str1_start) > tolower(*str2_start))
        return GREATER;

    return LESS;
}

void reverse_finding_start_address(char** address_str)
{
    assert(address_str);

    while (isalpha(**address_str) == 0)
        *address_str = *address_str - sizeof(char);
}

int reverse_comparing(StringParameters* const str1, StringParameters* const str2)
{
    assert(str1);
    assert(str2);

    char* str1_end = str1->end;
    char* str2_end = str2->end;

    reverse_finding_start_address(&str1_end); 
    reverse_finding_start_address(&str2_end);
    
    if (tolower(*str1_end) == tolower(*str2_end))
    {
        while(tolower(*str1_end) == tolower(*str2_end))
        {
            str1_end--;
            str2_end--;
        }
    }

    if (tolower(*str1_end) > tolower(*str2_end))
        return GREATER;

    
    return LESS;
}

void swap(StringParameters* const str1, StringParameters* const str2)
{
    assert(str1);
    assert(str2);

    StringParameters temp = {};
    temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}
