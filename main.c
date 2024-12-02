#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estruturas de Dados
typedef struct {
  int codigo;
  char nome[50];
  char endereco[100];
  char telefone[15];
  int fidelidade; // 0 = Não, 1 = Sim
  int pontos;
} Passageiro;

typedef struct {
  int codigo;
  char nome[50];
  char telefone[15];
  char cargo[20]; // Piloto, Copiloto, Comissário
} Tripulante;

typedef struct {
  int codigo;
  char data[11];
  char hora[6];
  char origem[50];
  char destino[50];
  char aviao[20];
  int piloto;
  int copiloto;
  int status; // 0 = Inativo, 1 = Ativo
  float tarifa;
} Voo;

typedef struct {
  int numero;
  int codigo_voo;
  int status; // 0 = Livre, 1 = Ocupado
} Assento;

typedef struct {
  int codigo_voo;
  int numero_assento;
  int codigo_passageiro;
} Reserva;

// Funções de Utilidade
void menu();
int gerarCodigo(const char *arquivo);

// Funções de CRUD
void cadastrarPassageiro();
void listarPassageiros();
void cadastrarTripulacao();
void listarTripulacao();
void cadastrarVoo();
void listarVoos();
void cadastrarAssento();
void listarAssentos();
void realizarReserva();
void baixaReserva();
void programaFidelidade();
void pesquisar();

// Geração de Código
int gerarCodigo(const char *arquivo) {
  FILE *file = fopen(arquivo, "r");
  if (!file)
    return 1; // Arquivo não existe, começa do código 1

  int codigo = 0, maiorCodigo = 0;
  while (fscanf(file, "%d|", &codigo) != EOF) {
    if (codigo > maiorCodigo)
      maiorCodigo = codigo;
    while (fgetc(file) != '\n' && !feof(file))
      ; // Avança até o final da linha
  }
  fclose(file);
  return maiorCodigo + 1;
}

// Menu Principal
void menu() {
  printf("\n========== MENU ==========\n");
  printf("1. Cadastrar Passageiro\n");
  printf("2. Listar Passageiros\n");
  printf("3. Cadastrar Tripulacao\n");
  printf("4. Listar Tripulacao\n");
  printf("5. Cadastrar Voo\n");
  printf("6. Listar Voos\n");
  printf("7. Cadastrar Assento\n");
  printf("8. Listar Assentos\n");
  printf("9. Realizar Reserva\n");
  printf("10. Baixa em Reserva\n");
  printf("11. Programa de Fidelidade\n");
  printf("12. Pesquisar\n");
  printf("13. Sair\n");
  printf("==========================\n");
}

// Cadastro de Passageiro
void cadastrarPassageiro() {
  Passageiro p;
  FILE *file = fopen("passageiros.txt", "a");
  if (!file) {
    printf("\nErro ao abrir arquivo para salvar passageiro.\n");
    return;
  }

  p.codigo = gerarCodigo("passageiros.txt");
  printf("\nNome: ");
  fgets(p.nome, sizeof(p.nome), stdin);
  strtok(p.nome, "\n");
  printf("Endereço: ");
  fgets(p.endereco, sizeof(p.endereco), stdin);
  strtok(p.endereco, "\n");
  printf("Telefone: ");
  fgets(p.telefone, sizeof(p.telefone), stdin);
  strtok(p.telefone, "\n");
  printf("Fidelidade (0 = Não, 1 = Sim): ");
  scanf("%d", &p.fidelidade);
  getchar();
  p.pontos = 0;

  fprintf(file, "%d|%s|%s|%s|%d|%d\n", p.codigo, p.nome, p.endereco, p.telefone,
          p.fidelidade, p.pontos);
  fclose(file);
  printf("\nPassageiro cadastrado com sucesso!\n");
}

// Listar Passageiros
void listarPassageiros() {
  FILE *file = fopen("passageiros.txt", "r");
  if (!file) {
    printf("\nNenhum passageiro cadastrado.\n");
    return;
  }

  Passageiro p;
  printf("\n========== Passageiros Cadastrados ==========\n");
  while (fscanf(file, "%d|%49[^|]|%99[^|]|%14[^|]|%d|%d\n", &p.codigo, p.nome,
                p.endereco, p.telefone, &p.fidelidade, &p.pontos) != EOF) {
    printf("\nCódigo: %d\nNome: %s\nEndereço: %s\nTelefone: %s\nFidelidade: "
           "%d\nPontos: %d\n",
           p.codigo, p.nome, p.endereco, p.telefone, p.fidelidade, p.pontos);
  }
  fclose(file);
}

