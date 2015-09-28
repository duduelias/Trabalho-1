#include<stdio.h>
#include<stdlib.h>
//este programa deverá receber n pontos num plano 2D, encontrar o polígono de menor area, em que todos os pontos devem pertencer ao seu perímetro, ou serem internos à sua area
int main(){
	int n,i,tan,aux1,a=0;
	printf("Digite quantos pontos serao anilzados para o calculo do fecho convexo\n");
	scanf("%d",&n);
	printf("Digite a abscissa e a ordenada de cada ponto, respectivamente\n");
	int **mat = (int**)(malloc(2*sizeof(int*)));//definindo por alocação dinamina a matriz que receberá as coordenadas de cada ponto
	for(i=0;i<n;i++){
		mat[i] = (int*)(malloc(2*sizeof(int)));
	}
	for(i=0;i<n;i++){
		scanf("%d %d", &mat[i][1], &mat[i][2]);
	}//recebendo as coordenadas de cada ponto
	system("pause");
	int aux[4][3];
	aux[0][0] = aux[1][0] = aux[2][0] = aux[3][0] = mat[0][0];
	aux[0][1] = aux[1][1] = aux[2][1] = aux[3][1] = mat[0][1];
	aux[0][3] = aux[1][3] = aux[2][3] = aux[3][3] = 0;//definindo uma variavel auxiliar
	for(i=0;i<n;i++){
		if(mat[i][0] <= aux[0][0]){
			if(mat[i][0] == aux[0][0]){
				if(mat[i][1] < aux[0][1]){
					aux[0][2] = i;
					aux[0][1] = mat[i][1];
				}
			}
			else{
				aux[0][0] = mat[i][0];
				aux[0][2] = i;
				aux[0][1] = mat[i][1];
			}
		}
	}//achando ponto de menor abscissa que possui menor ordenada
	
	for(i=0;i<n;i++){
		if(mat[i][1] < aux[1][1]){
			aux[1][1] = mat[i][1];
			aux[1][2] = i;
			aux[1][0] = mat[i][0];
		}
	}//achando ponto de menor ordenada
	
	for(i=0;i<n;i++){
		if(mat[i][0] >= aux[2][0]){
			if(mat[i][0] == aux[2][0]){
				if(mat[i][1] < aux[2][1]){
					aux[2][2] = i;
					aux[2][1] = mat[i][1];
				}
			}
			else{
				aux[2][0] = mat[i][0];
				aux[2][2] = i;
				aux[2][1] = mat[i][0];
			}
		}
	}//achando ponto com maior abscissa e menor ordenada
	
	for(i=0;i<n;i++){
		if(mat[i][1] > aux[3][1]){
			aux[3][1] = mat[i][1];
			aux[3][2] = i;
			aux[3][0] = mat[i][0];
		}
	}//achando ponto de maior ordenada
	
	int v[n];
	for(i=0;i<n;i++){
		v[i] = -1;
	}// vetor de armazenamento dos pontos que pertencem ao perimetro do poligono
	int b[1][2];
	b[0][0] = aux[0][0];
	b[0][1] = aux[0][1];
	tan = (aux[0][1] - aux[1][1])/(aux[0][0] - aux[1][0]);//definindo variavel auxiliar que carregará a tangente da reta que passa por 2 pontos a serem testados
	while(b[0][0]<aux[1][0]){
		for(i=0;i<n;i++){
			if((b[0][1] - mat[i][1])/(b[0][0] - mat[i][0]) < tan ){
				
				tan = (b[0][1] - mat[i][1])/(b[0][0] - mat[i][0]);
				aux1 = i;
			}
		}
		for(i=0;i<n;i++){
			while(v[i] != -1){
				i++;
			}
			v[i] = aux1;
			i=n;
		}
		i = aux1;
		b[0][0] = mat[i][0];
		b[0][1] = mat[i][1];
	}//partindo do ponto de menor abscissa, encontra o proximo ponto cuja tangente de sua reta com o ponto anterior é a menor possível, até chegar ao ponto de ordenada minima
	tan = (aux[2][1] - aux[1][1])/(aux[2][0] - aux[1][0]);
	while(b[0][0] < aux[2][0]){
		for(i=0;i<n;i++){
			if(tan>0 && (b[0][1] - mat[i][1])/(b[0][0] - mat[i][0]) < tan){
				tan = (b[0][1] - mat[i][1])/(b[0][0] - mat[i][0]);
				aux1 = i;
			}
		}
		for(i=0;i<n;i++){
			while(v[i] != -1){
				i++;
			}
			v[i] = aux1;
		}
		i = aux1;
		b[0][0] = mat[i][0];
		b[0][1] = mat[i][1];
	}//partindo do ponto de menor ordenada, encontra o proximo ponto cuja tangente de sua reta com o ponto anterior é a positiva e menor possível, até chegar ao ponto de abscissa maxima
	tan = (aux[3][1] - aux[2][1])/(aux[3][0] - aux[2][0]);
	while(b[0][0] > aux[3][0]){
		for(i=0;i<n;i++){
			if((b[0][1] - mat[i][1])/(b[0][0] - mat[i][0]) < tan ){
				tan = (b[0][1] - mat[i][1])/(b[0][0] - mat[i][0]);
				aux1 = i;
			}
		}
		for(i=0;i<n;i++){
			while(v[i] != -1){
				i++;
			}
			v[i] = aux1;
			i=n;
		}
		i = aux1;
		b[0][0] = mat[i][0];
		b[0][1] = mat[i][1];
	}//partindo do ponto de maior abscissa, encontra o proximo ponto cuja tangente de sua reta com o ponto anterior é a menor possível, até chegar ao ponto de ordenada maxima
	tan = (aux[3][1] - aux[0][1])/(aux[3][0] - aux[0][0]);
	while(b[0][0] > aux[0][0]){
		for(i=0;i<n;i++){
			if(tan>0 && (b[0][1] - mat[i][1])/(b[0][0] - mat[i][0]) < tan){
				tan = (b[0][1] - mat[i][1])/(b[0][0] - mat[i][0]);
				aux1 = i;
			}
		}
		for(i=0;i<n;i++){
			while(v[i] != -1){
				i++;
			}
			v[i] = aux1;
		}
		i = aux1;
		b[0][0] = mat[i][0];
		b[0][1] = mat[i][1];
	}//partindo do ponto de maior ordenada, encontra o proximo ponto cuja tangente de sua reta com o ponto anterior é a positiva e menor possível, até chegar ao ponto de abscissa minima
	//até aqui o programa achou todos os pontos que pertencem ao perimetro do polígono, guardando suas posições, em relação à matriz original, no vetor v
	printf("%d %d %d %d", v[0], v[1], v[2], v[3]);
	free(mat);
	system("pause");
	return 0;
}
