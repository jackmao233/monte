#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()
{
	FILE *fp;
	fp = fopen("1.txt","w");
	srand48(time(NULL));	
	void flip(int **s, int i, int j, int n , double a2, double a4, double p);
	double mag(int**,int);
	int **s;
	int n, m;
	double t;
	double ave;
	printf("Enter N, and monte time :\n");
	scanf("%d %d",&n, &m);
	s = (int**)malloc(n*sizeof(int*));
	for (int i= 0;i < n; i++)
	{
		s[i] = (int*)malloc(n*sizeof(int));
	}
	
	for (t= 1.2; t<2.6;t=t+0.1)
	{
	double a2 = exp(-4/t);
	double a4 = exp(-8/t);
	for (int i = 0; i < n; i++)
	{	
		for (int j=0; j <n; j++)
		{
			if (drand48() < 0.5)
			{s[i][j]=-1;}
			else
			{s[i][j]=1;}	
		} 

	}
	
	ave = 0;
	for (int c = 0; c< m; c++)
	{
	for (int i = 0; i< n*n; i++)
	flip(s, drand48()*n, drand48()*n, n, a2, a4, drand48());
	if (c>8000)
	{ave += mag(s,n);}}
	printf("%e\n",t);
	fprintf(fp,"%e %e\n", t, fabs(ave)/(m-8000)); 
	}
	fclose(fp);
}


double mag(int **s, int n)
{
	double x=0;
	for (int i=0; i < n; i++)
	{
		for (int j =0; j < n;j++)
		{x += s[i][j];}
	}
	return x/(n*n);

}
void flip(int **s, int i, int j, int n , double a2, double a4, double p)
{	
	int b(int , int);
	double x;
	x = -s[i][j]*(s[b(i-1,n)][b(j-1,n)]+s[b(i+1,n)][b(j+1,n)]+s[b(i+1,n)][b(j-1,n)]+s[b(i-1,n)][b(j+1,n)]);
	if (x >= 0)
		s[i][j] = -s[i][j];
	else
		{
			if (x == -2)
				{if ( p < a2)
				s[i][j] = -s[i][j];}
			else 
				{if ( p < a4)
				s[i][j] = -s[i][j];}
		}
	
}
int b(int n, int m)
{
	if (n == -1 )
		return m-1;
	else if (n == m)
		return 0;
	return n;
}

