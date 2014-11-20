/*
 * 2.1
 * By: Hidde Hensel en Diederik Beker
 * http://stackoverflow.com/questions/8344404/rectangle-method-c
 * http://stackoverflow.com/questions/21146540/trapezoidal-rule-in-python
 * http://en.wikipedia.org/wiki/Simpson%27s_rule
 * https://www.youtube.com/watch?v=i1DAfQYsCuo
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

double function(double x)
{
	return pow(x,2);
}

double rectangle(double (*functionPointer)(double), double from, double to, int subinterval)
{
	double result = 0, interval;
	
	interval = (to - from) / subinterval;

	for(double i = 0.5; i < subinterval; i++)
	{
		result += functionPointer(from + interval * i);
	}
	
	result *= interval;
	
	return result;
}

double trapezoidal(double (*functionPointer)(double), double from, double to, int subinterval)
{
	double result = 0, interval;
	
	interval = (to - from) / subinterval;
	
	result += functionPointer(from) / 2.0;
	
	for(int i = 1; i < subinterval; i++)
	{
		result += functionPointer(from + interval * i);
	}
	
	result += functionPointer(to) / 2.0;
	
	result *= interval;
	
	return result;
}

double simpson(double (*functionPointer)(double), double from, double to, int subinterval)
{
	double result = 0, interval;
	
	interval = (to - from) / subinterval;
	
	result = functionPointer(from) + functionPointer(to);
	
	for(int i = 1; i < subinterval; i += 2)
	{
		result += 4 * functionPointer(from + interval * i);
	}
	
	for(int i = 2; i < subinterval - 1; i += 2)
	{
		result += 2 * functionPointer(from + interval * i);
	}
	
	result = result * interval / 3;
	
	return result;
}

double gauss(double (*functionPointer)(double), double from, double to, int subinterval)
{
	double result = 0, interval, x1, x2;
	
	interval = (to - from) / 2;
	
	x1 = ((to + from) / 2) + (-1 / sqrt(3)) * interval;
	x2 = ((to + from) / 2) + (1 / sqrt(3)) * interval;
	
	result = (interval * functionPointer(x1)) + (interval * functionPointer(x2));
	
	return result;
}

int main(int argc, char* argv[])
{
	int subinterval;
	double from, to, result;
	
	printf("Enter a subinterval: ");
	scanf("%d", &subinterval);
	
	printf("Enter a bottom limit: ");
	scanf("%lf", &from);
	
	printf("Enter a top limit: ");
	scanf("%lf", &to);
	
  	//Declare function pointer
  	double (*functionPointer)(double);
  	functionPointer = &function;
  	
  	result = rectangle(*functionPointer, from, to, subinterval);
  	printf("Rectangle rule gives: %e\n", result);
	
	result = trapezoidal(*functionPointer, from, to, subinterval);
  	printf("Trapezoidal rule gives: %e\n", result);
    
	result = simpson(*functionPointer, from, to, subinterval);
  	printf("Simpson gives: %e\n", result);
	
	result = gauss(*functionPointer, from, to, subinterval);
  	printf("Guass gives: %e\n", result);
	
	return 0;
}