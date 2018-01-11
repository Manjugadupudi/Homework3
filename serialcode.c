#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void sample_rand(const double a, const double b ,const int dim, double *x) {

	for(int i=0;i<dim;++i) {

		double tmp = ((double) rand())/((double) RAND_MAX);
		x[i] = (b-a)*tmp + a;
	}
}


int main(int argc, char** argv)
{
	long N = atol( argv[1] );
	srand(time(NULL)); 
	const int dim = 10;
	double x[dim]; 
	double V = 4.0, integral = 0.0, sum = 0.0;
	int count=0;
	for(int i=N;i>1;i=i/4)
	{
		count++; 
	}
	double integrals[count]; 
	for(int i=0;i<N;i++)
	{
		sample_rand(-1.,1.,dim,x);
		double f;
		if(pow(x[0],2)+pow(x[1],2)+pow(x[2],2)+pow(x[3],2)+pow(x[4],2)+pow(x[5],2)+pow(x[6],2)+pow(x[7],2)+pow(x[8],2)+pow(x[9],2)<=1)
			f=1.0;
		else
			f=0.0;
		sum+=f;
	int k=1;
	for(int j=1;j<=i+1;j=pow(4,k))
	{
		
		if(i+1==j)
			//printf("For iteration %d integral is %lf\n", j,V*sum/N);
			integrals[k-1]=V*sum/N;
		k++;
		
			
	}
	}
	for(int i=0;i<count;i++)
	{ 
		printf("%lf %e %e\n",pow(4,i+1), fabs(integrals[i]-0.0), fabs(integrals[i]-integrals[i+1]));	
	
	}
	integral = V*sum/N;
	//uncomment printf to get integral value
	//printf("final integral is:%e\n",integral);
	return 0;
}

