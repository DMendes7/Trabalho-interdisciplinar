#include <stdio.h>
#include <stdlib.h>

// Declaração das funções (supondo que estejam implementadas)
void cadastrarPassageiro();
void listarPassageiros();
void cadastrarTripulacao();
void listarTripulacao();
void cadastrarVoo();
void listarVoos();
void gerenciarAssentos();
void criarReserva();
void baixaReserva();
void pesquisarPassageiroOuTripulacao();
void listarVoosPassageiro();
void consultarFidelidade();

int main() {
    int opcao;

    do {
        printf("\n--- Sistema de Gerenciamento de Voos ---\n");
        printf("1. Cadastrar Passageiro\n");
        printf("2. Listar Passageiros\n");
        printf("3. Cadastrar Tripulação\n");
        printf("4. Listar Tripulação\n");
        printf("5. Cadastrar Voo\n");
        printf("6. Listar Voos\n");
        printf("7. Gerenciar Assentos\n");
        printf("8. Criar Reserva\n");
        printf("9. Baixa em Reserva\n");
        printf("10. Pesquisa (Passageiros/Tripulação)\n");
        printf("11. Listar Voos de um Passageiro\n");
        printf("12. Consultar Programa de Fidelidade\n");
        printf("13. Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarPassageiro();
                break;
            case 2:
                listarPassageiros();
                break;
            case 3:
                cadastrarTripulacao();
                break;
            case 4:
                listarTripulacao();
                break;
            case 5:
                cadastrarVoo();
                break;
            case 6:
                listarVoos();
                break;
            case 7:
                gerenciarAssentos();
                break;
            case 8:
                criarReserva();
                break;
            case 9:
                baixaReserva();
                break;
            case 10:
                pesquisarPassageiroOuTripulacao();
                break;
            case 11:
                listarVoosPassageiro();
                break;
            case 12:
                consultarFidelidade();
                break;
            case 13:
                printf("Encerrando o sistema. Até logo!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 13);

    return 0;
}
