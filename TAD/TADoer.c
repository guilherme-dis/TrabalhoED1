#include "TADoer.h"
//#include "TQueue.h"
#include <stdio.h>

matriz *read_file_txt(char nome[])
{
    FILE *file;              //Abre o arquivo, e o chama de file
    file = fopen(nome, "r"); //Aqui abre o arquivo passado como parâmetro.
    if (file == NULL)
    {
        //printf("Error, file not found!");
        return NULL;
    }
    //Aqui ta testando quantas linhas tem o arquivo.
    char c;
    int nLinha = 1, nColuna = 0;

    while (!feof(file))
    {
        c = fgetc(file);
        if (c == '\n')
        {
            nLinha++;
        }
    }
    rewind(file); //Para voltar o arquivo ao início.
    //Agora calcula quantas colunas tem
    int aux;

    while (!feof(file))
    {
        fscanf(file, "%d", &aux);
        nColuna++;
    }
    nColuna /= nLinha; //Pego quantos itens tem dentro do texto, e divido pelo numero de linhas, assim me resulta o número de colunas.

    matriz *mat = matriz_create(nLinha, nColuna);
    if (mat == NULL)
    {
        //printf("Não foi possível fazer a alocação da matriz.");
        return NULL;
    }
    rewind(file); //Para voltar o arquivo ao início.

    int aux2 = 0;
    while (!feof(file))
    {
        for (int i = 0; i < nLinha; i++)
        {
            for (int j = 0; j < nColuna; j++)
            {
                fscanf(file, "%d", &aux2);   //Pega os valores do txt
                matriz_set(mat, i,j, aux2); //E joga para dentro da matriz
            }
        }
    }

    fclose(file);
    return mat;
}

matriz *read_file_imm(char name[])
{
    FILE *file;               //Declara o file com o tipo de arquivo.
    file = fopen(name, "rb"); //Aqui abre o arquivo passado como parâmetro.
    if (file == NULL)         //Se o arquivo não for encontrado, vai retornar NULL
    {
        return NULL;
    }
    int nColuna, nLinha; //Iniciei essas váriaveis, e vou pegar do arquivo com um fread. Já é sabido quais são os tres primeiros valores do arquivo.
    fread(&nLinha, sizeof(float), 1, file);
    fread(&nColuna, sizeof(float), 1, file);
    matriz *mat = matriz_create(nLinha, nColuna); //Criando a matriz com os valores colhidos.

    if (mat == NULL) //Se não foi possível criar a matriz.
    {
        //printf("\nIt was not possible to allocate the matriz.\n");
        return NULL;
    }
    int aux = 0; //Variável auxiliar.
    for (int i = 0; i < nLinha; i++)
    {
        for (int j = 0; j < nColuna; j++)
        {
            fread(&aux, sizeof(int), 1, file); //Pega os valores do arquivo imm que é está alocado na forma de binário.
            matriz_set(mat, i,j, aux); //Essa linha pega o valor da variável aux, e joga pra dentro da matriz.
        }
    }
    fclose(file);

    return mat;
}

/* Você fala qual o nome do arquivo binario que você quer criar, e a função vai devolver o ponteiro para o arquivo.
Lembre de dar o fclose quanto terminar de usar.*/
FILE *create_file_imm(char name[])
{
    FILE *file;               //Cria o arquivo do tipo FILE
    file = fopen(name, "wb"); //Aqui abre o arquivo passando como parâmetro wb(write binario).
    if (file == NULL)         //Se o arquivo não for encontrado, vai retornar NULL
    {
        //printf("\nThe FILE created with function create_file_imm, Couldn't open!\n"); //caso o arquivo não seja encontrado.
        return NULL;
    }
    return file; //Retornando um ponteiro para o arquivo.
}
/*Você insere o ponteiro para o arquivo, o nome do arquivo, e qual vai ser o valor, do tipo inteiro, que sera cocolado dentro do arquivo*/
int write(FILE *file, char name[], int aux)
{
    file = fopen(name, "ab"); //Aqui abre o arquivo passado como parâmetro.
    if (file == NULL)         //Se o arquivo não for encontrado, vai retornar NULL
    {
        //printf("\nCan not write on file or file not found!\n"); //caso o arquivo não seja encontrado, ou haja algum problema.
        return FILE_NOT_FOUND;
    }
    fwrite(&aux, sizeof(int), 1, file); //pega o valor que o usuário pediu e coloca no arquivo
    fclose(file);
    return SUCCESS;
}