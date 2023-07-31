#include <stdio.h>
#include "my_math_converter.h"

double fahrenheitToCelsiusConverter(double fahrenheit) {
    double celsius;
    celsius = (fahrenheit - 32) * 5 / 9;
    printf("%.2lf°F is equal to %.2lf°C\n", fahrenheit, celsius);
    return 0;
}

