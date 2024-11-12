#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "c:/cproject/PIM/lib/estoque.h"
#include "c:/cproject/PIM/lib/pesquisa_codigo.h"


int pesquisar(); // declaração da função de pesquisa (vindo do pesquisa_codigo.h)

int pesquisar() // implementação da função pesquisa
{
    Pesquisa pesquisar[] = // array para cada produto, contendo nome e preço 
    {
    {"Melancia", 10.50},
    {"Morango (Caixa)", 5.50},
    {"Banana Nanica", 4.50},
    {"Banana Prata", 6.00},
    {"Uvas", 8.90},
    {"Maca", 6.90},
    {"Banda da Melancia", 5.50},
    {"Melancia Baby", 7.00},
    {"Mexerica", 5.00},
    {"Maca Gala", 8.70},
    {"Maca Fuji", 8.00},
    {"Maca Saco", 10.50},
    {"Pera", 20.00},
    {"Manga Palmer", 9.00},
    {"Manga Tommy", 9.00},
    {"Kiwi", 25.00},
    {"Melao", 20.00},
    {"Banda do Melao", 9.50},
    {"Coco", 3.50},
    {"Laranja Pera", 9.00},
    {"Carambola", 25.00},
    {"Amora", 22.00},
    {"Caqui Fuyu", 8.00},
    {"Limao Taiti", 4.50},
    {"Limao Siciliano", 11.00},
    {"Tomate", 5.60},
    {"Alface", 3.50},
    {"Abobora", 7.00},
    {"Abobora Manteiga", 11.70},
    {"Pepino Comum", 12.00},
    {"Pepino Japones", 10.00},
    {"Cheiro Verde", 2.00},
    {"Cebolinha", 4.50},
    {"Chuchu", 10.00},
    {"Cenoura", 4.50},
    {"Batata Comum", 8.00},
    {"Batata Asterix", 15.00},
    {"Batata Doce", 9.00},
    {"Cebola", 6.00},
    {"Pimenta", 16.90}
    };

    int escolha, i; // variavel de escolha
    
    while (1) // loop para verificar se a escolha do usuário é valida e mostrá-la na tela
    {
        printf("(0 - Sair)\nDigite o codigo para consultar o produto (1 - 40): \n");
        scanf("%d", &escolha);

        if (escolha == 0) // encerra o loop se for 0
        {
            break; 
        }
        if (escolha >= 1 && escolha <= 40) // verifica se a escolha está dentro de 1 - 40
        {
            int indice = escolha - 1; // ajuste do índice para acessar o array corretamente
            printf("\nProduto: %s\nPreco: %.2f\n", pesquisar[indice].nome, pesquisar[indice].preco);
        }  
        else // se estiver fora de 1 - 40, é inválido 
        {
            printf("Codigo invalido. Tente novamente\n");
        }
    }
    return 0;
}