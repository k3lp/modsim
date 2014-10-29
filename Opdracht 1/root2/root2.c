#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

double function(double x)
{
	double result = (x*x) - 2;

	return result;
}

//http://nl.wikipedia.org/wiki/Regula_falsi
//pak 2 punten links en rechts van te berekenen punt
//kijk waar deze gaat snijden met de x - as
//pak dat snijpunt van x as en stop in formule
//vervang dat punt met of links of rechts en bereken de overgebleven
//doe dit n keer
double regulaFalsi(double x, double stapgrootte, double n)
{
	double result;
	double links = x - stapgrootte;
	double rechts = x + stapgrootte;
	double snijpunt = x;
	double functionLinks = function(links);
	double functionRechts = function(rechts);
	double functionX = function(x);



	//pak snijpunt met x-as tussen left en right
	for(int i = 0; i < n; i++)
	{
		functionLinks = function(links);

		functionRechts = function(rechts);


		snijpunt = links - ((links - rechts)/(functionLinks-functionRechts));
		snijpunt *= functionLinks;

		if((functionLinks * functionX) > 0)
		{
			links = snijpunt;
		}
		else if((functionRechts * functionX) > 0)
		{
			rechts = snijpunt;
		}
		printf("snijpunt = %.10e\n", snijpunt);
		
	}
	result = snijpunt;

	return result;
}

double newtonRaphson()
{
	double result = 0.0;

	return result;
}



int main(int argc, char* argv[])
{
	double stapgrootte = 5;
	double n = 5;
	double x = sqrt(2);
	double result = regulaFalsi(x, stapgrootte, n);

	return 0;
}
