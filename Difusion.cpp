#include<iostream>
#include<fstream>
#include<math.h>
#include <cmath>


using namespace std;

void Difusion(double vc, int npuntos);

int main(){

	double v= pow(10,-4);
	int N=100;
	Difusion(v,N);
	return 0;
}

void Difusion(double vc, int npuntos){

	ofstream outfile;
	outfile.open("inicial.txt");

	double Ppresente[npuntos][npuntos];
	double Pfutura[npuntos][npuntos];

	//condiciones iniciales
	double dx=0.01;
	double dy=0.01;
	double dt=(0.025*pow(dx,2))/(vc);
	double v1= vc*dt/(pow(dx,2));
	double v2= vc*dt/(pow(dy,2));

	// k recorre y y j recorre x.
	
	for(int k=0; k<npuntos;k++){
		for(int j=0; j<npuntos;j++){
			Ppresente[k][j]=50.0;

			if(j>=20 && j<= 40 && k>=40 && k<=60){
				Ppresente[k][j]=100.0;
			}

		}
	}

	for(int k=0; k<npuntos;k++)
	{
		for(int j=0; j<npuntos;j++)
		{
			outfile << Ppresente[k][j] << " ";
		}
		outfile << "\n";
	}

	outfile.close();

	ofstream outfile2;
	outfile2.open("futura.txt");
	//Para t=100s
	for(float i=0; i<100;i+=dt){
		for(int k=1; k<npuntos-1;k++){
			for(int j=1; j<npuntos-1;j++){
				Pfutura[k][j]= v1*(Ppresente[k+1][j]+Ppresente[k-1][j]-2.0*Ppresente[k][j]) + v2*(Ppresente[k][j+1]+Ppresente[k][j-1]-2.0*Ppresente[k][j]) + Ppresente[k][j];
				Ppresente[k][j]=Pfutura[k][j];
			}
		}

	}

	for(int k=0; k<npuntos;k++)
	{
		for(int j=0; j<npuntos;j++)
		{
			outfile2 << Ppresente[k][j] << " ";
		}
		outfile2 << "\n";
	}

	outfile2.close();

	ofstream outfile3;
	outfile3.open("futura2.txt");

	//Para t=2500s
	for(float i=0; i<2500;i+=dt){
		for(int k=1; k<npuntos-1;k++){
			for(int j=1; j<npuntos-1;j++){
				Pfutura[k][j]= v1*(Ppresente[k+1][j]+Ppresente[k-1][j]-2.0*Ppresente[k][j]) + v2*(Ppresente[k][j+1]+Ppresente[k][j-1]-2.0*Ppresente[k][j]) + Ppresente[k][j];
				Ppresente[k][j]=Pfutura[k][j];
			}
		}

	}

	for(int k=0; k<npuntos;k++)
	{
		for(int j=0; j<npuntos;j++)
		{
			outfile3 << Ppresente[k][j] << " ";
		}
		outfile3 << "\n";
	}

	outfile3.close();

	//Caso 2: condiciones abiertas.

	ofstream outfile4;
	outfile4.open("inicialc2.txt");

	double P2presente[npuntos][npuntos];
	double P2futura[npuntos][npuntos];

	for(int k=0; k<npuntos;k++){
		for(int j=0; j<npuntos;j++){
			P2presente[k][j]=50.0;

			if(j>=20 && j<= 40 && k>=40 && k<=60){
				P2presente[k][j]=100.0;
			}

		}
	}

	for(int k=0; k<npuntos;k++)
	{
		for(int j=0; j<npuntos;j++)
		{
			outfile4 << P2presente[k][j] << " ";
		}
		outfile4 << "\n";
	}
	outfile4.close();

	ofstream outfile5;
	outfile5.open("futurac2.txt");

	//Para t=100s
	for(float i=0; i<100;i+=dt){
		for(int k=1; k<npuntos-1;k++){
			for(int j=1; j<npuntos-1;j++){
				P2futura[k][j]= v1*(P2presente[k+1][j]+P2presente[k-1][j]-2.0*P2presente[k][j]) + v2*(P2presente[k][j+1]+P2presente[k][j-1]-2.0*P2presente[k][j]) + P2presente[k][j];
				P2presente[k][j]=P2futura[k][j];
			}
		}

	}

	for(int k=0; k<npuntos;k++)
	{
		for(int j=0; j<npuntos;j++)
		{
			outfile5 << P2presente[k][j] << " ";
		}
		outfile5 << "\n";
	}
	outfile5.close();

	ofstream outfile6;
	outfile6.open("futura2c2.txt");

	//Para t=2500s
	for(float i=0; i<2500;i+=dt){
		for(int k=1; k<npuntos-1;k++){
			for(int j=1; j<npuntos-1;j++){
				P2futura[k][j]= v1*(Ppresente[k+1][j]+P2presente[k-1][j]-2.0*P2presente[k][j]) + v2*(P2presente[k][j+1]+P2presente[k][j-1]-2.0*P2presente[k][j]) + P2presente[k][j];
				P2presente[k][j]=P2futura[k][j];
			}
		}

	}

	for(int k=0; k<npuntos;k++)
	{
		for(int j=0; j<npuntos;j++)
		{
			outfile6 << P2presente[k][j] << " ";
		}
		outfile6 << "\n";
	}
	outfile6.close();

	//Caso 3: condiciones periodicas.

	ofstream outfile7;
	outfile7.open("inicialc3.txt");

	double P3presente[npuntos][npuntos];
	double P3futura[npuntos][npuntos];

	for(int k=0; k<npuntos;k++){
		for(int j=0; j<npuntos;j++){
			P3presente[k][j]=50.0;

			if(j>=20 && j<= 40 && k>=40 && k<=60){
				P3presente[k][j]=100.0;
			}

		}
	}

	for(int k=0; k<npuntos;k++)
	{
		for(int j=0; j<npuntos;j++)
		{
			outfile7 << P3presente[k][j] << " ";
		}
		outfile7 << "\n";
	}
	outfile7.close();

	ofstream outfile8;
	outfile8.open("futurac3.txt");

	//Para t=100s
	for(float i=0; i<100;i+=dt){
		for(int k=1; k<npuntos-1;k++){
			for(int j=1; j<npuntos-1;j++){
				P3futura[k][j]= v1*(P3presente[k+1][j]+P3presente[k-1][j]-2.0*P3presente[k][j]) + v2*(P3presente[k][j+1]+P3presente[k][j-1]-2.0*P3presente[k][j]) + P3presente[k][j];
				P3presente[k][j]=P3futura[k][j];
			}
		}

	}

	for(int k=0; k<npuntos;k++)
	{
		for(int j=0; j<npuntos;j++)
		{
			outfile8 << P3presente[k][j] << " ";
		}
		outfile8 << "\n";
	}
	outfile8.close();

	ofstream outfile9;
	outfile9.open("futura2c3.txt");

	//Para t=2500s
	for(float i=0; i<2500;i+=dt){
		for(int k=1; k<npuntos-1;k++){
			for(int j=1; j<npuntos-1;j++){
				P3futura[k][j]= v1*(P3presente[k+1][j]+P3presente[k-1][j]-2.0*P3presente[k][j]) + v2*(P3presente[k][j+1]+P3presente[k][j-1]-2.0*P3presente[k][j]) + P3presente[k][j];
				P3presente[k][j]=P3futura[k][j];
			}
		}

	}

	for(int k=0; k<npuntos;k++)
	{
		for(int j=0; j<npuntos;j++)
		{
			outfile9 << P3presente[k][j] << " ";
		}
		outfile9 << "\n";
	}
	outfile9.close();


}
