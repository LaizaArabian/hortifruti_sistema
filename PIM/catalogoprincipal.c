#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "c:/cproject/PIM/lib/estoque.h"
#include "c:/cproject/PIM/lib/pesquisa_codigo.h"
#include "c:/cproject/PIM/lib/feedback.h"

int menu() // função para mostrar o menu de opções ao usuário
{
    int escolha; // variável de escolha do usuario (case 1, 2 ou 3)
    do 
    {   
        printf("| 1 - Pesquisa por codigo | 2 - Adicionar ao carrinho | 3 - Feedback |\n");
        scanf("%d", &escolha);

        if (escolha < 1 || escolha > 3) // validação de escolha, se for invalida, digite novamente
        {
            printf("Digite novamente:\n");
        }
    }
    
    while (escolha < 1 || escolha > 3); // continua no loop quando o usuario digitar 1, 2 ou 3, entrará nos cases
    switch (escolha) // estrutura de seleção para escolha do usuário
        {
        case 1: 
            pesquisar(); // vai para o pesquisa_codigo.c e chama a funcao pesquisar()
            break;
        
        case 2: // vai para o estoque.c e chama a funcao estoque()
            estoque();
            break;
        case 3:
            escreve(); // vai para feedback.c e chama escreve()
            break;
        }
}

int main ()
{
    menu(); // chama a função do menu para exibir as opções
}