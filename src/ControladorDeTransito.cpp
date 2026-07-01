#include "ControladorDeTransito.h"
#include <iostream>


Cidade* ControladorDeTransito::buscarCidade(std::string nome) {
    for (Cidade* c : cidades)
        if (c->getNome() == nome) return c;
    return nullptr;
}

Transporte* ControladorDeTransito::buscarTransporte(std::string nome) {
    for (Transporte* t : transportes)
        if (t->getNome() == nome) return t;
    return nullptr;
}

Passageiro* ControladorDeTransito::buscarPassageiro(std::string nome) {
    for (Passageiro* p : passageiros)
        if (p->getNome() == nome) return p;
    return nullptr;
}


void ControladorDeTransito::cadastrarCidade(std::string nome) {
    if (buscarCidade(nome)) {
        std::cout << "Cidade já cadastrada: " << nome << std::endl;
        return;
    }
    cidades.push_back(new Cidade(nome));
    std::cout << "Cidade cadastrada: " << nome << std::endl;
}

void ControladorDeTransito::cadastrarTrajeto(std::string nomeOrigem, std::string nomeDestino,
                                              char tipo, int distancia) {
    Cidade* origem = buscarCidade(nomeOrigem);
    Cidade* destino = buscarCidade(nomeDestino);

    if (!origem || !destino) {
        std::cout << "Cidade não encontrada." << std::endl;
        return;
    }

    trajetos.push_back(new Trajeto(origem, destino, tipo, distancia));
    std::cout << "Trajeto cadastrado: " << nomeOrigem << " -> " << nomeDestino << std::endl;
}

void ControladorDeTransito::cadastrarTransporte(std::string nome, char tipo, int capacidade,
                                                 int velocidade, int distanciaEntreDescansos,
                                                 int tempoDeDescanso, std::string localAtual) {
    Cidade* cidade = buscarCidade(localAtual);
    if (!cidade) {
        std::cout << "Cidade não encontrada: " << localAtual << std::endl;
        return;
    }
    transportes.push_back(new Transporte(nome, tipo, capacidade, velocidade,
                                          distanciaEntreDescansos, tempoDeDescanso, cidade));
    std::cout << "Transporte cadastrado: " << nome << std::endl;
}

void ControladorDeTransito::cadastrarPassageiro(std::string nome, std::string localAtual) {
    Cidade* cidade = buscarCidade(localAtual);
    if (!cidade) {
        std::cout << "Cidade não encontrada: " << localAtual << std::endl;
        return;
    }
    passageiros.push_back(new Passageiro(nome, cidade));
    std::cout << "Passageiro cadastrado: " << nome << std::endl;
}


void ControladorDeTransito::iniciarViagem(std::string nomeTransporte,
                                           std::vector<std::string> nomesPassageiros,
                                           std::string nomeOrigem, std::string nomeDestino) {
    Transporte* transporte = buscarTransporte(nomeTransporte);
    Cidade* origem = buscarCidade(nomeOrigem);
    Cidade* destino = buscarCidade(nomeDestino);

    if (!transporte || !origem || !destino) {
        std::cout << "Transporte ou cidade não encontrado." << std::endl;
        return;
    }

    if (transporte->getLocalAtual()->getNome() != nomeOrigem) {
        std::cout << "Transporte não está na cidade de origem." << std::endl;
        return;
    }

    std::vector<Passageiro*> listaPassageiros;
    for (std::string nome : nomesPassageiros) {
        Passageiro* p = buscarPassageiro(nome);
        if (p) listaPassageiros.push_back(p);
    }

    Viagem* v = new Viagem(transporte, listaPassageiros, origem, destino);
    v->iniciarViagem();
    viagens.push_back(v);
}


void ControladorDeTransito::avancarHoras(int horas) {
    for (Viagem* v : viagens)
        if (v->isEmAndamento())
            v->avancarHoras(horas);
}


void ControladorDeTransito::relatarEstado() {
    std::cout << "\n=== Estado do Sistema ===" << std::endl;
    for (Viagem* v : viagens)
        v->relatarEstado();
}