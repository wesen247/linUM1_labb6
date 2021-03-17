#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "libresistance.h"



float calc_resistance(int count, char conn, float *array){
	float sum = 0.0;
	if(count && conn && array){
		if(conn == 'P'){
			while(count > 0){
				count -= 1;
				sum += (1/array[count]);
			}
			return (1/sum);
		} else if(conn == 'S') {
			while(count > 0) {
				count -= 1;
				sum += array[count];
			}
			return sum;
		} else {
			printf("Error: conn can only have values S or P");
			return -1;
			}
	} else {
		printf("Error: please specify all variables: count, conn and *array");
		return -1;
		}
	
}