// Cadastro de Tripulação
void cadastrarTripulacao() {
  Tripulante t;
  FILE *file = fopen("tripulacao.txt", "a");
  if (!file) {
    printf("\nErro ao abrir arquivo para salvar tripulante.\n");
    return;
  }

  t.codigo = gerarCodigo("tripulacao.txt");
  printf("\nNome: ");
  fgets(t.nome, sizeof(t.nome), stdin);
  strtok(t.nome, "\n");
  printf("Telefone: ");
  fgets(t.telefone, sizeof(t.telefone), stdin);
  strtok(t.telefone, "\n");
  printf("Cargo (Piloto, Copiloto, Comissario): ");
  fgets(t.cargo, sizeof(t.cargo), stdin);
  strtok(t.cargo, "\n");

  fprintf(file, "%d|%s|%s|%s\n", t.codigo, t.nome, t.telefone, t.cargo);
  fclose(file);
  printf("\nTripulante cadastrado com sucesso!\n");
}

// Listar Tripulação
void listarTripulacao() {
  FILE *file = fopen("tripulacao.txt", "r");
  if (!file) {
    printf("\nNenhuma tripulação cadastrada.\n");
    return;
  }

  Tripulante t;
  printf("\n========== Tripulantes Cadastrados ==========\n");
  while (fscanf(file, "%d|%49[^|]|%14[^|]|%19[^\n]\n", &t.codigo, t.nome,
                t.telefone, t.cargo) != EOF) {
    printf("\nCódigo: %d\nNome: %s\nTelefone: %s\nCargo: %s\n", t.codigo,
           t.nome, t.telefone, t.cargo);
  }
  fclose(file);
}

// Cadastro de Voo
void cadastrarVoo() {
  Voo v;
  FILE *file = fopen("voos.txt", "a");
  if (!file) {
    printf("\nErro ao abrir arquivo para salvar voo.\n");
    return;
  }

  v.codigo = gerarCodigo("voos.txt");
  printf("\nData (dd/mm/aaaa): ");
  fgets(v.data, sizeof(v.data), stdin);
  strtok(v.data, "\n");
  printf("Hora (hh:mm): ");
  fgets(v.hora, sizeof(v.hora), stdin);
  strtok(v.hora, "\n");
  printf("Origem: ");
  fgets(v.origem, sizeof(v.origem), stdin);
  strtok(v.origem, "\n");
  printf("Destino: ");
  fgets(v.destino, sizeof(v.destino), stdin);
  strtok(v.destino, "\n");
  printf("Piloto (Código): ");
  scanf("%d", &v.piloto);
  printf("Copiloto (Código): ");
  scanf("%d", &v.copiloto);
  printf("Tarifa: ");
  scanf("%f", &v.tarifa);
  getchar();

  v.status = (v.piloto > 0 && v.copiloto > 0) ? 1 : 0;

  fprintf(file, "%d|%s|%s|%s|%s|%d|%d|%d|%.2f\n", v.codigo, v.data, v.hora,
          v.origem, v.destino, v.piloto, v.copiloto, v.status, v.tarifa);
  fclose(file);
  printf("\nVoo cadastrado com sucesso!\n");
}

// Listar Voos
void listarVoos() {
  FILE *file = fopen("voos.txt", "r");
  if (!file) {
    printf("\nNenhum voo cadastrado.\n");
    return;
  }

  Voo v;
  printf("\n========== Voos Cadastrados ==========\n");
  while (fscanf(file, "%d|%10[^|]|%5[^|]|%49[^|]|%49[^|]|%d|%d|%d|%f\n",
                &v.codigo, v.data, v.hora, v.origem, v.destino, &v.piloto,
                &v.copiloto, &v.status, &v.tarifa) != EOF) {
    printf("\nCódigo: %d\nData: %s\nHora: %s\nOrigem: %s\nDestino: %s\nPiloto: "
           "%d\nCopiloto: %d\nStatus: %d\nTarifa: %.2f\n",
           v.codigo, v.data, v.hora, v.origem, v.destino, v.piloto, v.copiloto,
           v.status, v.tarifa);
  }
  fclose(file);
}

