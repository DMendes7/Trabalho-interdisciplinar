# Descrição Geral
O Sistema de Gerenciamento de Voos é um software desenvolvido para a companhia aérea Voo Seguro. 
Ele organiza e gerencia as operações relacionadas a passageiros, tripulação, voos, assentos e reservas,
resolvendo problemas como reservas duplicadas e falta de controle sobre disponibilidade de assentos.

## **Funcionalidades**

### **1. Gerenciamento de Passageiros**
- Cadastrar novos passageiros.
- Listar passageiros existentes.
- Armazenar informações:
  - Código (único).
  - Nome.
  - Endereço.
  - Telefone.
  - Fidelidade.
  - Pontos de fidelidade.

### **2. Gerenciamento de Tripulação**
- Cadastrar novos membros.
- Listar tripulação cadastrada.
- Armazenar informações:
  - Código (único).
  - Nome.
  - Telefone.
  - Cargo (Piloto, Copiloto, Comissário).

### **3. Gerenciamento de Voos**
- Cadastrar novos voos.
- Listar voos cadastrados.
- Validar:
  - Presença de piloto e copiloto para ativar um voo.

### **4. Gerenciamento de Assentos**
- Cadastrar assentos por voo.
- Listar assentos de um voo, com status (livre/ocupado).

### **5. Reservas**
- Realizar reservas de assentos.
- Cancelar reservas, liberando assentos.

### **6. Programa de Fidelidade**
- Listar passageiros fidelizados e seus pontos.

### **7. Pesquisa**
- Pesquisar passageiros ou tripulação por código ou nome.


# Estrutura dos Arquivos
O sistema utiliza arquivos de texto para armazenar dados persistentes. Cada funcionalidade possui seu respectivo arquivo.

# Estrutura dos Arquivos
1 - passageiros.txt

    Código|Nome|Endereço|Telefone|Fidelidade|Pontos

    1|Lucas|Rua 1|12341234|1|0
    2|Mariana|Rua 2|98765432|0|0

2 - tripulacao.txt

    Código|Nome|Telefone|Cargo

    1|Trip1|12341234|Piloto
    2|Trip2|12341234|Copiloto

3 - voos.txt

    Código|Data|Hora|Destino|Piloto|Copiloto|Status|Tarifa

    1|05/12/2024|12:00|Brasilia|1|2|1|5.00

4 - assentos.txt

    Código do Voo|Número do Assento|Status

    1|1|0
    1|2|1

5 - reservas.txt

    Código do Voo|Número do Assento|Código do Passageiro
    
    1|1|101

## **Estrutura do Código**

### **1. Arquitetura**
- Funções separadas por responsabilidades:
  - Cadastro.
  - Listagem.
  - Atualização.
  - Cancelamento.
- Persistência em arquivos de texto.

### **2. Funções Principais**
#### **Menu Principal**
Exibe opções do sistema:
void menu();

