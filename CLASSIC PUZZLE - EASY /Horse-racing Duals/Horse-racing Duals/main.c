#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;
    scanf("%d", &N);
    
    int Horses[N];
    
    for (int i = 0; i < N; i++) {
        int Pi;
        scanf("%d", &Pi);
        Horses[i] = Pi;
    }
    qsort(Horses, N, sizeof(int), cmpfunc);
    // Horses;
    int closest_strengths = INT_MAX;
    
    for (int i = 0; Horses[i] != 0; i++) {
        int temp;
        temp = (Horses[i + 1] - Horses[i]);
        
        if(closest_strengths > temp && temp >= 0){
            closest_strengths = temp;
        }else{
            continue;
        }
    }
    printf("%d", closest_strengths);
    
    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    
    // printf("answer\n");
    
    return 0;
}