void cadastrarAssento() {
  Assento a;
  FILE *file = fopen("assentos.txt", "a");
  if (!file) {
    printf("\nErro ao abrir arquivo para salvar assento.\n");
    return;
  }

  printf("\nCadastro de Assento");
  printf("\nCódigo do Voo: ");
  scanf("%d", &a.codigo_voo);
  printf("Número do Assento: ");
  scanf("%d", &a.numero);
  a.status = 0; // Livre

  fprintf(file, "%d|%d|%d\n", a.codigo_voo, a.numero, a.status);
  fclose(file);
  printf("\nAssento cadastrado com sucesso!\n");
}

void listarAssentos() {
  int codigo_voo;
  printf("\nDigite o código do voo para listar os assentos: ");
  scanf("%d", &codigo_voo);

  FILE *file = fopen("assentos.txt", "r");
  if (!file) {
    printf("\nNenhum assento cadastrado.\n");
    return;
  }

  Assento a;
  printf("\n========== Assentos do Voo %d ==========\n", codigo_voo);
  int encontrado = 0;
  while (fscanf(file, "%d|%d|%d\n", &a.codigo_voo, &a.numero, &a.status) !=
         EOF) {
    if (a.codigo_voo == codigo_voo) {
      printf("\nAssento: %d\nStatus: %s\n", a.numero,
             a.status == 0 ? "Livre" : "Ocupado");
      encontrado = 1;
    }
  }
  fclose(file);
  if (!encontrado) {
    printf("\nNenhum assento encontrado para este voo.\n");
  }
}

void realizarReserva() {
  int codigo_voo, numero_assento, codigo_passageiro;
  printf("\nRealizar Reserva");
  printf("\nCódigo do Voo: ");
  scanf("%d", &codigo_voo);
  printf("Número do Assento: ");
  scanf("%d", &numero_assento);
  printf("Código do Passageiro: ");
  scanf("%d", &codigo_passageiro);

  FILE *file = fopen("assentos.txt", "r");
  if (!file) {
    printf("\nErro ao abrir o arquivo de assentos.\n");
    return;
  }

  FILE *tempFile = fopen("assentos_temp.txt", "w");
  if (!tempFile) {
    printf("\nErro ao criar arquivo temporário.\n");
    fclose(file);
    return;
  }

  Assento a;
  int encontrado = 0;

  // Lê os registros, alterando o status do assento se for encontrado
  while (fscanf(file, "%d|%d|%d\n", &a.codigo_voo, &a.numero, &a.status) !=
         EOF) {
    if (a.codigo_voo == codigo_voo && a.numero == numero_assento) {
      if (a.status == 1) {
        printf("\nErro: O assento já está reservado!\n");
        encontrado = 1;
      } else {
        a.status = 1; // Marca o assento como ocupado
        encontrado = 1;
      }
    }
    fprintf(tempFile, "%d|%d|%d\n", a.codigo_voo, a.numero, a.status);
  }

  fclose(file);
  fclose(tempFile);

  // Substitui o arquivo original pelo temporário
  remove("assentos.txt");
  rename("assentos_temp.txt", "assentos.txt");

  if (!encontrado) {
    printf("\nErro: Assento não encontrado no voo especificado!\n");
    return;
  }

  // Salva a reserva no arquivo de reservas
  FILE *reservas = fopen("reservas.txt", "a");
  if (!reservas) {
    printf("\nErro ao salvar reserva.\n");
    return;
  }
  fprintf(reservas, "%d|%d|%d\n", codigo_voo, numero_assento,
          codigo_passageiro);
  fclose(reservas);

  printf("\nReserva realizada com sucesso!\n");
}

void baixaReserva() {
  int codigo_voo, numero_assento;
  printf("\nCancelar Reserva");
  printf("\nCódigo do Voo: ");
  scanf("%d", &codigo_voo);
  printf("Número do Assento: ");
  scanf("%d", &numero_assento);

  FILE *file = fopen("assentos.txt", "r+");
  if (!file) {
    printf("\nErro ao abrir arquivo de assentos.\n");
    return;
  }

  Assento a;
  int encontrado = 0;
  while (fscanf(file, "%d|%d|%d\n", &a.codigo_voo, &a.numero, &a.status) !=
         EOF) {
    if (a.codigo_voo == codigo_voo && a.numero == numero_assento) {
      if (a.status == 0) {
        printf("\nErro: Assento já está livre!\n");
        fclose(file);
        return;
      }
      a.status = 0; // Livre
      fseek(file, -sizeof(Assento), SEEK_CUR);
      fprintf(file, "%d|%d|%d\n", a.codigo_voo, a.numero, a.status);
      encontrado = 1;
      break;
    }
  }
  fclose(file);

  if (!encontrado) {
    printf("\nErro: Assento não encontrado!\n");
    return;
  }

  printf("\nReserva cancelada com sucesso!\n");
}

