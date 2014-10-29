//http://en.wikipedia.org/wiki/Finite_difference
//http://mathfaculty.fullerton.edu/mathews/n2003/differentiation/numericaldiffproof.pdf

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

double function(double x)
{
	return sin(x);
}


//lim 0 -> oneindig
double rightHand(double (*functionPointer)(double y), double x, double h)
{
	double result; 

	//f(x+h) -f(x) / h (h is finite)
	result = (functionPointer(x+h) - functionPointer(x)) / h;

	return result;
}


//lim -oneindig -> + oneindig
double central(double (*functionPointer)(double y), double x, double h)
{
	double result;

	//deriv in x wil je weten
	//dx = h

	//(f(x + 0.5h) - f(x-0.5h))/2h
	//double sinResult = function(x);
	result = ((functionPointer(x + h) - functionPointer(x - h)) / (2*h));


	return result;
}

int main(int argc, char* argv[])
{
	//pi
	const double pi = 4.0 * atan(1.0);

	//parameter value x
	double x = 0.0;

	//increment h
	double h = 0.001;
  	// When setting h to 1 central still works, right hand does not.
  	// h = 0.0001 is too small for 10^12 pi.
  	// h must be between 0.1 and 0.001.


	double result = 0.0;
	//function to be differntiated
	//double (*functionPointer)(double);
	//functionPointer = &function;
	
	//Declare function pointer
	double (*functionPointer)(double);
	functionPointer = &function;
	
	//double result = rightHand(x, h);
	//printf("righthand = %.10e\n", result);

	//met pi/3
	x = pi / 3;
	result = central(*functionPointer, x, h);
	printf("central = %.10e\n", result);

	result = rightHand(*functionPointer, x, h);
	printf("righthand = %.10e\n", result);

	//met pi/3 + 100 pi
	x = (pi / 3) + (100 * pi);
	result = central(*functionPointer, x, h);
	printf("central = %.10e\n", result);

	result = rightHand(*functionPointer, x, h);
	printf("righthand = %.10e\n", result);

  //met pi/3 + 10^12pi
	x = (pi / 3) + (pow(10,12) * pi);
	result = central(*functionPointer, x, h);
	printf("central = %.10e\n", result);

	result = rightHand(*functionPointer, x, h);
	printf("righthand = %.10e\n", result);
	
	return 0;
}
