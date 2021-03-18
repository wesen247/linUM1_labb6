#include <stdio.h>

#include "libcomponent.h"

int e_resistance(float orig_resistance, float *res_array)
{
    const float e12[29] = {1, 10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82, 100, 
        120, 150, 180, 220, 270, 330, 390, 470, 560, 680, 820, 1000,
        1200, 1500, 1800};

    int count = 0;
    int i = 0;
    int j = 0;
    float temp = orig_resistance;

// serching on e12-series and finding the best value
    while(i>=0&&count<3){
        j = i;

        for(i=28; temp-e12[i]<0 && i>=0;i--);

        if(i>=0)
        {
            temp = temp-e12[i];
        // safe the value to the array
            *res_array=e12[i];
            res_array++;
            count++;
        }

    }

    return count;
}

