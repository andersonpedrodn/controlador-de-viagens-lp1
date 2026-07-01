#include "Transporte.h"

Transporte::Transporte(std::string nome, char tipo, int capacidade, int velocidade,
                       int distanciaEntreDescansos, int tempoDeDescanso, Cidade* localAtual) {
    this->nome = nome;
    this->tipo = tipo;
    this->capacidade = capacidade;
    this->velocidade = velocidade;
    this->distanciaEntreDescansos = distanciaEntreDescansos;
    this->tempoDeDescanso = tempoDeDescanso;
    this->tempoDeDescansoAtual = 0;
    this->localAtual = localAtual;
}

std::string Transporte::getNome() { return nome; }
char Transporte::getTipo() { return tipo; }
int Transporte::getCapacidade() { return capacidade; }
int Transporte::getVelocidade() { return velocidade; }
int Transporte::getDistanciaEntreDescansos() { return distanciaEntreDescansos; }
int Transporte::getTempoDescanso() { return tempoDeDescanso; }
int Transporte::getTempoDescansoAtual() { return tempoDeDescansoAtual; }
Cidade* Transporte::getLocalAtual() { return localAtual; }
void Transporte::setLocalAtual(Cidade* local) { this->localAtual = local; }