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




double function4(double x)
{
	return (pow(x,3) + (3 * pow(x,2)) -4);
}




double function4Derivative(double x)
{
	return (3 * (x*x) + 6*x);
}

double function4Derivative2(double x)
{
	return (6*x + 6);
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
			printf("stap = %d\n", i);
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
double newtonRaphson(double (*functionPointer)(double y), double (*functionPointerDerivative)(double y2), double linksGet, double n, double errorGet, int multiple_roots)
{
	double result = 0.0;
	double x0 = abs(linksGet), x1 = 0.0;
	double temp;
	double error = errorGet;
	double breakcheck;


	for(int i = 0; i < n; i++)
	{
		//x1 = x0 - ( (f(x0) / f'(x0) )
		temp = functionPointer(x0) / functionPointerDerivative(x0);
		x1 = x0 - temp;

		breakcheck = x1 - x0;
		if(breakcheck >= -error && breakcheck <= error)
		{
			printf("stap = %d\n", i);
			break;
		}

		x0 = x1;


	}
	result = x1;		
	printf("result = %.10e\n", result);




	x0 = abs(linksGet);
	//root 1 found, op zoek naar root nr 2
	if(multiple_roots != 0)
	{
		for(int j = 0; j < n; j++)
		{
			//x1 = x0 - ( (f(x0) / f'(x0) )


		//modified newton raphson is x0 - 
		//( (f(x0) * f'(x0)) / f'(x0)^2 - f(x0) * f''(x0))
			temp = ((functionPointer(x0) * functionPointerDerivative(x0)) / ( (functionPointerDerivative(x0)*functionPointerDerivative(x0))
					- (functionPointer(x0) *  function4Derivative2(x0))));
			x1 = x0 - temp;

			breakcheck = x1 - x0;
			if(breakcheck >= -error && breakcheck <= error)
			{
				printf("stap2 = %d\n", j);
				break;
			}
			x0 = x1;
		}
		result = x1;		
		printf("result = %.10e\n", result);
	}


	return result;
}




int main(int argc, char* argv[])
{
	double n = 1000;
	double startRechts = 50;
	double startLinks = -20;
	double error = 0.00001;
	double (*functionPointer)(double);
	functionPointer = &function;
	double (*functionPointerDerivative)(double);
	functionPointerDerivative = &functionDerivative;


	double result = regulaFalsi(*functionPointer, startLinks, startRechts, n, error);
	printf("klaar met regulaFalsi\n");

	result = newtonRaphson(*functionPointer, *functionPointerDerivative, startLinks, n, error,0);
	printf("klaar met newton\n");
	
	
	
	
	functionPointer = &function4;
	functionPointerDerivative = &function4Derivative;
	
	//result = regulaFalsi(*functionPointer, startLinks, startRechts, n, error);
	//printf("klaar met regulaFalsi\n");
	startLinks = 10;
	error = 0.00001;
	result = newtonRaphson(*functionPointer, *functionPointerDerivative, startLinks, n, error,1);
	printf("klaar met newton\n");
	return 0;
}
