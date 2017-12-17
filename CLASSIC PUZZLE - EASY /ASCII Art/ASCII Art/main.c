#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define ROWS_INPUT_CONDITION    257
#define ROWS_ASCII              1025
#define COLS                    20

void draw_ASCII(char T[ROWS_INPUT_CONDITION], int width, int height, char ROW[][ROWS_ASCII]);
int index_of_input_character(char character);

int main()
{
    int L;
    scanf("%d", &L);
    int H;
    scanf("%d", &H); fgetc(stdin);
    char T[ROWS_INPUT_CONDITION];
    fgets(T, ROWS_INPUT_CONDITION, stdin);
    
    char ROW[COLS][ROWS_ASCII];
    for (int i = 0; i <= H; i++) {
        fgets(ROW[i], ROWS_ASCII, stdin);
    }
    
    draw_ASCII(T, L, H, ROW);
    
    
}

void draw_ASCII(char T[ROWS_INPUT_CONDITION], int width, int height, char ROW[][ROWS_ASCII]){
    /*
     Print character columns.
     */
    for(int i = 0; i < height; i++){
        
        /*
         Removing unused input conditions.
         */
        for (int y = 0; y < ROWS_INPUT_CONDITION && T[y] != '\n'; y++){
            /*
             Print character rows.
             */
            for(int j = index_of_input_character(T[y]) * width; j < index_of_input_character(T[y]) * width + width; j++){
                
                printf("%c", ROW[i][j]);
            }
            // putchar('\n');
        }
        putchar('\n');
    }
}

int index_of_input_character(char character){
    /*
     Making array of ASCII characters.
     */
    char alphabet = ' ';
    char ASCII[27];
    for(int i = 33, j = 0; i <= 58; i++, j++){
        ASCII[j] = alphabet + i;
    }
    ASCII[26] = alphabet + 31;
    
    /*
     Search for characters in ASCII's array.
     */
    int index_of_finded_simbol = -1;
    for(int i = 0; i < 27; i++){
        if(toupper(character) == ASCII[i])
            index_of_finded_simbol = i;
        //realy don't know why is condition ELSE don't work
    }
    if (index_of_finded_simbol == -1)
        index_of_finded_simbol = 26;
    
    return index_of_finded_simbol;
}


