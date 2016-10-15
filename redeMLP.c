#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Rede Neural Artificial Perceptron Multicamadas (MLP)*/

#define LINHAS 97
#define COLUNAS 2
#define PATH "ex1data1.txt"

void printData(double data[LINHAS][COLUNAS]){
	int i, j;
	for(i = 0; i < LINHAS; i++){
		for(j = 0; j < COLUNAS; j++){
			printf("%.5f ", data[i][j]);
		}
		printf("\n");
	}
}

void createData(double data[LINHAS][COLUNAS]){
	int i,j;
	FILE *arq = fopen(PATH,"r");

	for( i= 0; i < LINHAS;i++){
		for(j = 0; j < COLUNAS;j++){
			fscanf(arq, "%lf",&data[i][j]);
		}
	}

}


int main(){

	double valor, data[LINHAS][COLUNAS];
	createData(data);
	printData(data);
	//printf("%f",data[0][0]);

	return(0);
}
