#include <stdio.h>

#include "libpower.h"
#include "libresistance.h"

int main()
{
	float power_test_r, power_test_i; //, power_test_volt, power_test_resistance, power_test_expected;
	//printf("%s\n", "Enter volt: ");
	//scanf("%f, &power_test_volt);
	//printf("%s\n", "Enter resistance: ");
	//scanf("%f, &power_test_resistance);
	
	//power_test_r = calc_power_r(power_test_volt, power_test_resistance);
	//power_test_expected = volt*resistance;
	//printf("%s", "Expected result of 'calc_power_r' is ");
	//printf("%0.6f\n", power_test_expected);
	
	power_test_r = calc_power_r(20, 5); //Skall tas bort sen
	printf("%s\n", "Expected result of 'calc_power_r' is '100'"); //Skall tas bort sen
	printf("%s", "Result: ");
	printf("%0.6f\n", power_test_r);
	
	//power_test_expected = volt*resistance;
	//power_test_i = calc_power_r(power_test_volt, power_test_resistance);
	//power_test_expected = volt*volt/resistance;
	//printf("%s", "Expected result of 'calc_power_r' is ");
	//printf("%0.6f\n", power_test_expected);
	
	power_test_i = calc_power_r(20, 5); //Skall tas bort sen
	printf("%s\n", "Expected result of 'calc_power_i' is '80'"); //Skall tas bort sen
	printf("%s", "Result: ");
	printf("%0.6f\n\n", power_test_i);
	
	
	
	
	float resistance_test;
	float resistors[] = {30.0, 25.5, 70.0};
	resistance_test = calc_resistance(3, "S", &resistors);
	printf("%s\n", "Expected result of 'calc_resistance' using 'S' is '125.5'");
	
	float resistance_test;
	float resistors[] = {30.0, 25.5, 70.0};
	resistance_test = calc_resistance(3, "P", &resistors);
	printf("%s\n\n", "Expected result of 'calc_resistance' 'P' is '~11.5169'");
	
	return 0;
}
