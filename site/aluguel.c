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

void inicializar_carros() {
    strcpy(carros[0].modelo, "Fusca");
    carros[0].preco_diaria = 50.0;
    carros[0].disponivel = 1;

    strcpy(carros[1].modelo, "Civic");
    carros[1].preco_diaria = 100.0;
    carros[1].disponivel = 1;

    strcpy(carros[2].modelo, "Palio");
    carros[2].preco_diaria = 70.0;
    carros[2].disponivel = 1;

    strcpy(carros[3].modelo, "Gol");
    carros[3].preco_diaria = 60.0;
    carros[3].disponivel = 1;

    strcpy(carros[4].modelo, "Fiesta");
    carros[4].preco_diaria = 80.0;
    carros[4].disponivel = 1;

    strcpy(carros[5].modelo, "Celta");
    carros[5].preco_diaria = 55.0;
    carros[5].disponivel = 1;

    strcpy(carros[6].modelo, "HB20");
    carros[6].preco_diaria = 90.0;
    carros[6].disponivel = 1;

    strcpy(carros[7].modelo, "Onix");
    carros[7].preco_diaria = 85.0;
    carros[7].disponivel = 1;

    strcpy(carros[8].modelo, "Sandero");
    carros[8].preco_diaria = 75.0;
    carros[8].disponivel = 1;

    strcpy(carros[9].modelo, "Kwid");
    carros[9].preco_diaria = 65.0;
    carros[9].disponivel = 1;
}

void inicializar_clientes() {
    strcpy(clientes[0].login, "cliente1");
    strcpy(clientes[0].senha, "senha1");
    
    strcpy(clientes[1].login, "cliente2");
    strcpy(clientes[1].senha, "senha2");

    strcpy(clientes[2].login, "cliente3");
    strcpy(clientes[2].senha, "senha3");

    strcpy(clientes[3].login, "cliente4");
    strcpy(clientes[3].senha, "senha4");

    strcpy(clientes[4].login, "cliente5");
    strcpy(clientes[4].senha, "senha5");
}

int login(Cliente *cliente) {
    char login[MAX_LOGIN], senha[MAX_SENHA];
    printf("Login: ");
    scanf("%s", login);
    printf("Senha: ");
    scanf("%s", senha);

    for (int i = 0; i < MAX_CLIENTES; i++) {
        if (strcmp(clientes[i].login, login) == 0 && strcmp(clientes[i].senha, senha) == 0) {
            *cliente = clientes[i];
            return 1;
        }
    }
    return 0;
}

void listar_carros() {
    printf("\nCarros disponíveis para aluguel:\n");
    for (int i = 0; i < MAX_CARROS; i++) {
        if (carros[i].disponivel) {
            printf("%d: %s - R$ %.2f por dia\n", i + 1, carros[i].modelo, carros[i].preco_diaria);
        }
    }
}

void alugar_carro() {
    int escolha, dias;
    listar_carros();
    printf("Escolha o carro (1-%d): ", MAX_CARROS);
    scanf("%d", &escolha);
    
    if (escolha < 1 || escolha > MAX_CARROS || !carros[escolha - 1].disponivel) {
        printf("Carro inválido ou não disponível.\n");
        return;
    }

    printf("Por quantos dias deseja alugar? ");
    scanf("%d", &dias);
    if (dias <= 0) {
        printf("Número de dias inválido.\n");
        return;
    }

    carros[escolha - 1].disponivel = 0; // Marca como alugado
    float total = carros[escolha - 1].preco_diaria * dias;
    printf("Você alugou %s por %d dias. Total: R$ %.2f\n", carros[escolha - 1].modelo, dias, total);
}
