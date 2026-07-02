# Manual de Uso — Sistema Controlador de Viagens

## Iniciando o Sistema

Após compilar com `make`, execute:
```bash
./bin/controlador
```

Os dados salvos anteriormente são carregados automaticamente.

## Menu Principal
1. Cadastrar Cidade
2. Cadastrar Trajeto
3. Cadastrar Transporte
4. Cadastrar Passageiro
5. Iniciar Viagem
6. Avançar Horas
7. Relatar Estado Geral
8. Relatar Passageiros
9. Relatar Transportes
10. Viagens em Andamento
11. Cidades Mais Visitadas
12. Salvar Dados
0. Sair

## Guia de Uso

### 1. Cadastrar Cidade
Digite o nome da cidade quando solicitado.  
**Atenção:** o sistema é case-sensitive — "Natal" e "natal" são cidades diferentes.

### 2. Cadastrar Trajeto
Informe a cidade de origem, destino, tipo (`T` para Terrestre ou `A` para Aquático) e distância em km.  
**Atenção:** as cidades devem estar cadastradas antes de criar o trajeto.

### 3. Cadastrar Transporte
Informe os dados do transporte:
- Nome
- Tipo (`T` ou `A`)
- Capacidade de passageiros
- Velocidade (km/h)
- Distância entre descansos (km)
- Tempo de descanso (horas)
- Cidade atual (deve estar cadastrada)

### 4. Cadastrar Passageiro
Informe o nome e a cidade atual do passageiro (deve estar cadastrada).

### 5. Iniciar Viagem
Informe o transporte, cidade de origem, cidade de destino e os passageiros.  
O sistema calcula automaticamente o melhor caminho — mesmo sem trajeto direto entre as cidades.

### 6. Avançar Horas
Informe quantas horas deseja avançar na simulação.  
O sistema atualiza automaticamente o estado de todas as viagens em andamento.

### 7. Relatar Estado Geral
Mostra todas as viagens cadastradas e seus estados.

### 8. Relatar Passageiros
Mostra onde cada passageiro está — em uma cidade ou em trânsito.

### 9. Relatar Transportes
Mostra onde cada transporte está — em uma cidade ou em trânsito.

### 10. Viagens em Andamento
Lista apenas as viagens que estão em andamento no momento.

### 11. Cidades Mais Visitadas
Exibe o ranking de cidades por número de viagens concluídas.

### 12. Salvar Dados
Salva manualmente os dados no disco. Os dados também são salvos automaticamente ao sair (opção 0).

## Exemplo de Uso Completo

1 → Natal
1 → Mossoró
1 → Fortaleza
2 → Natal / Mossoró / T / 280
2 → Mossoró / Fortaleza / T / 380
3 → Onibus RN / T / 40 / 80 / 200 / 1 / Natal
4 → Anderson / Natal
5 → Onibus RN / Natal / Fortaleza / 1 / Anderson
6 → 5
7 → ver estado

## Limitações Conhecidas

- O sistema é case-sensitive para nomes de cidades
- Viagens em andamento não são persistidas — apenas a posição atual de passageiros e transportes é salva
- O tipo do trajeto e do transporte devem ser compatíveis (Aquático com Aquático, Terrestre com Terrestre)