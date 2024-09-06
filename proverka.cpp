#include <stdio.h>

const int AMOUNT_OF_STR = 3;
const int AMOUNT_OF_ELEMENTS_IN_STR = 50;

void print(char text[][AMOUNT_OF_ELEMENTS_IN_STR]);
void sorting(char text[][AMOUNT_OF_ELEMENTS_IN_STR]);

int main()
{
    char text[AMOUNT_OF_STR][AMOUNT_OF_ELEMENTS_IN_STR] = {
    "cool guys\n",
    "dont do this shit\n",
    "but he does\n"
    };

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
    
    int str = AMOUNT_OF_STR;
    while (str > 0 )
    {

        for (int element = 0; element < AMOUNT_OF_STR-1; element++)
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
        --str;
    }
}