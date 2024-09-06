#include <stdio.h>

const int AMOUNT_OF_STR = 14;
const int AMOUNT_OF_ELEMENTS_IN_STR = 200;

void print(char text[][AMOUNT_OF_ELEMENTS_IN_STR]);
void sorting(char text[][AMOUNT_OF_ELEMENTS_IN_STR]);

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

    if ('E'<'e')    
        printf("yes, but its strange\n\n");

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
    for (int str = AMOUNT_OF_STR-1; str > 0; str--)
    {
        for (int element = 0; element < str; element++)
        {
            //printf("%s\n", text[element]);
            if (text[element][0] > text[element+1][0])
            {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
                for (int i = 0; i < AMOUNT_OF_ELEMENTS_IN_STR; i++)
                {
                    
                    char temp = 0;
                    temp = text[element][i];
                    text[element][i] = text[element+1][i];
                    text[element+1][i] = temp;
                }
            }
        }
    }
}