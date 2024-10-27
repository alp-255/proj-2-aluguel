#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARROS 10
#define MAX_CLIENTES 5
#define MAX_LOGIN 20
#define MAX_SENHA 20

typedef struct {
    char modelo[30];
    float preco_diaria;
    int disponivel;
} Carro;

typedef struct {
    char login[MAX_LOGIN];
    char senha[MAX_SENHA];
} Cliente;

