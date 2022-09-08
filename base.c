#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
main(){
	FILE *txt;
	txt=fopen("Arquivo.txt", "r");
	float v[100000], n=100000;
	float j= 0, aux;
	long int i=0;
	printf("\nCarregando o Arquivo no Vetor");
	while(i<n){
		fscanf(txt, "%f", &v[i]);
		i++;
	}
	fclose(txt);
	
	// codigo aqui
	
	printf("\nImprimindo Vetor Ordenado");
	txt= fopen("Arquivo_ordenado.txt", "w");
	
	//Laço de impressão do Vetor
	for(i=0; i<n; i++){
		fprintf(txt, "%.0f\n", v[i]);
	}
	fclose(txt);
}
