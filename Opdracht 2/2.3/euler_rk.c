/*
 * 2.3
 * By: Hidde Hensel en Diederik Beker
 *
 * en.wikipedia.org/wiki/Runge-Kutta_methods
 * http://mathworld.wolfram.com/Runge-KuttaMethod.html
 * http://en.wikipedia.org/wiki/Euler_method
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
int Euler(double t0, double t1, double dt, double * y0, double * y1, int N, int f(double, double *, double *, void *), void * params);

int RungeKutta2(double t0, double t1, double dt, double * y0, double * y1, int N, int f(double, double *, double *, void *), void * params);

int RungeKutta2(double t0, double t1, double dt, double * y0, double * y1, int N, int f(double, double *, double *, void *), void * params);

/*	t0		the start value of t0 of t (input)
	t1		the final value of t (input)
	dt 		the increment in t (input)
	y0[N]	the values of the functions y_n(t) at t0 (input)
	y1[N]	the values of the functions y_n(t) at t1 (output)
	N		the dimension of y
	int f(double t, double * y, double * dy, void params)
			computes the vector of derivatives dy[N] of y[N], given t,
			y[N] and params
	void * params
			a pointer to a struct containing any parameters needed by f (input)
			All three functions return an estimate of y(t1) in y1.
			All functions, return 0 upon succes, or -1 when a computational error occurs (overflow, NaN or such)

*/


int Euler(double t0, double t1, double dt, double * y0, double * y1, int N, int f(double, double *, double *, void *), void * params)
{
	double Nsteps;
	double t = t0;
	//init y0 + y1

	for(int i = 0; i < N; i++)
	{
		//calculate dt
		Nsteps = ceil((t1-t0)/dt);
		dt = (t1-t0) / Nsteps;

		for(int j = 0; j < Nsteps; j++)
		{ 
			//calculate f() at t
			f(t,y0, y1, params);

			//printf("y0 = %f, y1 = %f\n\n",y0[i],y1[i]); 
			//ynext = yprev + dt * f()
			y0[i] = y0[i] + dt * y1[i];

			//calculate new t
			t = t0 + j * dt;

			//y1 = y2
			y1[i] = y0[i];
			//printf("test: %f\n",y1[i]);
		}
	}
	return 0;
}


int RungeKutta2(double t0, double t1, double dt, double * y0, double * y1, int N, int f(double, double *, double *, void *), void * params)
{
	double k1, k2, Nsteps;
	double t = t0;
	double temp;

	for(int i = 0; i < N; i++)
	{
		//calculate dt
		Nsteps = ceil((t1-t0)/dt);
		dt = (t1-t0) / Nsteps;

		for(int j = 0; j < Nsteps; j++)
		{ 
			//keep yn in temp for ynext calculation
			temp = y1[i];

			//calculat ks
			//calculate f() at t
			f(t, y0, y1, params);

			//k1 = dt * f()
			k1 = dt * y1[i];

			//calculate f(+dt/2, +k1/2)
			y0[i] = y1[i]+ (k1/2)*dt;
			f(t + (dt/2),y0, y1, params);
			//a = 0.5
			//k2 = dt * f(+a*dt, +a*k1)
			k2 = dt * y1[i];

			//y1 = y1 + 0.5(k1+k2)
			y1[i] = temp + (k1+k2)/2;

			//calculate new t
			t = t0 + j * dt;


			//y1[i] = y0[i];
			//printf("test: %f\n",y1[i]);
		}
	}

	return 0;
}


int RungeKutta4(double t0, double t1, double dt, double * y0, double * y1, int N, int f(double, double *, double *, void *), void * params)
{
	double k1, k2 ,k3 ,k4 , Nsteps;
	//calculate ks
	double t = t0;
	double temp;

	for(int i = 0; i < N; i++)
	{
		//calculate dt
		Nsteps = ceil((t1-t0)/dt);
		dt = (t1-t0) / Nsteps;

		for(int j = 0; j < Nsteps; j++)
		{ 
			//keep yn in temp for ynext calculation
			temp = y1[i];

			//calculat ks
			//calculate f() at t
			f(t, y0, y1, params);

			//k1 = dt * f()
			k1 = dt * y1[i];

			//a = 0.5
			//calculate f(+a*dt, +a*k1*dt)
			y0[i] = y1[i]+(k1/2)*dt;
			f(t + (dt/2),y0, y1, params);

			//k2 = dt * f()
			k2 = dt * y1[i];


			y0[i] = y1[i]+(k2/2)*dt;
			f(t + (dt/2),y0, y1, params);
			//k3 = dt * f()
			k3 = dt * y1[i];

			y0[i] = y1[i] + k3*dt;
			f(t + dt,y0, y1, params);
			//k4 = dt * f()
			k4 = dt * y1[i];

			//labda = 2
			//yn+1 = yn + (k1 + (4-l) * k2 + l* k3 + k4 ) / 6
			y1[i] = temp +  (k1 + 2*k2 + 2*k3 + k4)/6;

			//calculate new t
			t = t0 + j * dt;


			//y1[i] = y0[i];
			//printf("test: %f\n",y1[i]);


		}
	}

	return 0;
}

int testFunction(double t, double *y, double *y1, void *params)
{
	y1[0] = y1[0] * y1[0];
	return 0;
}


int main(int argc, char* argv[])
{
	double t0 = -1.0;
	double t1 = 1.0;
	double dt = 0.1;
	int N = 1;
	double y0[N];
	double y1[N];
	void * params;


	y0[0] = 1.0; 
	y1[0] = 0.0;
	Euler(t0,t1,dt,y0,y1,N,&testFunction,&params);
	printf("testEuler: %f\n",y1[0]);

	y0[0] = 1.0; 
	y1[0] = 0.0;
	RungeKutta2(t0,t1,dt,y0,y1,N,&testFunction,&params);
	printf("testRK2: %f\n",y1[0]);

	y0[0] = 1.0; 
	y1[0] = 0.0;
	RungeKutta4(t0,t1,dt,y0,y1,N,&testFunction,&params);
	printf("testRK4: %f\n",y1[0]);
}



