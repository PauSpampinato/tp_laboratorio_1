/*
 ============================================================================
 Name        : CalculadoraTP1.c
 Author      : Spampinato Paula
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Calculos.h"

int menu(int A, int B);

int main(void) {
	setbuf(stdout,NULL);

	//Declaraci�n de variables.
	int opcion;
	int salir;
	int A;
	int B;
	int suma;
	int resta;
	float division;
	int multiplicacion;
	double factorialA;
	double factorialB;
	int flagYaCalculo;

	//Inicializaci�n de las variables que as� lo requieran.
	A=0;
	B=0;
	salir=0;
	flagYaCalculo=0;

	//Iteraci�n de tipo do while para que muestre el men� siempre hasta que el usuario decida salir.
	do
	{

		opcion=menu(A,B);//llamada la funci�n que muestra el men�


		switch(opcion)//condicional para decidir qu� hara el programa en funci�n de la opci�n del men� que eligi� el usuario.
		{
		case 1:
			printf("\n A=");
			scanf("%d", &A);
			break;
		case 2:
			printf("\n B=");
			scanf("%d", &B);
			break;
		case 3:
			//Llamada a todas las funciones que realizan calculos (�stas se encuentran en una biblioteca aparte)
			suma=sumar(A,B);
			resta=restar(A,B);
			division=dividir(A,B);
			multiplicacion=multiplicar(A,B);
			factorialA=factorial(A);
			factorialB=factorial(B);
			flagYaCalculo=1;
			break;
		case 4:
			if(flagYaCalculo==1)//condicional para saber si ya solicit� que se realicen los c�lculos.
			{printf("\na) El resultado de A+B es: %d", suma);
			printf("\nb) El resultado de A-B es: %d", resta);
			if(B==0)//condicional para saber si se puede realizar o no la operaci�n.
			{
				printf("\nc) No es posible dividir por cero");
			}
			else
			{
				printf("\nc) El resultado de A/B es: %.2f", division);
			}

			printf("\nd) El resultado de A*B es: %d", multiplicacion);
			if(factorialA==0)//condicional para saber si se pudo realizar o no la operaci�n.
			{
				if(factorialB==0)
				{
					printf("\ne) Los factoriales de A y B no existen por no ser numeros mayores a 0\n");
				}
				else
				{
					printf("\ne) El factorial de A no existe por no ser un numero mayor a 0 y el factorial de B es: %.0lf\n", factorialB);
				}

			}
			else
			{
				if(factorialB==0)
				{
					printf("\ne) El factorial de A es: %.0lf y el factorial de B no existe por no ser un numero mayor a 0\n", factorialA);
				}
				else
				{
					printf("\ne) El factorial de A es: %.0lf y el factorial de B es: %.0lf\n", factorialA, factorialB);
				}
			}}
			else
			{
				printf("\nDebe solicitar la opci�n 3 para calcular los resultados antes de mostrarlos.\n");
			}
			break;
		case 5:
			salir=1;
			break;
		default:
			printf("\n El numero ingresado no corresponde a una opci�n de men�. Por favor, vuelva a seleccionar una opci�n.");
			break;
		}
	}while(salir==0);
	return EXIT_SUCCESS;
}
int menu(int A,int B)//funci�n que muestra el men�
{
	int opcion;

	printf("\n 1. Ingresar primer operando (A=%d)", A);
	printf("\n 2. Ingresar segundo operando (B=%d)", B);
	printf("\n 3. Calcular todas las operaciones");
	printf("\n 4. Informar resultados");
	printf("\n 5. Salir\n");
	scanf("%d", &opcion);

	return opcion;
}