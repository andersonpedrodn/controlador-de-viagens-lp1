#pragma once
#include <string>
#include "Cidade.h"

class Transporte {
private:
    std::string nome;
    char tipo; 
    int capacidade;
    int velocidade; 
    int distanciaEntreDescansos; 
    int tempoDeDescanso; 
    int tempoDeDescansoAtual; 
    Cidade* localAtual;

public:
    Transporte(std::string nome, char tipo, int capacidade, int velocidade,
               int distanciaEntreDescansos, int tempoDeDescanso, Cidade* localAtual);

    std::string getNome();
    char getTipo();
    int getCapacidade();
    int getVelocidade();
    int getDistanciaEntreDescansos();
    int getTempoDescanso();
    int getTempoDescansoAtual();
    Cidade* getLocalAtual();
    void setLocalAtual(Cidade* local);
};