#include <stdio.h>

#include "lib/libpower.h"
#include "lib/libresistance.h"

int main()
{
	float resistance_test;
	int nbr_resistors, resistors_count;
	char type[]={0};
	
	printf("Enter number of resistors: ");
	scanf("%d", &nbr_resistors);
	resistors_count = nbr_resistors;
	
	float resistors[nbr_resistors];
	while(resistors_count > 0) {
		printf("Enter resistor: ");
		scanf("%f", &resistors[resistors_count-1]);
		resistors_count -= 1;
	}
	
	printf("Serial (S) or Paralel (P) ?: ");
	scanf("%s", &type);
	
	resistance_test = calc_resistance(nbr_resistors, type[0], &resistors);
	printf("%s\n", "Replacement resistor for given resistors results in: ");
	printf("%0.6f\n\n", resistance_test);
	
	float power_test_r, power_test_i, power_test_volt, power_test_resistance, power_test_expected;
	printf("Enter volt: ");
	scanf("%f", &power_test_volt);
	printf("Enter resistance: ");
	scanf("%f", &power_test_resistance);
	
	power_test_r = calc_power_r(power_test_volt, power_test_resistance);
	printf("Calc_power_r: %0.6f\n", power_test_r);
	
	power_test_i = calc_power_i(power_test_volt, power_test_resistance);
	printf("Calc_power_i: %0.6f\n", power_test_i);
	
	return 0;
}
