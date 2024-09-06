#include <stdio.h>

const int AMOUNT_OF_STR = 14;
const int AMOUNT_OF_ELEMENTS_IN_STR = 1000;

int main()
{
    char text[][AMOUNT_OF_ELEMENTS_IN_STR] = {
    "Evgeny's total store of knowledge\n"
    "I have no leisure to recall;\n"
    "where he was master of his college,\n"
    "the art he'd studied best of all,\n"
    "his young heyday's supreme employment,\n"
    "its work, its torture, its enjoyment,\n"
    "what occupied his chafing powers\n"
    "throughout the boredom of the hours -\n"
    "this was the science of that passion\n"
    "which Ovid sang, for which the bard,\n"
    "condemned to a lifetime of hard,\n"
    "ended his wild career of fashion\n"
    "deep in Moldavia the abhorred,\n"
    "far, far from Italy, his adored."
    };

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

    return 0;
}
