#include <stdio.h>
#include <stdlib.h>

int main()
{

	double dt=0.00001;
	double dx=0.005;
	int n = 100000;
	int m = 129;
	double **M=malloc(n*sizeof(double));
	for(int i=0;i<n;i++)
	{
		M[i]=malloc(m*sizeof(double*));
	}
	double var1;
	double var2;
	FILE *in;
	double c = 250;
	double r = (dt*c)/dx;
	double h = 101
	double N[h][h][h];
	
	in = fopen("cond_ini_cuerda.dat","r");
	if(!in)
	{
		printf("problems opening the file %s\n", "cond_ini_cuerda.dat");
		exit(1);
	}
	
	for(int j=0;j<m;j++)
	{
		fscanf(in, "%lf %lf\n", &var1, &var2);
		M[0][j] = var2;
		
	}

	for(int j=1;j<m-1;j++)
	{
		M[1][j] = M[0][j]+((r*r)/2)*(M[0][j+1]-2*M[0][j]+M[0][j-1]);
	}

	fclose(in);
	
	

	for(int i=0;i<n;i++)
	{
		M[i][0]=0;
		M[i][m-1]=0;
	}
	

	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<m-1;j++)
		{
			M[i+1][j]=r*r*(M[i][j+1]-2*M[i][j]+M[i][j-1]) + 2*M[i][j]-M[i-1][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%f\n",M[i][j]);
		}
	printf("%f", r*r);
	}

	FILE *on;
	on=fopen("cuerda.dat","w");
	if(!on)
	{
		printf("problems opening the file %s\n", "cuerda.dat");
		exit(1);
	}
	
	for(int j=0;j<m;j++)
	{
		fprintf(on,"b%f\n",M[n-1][j]);
		
	}
	fclose(on);

	un = fopen("cond_ini_cuerda.dat","r");
	if(!un)
	{
		printf("problems opening the file %s\n", "cond_ini_tambor.dat");
		exit(1);
	}
	
	for(int j=0;j<m;j++)
	{
		fscanf(un, "%lf %lf\n", &var1, &var2);
		M[0][j] = var2;
		
	}

	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<100;j++)
		{
			for(int k=1;k<100;k++)
			{
				N[i+1][j][k]=r*r*(N[i][j+1]-2*N[i][j]+N[i][j-1]) + 2*N[i][j]-N[i-1][j]+r*r*(N[i][j+1]-2*N[i][j]+N[i][j-1]) + 2*N[i][j]-N[i-1][j];
			}
		}
	}
}
