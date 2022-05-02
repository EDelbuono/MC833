#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct com informações para cada um dos filmes
typedef struct{
    char titulo[64], genero[32], diretor[64];
    int ano, id;
} Filme;

// Função que printa todas as informações de um filme
void mostra_filme(Filme filme){
    printf("\nTitulo: %s", filme.titulo);
    printf("Genero: %s", filme.genero);
    printf("Diretor(a): %s", filme.diretor);
    printf("Ano de lancamento: %d\n", filme.ano);
}

// Função que printa o nome do filme e seu ID
void mostra_id(Filme filme){
    printf("\nID %d - %s", filme.id, filme.titulo);
}

// Mostra os comandos disponíveis ao cliente
void lista_comandos(){
    printf("Lista de comandos do streaming\nh: Lista de comandos disponiveis\n1: Cadastra um novo filme\n2: Acrescenta um novo genero em um filme\n3: Lista todos os titulos\n4: Lista todas as informacoes dos filmes de um determinado genero\n5: Lista todas as informacoes de todos os filmes\n6: Lista todas as informacoes de um determinado filme\n7: Remove um filme\nx: Fecha o streaming\n");
}

void main(){
    char comando[16];   // Comando para executar as ações
    lista_comandos();   // Mostra os comandos disponíveis ao cliente
    Filme filme[256];   // Lista com os filmes e suas informações
    int contador = 0; // Contador do número de filmes

    while(1){
        fgets(comando, 16, stdin);   // Lê o comando a ser inserido pelo usuário

        // Lista os comandos disponíveis
        if (strtok(comando," ")[0] == 'h'){
            lista_comandos();
        }

        // Cadastra um novo filme
        else if (strtok(comando," ")[0] == '1'){
            printf("\nEscreva o nome do filme:\n");
            fgets(filme[contador].titulo, 64, stdin); // Lê o nome do filme

            printf("\nEscreva o genero do filme:\n");
            fgets(filme[contador].genero, 64, stdin); // Lê o gênero do filme

            printf("\nEscreva o diretor do filme:\n");
            fgets(filme[contador].diretor, 64, stdin); // Lê o diretor do filme

            printf("\nEscreva o ano do filme:\n");
            scanf("%d", &filme[contador].ano); // Lê o ano de lançamento do filme

            filme[contador].id = contador; // Atualiza o ID do filme criado
            printf("\nNovo filme cadastrado! Seu ID eh %d\n", filme[contador].id);
            contador++;
        }

        // Acrescenta um novo genero em um filme
        else if (strtok(comando," ")[0] == '2'){

        }

        // Lista todos os títulos com seus identificadores
        else if (strtok(comando," ")[0] == '3'){
            for (int i = 0; i < contador; i++)
                mostra_id(filme[i]);
        }

        // Lista todas as informações de um determinado gênero
        else if (strtok(comando," ")[0] == '4'){

        }

        // Lista todas as informações de todos os filmes
        else if (strtok(comando," ")[0] == '5'){
            for (int i = 0; i < contador; i++)
                mostra_filme(filme[i]);
        }

        // Lista todas as informações de um determinado filme a partir do ID
        else if (strtok(comando," ")[0] == '6'){
            int identificador, id_existente = 0;
            printf("\nInsira o ID do filme\n");
            scanf("%d", &identificador);
            for (int i = 0; i < contador; i++){
                if (filme[i].id == identificador){
                    mostra_filme(filme[i]);
                    id_existente = 1; 
                }
            }
            if (id_existente == 0) // Verifica se o ID inserido realmente existe
                printf("\nNao existe um filme com esse ID\n");
        }

        // Remove um filme
        else if (strtok(comando," ")[0] == '7'){
            int identificador, id_removido = 0; // Variável para verificar se o filme a ser removido foi encontrado
            printf("\nInsira o ID do filme a ser removido\n");
            scanf("%d", &identificador);
            for (int i = 0; i < contador; i++){
                if (filme[i].id == identificador){
                    id_removido = 1;
                }
                else if (id_removido == 1){
                    filme[i-1] = filme[i];
                    filme[i-1].id--;
                }
            }
            if (id_removido == 1){
                contador--;
                printf("\nFilme removido com sucesso!\n");
            }
            else
                printf("\nNao existe um filme com esse ID\n");
        }

        // Finaliza o programa
        else if (strtok(comando," ")[0] == 'x'){
            printf("\nFechando o streaming...\n");
            exit(1);
        }
    }
}