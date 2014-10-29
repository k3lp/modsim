//http://en.wikipedia.org/wiki/Newton's_method#Difficulty_in_calculating_derivative_of_a_function
//https://hal.archives-ouvertes.fr/file/index/docid/71899/filename/RR-4687.pdf

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

double function(double x)
{
	return (pow(x,3)+(3*pow(x,2))-4);
}

double newtonRaphson(double (*functionPointer)(double y), double x)
{
	double prevx;
	double nextx;
	
	for(int i = 0; i<=20; i++)
	{
		nextx = x - (functionPointer(x)/deriv(x));
		prevx = x;
	}
	
	return nextx;
}

int main(int argc, char* argv[])
{	
	double x = 1.0;
	
	double (*functionPointer) (double);
	functionPointer = &function;
	
	result = newtonRaphson(*functionPointer, x);
	
	printf("Result = %.10e\n", result);
	return 0;
}

derivative f'

xn+1 = xn - (f(xn)/f'(xn))