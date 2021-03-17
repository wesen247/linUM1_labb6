#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#include "libpower.h"

float calc_power_r(float volt, float resistance)
{
	if (volt && resistance)
	{
		return volt*volt/resistance;
	}
	else if (!volt)
	{
		printf("Volt can't be null, try again.");
		return 0;
	}
	else if (!resistance)
	{
		printf("Resistance can't be null, try again.");
		return 0;
	}
	else
	{
		printf("Something went wrong, try again.");
		return 0;
	}
}

float calc_power_i(float volt, float current)
{
	if (volt && current)
	{
		return volt*current;
	}
	else if (!volt)
	{
		printf("Volt can't be null, try again.");
		return 0;
	}
	else if (!current)
	{
		printf("Resistance can't be null, try again.");
		return 0;
	}
	else
	{
		printf("Something went wrong, try again.");
		return 0;
	}
}


