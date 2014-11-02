#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>




double function(double x)
{
	double result = (x*x) - 2;

	return result;
}




double functionDerivative(double x)
{
	double result = 2*x;

	return result;
}




//formule van http://nl.wikipedia.org/wiki/Regula_falsi
//pak 2 punten links en rechts van te berekenen punt
//kijk waar deze gaat snijden met de x - as
//pak dat snijpunt van x as en stop in formule
//vervang dat punt met of links of rechts en bereken de overgebleven
//doe dit n keer
double regulaFalsi(double (*functionPointer)(double y), double linksGet, double rechtsGet, double n, double errorGet)
{
	double result, functionLinks, functionRechts;
	double links = linksGet;
	double rechts = rechtsGet;
	double snijpunt = 0.0;
	double snijpuntprev = 0.0;
	double functionX = 0.0;
	double error = errorGet;
	double breakcheck;
	//pak snijpunt met x-as tussen left en right
	for(int i = 0; i < n; i++)
	{
		functionLinks = functionPointer(links);
		functionRechts = functionPointer(rechts);
		snijpunt = links - ((links - rechts)/(functionLinks-functionRechts)) * functionLinks;


		functionX = functionPointer(snijpunt);
		if((functionLinks * functionX) > 0)
		{
			links = snijpunt;
		}
		else if((functionRechts * functionX) > 0)
		{
			rechts = snijpunt;
		}
		breakcheck = snijpunt - snijpuntprev;
		if(breakcheck >= -error && breakcheck <= error)
		{
			break;
		}
		//printf("snijpunt = %.10e\n", snijpunt);
		snijpuntprev = snijpunt;
	}
	result = snijpunt;
	printf("wortel2 = %.10e\n", result);
	return result;
}



//formule van en.wikipedia.org/wiki/Newton%27s_method
//
double newtonRaphson(double (*functionPointer)(double y), double (*functionPointerDerivative)(double y2), double linksGet, double n, double errorGet)
{
	double result = 0.0;
	double x0 = linksGet, x1 = 0.0;
	double temp;


	for(int i = 0; i < n; i++)
	{
		//x1 = x0 - ( (f(x0) / f'(x0) )
		temp = functionPointer(x0) / functionPointerDerivative(x0);
		x1 = x0 - temp;
		x0 = x1;
	}
	result = x1;		
	printf("wortel2 = %.10e\n", result);
	return result;
}




int main(int argc, char* argv[])
{
	double n = 100;
	double startRechts = 5;
	double startLinks = 1;
	double error = 0.000001;
	double (*functionPointer)(double);
	functionPointer = &function;
	double (*functionPointerDerivative)(double);
	functionPointerDerivative = &functionDerivative;


	double result = regulaFalsi(*functionPointer, startLinks, startRechts, n, error);
	printf("klaar met regulaFalsi\n");

	result = newtonRaphson(*functionPointer, *functionPointerDerivative, startLinks, n, error);
	printf("klaar met newton\n");
	return 0;
}
