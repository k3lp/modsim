#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <float.h>
#include <math.h>

void floatRepresentation()
{
	printf("Floats:\n");
  
	float f;
	//size in bytes
	printf("The machine's float size in bytes = %lu\n",sizeof(f));
	
	//machine precision  
    	float epsilon = 1.0;
	float prevepsilon = 0.0;

	while((float)(1.0+(epsilon/2)) != 1.0)
	{
		prevepsilon = epsilon;
		epsilon /= 2;
	}

	printf("The machine's calculated precision of float = %.10e\n", prevepsilon);
	printf("The machine's precision of float = %.10e\n", FLT_EPSILON);

	//range of valid numbers
	float tomax = 1;
	float prevtomax;
  
	while(!isinf(tomax))
	{
		prevtomax = tomax;
		tomax *= 1.0001;
	}
  
	float tomin = 1;
	float prevtomin = 0;
    float temp = 0;

	while(tomin != 0)
	{
		prevtomin = tomin;
		tomin /= 2;
	}

	printf("The machine's maximum value of float = %.10e\n", FLT_MAX);
	printf("The machine's minimum value of float = %.10e\n", FLT_MIN);
	printf("The machine's calculated maximum value of float = %.10e\n", prevtomax); 
	printf("The machine's calculated maximum value of float = %.10e\n", prevtomin);
} 





void doubleRepresentation()
{
	printf("\nDouble:\n");
  
	double d;
	//size in bytes
	printf("The machine's double size in bytes = %lu\n",sizeof(d));
	
	//machine precision  
	printf("The machine's precision of double = %.10e\n", DBL_EPSILON);

	//range of valid numbers
	printf("The machine's maximum value of double = %.10e\n", DBL_MAX);
	printf("The machine's minimum value of double = %.10e\n", DBL_MIN);
}





void longRepresentation()
{
	printf("\nLong double:\n");
  
	long double l;
	//size in bytes
	printf("The machine's long double size in bytes = %lu\n",sizeof(l));
	
	//machine precision  
	printf("The machine's precision of long double = %.10Le\n", LDBL_EPSILON);

	//range of valid numbers
	printf("The machine's maximum value of long double = %.10Le\n", LDBL_MAX);
	printf("The machine's minimum value of long double = %.10Le\n", LDBL_MIN);
}


void invalidOperations()
{
	printf("\nInvalid Operations:\n");

	//float

	//INF
	float f = FLT_MAX * 2;
	printf("(INF) float max * 2 = %.10e\n", f);
	printf("(INF) float max * 2 bit pattern = %.10X\n", (int)f);

	//NAN
	f /= f;
	printf("(NAN) float max * 2 / float max * 2 = %.10e\n", f);
	printf("(NAN) float max * 2 / float max * 2 bit pattern = %.10X\n", (int)f);

	//UNDERFLOWS
	f = FLT_MIN / (9999999999);
	printf("(Underflow) = %.10e\n", f);
	printf("(Underflow) bit pattern = %.10X\n", (int)f);



	//double
	//long double

}


int main(int argc, char* argv[])
{

	floatRepresentation();
	doubleRepresentation();
	longRepresentation();
	invalidOperations();

	return 0;
}
