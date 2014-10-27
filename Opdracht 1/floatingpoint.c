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
  printf("The machine's precision of float = %.10e\n", FLT_EPSILON);

	//range of valid numbers
  float tomax = 1;
  float prevtomax;
  
  while(!isinf(tomax)) {
    prevtomax = tomax;
    tomax *= 1.00001;
  }
  
  float tomin = 1;
  float prevtomin;
  
  prevtomin = FLT_MIN/20;
  
  /*while(!isinf(tomin)) {
    prevtomin = tomin;
    tomin /= 1.1;
  }    */
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

int main(int argc, char* argv[])
{
	floatRepresentation();
	doubleRepresentation();
	longRepresentation();

	return 0;
}
