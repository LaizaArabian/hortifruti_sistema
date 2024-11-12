#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c:/cproject/PIM/lib/feedback.h"

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int escreve(); // declaração da estrutura

int escreve()
{
	FILE *feedback;
	
	//criacao de variaveis
	char letra;
	int numero_arq = 1;
	char name[50];
	
	do // loop para criar arquivo
	{
		sprintf(name, "c:/cproject/PIM/output/feedback%d.txt", numero_arq); 	
		feedback = fopen(name, "r");
		
		if(feedback != NULL) // se ja existe cria novo
		{
			fclose(feedback);
			numero_arq++;
		}
	} while(feedback != NULL); // ate achar um arquivo disponivel

    feedback = fopen(name, "w"); // abre o arquivo para escrita
    if (feedback == NULL) 
	{
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

	printf("(0 - Sair)\nDigite o seu feedback sobre nosso Hortifruti: ");// registra feedback
	limparBuffer();

	 // Loop para capturar o feedback do usuário
    while (1) 
	{
        printf(""); // Captura a linha de reclamação ou nota
		char linha[500];  // Buffer para armazenar a linha de feedback
		fgets(linha, sizeof(linha), stdin);  // Captura a linha até o limite do buffer

		// Se o usuário digitar '0' e pressionar Enter, finaliza a entrada
		if (linha[0] == '0' && linha[1] == '\n') 
		{
			fclose(feedback);  // Fecha o arquivo
			printf("Feedback salvo no arquivo '%s'.\n", name);  // mensagem de confirmação
			return 1;  // Retorna 1, indicando que o feedback foi salvo
		}
			
			fputs(linha, feedback); // Escreve a linha no arquivo com um caractere de nova linha
		}
}