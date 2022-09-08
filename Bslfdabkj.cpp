#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define TAMANHO 100000
void counting_sort(int *array, int size);
main(){
	FILE *txt;
	txt=fopen("Arquivo100k.txt", "r");
	int v[TAMANHO], n=TAMANHO;
	int j= 0, aux;
	int i=0;
	printf("\nCarregando o Arquivo no Vetor");
	while(i<n){
		fscanf(txt, "%f", &v[i]);
		printf("\n%d\n", v[0]);
		if(i==0) i=n;
		i++;
	}
	printf("\n%d\n", v[0]);
	fclose(txt);
	printf("\n%d\n", v[0]);
	// Algoritmo Bubble Sort
	//counting_sort(v,n);
	// Fim

	printf("\nImprimindo Vetor Ordenado");
	txt= fopen("Arquivo_ordenado.txt", "w");
	//Laço de impressão do Vetor
	for(i=0; i<n; i++){
		fprintf(txt, "%.0f\n", v[i]);
	}
	fclose(txt);
}

void counting_sort(int *array, int size){
	printf("\n%d\n", array[0]);
	int i;
	int min, max;
	min = max = array[0];
	printf("%d", array[0]);
	//Identifica o Maior Elemento
	for(i = 1; i < size; i++){
		if (array[i] < min){
			min = array[i];
		}else if (array[i] > max){
			max = array[i];
		}
	}
	
	int range = max - min + 1;
	int *count = (int *) malloc(range * sizeof(int));
	//Marca Todas as posições com Zero
	for(i = 0; i < range; i++)
		count[i] = 0;
	//Marca as posições ocupadas
	for(i = 0; i < size; i++)
		count[array[i] - min]++;
	int j, indice = 0;
	//Array recebe as posicoes ocupadas
	for(i = min; i <= max; i++)
		for(j = 0; j < count[ i - min ]; j++)
			array[indice++] = i;
	free(count);
}

