#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define INPUT_LIMIT 200
#define M_PI 3.14159265358979323846264338327950288

double string_to_float_in_rad(char *string);
double distance(double Longitude_curent, double Latitude_curent, double Longitude_def, double Latitude_def);
void get_separate_fields(char data[], char separate[][INPUT_LIMIT]);
void clear_array(char arr[]);

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main(){
    char LON[51];
    scanf("%s", LON);
    char LAT[51];
    scanf("%s", LAT);
    int N;

    char all_defibrillators[INPUT_LIMIT][INPUT_LIMIT][INPUT_LIMIT] = {" "};

    scanf("%d", &N); fgetc(stdin);

    for (int i = 0; i < N; i++) {
        char DEFIB[257];
        fgets(DEFIB, 257, stdin);
        get_separate_fields(DEFIB, all_defibrillators[i]);
    }

    double min_distance = LLONG_MAX;
    
    char closest_defibrillator[INPUT_LIMIT] = {" "};
    for(int i = 0; i < N; i++){
        
        double distance_betweent = distance (string_to_float_in_rad(LON),
                                      string_to_float_in_rad(LAT),
                                      string_to_float_in_rad(all_defibrillators[i][4]),
                                      string_to_float_in_rad(all_defibrillators[i][5])
                                      );
        if(min_distance > distance_betweent){
            min_distance = distance_betweent;
            clear_array(closest_defibrillator);
            for(int j = 0; all_defibrillators[i][1][j] != '\0'; j++){
                closest_defibrillator[j] = all_defibrillators[i][1][j];
            }
        }else{
            continue;
        }
    }
    printf("%s\n", closest_defibrillator);

    return 0;
}

void clear_array(char arr[]){
    for (int i = 0; arr[i]; i++){
        arr[i] = '\0';
    }
}

double string_to_float_in_rad(char *string){
    char fl[INPUT_LIMIT];
    for(int i = 0 ; string[i] != '\0'; i++){
        if(string[i] != ','){
            fl[i] = string[i];
        }else{
        fl[i] = '.';
        }
    }
    return (M_PI * atof(fl)) / 180;
}

double distance(double Longitude_curent, double Latitude_curent, double Longitude_def, double Latitude_def){
    double x, y, d;
    
    x = ((Longitude_def - Longitude_curent) * cos((Latitude_curent + Latitude_def) / 2));
    y = (Latitude_def - Latitude_curent);
    d = (sqrt(pow(x,2) + pow(y, 2))) * 6371;
    return d;
}

void get_separate_fields(char data[], char separate[][INPUT_LIMIT]){
    char sep = ';';
    for(int i = 0, j = 0, z = 0; data[i]; i++, z++){
        if(data[i] != sep && data[i] != '\n'){
            separate[j][z] = data[i];
        }else{
            j++;
            z = -1;
            continue;
        }
    }
}
