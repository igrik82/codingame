#include <stdlib.h>
#include <stdio.h>

void control_vSpeed(int vSpeed, int *power);
int main()
{
    int surfaceN; // the number of points used to draw the surface of Mars.
    scanf("%d", &surfaceN);
    for (int i = 0; i < surfaceN; i++) {
        int landX; // X coordinate of a surface point. (0 to 6999)
        int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        scanf("%d%d", &landX, &landY);
    }
    
    // game loop
    while (1) {
        int X;
        int Y;
        int hSpeed; // the horizontal speed (in m/s), can be negative.
        int vSpeed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power; // the thrust power (0 to 4).
        scanf("%d%d%d%d%d%d%d", &X, &Y, &hSpeed, &vSpeed, &fuel, &rotate, &power);
        
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        
        
        // 2 integers: rotate power. rotate is the desired rotation angle (should be 0 for level 1), power is the desired thrust power (0 to 4).
        control_vSpeed(vSpeed, &power);
        printf("0 %d\n", power);
    }
    
    return 0;
}
void control_vSpeed(int vSpeed, int *power){
    //fuel - 3031
    if(vSpeed >= -40 && *power > 0){
        (*power)--;
    }
    else if(*power < 4){
        (*power)++;
    }
}
