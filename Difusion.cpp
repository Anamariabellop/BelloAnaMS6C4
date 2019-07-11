#include<iostream>
#include<fstream>
#include<math.h>
#include <cmath>


using namespace std;

void Difusion(double vc, int npuntos);

int main(){

	double v= pow(10,-4);
	double tiempo;
	int N=100;
	Difusion(v,N);
	return 0;
}

void Difusion(double vc, int npuntos){


	ofstream outfile;
	outfile.open("placa.txt");


	int Ppresente[npuntos][npuntos];
	int Pfuturo[npuntos][npuntos];
	double T;
	double dx=0.01;
	double dy=0.01;

	double v1= (v*dt)/(dx*dx);
	double v2= (v*dt)/(dy*dy);
	double dt= (0.5*pow(dx,2)*)


	for(int k=0; k<npuntos;k++)
	{
		for(int j=0; j<npuntos;j++)
		{
			Ppresente[j][k]=50.0;

			if(j>=20 && j<= 40 && k>=40 && k<=60)
			{
				Ppresente[j][k]=100.0;
			}
		}

	}

	for(int k=0; k<npuntos;k++)
	{
		for(int j=0; j<npuntos;j++)
		{
			outfile << Ppresente[j][k] << " ";
		}
		outfile << "\n";
	}

	for(int i=0; i<npuntos;i++)
	{
		for(int k=0; k<npuntos;k++)
		{
		for(int j=0; j<npuntos;j++)
			{
				Pfuturo[j][k]= v*
			}
		}
	}


	outfile.close();
}