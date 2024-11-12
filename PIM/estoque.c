#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "c:/cproject/PIM/lib/estoque.h"

void limpandoBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Produtos frutas;
int estoque(); // declaração da função de pesquisa (vindo do estoque.h)

int estoque() // implementação da função estoque 
{
    Produtos frutas[] = // array para cada produto, contendo nome e preço 
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

    //array para cada produto
    int quantidade_frutas[40]= {0}; //inicia as quantidades com 0
    int escolha, i;
    float valor_total = 0; 
    
    do
    {
        printf( // mostra o catálogo de produtos
        "Produtos disponiveis:\n"
        "1. Melancia          - R$10.50\n"
        "2. Morango (Caixa)   - R$5.50\n"
        "3. Banana Nanica     - R$4.50\n"
        "4. Banana Prata      - R$6.00\n"
        "5. Uvas              - R$8.90\n"
        "6. Maca              - R$6.90\n"
        "7. Banda da Melancia - R$5.50\n"
        "8. Melancia Baby     - R$7.00\n"
        "9. Mexerica          - R$5.00\n"
        "10. Maca Gala        - R$8.70\n"
        "11. Maca Fuji        - R$8.00\n"
        "12. Maca Saco        - R$10.50\n"
        "13. Pera             - R$20.00\n"
        "14. Manga Palmer     - R$9.00\n"
        "15. Manga Tommy      - R$9.00\n"
        "16. Kiwi             - R$25.00\n"
        "17. Melao            - R$20.00\n"
        "18. Banda do Melao   - R$9.50\n"
        "19. Coco             - R$3.50\n"
        "20. Laranja Pera     - R$9.00\n"
        "21. Carambola        - R$25.00\n"
        "22. Amora            - R$22.00\n"
        "23. Caqui Fuyu       - R$8.00\n"
        "24. Limao Taiti      - R$4.50\n"
        "25. Limao Siciliano  - R$11.00\n"
        "26. Tomate           - R$5.60\n"
        "27. Alface           - R$3.50\n"
        "28. Abobora          - R$7.00\n"
        "29. Abobora Manteiga - R$11.70\n"
        "30. Pepino Comum     - R$12.00\n"
        "31. Pepino Japones   - R$10.00\n"
        "32. Cheiro Verde     - R$2.00\n"
        "33. Cebolinha        - R$4.50\n"
        "34. Chuchu           - R$10.00\n"
        "35. Cenoura          - R$4.50\n"
        "36. Batata Comum     - R$8.00\n"
        "37. Batata Asterix   - R$15.00\n"
        "38. Batata Doce      - R$9.00\n"
        "39. Cebola           - R$6.00\n"
        "40. Pimenta          - R$16.90\n"
        "0.  Sair\n"
        "Digite a opcao: \n");
        scanf("%d", &escolha);
        limpandoBuffer(); 


    if (escolha >= 1 && escolha <= 40) // perguntará a quantidade desejada se a entrada for válida (1 - 40)
    {
        printf("Quantas unidades de %s voce deseja? ", frutas[escolha - 1].nome);
        scanf("%d", &quantidade_frutas[escolha - 1]);// começa a partir do 1
        limpandoBuffer();
    }
    } while (escolha !=0); // repete até a escolha ser 0 (e sair) 

    FILE *nota_fiscal; // cria um arquivo para nota fiscal
    char nome_arquivo[30];
    int numero_arquivo = 1; // gera um nome de arquivo sequencial

    do // loop para gerar um arquivo que ainda não exista 
    { 
        sprintf(nome_arquivo, "c:/cproject/PIM/output/nota_fiscal%d.txt", numero_arquivo); // salva na pasta "c:/cproject/PIM/output/nota_fiscal"
        nota_fiscal = fopen(nome_arquivo, "r"); // abre o arquivo para leitura

        if (nota_fiscal != NULL)
        {
            fclose(nota_fiscal);
            numero_arquivo++; //se houver um arquivo com esse nome, ele incrementa 1
        }
    } while(nota_fiscal != NULL); 

    // abre o arquivo para escrita
    nota_fiscal = fopen(nome_arquivo, "w");
    if (nota_fiscal == NULL) 
    {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }
    
    // saída na nota fiscal
    fprintf(nota_fiscal, "\nNota Fiscal:\n");
    fprintf(nota_fiscal, "-----------------------------------------------------------------\n");
    fprintf(nota_fiscal, "|  Produto     | Quantidade | Preco Unitario |   Total |\n");
    fprintf(nota_fiscal, "-----------------------------------------------------------------\n");

    // pega todos os dados para colocar na nota fiscal
    for (int i = 0; i < 40; i++) {
        if (quantidade_frutas[i] > 0) 
        {
            float total_fruta = quantidade_frutas[i] * frutas[i].preco;
            fprintf(nota_fiscal, "| %-17s | %10d | R$ %-11.2f | R$ %-8.2f |\n", 
                    frutas[i].nome, quantidade_frutas[i], frutas[i].preco, total_fruta);
            valor_total += total_fruta; // adiciona ao valor total
        }
    }

    fprintf(nota_fiscal, "-----------------------------------------------------------------\n");
    fprintf(nota_fiscal, "Valor Total da Compra: R$ %.2f\n", valor_total); 
    fprintf(nota_fiscal, "-----------------------------------------------------------------\n");

    fclose(nota_fiscal); // fecha o arquivo após a gravação
    printf("Nota fiscal salva com sucesso em '%s'.\n", nome_arquivo);
    return 1;

};