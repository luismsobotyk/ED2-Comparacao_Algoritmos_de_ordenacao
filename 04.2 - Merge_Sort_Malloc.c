#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define TAMANHO 500000
void mergeSort(int vec[], int vecSize);
void merge(int vec[], int vecSize);
main(){
	int* v = malloc(TAMANHO*sizeof(int));
	if(v == NULL){
		printf("Memória insuficiente para alocação.");
		exit(1);
	}
	FILE *txt;
	txt=fopen("Arquivo500k.txt", "r");
	int i=0;
	printf("\nCarregando o Arquivo no Vetor");
	int porcentagem=0;
	while(i<TAMANHO){
		fscanf(txt, "%i", &v[i]);
		i++;
		float percent= TAMANHO/100;
		if(i-porcentagem>=percent){
			porcentagem= porcentagem+percent;
			system("cls");
			printf("Carregando o Arquivo no Vetor\nStatus: %f %%", porcentagem/percent);
		}
	}
	fclose(txt);
	printf("\nIniciando Ordenacao");
	// Algoritmo Bubble Sort
	mergeSort(v,TAMANHO);
	// Fim

	printf("\nImprimindo Vetor Ordenado");
	txt= fopen("Arquivo_ordenado_merge_sort_500k.txt", "w");
	//Laço de impressão do Vetor
	for(i=0; i<TAMANHO; i++){
		fprintf(txt, "%i\n", v[i]);
	}
	fclose(txt);
}

void mergeSort(int vec[], int vecSize){
	int mid;
	if (vecSize > 1){
		mid = vecSize / 2;
		mergeSort(vec, mid);
		mergeSort(vec + mid, vecSize - mid);
		merge(vec, vecSize);
	}
}
void merge(int vec[], int vecSize) {
	int mid;
	int i, j, k;
	int* tmp;
	tmp = (int*) malloc(vecSize * sizeof(int));
	if (tmp == NULL) {
		exit(1);
	}
	mid = vecSize / 2;
	i = 0;
	j = mid;
	k = 0;
	while (i < mid && j < vecSize) {
		if (vec[i] < vec[j]) {
			tmp[k] = vec[i];
			++i;
		}else {
			tmp[k] = vec[j];
			++j;
		}
		++k;
	}
	if (i == mid) {
		while (j < vecSize) {
			tmp[k] = vec[j];
			++j;
			++k;
		}
	}else {
		while (i < mid) {
			tmp[k] = vec[i];
			++i;
			++k;
		}
	}
	for (i = 0; i < vecSize; ++i) {
		vec[i] = tmp[i];
		//printf("%d\n", i+1);
	}
	free(tmp);
}

