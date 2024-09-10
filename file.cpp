#include <stdio.h>
const int AMOUNT_OF_STR = 14;
const int AMOUNT_OF_ELEMENTS_IN_STR = 200;

void print(char text[][AMOUNT_OF_ELEMENTS_IN_STR]);



int main()
{
   
    char text[AMOUNT_OF_STR][AMOUNT_OF_ELEMENTS_IN_STR] = {};

    char buffer[200];

    FILE *fp = fopen("text.txt", "r");

    if(fp)
    {
        char ch = 0;
        //printf("all right\n");
        while(ch != EOF)
        {
            for (int i = 0; i < AMOUNT_OF_STR; i++)
            {
                for (int j = 0; j < AMOUNT_OF_ELEMENTS_IN_STR; j++)
                {
                    ch = getc(fp);
                    text[i][j] = ch;
                    if (ch == EOF || ch == '\n' )
                        
                        break;
                }
            }
        }
    } 

    print(text);
    fclose(fp);
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