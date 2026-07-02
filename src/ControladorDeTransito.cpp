#include "ControladorDeTransito.h"
#include <iostream>
#include <queue>
#include <map>

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

Trajeto* ControladorDeTransito::buscarTrajeto(Cidade* origem, Cidade* destino) {
    for (Trajeto* t : trajetos)
        if (t->getOrigem() == origem && t->getDestino() == destino)
            return t;
    return nullptr;
}

std::vector<Cidade*> ControladorDeTransito::calcularMelhorTrajeto(Cidade* origem, Cidade* destino) {
    std::queue<Cidade*> fila;
    std::map<Cidade*, Cidade*> anterior;

    fila.push(origem);
    anterior[origem] = nullptr;

    while (!fila.empty()) {
        Cidade* atual = fila.front();
        fila.pop();

        if (atual == destino) {
            std::vector<Cidade*> caminho;
            Cidade* c = destino;
            while (c != nullptr) {
                caminho.insert(caminho.begin(), c);
                c = anterior[c];
            }
            return caminho;
        }

        for (Trajeto* t : trajetos) {
            if (t->getOrigem() == atual && anterior.find(t->getDestino()) == anterior.end()) {
                anterior[t->getDestino()] = atual;
                fila.push(t->getDestino());
            }
        }
    }

    return {};
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

    if (transporte->getLocalAtual() != origem) {
        std::cout << "Transporte não está na cidade de origem." << std::endl;
        return;
    }

    std::vector<Passageiro*> listaPassageiros;
    for (std::string nome : nomesPassageiros) {
        Passageiro* p = buscarPassageiro(nome);
        if (p) listaPassageiros.push_back(p);
    }

    std::vector<Cidade*> caminho = calcularMelhorTrajeto(origem, destino);

    if (caminho.empty()) {
        std::cout << "Não existe trajeto entre " << nomeOrigem << " e " << nomeDestino << std::endl;
        return;
    }

    Viagem* primeira = nullptr;
    Viagem* anterior = nullptr;

    for (int i = 0; i < (int)caminho.size() - 1; i++) {
        Viagem* v = new Viagem(transporte, listaPassageiros, caminho[i], caminho[i+1]);

        Trajeto* t = buscarTrajeto(caminho[i], caminho[i+1]);
        if (t) v->setDistancia(t->getDistancia());

        viagens.push_back(v);

        if (!primeira) primeira = v;
        if (anterior) anterior->setProxima(v);
        anterior = v;
    }

    if (primeira) primeira->iniciarViagem();
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