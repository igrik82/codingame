#include <stdlib.h>
#include <stdio.h>

int min_temperature(int arr_temperature[],int size_array);
int main()
{
    int n; // the number of temperatures to analyse
    int minimal_temperature = 0;
    
    if(scanf("%d", &n) == 1){
        int temperature[n];
        for (int i = 0; i < n; i++) {
            int t; // a temperature expressed as an integer ranging from -273 to 5526
            scanf("%d", &t);
            temperature[i] = t;
            //printf("%d\n\n%d\n", n, temperature[i]);
        }
        
        minimal_temperature = min_temperature(temperature, n);
        printf("%d\n", minimal_temperature);
        
    }else{
        printf("%d\n", minimal_temperature);
    }
    return 0;
}

int min_temperature(int arr_temperature[],int size_array){
    int min_temp = *arr_temperature;
    for (int i = 0; i < size_array; i++){
        if(abs(arr_temperature[i]) < abs(min_temp))
            min_temp = arr_temperature[i];
    }
    for (int i = 0, j = 0; i < size_array; i++) {
        if(abs(min_temp) == abs(arr_temperature[i])){
            j++;
            if(j > 1 && min_temp != arr_temperature[i]){
                min_temp = abs(arr_temperature[i]);
            }else{
                min_temp = arr_temperature[i];
            }
        }
    }
    return min_temp;
}

