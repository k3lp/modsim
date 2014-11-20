/*
 * 2.2
 * By: Hidde Hensel en Diederik Beker
 * https://www.gnu.org/software/gsl/manual/html_node/Numerical-integration-examples.html
 */

#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

double f (double x, void * params) {
	double f = pow(x,2);
	return f;
}

int
main (void)
{
	gsl_integration_workspace * w 
	= gsl_integration_workspace_alloc (1000);
	
	double from, to;

	printf("Enter a bottom limit: ");
	scanf("%lf", &from);

	printf("Enter a top limit: ");
	scanf("%lf", &to);

	double result, error;

	gsl_function F;
	F.function = &f;

	gsl_integration_qags (&F, from, to, 0, 1e-7, 1000,
	                    w, &result, &error); 

	printf ("result = %.18f\n", result);
	printf ("intervals = %zd\n", w->size);

	gsl_integration_workspace_free (w);

	return 0;
}