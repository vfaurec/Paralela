
#include <stdio.h>  
#include <stdlib.h>
#include <math.h>
//#include <conio.h>
#include <string.h>

#define N 100000
#define M 100

/*
math.h --> permite el uso de funciones matematicas especificas (fuera de la de los operadores logicos
stdio.h --> significa standard input-output header, funciones de entrada y salida
stdlib.h --> uso de la funcion random
*/

int vector[N]; //Declaro un vector con 100000 valores
int i;

int main (){

	int opcion,p;
	char num;

		//La generación de valores será al inicio del programa, indicando cuando se generen
		printf("\n Generando numeros aleatorios... ");
		for(i=0; i<N; i++){
			vector[i] =  rand()%(M+1); //Le doy un rango de valores, entre 0 y 100
			printf("\n El valor [%d] es = %d", i+1, vector[i]);
		}
		printf("\n Vector Generado! \n");

	do{
		printf("\n\n\n MENU DE OPCIONES");  
		printf("\n 1. Calcular PROMEDIO de los valores "); 
		printf("\n 2. Calcular VARIANZA de los valores"); 
		printf("\n 3. calcular DESVIACION ESTANDAR de los valores"); 
		printf("\n 4. Salir"); 
		printf("\n Ingrese que opción desea realizar: ");
		scanf("%s", &num);

		opcion = validar(num);

		system("clear");

		switch(opcion){
			case 1: promedio(vector);
				break;
			case 2: p = promedio(vector);
				vari(vector,p);
				break;
			case 3: desviacion(vari(vector,p));
				break;
			case 4: return 0;
				break;
			default:printf("\n\n\n Numero invalido intente nuevamente! ");
		}

	} while (opcion!=0);	
	system("clear");
}

int promedio(int v[]){

	printf("\n PROMEDIO DE LOS VALORES");
	double suma, prom;

	for(i=0; i<N; i++){
		suma=suma+vector[i];
	}	
		
	printf("\n La suma de los valores es %f",suma);
	prom=suma/N;
	printf("\n La PROMEDIO de los valores es %f",prom);
	return (double) prom;
}

int vari(int v[],int prom){

	printf("\n VARIANZA DE LOS VALORES");
	double var=0;

	for(i=0;i<N;i++){
		var += pow(v[i]-prom,2);
	}

	var=var/N;
	printf("\n La VARIANZA de los valores es %f", var);
	return (double) var;
}

int desviacion(double vari){
	printf("\n DESVIACION DE LOS VALORES");
	printf("\n La DESVIACION ESTANDAR de los valores es %f", sqrt(vari));
	return (double) sqrt(vari);
}

void validar(char num){
    int i;
    if(!isdigit(num)){
            printf("\nNO SE ACEPTAN LETRAS\n");
            return 0;
    }
    return 1;
}
