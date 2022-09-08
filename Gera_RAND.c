#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>
#define TAMANHO 100000

main(){
int i;
unsigned int ex;

FILE *txt;

if((txt = fopen("Arquivo.txt", "w")) == NULL)    {
        printf("Erro ao abrir arquivo");
    }
 else {
       
	  	//Definindo a Semente Inicial do Gerador Aleatorio
		ex = ((unsigned) time(NULL)) ; 
		
		srand(ex) ; 
		
	     i = 0;
         while(i < TAMANHO)
         {
               float c = rand() % TAMANHO;
			   fprintf(txt, "%.0f\n",c);
               ++i;
          }
		fclose(txt);
      }
}

