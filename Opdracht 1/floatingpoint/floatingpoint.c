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
	
	//machine precision or epsilon 
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
	float prevtomaxspeedup;
  	//compute max size
	//compute first with 1.1 (large number)
	//then with 1.0001 (smaller number) for speedup
	while(!isinf(tomax))
	{
		prevtomax = tomax;
		tomax *= 1.1;
	}
	//compute max size with speedup
  	while(!isinf(prevtomax))
	{
		prevtomaxspeedup = prevtomax;
		prevtomax *= 1.0001;

	}



	float tomin = 1;
	float prevtomin = 0;
	float temp = 0;

	//compute min size
	while(tomin != 0)
	{
		prevtomin = tomin;
		tomin /= 2;
	}


	printf("The machine's maximum value of float = %.10e\n", FLT_MAX);
	printf("The machine's minimum value of float = %.10e\n", FLT_MIN);
	printf("The machine's calculated maximum value of float = %.10e\n", prevtomaxspeedup); 
	printf("The machine's calculated minimum value of float = %.10e\n", prevtomin);
} 





void doubleRepresentation()
{
	printf("\nDouble:\n");
  
	double d;
	//size in bytes
	printf("The machine's double size in bytes = %lu\n",sizeof(d));
		
	//machine precision or epsilon 
    double epsilon = 1.0;
	double prevepsilon = 0.0;

	while((double)(1.0+(epsilon/2)) != 1.0)
	{
		prevepsilon = epsilon;
		epsilon /= 2;
	}

	printf("The machine's calculated precision of double = %.10e\n", prevepsilon);
	printf("The machine's precision of double = %.10e\n", DBL_EPSILON);

	//range of valid numbers
	double tomax = 1;
	double prevtomax;
	double prevtomaxspeedup;
  	//compute max size
	//compute first with 1.1 (large number)
	//then with 1.0001 (smaller number) for speedup
	while(!isinf(tomax))
	{
		prevtomax = tomax;
		tomax *= 1.1;
	}
	//compute max size with speedup
  	while(!isinf(prevtomax))
	{
		prevtomaxspeedup = prevtomax;
		prevtomax *= 1.0001;

	}



	double tomin = 1;
	double prevtomin = 0;
	double temp = 0;

	//compute min size
	while(tomin != 0)
	{
		prevtomin = tomin;
		tomin /= 2;
	}


	printf("The machine's maximum value of double = %.10e\n", DBL_MAX);
	printf("The machine's minimum value of double = %.10e\n", DBL_MIN);
	printf("The machine's calculated maximum value of double = %.10e\n", prevtomaxspeedup); 
	printf("The machine's calculated minimum value of double = %.10e\n", prevtomin);

}





void longRepresentation()
{
	printf("\nLong double:\n");
  
	long double l;
	//size in bytes
	printf("The machine's long double size in bytes = %lu\n",sizeof(l));
	
	//machine precision or epsilon 
    long double epsilon = 1.0;
	long double prevepsilon = 0.0;

	while((long double)(1.0+(epsilon/2)) != 1.0)
	{
		prevepsilon = epsilon;
		epsilon /= 2;
	}

	printf("The machine's calculated precision of double = %.10Le\n", prevepsilon);
	printf("The machine's precision of double = %.10e\n", LDBL_EPSILON);

	//range of valid numbers
	long double tomax = 1;
	long double prevtomax;
	long double prevtomaxspeedup;
  	//compute max size
	//compute first with 1.1 (large number)
	//then with 1.0001 (smaller number) for speedup
	while(!isinf(tomax))
	{
		prevtomax = tomax;
		tomax *= 1.1;
	}
	//compute max size with speedup
  	while(!isinf(prevtomax))
	{
		prevtomaxspeedup = prevtomax;
		prevtomax *= 1.0001;

	}



	long double tomin = 1;
	long double prevtomin = 0;
	long double temp = 0;

	//compute min size
	while(tomin != 0)
	{
		prevtomin = tomin;
		tomin /= 2;
	}


	printf("The machine's maximum value of double = %.10Le\n", LDBL_MAX);
	printf("The machine's minimum value of double = %.10Le\n", LDBL_MIN);
	printf("The machine's calculated maximum value of double = %.10Le\n", prevtomaxspeedup); 
	printf("The machine's calculated minimum value of double = %.10Le\n", prevtomin);

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

	//INF
	double d = FLT_MAX * 2;
	printf("(INF) double max * 2 = %.10e\n", d);
	printf("(INF) double max * 2 bit pattern = %.10X\n", (int)d);

	//NAN
	d /= d;
	printf("(NAN) double max * 2 / double max * 2 = %.10e\n", d);
	printf("(NAN) double max * 2 / double max * 2 bit pattern = %.10X\n", (int)d);

	//UNDERFLOWS
	d = FLT_MIN / (9999999999);
	printf("(Underflow) = %.10e\n", d);
	printf("(Underflow) bit pattern = %.10X\n", (int)d);



	//long double

	//INF
	long double ld = FLT_MAX * 2;
	printf("(INF) long double max * 2 = %.10Le\n", ld);
	printf("(INF) long double max * 2 bit pattern = %.10X\n", (int)ld);

	//NAN
	ld /= ld;
	printf("(NAN) long double max * 2 / long double max * 2 = %.10Le\n", ld);
	printf("(NAN) long double max * 2 / long double max * 2 bit pattern = %.10X\n", (int)ld);

	//UNDERFLOWS
	ld = FLT_MIN / (9999999999);
	printf("(Underflow) = %.10Le\n", ld);
	printf("(Underflow) bit pattern = %.10X\n", (int)ld);

}


int main(int argc, char* argv[])
{

	floatRepresentation();
	doubleRepresentation();
	longRepresentation();
	invalidOperations();

	return 0;
}
