/*
 *  1.3 + 1.4
 *  By: Hidde Hensel en Diederik Beker
 *
 */

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


//(x-1)(x+2)^2
double function4(double x)
{
	double result = pow(x,3) + (3 * pow(x,2)) - 4;
	return result;
}


double function4Derivative(double x)
{
	double result = 3 * (x*x) + 6*x;
	return result;
}


double function4Derivative2(double x)
{
	double result = 6*x + 6;
	return result;
}


//formule van http://nl.wikipedia.org/wiki/Regula_falsi
//pak 2 punten links en rechts van te berekenen punt
//kijk waar deze gaat snijden met de x - as
//pak dat snijpunt van x as en stop in formule
//vervang dat punt met of links of rechts en bereken de overgebleven
//doe dit n keer
void regulaFalsi(double (*functionPointer)(double y), double linksGet, double rechtsGet, double n, double errorGet, double trueValue)
{
	double result, functionLinks, functionRechts;
	double links = linksGet;
	double rechts = rechtsGet;
	double snijpunt = 0.0;
	double snijpuntprev = 0.0;
	double functionX = 0.0;
	double error = errorGet;
	double breakcheck;
	double calculatedError;
	printf("\nROOT R-F: \n");
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
			printf("totaal stappen = %d\n", i);
			break;
		}
		
		snijpuntprev = snijpunt;
		calculatedError = trueValue - snijpunt;
		printf("stap = %d, snijpunt = %e, error = %e\n", i, snijpunt, calculatedError);
	}
	result = snijpunt;
	printf("root = %.10e\n", result);
}



//formule van en.wikipedia.org/wiki/Newton%27s_method
//
void newtonRaphson(double (*functionPointer)(double y), double (*functionPointerDerivative)(double y2), double (*functionPointerDerivative2)(double y3), double linksGet, double n, double errorGet, int multiple_roots, double trueValue)
{
	double result = 0.0;
	double x0 = abs(linksGet), x1 = 0.0;
	double temp;
	double error = errorGet;
	double breakcheck;
	double calculatedError = 0;
	printf("\nROOT N-R 1: \n");
	for(int i = 0; i < n; i++)
	{
		//x1 = x0 - ( (f(x0) / f'(x0) )
		temp = functionPointer(x0) / functionPointerDerivative(x0);
		x1 = x0 - temp;
		calculatedError = trueValue - x1;
		printf("stap = %d, function(x) = %e, calculatedError = %e\n", i, x1,calculatedError);
		breakcheck = x1 - x0;
		if(breakcheck >= -error && breakcheck <= error)
		{
			printf("totaal stappen = %d\n", i);
			break;
		}

		x0 = x1;


	}
	result = x1;		
	printf("root 1 = %.10e\n", result);


	result = 0;
	x1 = 0;
	x0 = linksGet;
	//root 1 found, op zoek naar root nr 2
	if(multiple_roots != 0)
	{
		printf("\nROOT N-R 2: \n");
		for(int j = 0; j < n; j++)
		{
			//formule van https://www.youtube.com/watch?v=aMwpQfV0Vds
			//ookwel de Ralston-Rabinowitz methode
			//modified newton raphson is x0 - 
			//( (f(x0) * f'(x0)) / f'(x0)^2 - f(x0) * f''(x0))
			temp = ((functionPointer(x0) * functionPointerDerivative(x0)) / 
				( (functionPointerDerivative(x0)*functionPointerDerivative(x0))
				- (functionPointer(x0) *  functionPointerDerivative2(x0))));
			x1 = x0 - temp;
			calculatedError = -2 - x1;

			breakcheck = x1 - x0;
			if(breakcheck >= -error && breakcheck <= error)
			{
				printf("totaal stappen = %d\n", j);
				break;
			}
			printf("stap = %d, function(x) = %e, calculatedError = %e\n", j, x1,calculatedError);
			x0 = x1;
		}
		result = x1;		
		printf("root 2 = %.10e\n", result);
	}

}




int main(int argc, char* argv[])
{
	double n = 1000;
	double startRechts = 4;
	double startLinks = -3;
	double error = 0.00001;
	double startOpdracht4 = -200;

	double root2 = sqrt(2);

	double (*functionPointer)(double);
	functionPointer = &function;
	double (*functionPointerDerivative)(double);
	functionPointerDerivative = &functionDerivative;
	double (*functionPointerDerivative2)(double);
	functionPointerDerivative2 = &function4Derivative2;

	//opdracht3
	regulaFalsi(*functionPointer, startLinks, startRechts, n, error, root2);
	printf("klaar met regulaFalsi van function1 tussen %.1f en %.1f.\n\n",startLinks, startRechts);

	newtonRaphson(*functionPointer, *functionPointerDerivative, *functionPointerDerivative2, startLinks, n, error,0,root2);
	printf("klaar met newton van function1 met startwaarde %.1f.\n\n",startLinks);
	
	//opdracht4
	functionPointer = &function4;
	functionPointerDerivative = &function4Derivative;

	newtonRaphson(*functionPointer, *functionPointerDerivative, *functionPointerDerivative2, startOpdracht4, n, error,1,1);
	printf("klaar met newton van function2 met startwaarde %.1f.\n", startOpdracht4);

	return 0;
}
