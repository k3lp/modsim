/*
 *  1.1
 *  By: Hidde Hensel en Diederik Beker
 *
 */


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
	printf("The machine's precision of double = %.10Le\n", LDBL_EPSILON);

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

  f = 1.0;
  f = f/0.0;
  printf("(INF) float / 0 = %.10e\n", f);
  printf("(INF) float / 0 * 2 bit pattern = %.10X\n", (int)f);
  
  f = 0.0;
  f = log(f);
  printf("(INF) log(0.0) = %.10e\n", f);
  printf("(INF) log(0.0) * 2 bit pattern = %.10X\n", (int)f);

	//NAN
	f /= f;
	printf("(NAN) float max * 2 / float max * 2 = %.10e\n", f);
	printf("(NAN) float max * 2 / float max * 2 bit pattern = %.10X\n", (int)f);
  
  f = 0.0;
  f = f / 0.0;
  printf("(NAN) float divide by 0 = %.10e\n", f);
  printf("(NAN) float divide by 0 * 2 bit pattern = %.10X\n", (int)f);

  f = -2.0;
  f = sqrt(f);
  printf("(NAN) squareroot of negative float = %.10e\n", f);
  printf("(NAN) squareroot of negative float * 2 bit pattern = %.10X\n", (int)f); 

	//UNDERFLOWS
	f = FLT_MIN / (9999999999);
	printf("(Underflow) float min / large number = %.10e\n", f);
	printf("(Underflow) bit pattern = %.10X\n", (int)f);
  
  f = -0.0;
  f = sqrt(f);
  printf("(Underflow) sqrt(-0.0) = %.10e\n", f);
  printf("(Underflow) sqrt(-0.0) * 2 bit pattern = %.10X\n", (int)f);
  
  f = 1.0;
  f = f/0.0; //= infinity (see above)
  f = -0.0/f;
  printf("(Underflow) -0.0/infinity = %.10e\n", f);
  printf("(Underflow) -0.0/infinity * 2 bit pattern = %.10X\n", (int)f);

  printf("-----------------------------\n");

	//double
	//INF
	double d = FLT_MAX * 2;
	printf("(INF) double max * 2 = %.10e\n", d);
	printf("(INF) double max * 2 bit pattern = %.10X\n", (int)d);
  
  d = 1.0;
  d = d/0.0;
  printf("(INF) double / 0 = %.10e\n", d);
  printf("(INF) double / 0 * 2 bit pattern = %.10X\n", (int)d);
  
  d = 0.0;
  d = log(d);
  printf("(INF) log(0.0) = %.10e\n", d);
  printf("(INF) log(0.0) * 2 bit pattern = %.10X\n", (int)d);

	//NAN
	d /= d;
	printf("(NAN) double max * 2 / double max * 2 = %.10e\n", d);
	printf("(NAN) double max * 2 / double max * 2 bit pattern = %.10X\n", (int)d);
  
  d = 0.0;
  d = d / 0.0;
  printf("(NAN) double divide by 0 = %.10e\n", d);
  printf("(NAN) double divide by 0 * 2 bit pattern = %.10X\n", (int)d);

  d = -2.0;
  d = sqrt(d);
  printf("(NAN) squareroot of negative double = %.10e\n", d);
  printf("(NAN) squareroot of negative double * 2 bit pattern = %.10X\n", (int)d);

	//UNDERFLOWS
	d = FLT_MIN / (9999999999);
	printf("(Underflow) double min / large number = %.10e\n", d);
	printf("(Underflow) bit pattern = %.10X\n", (int)d);
  
  d = -0.0;
  d = sqrt(d);
  printf("(Underflow) sqrt(-0.0) = %.10e\n", d);
  printf("(Underflow) sqrt(-0.0) * 2 bit pattern = %.10X\n", (int)d);
  
  d = 1.0;
  d = d/0.0; //= infinity (see above)
  d = -0.0/d;
  printf("(Underflow) -0.0/infinity = %.10e\n", d);
  printf("(Underflow) -0.0/infinity * 2 bit pattern = %.10X\n", (int)d);
  
  printf("-----------------------------\n");

	//long double
	//INF
	long double ld = FLT_MAX * 2;
	printf("(INF) long double max * 2 = %.10Le\n", ld);
	printf("(INF) long double max * 2 bit pattern = %.10X\n", (int)ld);
  
  ld = 1.0;
  ld = ld/0.0;
  printf("(INF) long double / 0 = %.10Le\n", ld);
  printf("(INF) long double / 0 * 2 bit pattern = %.10X\n", (int)ld);
  
  ld = 0.0;
  ld = log(ld);
  printf("(INF) log(0.0) = %.10Le\n", ld);
  printf("(INF) log(0.0) * 2 bit pattern = %.10X\n", (int)ld);  

	//NAN
	ld /= ld;
	printf("(NAN) long double max * 2 / long double max * 2 = %.10Le\n", ld);
	printf("(NAN) long double max * 2 / long double max * 2 bit pattern = %.10X\n", (int)ld);
  
  ld = 0.0;
  ld = ld / 0.0;
  printf("(NAN) long double divide by 0 = %.10Le\n", ld);
  printf("(NAN) long double divide by 0 * 2 bit pattern = %.10X\n", (int)ld);

  ld = -2.0;
  ld = sqrt(ld);
  printf("(NAN) squareroot of negative long double = %.10Le\n", ld);
  printf("(NAN) squareroot of negative long double * 2 bit pattern = %.10X\n", (int)ld);
  
	//UNDERFLOWS
	ld = FLT_MIN / (9999999999);
	printf("(Underflow) long double min / large number = %.10Le\n", ld);
	printf("(Underflow) bit pattern = %.10X\n", (int)ld);
  
  ld = -0.0;
  ld = sqrt(ld);
  printf("(Underflow) sqrt(-0.0) = %.10Le\n", ld);
  printf("(Underflow) sqrt(-0.0) * 2 bit pattern = %.10X\n", (int)ld);
  
  ld = 1.0;
  ld = ld/0.0; //= infinity (see above)
  ld = -0.0/ld;
  printf("(Underflow) -0.0/infinity = %.10Le\n", ld);
  printf("(Underflow) -0.0/infinity * 2 bit pattern = %.10X\n", (int)ld);

}


int main(int argc, char* argv[])
{

	floatRepresentation();
	doubleRepresentation();
	longRepresentation();
	invalidOperations();

	return 0;
}
