#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define TAMANHO 500000
void counting_sort(int *array, int size);
main(){
	FILE *txt;
	txt=fopen("Arquivo.txt", "r");
	int v[TAMANHO], n=TAMANHO;
	int j= 0, aux;
	int i=0;
	printf("\nCarregando o Arquivo no Vetor");
	while(i<n){
		fscanf(txt, "%d", &v[i]);
		i++;
	}
	fclose(txt);
	// Algoritmo Bubble Sort
	counting_sort(v,n);
	// Fim

	printf("\nImprimindo Vetor Ordenado");
	txt= fopen("Arquivo_ordenado_count_sort.txt", "w");
	//Laço de impressão do Vetor
	for(i=0; i<n; i++){
		fprintf(txt, "%i\n", v[i]);
		printf("%d\n", i+1);
	}
	fclose(txt);
}

void counting_sort(int *array, int size){
	int i;
	int min, max;
	min = max = array[0];

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
		count[array[i]]++;
		
	//Array recebe as posicoes ocupadas
	int j, indice = 0;
	for(i = min; i <= max; i++)
		for(j = 0; j < count[ i - min ]; j++)
			array[indice++] = i;
	free(count);
}

