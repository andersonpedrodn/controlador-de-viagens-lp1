#pragma once
#include <vector>
#include <string>
#include "Cidade.h"
#include "Trajeto.h"
#include "Transporte.h"
#include "Passageiro.h"
#include "Viagem.h"
#include <fstream>


class ControladorDeTransito {
private:
    std::vector<Cidade*> cidades;
    std::vector<Trajeto*> trajetos;
    std::vector<Transporte*> transportes;
    std::vector<Passageiro*> passageiros;
    std::vector<Viagem*> viagens;

    Cidade* buscarCidade(std::string nome);
    Transporte* buscarTransporte(std::string nome);
    Passageiro* buscarPassageiro(std::string nome);
    Trajeto* buscarTrajeto(Cidade* origem, Cidade* destino);
    std::vector<Cidade*> calcularMelhorTrajeto(Cidade* origem, Cidade* destino);

public:
    void cadastrarCidade(std::string nome);
    void cadastrarTrajeto(std::string nomeOrigem, std::string nomeDestino, char tipo, int distancia);
    void cadastrarTransporte(std::string nome, char tipo, int capacidade, int velocidade,
                             int distanciaEntreDescansos, int tempoDeDescanso, std::string localAtual);
    void cadastrarPassageiro(std::string nome, std::string localAtual);
    void iniciarViagem(std::string nomeTransporte, std::vector<std::string> nomesPassageiros,
                       std::string nomeOrigem, std::string nomeDestino);
    void avancarHoras(int horas);
    void relatarEstado();
    void relatarPassageiros();
    void relatarTransportes();
    void relatarViagensEmAndamento();
    void relatarCidadesMaisVisitadas();
    void salvarDados();
    void carregarDados();
};