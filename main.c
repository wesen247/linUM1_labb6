#include <stdio.h>

#include "lib/libpower.h"
#include "lib/libresistance.h"

int main()
{
	float resistance, volt;
	int nbr_resistors, resistors_count;
	char type[]={0};
	
	printf("Enter volt: ");
	scanf("%f", &volt);
	
	printf("Serial 'S' or Paralel 'P' ?: ");
	scanf("%s", &type);
	
	printf("Enter number of resistors: ");
	scanf("%d", &nbr_resistors);
	resistors_count = nbr_resistors;
	
	float resistors[nbr_resistors];
	while(resistors_count > 0) {
		printf("Enter resistor: ");
		scanf("%f", &resistors[resistors_count-1]);
		resistors_count -= 1;
	}
	
	resistance = calc_resistance(nbr_resistors, type[0], &resistors);
	printf("%s\n", "Replacement resistance: ");
	printf("%0.1f\n\n", resistance);
	
	
	float effect;
	effect = calc_power_r(volt, resistance);
	printf("Effect (calc_power_r): \n%0.2f W\n", effect);
	
	effect = calc_power_i(volt, (volt/resistance));
	printf("Effect (calc_power_i): \n%0.2f W\n", effect);
	
	return 0;
}
