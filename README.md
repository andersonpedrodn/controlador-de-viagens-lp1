# Sistema Controlador de Viagens

Projeto da disciplina Linguagem de Programação 1 - UFRN/IMD  
Professor: Isaac Franco Fernandes

## Descrição

Sistema desenvolvido em C++ para gerenciar o tráfego entre cidades, considerando diferentes tipos de trajeto e meios de transporte. O sistema permite o cadastro de cidades, trajetos, transportes e passageiros, além de calcular e simular viagens entre as cidades.

## Funcionalidades

- Cadastro de cidades, trajetos, transportes e passageiros
- Cálculo automático do melhor trajeto entre cidades (algoritmo BFS)
- Suporte a viagens com conexão (múltiplas cidades intermediárias)
- Simulação de viagens com avanço de horas
- Relatórios de passageiros, transportes, viagens e cidades mais visitadas
- Persistência de dados em arquivos de texto

## Estrutura do Projeto

controlador-de-viagens-lp1/
├── include/          # Headers das classes (.h)
│   ├── Cidade.h
│   ├── Trajeto.h
│   ├── Transporte.h
│   ├── Passageiro.h
│   ├── Viagem.h
│   └── ControladorDeTransito.h
├── src/              # Implementações (.cpp)
│   ├── Cidade.cpp
│   ├── Trajeto.cpp
│   ├── Transporte.cpp
│   ├── Passageiro.cpp
│   ├── Viagem.cpp
│   ├── ControladorDeTransito.cpp
│   └── main.cpp
├── data/             # Arquivos de persistência
├── docs/             # Documentação
│   └── manual.md
└── Makefile

## Como Compilar e Executar

### Pré-requisitos
- g++ com suporte a C++17
- make

### Compilar
```bash
make
```

### Executar
```bash
./bin/controlador
```

### Limpar binários
```bash
make clean
```

## Tecnologias Utilizadas

- C++17
- Algoritmo BFS para cálculo de rotas
- Persistência em arquivos .txt

## Autor

Anderson Pedro do Nascimento
Universidade Federal do Rio Grande do Norte - UFRN/IMD