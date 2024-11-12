#ifndef ESTOQUE_H
#define ESTOQUE_H

typedef struct // estrutura de definição para "produtos", armazena nomes e preços, será usada para consulta dos produtos
{
    char nome[30]; // array de caracteres, nome do produto (máx 30 caracteres)
    float preco;
} Produtos;

int estoque(); // declaração da função estoque, que será definida em outro arquivo (estoque.c)
                // a função será usada para acessar os elementos do catalogo, e add ao carrinho
#endif