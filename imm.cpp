#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD/TMat2D.h"  //TAD da matriz
#include "TAD/TQueue.h"  //TAD da fila
#include "TAD/TADoer.h"  //TAD da leitura e escrita
#include "TAD/TADmain.h" //TAD das funções principais
//Definir a quantidade da entrada de arquivos para cada função, na função cc, só entra com 5 parametros por exemplo
    //-open
    //-convert
    //-segment
    //-cc
    //-lab
int main(int argc, char *argv[])
{
    //Aqui faz a verificação se os argumentos de entrada na linha de comando são menores que 2;
    if (argc < 2)
    {
        printf("Error, missing parameter!\n");
        return 0;
    }
    //Caso o primeiro argumento seja igual a -open
    if (strcmp(argv[1], "-open") == 0)
    {
        char *check;                    //Variável utilizada para saber a extensão do arquivo.
        check = strstr(argv[2], ".");   //Joga para dentro do check, todo o texto depois do ".", incluindo o mesmo, por exemplo ".txt"
        if (strcmp(check, ".txt") == 0) //Verifica se o check é igual a .txt
        {

            matriz *mat = read_file_txt(argv[2]);
            matriz_print(mat); //Essa função vai imprimir na tela a matriz.       //Fecha o arquivo.
            
            matriz_free(mat);  //Desaloca da memória a matriz
        }

        else if (strcmp(check, ".imm") == 0)
        {
            matriz *mat = read_file_imm(argv[2]);
            matriz_print(mat); //Imprimindo a matriz.
            matriz_free(mat);
        }
        else //Caso a opção "-open" seja escolhida, mas não tenha achado a extensão.
        {
            printf("\nfile extension not found or not suported!\n");
            exit(1);
        }
    }
    
    else if (strcmp(argv[1], "-convert") == 0)
    {

        if (argc != 4)
        {
            printf("Not enough arguments!");
            exit(1);
        }
        char *check, *check2; //Variável utilizada para saber a extensão do arquivo.
        check2 = strstr(argv[3], ".");
        check = strstr(argv[2], ".");                                  //Joga para dentro do check, todo o texto depois do ".", incluindo o mesmo, por exemplo ".txt"
        if (strcmp(check, ".txt") == 0 && strcmp(check2, ".imm") == 0) //Verifica se o check é igual a .txt
        {

            int res; //Só para verificar o resultado.
            res = convert(argv[2], argv[3]);
            if (res == 1)
            {
                printf("Conversão feita com sucesso!");
            }
        }
        else
        {
            printf("O formato dos arquivos não são os especificados, TXT e IMM respectivamente.");
        }
        return 0;
    }
    //ferificar o thr se é maior que o profundidade, se for maior, retorna erro
    else if (strcmp(argv[1], "-segment") == 0)
    { //verificar quantos argumentos tem
        if (argc != 5)
        {
            printf("SEM argumentos suficientes");
            exit(1);
        }
        char *check, *check2; //Variável utilizada para saber a extensão do arquivo.
        check = strstr(argv[3], ".");
        check2 = strstr(argv[4], ".");
        //Joga para dentro do check, todo o texto depois do ".", incluindo o mesmo, por exemplo ".txt"
        if (strcmp(check, ".imm") == 0 && strcmp(check2, ".imm") == 0) //Verifica se o check é igual a .txt
        {

            int res; //Só para verificar o resultado.

            int thr = atoi(argv[2]);
            res = segment(thr, argv[3], argv[4]);
            if (res == 1)
            {
                printf("Segment feito com sucesso!");
            }
            else
            {

                printf("Deu falha no segment");
            }
        }
        else
        {
            printf("O formato dos arquivos não são os especificados, IMM e IMM respectivamente.");
        }

        return 0;
    }
    
    else if (strcmp(argv[1], "-cc") == 0)
    {
        if (argc != 4)
        {
            printf("SEM argumentos suficientes");
            exit(1);
        }
        char *check, *check2; //Variável utilizada para saber a extensão do arquivo.
        check2 = strstr(argv[3], ".");
        check = strstr(argv[2], ".");                                  //Joga para dentro do check, todo o texto depois do ".", incluindo o mesmo, por exemplo ".txt"
        if (strcmp(check, ".imm") == 0 && strcmp(check2, ".imm") == 0) //Verifica se o check é igual a .txt
        {

            int resposta = cc(argv[2], argv[3]);
            if (resposta == SUCCESS)
            {
                printf("Componentes conexos concluidos.!");
            }
            else
            {
                printf("Ocorreu algum erro!");
            }
        }
        else
        {

            printf("O formato dos arquivos não são os especificados, IMM e IMM respectivamente.");
        }
    }
    
    else if (strcmp(argv[1], "-lab") == 0)
    {
        if (argc != 4)
        {
            printf("SEM argumentos suficientes");
            exit(1);
        }
        int resposta = lab(argv[2], argv[3]);
        if (resposta == SUCCESS)
        {
            printf("Labirinto encontrado.!\nO arquivo chama outlab, use o -open para abrir!");
        }
        else
        {
            printf("algum problema deu");
        }
    }
    else
    {
        printf("Opção não Existente.");
        exit(1);
    }
    return 0;
}