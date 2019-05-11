#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <string.h>
#define T 100 //tamaño del vector original

int Random(){	//función que devuelve número aleatoreo entre 0 y 100

	int numero = rand()%100;
	return numero;
}

int* CrearVector(int inicio, int final, int* origen){

    int* sub_vector, tam, auxiliar=0, i; //inicializo puntero y variables
    tam=final-inicio;
    sub_vector=(int*)malloc(tam* sizeof(int)); //le da un espacio de memoria necesario (dinámico)
	    for(i=inicio;i<final;i++){ //recorrer arreglo original
		*(sub_vector+auxiliar)=*(origen+i);
		auxiliar+=1;
	    }
    return  sub_vector; //retorno subvector (puntero)
}

void imprimir(int id_proceso, int tam_subvector, int* sub_vector){

    int i;
    printf("\nEl proceso %d crea el sub_vector: [ ", id_proceso);
	    for (i=0;i<tam_subvector;++i){ //tam_subvector-->tamaño de cada subvector
		printf("%d, ", *(sub_vector+i));
	    }
    printf("]\n");

}

float promedio(int v[],int tam_sv){ //ingresan como parametros el subvector y el tamaño de cada uno (tam_sv)

	float prom=0,suma=0;
		for(int i=0; i<tam_sv; i++){
			suma=suma+v[i];
		}	
	prom=suma/tam_sv;
	return prom;
}


/*int vari(int v[],int prom){

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
}*/

/*void validar(char num){
    int i;
    if(!isdigit(num)){
            printf("\nNO SE ACEPTAN LETRAS\n");
            return 0;
    }
    return 1;
}*/

int main(void){

	int tam_procesos; //¿cuantos procesos hay? ---> tam_procesos
	int id_proceso; // identificador de proceso 
        int vector[T];
        int* sub_vector=NULL;
	int tam_subvector;
	float promedio_vector, suma_promedios;
	
    	//inicio uso del MPI
    	MPI_Init(NULL, NULL);
    	MPI_Comm_size(MPI_COMM_WORLD, &tam_procesos);
	MPI_Comm_rank(MPI_COMM_WORLD, &id_proceso);    
    	tam_subvector = T/tam_procesos; //en cuanto divido cada subvector

	//lleno el vector con datos aleatorios	
	for(int i=0;i<T;i++){
		vector[i]=Random();
	}

	float p[tam_procesos];
    
	    if (id_proceso!=0) {
		//procesos distintos de cero
		sub_vector=(int*)malloc(tam_subvector * sizeof(int));
		MPI_Recv(sub_vector,tam_subvector,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		imprimir(id_proceso,tam_subvector,sub_vector);
		printf("El PROMEDIO del subvector del proceso %d es: %f\n",id_proceso,promedio(sub_vector,tam_subvector));

	    } else {
		printf("\nSe solicita la ejecución con %d procesos\n", tam_procesos);
		printf("Proceso %d calcula tamaño de cada vector = %d\n\n", id_proceso, tam_subvector);
			for (int i=1;i<tam_procesos;i++) {
			    sub_vector=CrearVector(i*tam_subvector,(i*tam_subvector)+tam_subvector,vector);
			    MPI_Send(sub_vector,tam_subvector,MPI_INT,i,0,MPI_COMM_WORLD);
			}
		sub_vector=CrearVector(0,tam_subvector,vector); //se crea a si mismo el subvector para tener la division en todos lados (procesador 0)
		imprimir(id_proceso,tam_subvector,sub_vector);	
		printf("El PROMEDIO del subvector del proceso %d es: %f\n",id_proceso,promedio(sub_vector,tam_subvector));

	    }

	//finalizo uso de MPI
	MPI_Finalize();
	
    return 0;

}


