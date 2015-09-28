#include<stdio.h>
#include<stdlib.h>

int comparaCrescente( const void * a, const void * b){
    if (*(int*)a == *(int*)b)
        return 0;//iguais
    else
        if(*(int*)a < *(int*)b)
            return -1;//vem antes
        else
            return 1;//vem depois
    }// fun��o utilizada pela fun��o qsort para ordenar os elementos do vetor de maneira crescente

//Este programa receber� um vetor de elementos inteiros, ordenar� de forma crescente esses elementos, achar� a diferen�a minima entre um par de elementos e imprimir� qual � essa diferen�a e quais pares � possuem.
int main (){
    int i, n, dif;
    printf("Digite o tamanho do vetor\n");
    scanf("%d",&n);
    int *vet = (int*)calloc(n,sizeof(int));//aloca��o dinamica de memoria para o vetor
    if(n < 2){
    	printf("O vetor nao possui tamanho suficiente para calcular alguma diferenca\n");//checando se o vetor possui tamanho minimo suficiente
	}
	else{
    	printf("Entre com os elementos do vetor\n");
    	for(i=0;i<n;i++){
       	 scanf("%d",&vet[i]);
    }//recebendo os valores do vetor
    	qsort(vet, n, sizeof(int), comparaCrescente);//ordenando os elementos do vetor
    	dif = vet[1] - vet[0];//atribuindo valor inicial para a variavel auxiliar que carregar� a diferen�a minima
    	for(i=2;i<n;i++){
    		if(vet[i] - vet[i-1] < dif){
    			dif = vet[i] - vet[i-1];
		}
	}// encontrando a diferen�a minima dos elementos do vetor
		printf("A menor diferenca e %d, e os pares que a possuem sao:\n",dif);
		int vdif[n-1];//criando vetor que armazenar� todas as diferen�as de cada elemento com o seu sucessor 
		for(i=0;i<n-1;i++){
			vdif[i] = vet[i+1] - vet[i];
			if(vdif[i] == dif){
				printf("%d e %d\n",vet[i+1],vet[i]);//imprimindo na tela todos os pares que possuem a diferen�a minima
		}
	}
	}
	free(vet);//desaloca��o de memoria
    return 0;
    system("pause");
}

