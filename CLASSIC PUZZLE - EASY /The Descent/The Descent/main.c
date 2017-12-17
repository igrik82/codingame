#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/
int cmpfunc (const void * a, const void * b) {
    return (*(int*)b - *(int*)a);
}

int main()
{
    
    // game loop
    while (1) {
        int highest_mount = 0;
        int target = 0;
        for (int i = 0; i < 8; i++) {
            int mountainH; // represents the height of one mountain.
            scanf("%d", &mountainH);
            if (mountainH > highest_mount){
                highest_mount = mountainH;
                target = i;
            }
            
        }
        printf("%d\n", target);
        // qsort(array, 8, sizeof(int), cmpfunc);
        
    }
    
    return 0;
}
