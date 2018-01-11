#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<omp.h>
void sample_rand(const double a, const double b ,const int dim, double *x) {
	#pragma omp parallel for
	for(int i=0;i<dim;++i) {

		double tmp = ((double) rand())/((double) RAND_MAX);
		x[i] = (b-a)*tmp + a;
	}
}


int main(int argc, char** argv)
{
	
	double start_time = omp_get_wtime();
	long N = atol( argv[1] );
	srand(time(NULL)); // each MPI process gets a unique seed
	const int dim = 10;
	double x[dim]; // array of random numbers
	double V = 4.0, integral = 0.0, sum = 0.0, expo=0.0;
	int count=0;
	for(int i=N;i>1;i=i/4)
	{
		count++; // to get the number of intermediate integrals
	}
	double integrals[count]; // this array stores all intermediate integral values.
	for(int i=0;i<N;i++)
	{
		sample_rand(-1.,1.,dim,x);
		double f;
		for(int j=0;j<N;j++){
			f = pow(1-x[j],2)+100*pow(x[j+1]-pow(x[j],2),2);
			sum+=f;
		}
	//printf("%lf\n",sum);
	expo=exp(-sum);
	int k=1;
	for(int j=1;j<=i+1;j=pow(4,k))
	{
		
		if(i+1==j)
			integrals[k-1]=V*expo/N;
		k++;
        }   
	}
	for(int i=0;i<count;i++)
	{ 
		printf("%lf %e\n",pow(4,i+1),integrals[i]);	
	
	}
	integral = V*expo/N;
        double time = omp_get_wtime() - start_time;
        //printf("%lf\n",time);
        return 0;
}
