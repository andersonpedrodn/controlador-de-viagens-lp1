#include "Viagem.h"
#include <iostream>

Viagem::Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros,
               Cidade* origem, Cidade* destino) {
    this->transporte = transporte;
    this->passageiros = passageiros;
    this->origem = origem;
    this->destino = destino;
    this->proxima = nullptr;
    this->horasEmTransito = 0;
    this->emAndamento = false;
}

void Viagem::iniciarViagem() {
    emAndamento = true;
    std::cout << "Viagem iniciada: "
              << origem->getNome() << " -> " << destino->getNome()
              << " | Transporte: " << transporte->getNome()
              << std::endl;
}

void Viagem::avancarHoras(int horas) {
    if (!emAndamento) return;

    horasEmTransito += horas;
   
    std::cout << "Avançando " << horas << "h | Total em trânsito: "
              << horasEmTransito << "h" << std::endl;
}

void Viagem::relatarEstado() {
    std::cout << "[Viagem] " << origem->getNome()
              << " -> " << destino->getNome()
              << " | Transporte: " << transporte->getNome()
              << " | Horas em trânsito: " << horasEmTransito
              << " | Em andamento: " << (emAndamento ? "Sim" : "Não")
              << std::endl;
}

bool Viagem::isEmAndamento() { return emAndamento; }
Viagem* Viagem::getProxima() { return proxima; }
void Viagem::setProxima(Viagem* prox) { this->proxima = prox; }
Transporte* Viagem::getTransporte() { return transporte; }
Cidade* Viagem::getOrigem() { return origem; }
Cidade* Viagem::getDestino() { return destino; }