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
    bool emAndamento;

public:
    Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros,
           Cidade* origem, Cidade* destino);

    void iniciarViagem();
    void avancarHoras(int horas);
    void relatarEstado();
    bool isEmAndamento();
    Viagem* getProxima();
    void setProxima(Viagem* prox);
    Transporte* getTransporte();
    Cidade* getOrigem();
    Cidade* getDestino();
};