#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    
    int age = 22;
    float gpa = 3.67;
    
    printf("Calvin is %d years old and has a GPA of %.2f.\n", age, gpa);
    
    const float PI = 3.1416;
    int radius = 10;
    float circumference = 2 * PI * radius;
    
    printf("The circumference of a circle with radius %d is %.2f.\n", radius, circumference);
    
    typedef enum weather {RAINY, WINDY, SUNNY} Weather;
    
    Weather current_weather = WINDY;
    
    switch(current_weather) {
        case RAINY:
            printf("GET AN UMBRELLA!\n");
            break;
        case WINDY:
            printf("DON'T LOSE YOUR UMBRELLA!\n");
            break;
        case SUNNY:
            printf("WEAR SUNGLASSES!\n");
            break;
    }

    return (EXIT_SUCCESS);
}