void programaFidelidade() {
  FILE *file = fopen("passageiros.txt", "r");
  if (!file) {
    printf("\nNenhum passageiro cadastrado.\n");
    return;
  }

  Passageiro p;
  printf("\n========== Programa de Fidelidade ==========\n");
  while (fscanf(file, "%d|%49[^|]|%99[^|]|%14[^|]|%d|%d\n", &p.codigo, p.nome,
                p.endereco, p.telefone, &p.fidelidade, &p.pontos) != EOF) {
    if (p.fidelidade == 1) {
      printf("\nCódigo: %d\nNome: %s\nPontos: %d\n", p.codigo, p.nome,
             p.pontos);
    }
  }
  fclose(file);
}

void pesquisar() {
  int opcao;
  printf("\nPesquisar");
  printf("\n1. Passageiro");
  printf("\n2. Tripulante");
  printf("\nEscolha uma opção: ");
  scanf("%d", &opcao);
  getchar(); // Limpar buffer

  if (opcao == 1) {
    FILE *file = fopen("passageiros.txt", "r");
    if (!file) {
      printf("\nNenhum passageiro cadastrado.\n");
      return;
    }

    char nome[50];
    int codigo, encontrado = 0;
    printf("\nDigite o código (-1 para ignorar): ");
    scanf("%d", &codigo);
    getchar();
    printf("Digite o nome (ou deixe vazio para ignorar): ");
    fgets(nome, sizeof(nome), stdin);
    strtok(nome, "\n");

    Passageiro p;
    while (fscanf(file, "%d|%49[^|]|%99[^|]|%14[^|]|%d|%d\n", &p.codigo, p.nome,
                  p.endereco, p.telefone, &p.fidelidade, &p.pontos) != EOF) {
      if ((codigo == -1 || p.codigo == codigo) &&
          (strlen(nome) == 0 || strstr(p.nome, nome))) {
        printf("\nPassageiro encontrado:");
        printf("\nCódigo: %d\nNome: %s\nEndereço: %s\nTelefone: "
               "%s\nFidelidade: %d\nPontos: %d\n",
               p.codigo, p.nome, p.endereco, p.telefone, p.fidelidade,
               p.pontos);
        encontrado = 1;
      }
    }
    fclose(file);
    if (!encontrado)
      printf("\nNenhum passageiro encontrado.\n");
  } else if (opcao == 2) {
    FILE *file = fopen("tripulacao.txt", "r");
    if (!file) {
      printf("\nNenhum tripulante cadastrado.\n");
      return;
    }

    char nome[50];
    int codigo, encontrado = 0;
    printf("\nDigite o código (-1 para ignorar): ");
    scanf("%d", &codigo);
    getchar();
    printf("Digite o nome (ou deixe vazio para ignorar): ");
    fgets(nome, sizeof(nome), stdin);
    strtok(nome, "\n");

    Tripulante t;
    while (fscanf(file, "%d|%49[^|]|%14[^|]|%19[^\n]\n", &t.codigo, t.nome,
                  t.telefone, t.cargo) != EOF) {
      if ((codigo == -1 || t.codigo == codigo) &&
          (strlen(nome) == 0 || strstr(t.nome, nome))) {
        printf("\nTripulante encontrado:");
        printf("\nCódigo: %d\nNome: %s\nTelefone: %s\nCargo: %s\n", t.codigo,
               t.nome, t.telefone, t.cargo);
        encontrado = 1;
      }
    }
    fclose(file);
    if (!encontrado)
      printf("\nNenhum tripulante encontrado.\n");
  } else {
    printf("\nOpção inválida!\n");
  }
}

int main() {
  int opcao;
  do {
    menu();
    printf("\nEscolha uma opção: ");
    scanf("%d", &opcao);
    getchar();

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
      cadastrarAssento();
      break;
    case 8:
      listarAssentos();
      break;
    case 9:
      realizarReserva();
      break;
    case 10:
      baixaReserva();
      break;
    case 11:
      programaFidelidade();
      break;
    case 12:
      pesquisar();
      break;
    case 13:
      printf("\nEncerrando o sistema. Até logo!\n");
      break;
    default:
      printf("\nOpção inválida! Tente novamente.\n");
    }
  } while (opcao != 13);

  return 0;
}