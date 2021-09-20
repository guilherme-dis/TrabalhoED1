#ifndef _TADoer_
#define _TADoer_
#include "TMat2D.h"
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define FILE_NOT_FOUND -5
#define MATRIZ_NOT_ALlOCATED -6

matriz *read_file_txt(char name[]);//Função que vai ler arquivos txt
matriz *read_file_imm(char name[]);//Função que le arquivos binarios do tipo imm
FILE *create_file_imm(char name[]);//Essa função cria um arquivo binario e devolve o ponteiro para o arquivo criado
int write(FILE *file, char name[], int aux);//Essa função escreve dados do tipo inteiro para o arquivo binario.

#endif