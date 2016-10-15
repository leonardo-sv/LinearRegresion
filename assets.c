#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*Rede Neural Artificial Perceptron Multicamadas (MLP)*/

#define LINHAS 3
#define COLUNAS 4
#define PATH "ex1data1.txt"


double** alocarMatriz(int Linhas,int Colunas){ //Recebe a quantidade de Linhas e Colunas como Parâmetro

  int i,j; //Variáveis Auxiliares

  double **m = (double**)malloc(Linhas * sizeof(double*)); //Aloca um Vetor de Ponteiros

  for (i = 0; i < Linhas; i++){ //Percorre as linhas do Vetor de Ponteiros
       m[i] = (double*) malloc(Colunas * sizeof(double)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
       for (j = 0; j < Colunas; j++){ //Percorre o Vetor de Inteiros atual.
            m[i][j] = 0; //Inicializa com 0.
       }
  }
  return m; //Retorna o Ponteiro para a Matriz Alocada
}

void imprime(double matriz[LINHAS][COLUNAS]){
  int i, j;

  for (i = 0; i < LINHAS; i++) {
    for (j = 0; j < COLUNAS; j++) {
      printf("%.5f",matriz[i][j]);
    }
    printf("\n");
  }

}

double teste(double x, double e){
  return pow(x,e);
}
int main(){
  /*double matriz[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12},i;
  double *p = matriz[1];
  imprime(matriz);

  for (i = 0; i < 4; i++) {
    printf("%.5f\n", *(p++));
  }*/
   printf("Value 8.0 ^ 3 = %lf\n", pow(8.0, 3));

   printf("Value 3.05 ^ 1.98 = %lf", pow(3.05, 1.98));
  return 0;
}
