#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*Regressão Linear (Gradiente)*/

#define LINHAS 97
#define COLUNAS 3
#define PROP COLUNAS-1
#define ALPHA 0.01
#define NUM_ITERS 1500
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
void inicializaTheta(double *theta){
  int i;
  for (i = 0; i < COLUNAS; i++) {
    theta[i] = 0;
  }
}
void exibeMatrizDados(double dados[LINHAS][COLUNAS]){
	int i, j;
	for(i = 0; i < LINHAS; i++){
		for(j = 0; j < COLUNAS; j++){
			printf("%.5f ", dados[i][j]);
		}
		printf("\n");
	}
}

void criaMatrizDados(double dados[LINHAS][COLUNAS]){
	int i,j;
	FILE *arq = fopen(PATH,"r");

	for( i= 0; i < LINHAS;i++){
		for(j = 0; j < COLUNAS;j++){
			(j==0 ? (dados[i][j] = 1):(fscanf(arq, "%lf",&dados[i][j])));
		}
	}

}

double hipotese(double *dados, double *theta){
  int i,j;
  double hip = 0;

  for(j = 0; j < PROP;j++)
    hip = hip + ((*(dados+j)) * (*(theta+j)));

  return hip;
}

double funcaoCusto(double dados[][COLUNAS], double *theta){
  int i, j, m = LINHAS;
  double hip,erro,J = 0;

  for(i = 0; i < LINHAS;i++){
    hip = hipotese(dados[i],theta);
    erro = hip - dados[i][COLUNAS -1];
    printf(" %.5f %.5f %.5f\n - ", hip,dados[i][COLUNAS -1], erro );
    J = J +  (erro * erro)/2*m;
  }
  return J;

}


void gradiente(double dados[][COLUNAS], double *theta){
  int it,i,j,m = LINHAS;
  double grad[PROP],hip;
  inicializaTheta(grad);

  for(it = 0; it < NUM_ITERS; it++){

    for(j = 0; j < PROP;j++){
      printf("theta %i\n", j);
      for(i = 0; i < LINHAS; i++){
        hip = hipotese(dados[i],theta);
        grad[j] = grad[j] + (hip - dados[i][COLUNAS - 1]) * dados[i][j];
        if(it == 0){
            printf("%.5f\n",hip);
            printf("%.5f\n",dados[i][COLUNAS - 1]);
            printf("%.5f\n",dados[i][j]);
            printf("%.5f\n",grad[j]);
            printf("\n");
        }

      }

    }
    for(j = 0; j < PROP;j++){
      theta[j] = theta[j] - ((ALPHA/m) * grad[j]);
      grad[j] = 0;
    }

    //printf("%i  -> %.5f\n", it ,funcaoCusto(dados,theta) );
  }

}


int main(){

	double valor, dados[LINHAS][COLUNAS], theta[PROP] = {0 , 0};
  int j;

	criaMatrizDados(dados);
  exibeMatrizDados(dados);
  gradiente(dados, theta);
  for(j = 0; j< PROP;j++){
    printf("\n%f\n",theta[j]);
  }

	return(0);
}
