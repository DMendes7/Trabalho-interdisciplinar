# **Casos de Teste - Sistema de Gerenciamento de Voos**

Este documento descreve os casos de teste do **Sistema de Gerenciamento de Voos**. Cada teste cobre uma funcionalidade específica para verificar a conformidade com os requisitos.

---

## **Casos de Teste**

### **Caso de Teste 1: Cadastro de Passageiro**
- **Objetivo:** Garantir que o sistema cadastra corretamente um passageiro.
- **Entrada:**
  - Nome: "Lucas"
  - Endereço: "Rua 1"
  - Telefone: "12341234"
  - Fidelidade: `1`
- **Procedimento:**
  1. Execute o programa.
  2. Escolha a opção de cadastrar passageiro.
  3. Insira os dados mencionados.
  4. Verifique o arquivo `passageiros.txt`.
- **Saída Esperada:**  
  O arquivo `passageiros.txt` deve conter a seguinte linha:
  1|Lucas|Rua 1|12341234|1|0
  
### **Caso de Teste 2: Listar Passageiros**
- **Objetivo:** Verificar que a listagem de passageiros apresenta os dados corretamente.
- **Entrada:**  
    O arquivo `passageiros.txt` deve conter:
    1|Lucas|Rua 1|12341234|1|0

- **Procedimento:**
1. Execute o programa.
2. Escolha a opção de listar passageiros.
3. Observe a saída na tela.
- **Saída Esperada:**
Código: 1 Nome: Lucas Endereço: Rua 1 Telefone: 12341234 Fidelidade: 1 Pontos: 0

### **Caso de Teste 3: Cadastro de Voo**
- **Objetivo:** Garantir que o sistema cadastra voos corretamente.
- **Entrada:**
- Data: "05/12/2024"
- Hora: "12:00"
- Destino: "Brasilia"
- Piloto: `1`
- Copiloto: `2`
- Tarifa: `5.00`
- **Procedimento:**
1. Execute o programa.
2. Escolha a opção de cadastrar voo.
3. Insira os dados mencionados.
4. Verifique o arquivo `voos.txt`.
- **Saída Esperada:**  
O arquivo `voos.txt` deve conter a seguinte linha:
1|05/12/2024|12:00|Brasilia|1|2|1|5.00

### **Caso de Teste 4: Listar Voos**
- **Objetivo:** Verificar que a listagem de voos apresenta os dados corretamente.
- **Entrada:**  
O arquivo `voos.txt` deve conter:
1|05/12/2024|12:00|Brasilia|1|2|1|5.00

- **Procedimento:**
1. Execute o programa.
2. Escolha a opção de listar voos.
3. Observe a saída na tela.
- **Saída Esperada:**
Código: 1 Data: 05/12/2024 Hora: 12:00 Destino: Brasilia Piloto: 1 Copiloto: 2 Status: 1 Tarifa: 5.00

### **Caso de Teste 5: Cadastro de Assento**
- **Objetivo:** Garantir que o sistema cadastra corretamente os assentos de um voo.
- **Entrada:**
- Código do Voo: `1`
- Número do Assento: `1`
- **Procedimento:**
1. Execute o programa.
2. Escolha a opção de cadastrar assento.
3. Insira os dados mencionados.
4. Verifique o arquivo `assentos.txt`.
- **Saída Esperada:**  
O arquivo `assentos.txt` deve conter a seguinte linha:
1|1|0

### **Caso de Teste 6: Realizar Reserva**
- **Objetivo:** Garantir que o sistema realiza reservas corretamente.
- **Entrada:**
- Código do Voo: `1`
- Número do Assento: `1`
- Código do Passageiro: `1`
- **Procedimento:**
1. Execute o programa.
2. Escolha a opção de realizar reserva.
3. Insira os dados mencionados.
4. Verifique os arquivos `assentos.txt` e `reservas.txt`.
- **Saída Esperada:**
- `assentos.txt`:
  ```
  1|1|1
  ```
- `reservas.txt`:
  ```
  1|1|1
  ```

### **Caso de Teste 7: Fidelidade**
- **Objetivo:** Garantir que os pontos de fidelidade são atualizados corretamente após uma reserva.
- **Entrada:**
- Passageiro cadastrado: `1|Lucas|Rua 1|12341234|1|0`
- Reserva realizada: `1|1|1`
- **Procedimento:**
1. Execute o programa.
2. Escolha a opção de listar programa de fidelidade.
3. Verifique os pontos acumulados do passageiro.
- **Saída Esperada:**  
Código: 1 Nome: Lucas Pontos: 10

### **Caso de Teste 8: Pesquisa de Passageiro**
- **Objetivo:** Verificar se a pesquisa de passageiros funciona corretamente.
- **Entrada:**  
O arquivo `passageiros.txt` deve conter:
1|Lucas|Rua 1|12341234|1|0

- **Procedimento:**
1. Execute o programa.
2. Escolha a opção de pesquisar passageiros.
3. Insira o nome "Lucas".
- **Saída Esperada:**  
Código: 1 Nome: Lucas Endereço: Rua 1 Telefone: 12341234 Fidelidade: 1 Pontos: 0

## **Conclusão**

Estes casos de teste garantem que as funcionalidades principais do sistema estão funcionando corretamente. 