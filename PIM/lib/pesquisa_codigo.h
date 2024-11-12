#ifndef PESQUISA_CODIGO_H 
#define PESQUISA_CODIGO_H

typedef struct // estrutura de definição chamada "pesquisa", armazena informações dos produtos (nome e preço) 
{                       // para consultá-los depois
    char nome[30]; // array de caracteres, nome do produto (máx 30 caracteres)
    float preco; 
} Pesquisa;

int pesquisar(); // declaração da função pesquisar, que será definida em outro arquivo (pesquisa_codigo.c)
                // a função será responsável pela pesquisa de produtos no catálogo.
#endif 