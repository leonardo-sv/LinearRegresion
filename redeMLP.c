#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHAS 3
#define COLUNAS 3
#define PATH "teste.txt"
/*Rede Neural Artificial Perceptron Multicamadas (MLP)*/

void printData(double dados[LINHAS][COLUNAS]){
	int i, j;
	for(i = 0; i < LINHAS; i++){
		for(j = 0; j < COLUNAS; j++){
			printf("%.5f ", dados[i][j]);
		}
		printf("\n");
	}
}

void createData(double dados[LINHAS][COLUNAS]){
	int i,j;
	FILE *arq = fopen(PATH,"r");

	for( i= 0; i < LINHAS;i++){
		for(j = 0; j < COLUNAS;j++){
			fscanf(arq, "%lf",&dados[i][j]);
		}
	}

}

int main(){

	double valor, dados[LINHAS][COLUNAS];
	createData(dados);
	printData(dados);
	
	return(0);
}
