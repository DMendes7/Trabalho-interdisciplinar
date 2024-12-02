#include <stdio.h>
#include <stdlib.h>

// Declaração das funções (implementações são assumidas)
void cadastrarPassageiro();
void listarPassageiros();
void cadastrarTripulacao();
void listarTripulacao();
void cadastrarVoo();
void listarVoos();
void gerenciarAssentos();
void criarReserva();
void baixaReserva();
void listarVoosPassageiro();
void consultarFidelidade();

// Função para exibir o submenu Passageiro
void menuPassageiro() {
    int opcao;
    do {
        printf("\n--- Menu Passageiro ---\n");
        printf("1. Cadastrar Passageiro\n");
        printf("2. Listar Passageiros\n");
        printf("3. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarPassageiro();
                break;
            case 2:
                listarPassageiros();
                break;
            case 3:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);
}

// Função para exibir o submenu Tripulação
void menuTripulacao() {
    int opcao;
    do {
        printf("\n--- Menu Tripulação ---\n");
        printf("1. Cadastrar Tripulação\n");
        printf("2. Listar Tripulação\n");
        printf("3. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTripulacao();
                break;
            case 2:
                listarTripulacao();
                break;
            case 3:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);
}

// Função para exibir o submenu Voo
void menuVoo() {
    int opcao;
    do {
        printf("\n--- Menu Voo ---\n");
        printf("1. Cadastrar Voo\n");
        printf("2. Listar Voos\n");
        printf("3. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarVoo();
                break;
            case 2:
                listarVoos();
                break;
            case 3:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);
}

// Função principal com o menu principal
int main() {
    int opcao;

    do {
        printf("\n--- Sistema de Gerenciamento de Voos ---\n");
        printf("1. Menu Passageiro\n");
        printf("2. Menu Tripulação\n");
        printf("3. Menu Voo\n");
        printf("4. Gerenciar Assentos\n");
        printf("5. Reservas\n");
        printf("6. Listar Voos de um Passageiro\n");
        printf("7. Consultar Programa de Fidelidade\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuPassageiro();
                break;
            case 2:
                menuTripulacao();
                break;
            case 3:
                menuVoo();
                break;
            case 4:
                gerenciarAssentos();
                break;
            case 5: {
                int subopcao;
                do {
                    printf("\n--- Menu Reservas ---\n");
                    printf("1. Criar Reserva\n");
                    printf("2. Baixar Reserva\n");
                    printf("3. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &subopcao);

                    switch (subopcao) {
                        case 1:
                            criarReserva();
                            break;
                        case 2:
                            baixaReserva();
                            break;
                        case 3:
                            printf("Voltando ao menu principal...\n");
                            break;
                        default:
                            printf("Opção inválida! Tente novamente.\n");
                    }
                } while (subopcao != 3);
                break;
            }
            case 6:
                listarVoosPassageiro();
                break;
            case 7:
                consultarFidelidade();
                break;
            case 8:
                printf("Encerrando o sistema. Até logo!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
}
