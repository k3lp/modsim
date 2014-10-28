#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

double function(double x)
{
 return sin(x);
}

 

//lim 0 -> oneindig
double rightHand(double x, double h)
{
	double result; 

	//f(x+h) -f(x) / h (h is finite)
	result = (function(x+h) - function(x)) / h;

	return result;
}


//lim -oneindig -> + oneindig
double central(double x, double h)
{
	double result;
	//deriv in x wil je weten
	//dx = h

	//(f(x + 0.5h) - f(x-0.5h))/2h
	//double sinResult = function(x);
	result = (function(x + h) - function(x - h)) / (2*h);


	return result;
}

int main(int argc, char* argv[])
{
	//pi
	const double pi = 4.0 * atan(1.0);

	//parameter value x
	double x = 0.0;

	//increment h
	double h = 0.1;

	double result = 0.0;
	//function to be differntiated
	//double (*functionPointer)(double);
	//functionPointer = &function;

	//double result = rightHand(x, h);
	//printf("righthand = %.10e\n", result);

	//met pi/3
	x = pi / 3;
	result = central(x, h);
	printf("central = %.10e\n", result);

	result = rightHand(x, h);
	printf("righthand = %.10e\n", result);

	//met pi/3 + 100 pi
	x = (pi / 3) + 100 * pi;
	result = central(x, h);
	printf("central = %.10e\n", result);

	result = rightHand(x, h);
	printf("righthand = %.10e\n", result);



	return 0;
}
