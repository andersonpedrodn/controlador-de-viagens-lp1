#pragma once
#include <vector>
#include "Transporte.h"
#include "Passageiro.h"
#include "Cidade.h"

class Viagem {
private:
    Transporte* transporte;
    std::vector<Passageiro*> passageiros;
    Cidade* origem;
    Cidade* destino;
    Viagem* proxima;
    int horasEmTransito;
    int distancia;
    bool emAndamento;
    bool concluida;

public:
    Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros,
           Cidade* origem, Cidade* destino);

    void iniciarViagem();
    void avancarHoras(int horas);
    void relatarEstado();
    bool isEmAndamento();
    bool isConcluida();
    Viagem* getProxima();
    void setProxima(Viagem* prox);
    void setDistancia(int dist);
    int getDistancia();
    Transporte* getTransporte();
    Cidade* getOrigem();
    Cidade* getDestino();
};