#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void go_to_the_fire(int lightX, int lightY, int *ThorX, int *ThorY);

int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    scanf("%d%d%d%d", &lightX, &lightY, &initialTX, &initialTY);
    int ThorX = initialTX;
    int ThorY = initialTY;
    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        scanf("%d", &remainingTurns);
        go_to_the_fire(lightX, lightY, &ThorX, &ThorY);
    }
    
    return 0;
}

void go_to_the_fire(int lightX, int lightY, int *ThorX, int *ThorY){
    char *directionX = "";
    char *directionY = "";
    int temp;
    if(*ThorX > lightX){
        temp = (*ThorX)--;
        directionX = "W";
    }
    else if(*ThorX < lightX){
        (*ThorX)++;
        directionX = "E";
    }
    
    if(*ThorY > lightY){
        (*ThorY)--;
        directionY = "N";
    }
    else if(*ThorY < lightY){
        (*ThorY)++;
        directionY = "S";
    }
    
    printf("%s%s\n", directionY, directionX);
}

