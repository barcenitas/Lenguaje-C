#include <stdio.h>
#include <math.h>
#include <conio.h >
#include <windows.h>
#include "prototiposlin.h"
#define criteriodeparo 0.05

//podriamos ocupar extern pero las dejamos así
    int i, j, k, n = 5;
	double r, s, dr, ds, error;
    double A[6], B[6], C[6];
	char resp;

void ajustesdis(){
    SetConsoleTitle("Proyecto de Ingenieria 2: Calculadora de factores cuadraticos");
    system ("color F2");
}

void ecsegundogrado(double a, double b, double c){

	double x1, x2, disc;

	disc = pow(b, 2) - 4*a*c;
	if (disc >= -criteriodeparo)
	{
		x1 = (-b + sqrt(disc)) / 2*a;
		x2 = (-b - sqrt(disc)) / 2*a;
		printf("\n \t \t x = %g \n", x1);
		printf("\n \t \t x = %g  \n", x2);
	}
	else
	{
		x1 = -b / 2*a;
		x2 = sqrt(-disc) / 2*a;
		if (fabs(x1) < criteriodeparo)
			x1 = 0;
		printf("\n \t \t x = %g + %g i \n", x1, x2);
		printf("\n \t \t x = %g - %g i \n", x1, x2);
	}
}

//

double pregunta(){



		printf("\n \n \t \t Este programa calcula las raices de grado 5 con esta forma: \n \t \t p(x)=a0x^5+a1x^4+a2x^3+a3x^2+a4x+a5 \n");
	do{

	for (j=5; j>=0; j--){

	printf("\n \t \t Introduzca el valor de a%d: \n \t \t ",j);
	scanf("%lf",&A[j]);


	if (j==0){
			printf("\n \t \t Tus datos son los correctos (con minuscula) [s/n]: \n \t \t ");
	scanf("%s",&resp);
     if (resp!='s'){

        system("cls");
    }
	}

	}



	}while(resp!='s');

    r = 0;
	s = 0;
    system("cls");
	printf("\n \t \t Las raices son las siguientes: \n \t \t ");

}


double metodos(){

		// Metodo de Factores Cuadraticos
	while (n >= 3)
	{
		// M.Newton Raphson
		error = 1;
		while (error > criteriodeparo)
		{
			// Division sintetica -> Obtencion de factor cuadratico
			B[n] = A[n];
			B[n-1] = A[n-1] + r*B[n];
			for (i = n-2; i >= 0; i--)
			{
				B[i] = A[i] + r*B[i+1] + s*B[i+2];
			}

			// Div, sintetica
			C[n] = B[n];
			C[n-1] = B[n-1] + r*C[n];
			for (i = n-2; i >= 0; i--)
			{
				C[i] = B[i] + r*C[i+1] + s*C[i+2];
			}

			// sistema de ecs
			ds = (B[0]*C[2] - B[1]*C[1]) / (C[1]*C[3] - C[2]*C[2]);
			dr = -(B[0] + C[2]*ds) / C[1];

			// nuevo r y s
			r = r + dr;
			s = s + ds;

			// Calculo del error
			error = fabs(B[0]) + fabs(B[1]);
		}

		// ev. formula general
		ecsegundogrado(1, -r, -s);

		// Reduccion del polinomio original
		n = n - 2;
		for (i = 0; i <= n; i++)
			A[i] = B[i+2];
	}

	if (n == 1)
	{
		// polinomio impar


                printf("\n \t \t x = %g \n", -A[0] / A[1]);

	}
	else
	{
		//  polinomio par
		ecsegundogrado(A[2], A[1], A[0]);
	}

	getchar();
}

