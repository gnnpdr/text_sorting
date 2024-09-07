#include <stdio.h>

const int AMOUNT_OF_STR = 14;
const int AMOUNT_OF_ELEMENTS_IN_STR = 200;

void print(char text[][AMOUNT_OF_ELEMENTS_IN_STR]);
void sorting(char text[][AMOUNT_OF_ELEMENTS_IN_STR]);

int comparing(char text[][AMOUNT_OF_ELEMENTS_IN_STR], int* el, int* string);
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
    "this was the science of that passion\n",
    "which Ovid sang, for which the bard,\n",
    "condemned to a lifetime of hard,\n",
    "ended his wild career of fashion\n",
    "deep in Moldavia the abhorred,\n",
    "far, far from Italy, his adored.\n"
    };

    //if ('E'<'e')    
        //printf("yes, but its strange\n\n");

    //printf("%s\n", text[3][5]);
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
            //printf("str %d, el %d ", str, i);
            printf("%c", text[str][i]);
            i++;
        }
        while(text[str][i] != '\0');
        i = 0;
    }

}

void sorting(char text[][AMOUNT_OF_ELEMENTS_IN_STR])
{
    //for (int element = 0; element < AMOUNT_OF_ELEMENTS_IN_STR; element++)
    //{
    for (int str = AMOUNT_OF_STR-1; str > 0; str--)
    {
        for (int string = 0; string < str; string++)
        {
            int el = 0;

            //printf("%s\n", text[element]);

            int difference = comparing(text, &el, &string);

            if (difference > 0)
                change_srt(text, &string);
            else if (difference == 0)
            {
                //printf("\nproblem\n string %s\n", text[string][el]);
                while (difference == 0)
                {
                    el++;
                    difference = comparing(text, &el, &string);
                }
                if (difference > 0)
                    change_srt(text, &string);
            }
        }
    }
}
//}

int comparing(char text[][AMOUNT_OF_ELEMENTS_IN_STR], int* el, int* string)
{
    if (text[*string][*el] > text[*string+1][*el])
        return 1;
    else if (text[*string][*el] == text[*string+1][*el])
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