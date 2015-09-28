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
    }//Esta fun��o ser� utilizada pela fun��o qsort para ordenar os elementos do vetor de forma crescente

//Este programa receber� um vetor de elementos inteiros, os ordenar�, atribuir� a outro vetor quantas vezes cada elemento � repetido dentro do vetor e imprimir� na tela quais elementos s�o repetidos mais vezes e quantas vezes eles se repetem
int main (){
    int i,j,k,n;
    printf("Digite o tamanho do vetor\n");
    scanf("%d",&n);
    int *vet = (int*)calloc(n,sizeof(int));//aloca��o dinamica de memoria para o vetor
	int *cont = (int*)calloc(n,sizeof(int));//aloca��o dinamica de memoria para o vetor
    if(n<=0){
    	printf("Voce digitou um tamanho invalido para o vetor");
	}//checando se foi escolhido um tamanho v�lido para o vetor
	else{
    printf("Entre com os elementos do vetor\n");
    for(i=0;i<n;i++){
        scanf("%d",&vet[i]);
    }//recebendo os elementos do vetor
    if(n==1){
    	printf("O elemento que mais aparece no vetor e:\n");
    	printf("Elemento %d aparece %d vez no vetor\n",vet[0],1);
	}//se o vetor for unit�rio seu �nico elemento ser� o elemento que aparece mais vezes
	else{
    qsort(vet, n, sizeof(int), comparaCrescente);//ordenando os elementos do vetor
	for (i=0; i<n; i++){
		cont[i] = 1;
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(vet[i] == vet[j]){//checando quantas vezes cada elemento � repetido no vetor
				cont[i] = cont[i] + 1;//contando no vetor auxiliar quantas vezes cada elemento foi repetido
			}
			else{
				i = j-1;
				j = n-1;
			}//quando � achado um elemento diferente do que ele estava checando, o programa passa a checar se este novo elemento � repetido
		}
		}
	k = cont[0];//atribuindo a quantidade de vezes q o primeiro elemento aparece no vetor para uma variavel auxiliar
	for(i=1;i<n;i++){
		if(cont[i] > k){
			k = cont[i];
		}
	}//checando qual � o n�mero de repeti��o m�ximo que um elemento possui dentro do vetor
	printf("Os elementos que aparecem mais vezes no vetor sao repetidos %d vezes\nEsses elementos sao:\n",k);
	for(i=0;i<n;i++){
		if(cont[i] == k){
			printf("Elemento %d \n",vet[i]);
		}
	}//checando quais elementos possuem esse n�mero de repeti��o, e imprimindo-os na tela
}
}
	free(vet);
	free(cont);
    return 0;
    system("pause");
}
