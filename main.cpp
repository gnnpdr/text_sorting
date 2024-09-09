#include <stdio.h>
#include <ctype.h>

const int AMOUNT_OF_STR = 14;
const int AMOUNT_OF_ELEMENTS_IN_STR = 200;

void print(char text[][AMOUNT_OF_ELEMENTS_IN_STR]);
void sorting(char text[][AMOUNT_OF_ELEMENTS_IN_STR]);

int comparing(char text[][AMOUNT_OF_ELEMENTS_IN_STR], int* el1, int* el2, int* string);
void change_srt(char text[][AMOUNT_OF_ELEMENTS_IN_STR], int* string);

int main()
{
    char text[AMOUNT_OF_STR][AMOUNT_OF_ELEMENTS_IN_STR] = {
    "Evgeny's total store of knowledge\n",
    "I have no leisure to recall;\n",
    "where he was master of his college,\n",
    "the art he'd studied best of all,\n",
    "his young heyday's supreme employment,\n",
    "its work, its torture, its enjoyment,\n",
    "what occupied his chafing powers\n",
    "throughout the boredom of the hours -\n",
    " this was the science of that passion\n",
    "which Ovid sang, for which the bard,\n",
    "condemned to a lifetime of hard,\n",
    "ended his wild career of fashion\n",
    "deep in Moldavia the abhorred,\n",
    "far, far from Italy, his adored.\n"
    };

    print(text);
    sorting(text);
    printf("\n");
    print(text);

    return 0;
}

void print(char text[][AMOUNT_OF_ELEMENTS_IN_STR])
{
    for (size_t str = 0; str < AMOUNT_OF_STR; str++)
    {
        int i = 0;
        do
        {
            printf("%c", text[str][i]);
            i++;
        }
        while(text[str][i] != '\0');
        i = 0;
    }

}

void sorting(char text[][AMOUNT_OF_ELEMENTS_IN_STR])
{
    for (int str = AMOUNT_OF_STR-1; str > 0; str--)
    {
        for (int string = 0; string < str; string++)
        {
            int el1 = 0;
            int el2 = 0;

            int difference = comparing(text, &el1, &el2, &string);

            if (difference > 0)
                change_srt(text, &string);
            else if (difference == 0)
            {
                while (difference == 0)
                {
                    el1++;
                    el2++;
                    difference = comparing(text, &el1, &el2, &string);
                }
                if (difference > 0)
                    change_srt(text, &string);
            }
        }
    }
}

int comparing(char text[][AMOUNT_OF_ELEMENTS_IN_STR], int* el1, int* el2, int* string)
{
    if (isalpha(text[*string][*el1]) == 0)
        *el1++;

    if (isalpha(text[*string+1][*el2]) == 0)
        *el2++;
        

    if (tolower(text[*string][*el1]) > tolower(text[*string+1][*el2]))
        return 1;
    else if (tolower(text[*string][*el1]) == tolower(text[*string+1][*el2]))
        return 0;
    else
        return -1;
}

void change_srt(char text[][AMOUNT_OF_ELEMENTS_IN_STR], int* string)
{
    for (int i = 0; i < AMOUNT_OF_ELEMENTS_IN_STR; i++)
    {     
        char temp = 0;
        temp = text[*string][i];
        text[*string][i] = text[*string+1][i];
        text[*string+1][i] = temp;
    }
}