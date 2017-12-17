#include <stdlib.h>
#include <stdio.h>
#define LIMIT_OF_INPUT  101
#define BITS            7

void dec_to_bin(int decimal, int binary_array[BITS]);
int index_of_character(char character);

int main()
{
    char MESSAGE[LIMIT_OF_INPUT];
    fgets(MESSAGE, LIMIT_OF_INPUT, stdin);
    int binary[BITS];
    
    int flag = -1;
    int o;
    
    for(int i = 0; i < LIMIT_OF_INPUT && MESSAGE[i] != '\n'; i++){
        dec_to_bin(o = index_of_character(MESSAGE[i]), binary);
        for(int j = 0; j < BITS; j++){
            if(flag != binary[j]){
                if(flag != -1)
                    printf(" ");
                if(binary[j] == 0 ){
                    flag = 0;
                    printf("00 ");
                    j--;
                }else{
                    flag = 1;
                    printf("0 ");
                    j--;
                }
            }else if(flag == 0){
                
                printf("0");
            }else if(flag == 1){
                printf("0");
            }
            
        }
        
    }
    
}

void dec_to_bin(int decimal, int binary_array[BITS]){
    if(decimal == -1){
        printf("It's out of standard characters codes table's.");
    }else{
        for (int i = BITS - 1; i >= 0; i--){
            if(decimal){
                binary_array[i] = decimal - decimal / 2 * 2;
                decimal /= 2;
            }else{
                binary_array[i] = 0;
            }
        }
    }
}

int index_of_character(char character){
    char finded_char = -1;
    for(int i = 0; i <= 127; i++)
        if(character == (finded_char + i))
            finded_char = i -1;
    return finded_char;
}
