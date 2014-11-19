/*
 * 1.2
 * By: Hidde Hensel en Diederik Beker
 * http://en.wikipedia.org/wiki/Finite_difference
 * http://mathfaculty.fullerton.edu/mathews/n2003/differentiation/numericaldiffproof.pdf
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

double function(double x)
{
	return sin(x);
}

double rectangle(double (*functionPointer)(double y))
{
	
}

double trapezoidal(double (*functionPointer)(double y))
{
	
}

double simpson(double (*functionPointer)(double y))
{
	
}

double gauss(double (*functionPointer)(double y))
{
	
}

int main(int argc, char* argv[])
{
	int subinterval = 0;
	
  	//Declare function pointer
  	double (*functionPointer)(double);
  	functionPointer = &function;
  	
  	result = rectangle(*functionPointer);
  	printf("%.10e", result);
    
	return 0;
}