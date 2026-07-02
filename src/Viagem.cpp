#include "Viagem.h"
#include <iostream>

/**
 * @brief Construtor da classe Viagem.
 *
 * Inicializa uma etapa de viagem entre origem e destino. O ponteiro
 * proxima começa nulo — ele é preenchido por ControladorDeTransito
 * ao encadear etapas de uma rota com mais de dois pontos.
 */
Viagem::Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros,
               Cidade* origem, Cidade* destino) {
    this->transporte = transporte;
    this->passageiros = passageiros;
    this->origem = origem;
    this->destino = destino;
    this->proxima = nullptr;
    this->horasEmTransito = 0;
    this->distancia = 0;
    this->emAndamento = false;
    this->concluida = false;
}

/// @brief Define a distância desta etapa em km.
void Viagem::setDistancia(int dist) { this->distancia = dist; }

/// @brief Retorna a distância desta etapa em km.
int Viagem::getDistancia() { return distancia; }

/**
 * @brief Marca a viagem como em andamento e exibe uma mensagem de início.
 */
void Viagem::iniciarViagem() {
    emAndamento = true;
    std::cout << "Viagem iniciada: "
              << origem->getNome() << " -> " << destino->getNome()
              << " | Transporte: " << transporte->getNome()
              << std::endl;
}

/**
 * @brief Acumula horas de trânsito e verifica conclusão da etapa.
 *
 * O tempo total necessário é calculado como:
 *   (distancia / velocidade) + (numDescansos * tempoDeDescanso)
 * Quando horasEmTransito atinge esse valor, transporte e passageiros
 * são movidos para o destino e, se houver próxima etapa, ela é iniciada.
 */
void Viagem::avancarHoras(int horas) {
    if (!emAndamento) return;

    horasEmTransito += horas;

    int velocidade = transporte->getVelocidade();
    int distEntreDescansos = transporte->getDistanciaEntreDescansos();
    int tempoDescanso = transporte->getTempoDescanso();

    int numDescansos = distancia / distEntreDescansos;

    float tempoRodando = (float)distancia / velocidade;
    float tempoTotal = tempoRodando + (numDescansos * tempoDescanso);

    std::cout << "Avançando " << horas << "h | Total em trânsito: "
              << horasEmTransito << "h / " << tempoTotal << "h necessárias"
              << std::endl;

    if (horasEmTransito >= tempoTotal) {
        emAndamento = false;
        concluida = true;

        transporte->setLocalAtual(destino);
        for (Passageiro* p : passageiros)
            p->setLocalAtual(destino);

        std::cout << "Viagem concluída: " << origem->getNome()
                  << " -> " << destino->getNome() << std::endl;

        if (proxima != nullptr) {
            proxima->iniciarViagem();
        }
    }
}

/**
 * @brief Imprime o estado atual da viagem no console.
 */
void Viagem::relatarEstado() {
    std::cout << "[Viagem] " << origem->getNome()
              << " -> " << destino->getNome()
              << " | Transporte: " << transporte->getNome()
              << " | Horas em trânsito: " << horasEmTransito
              << " | Em andamento: " << (emAndamento ? "Sim" : "Não")
              << std::endl;
}

/// @brief Retorna true se a viagem está em progresso.
bool Viagem::isEmAndamento() { return emAndamento; }

/// @brief Retorna true se a viagem foi concluída.
bool Viagem::isConcluida() { return concluida; }

/// @brief Retorna a próxima etapa da rota (nullptr se for a última).
Viagem* Viagem::getProxima() { return proxima; }

/// @brief Define a próxima etapa da rota.
void Viagem::setProxima(Viagem* prox) { this->proxima = prox; }

/// @brief Retorna o transporte utilizado nesta etapa.
Transporte* Viagem::getTransporte() { return transporte; }

/// @brief Retorna a cidade de partida desta etapa.
Cidade* Viagem::getOrigem() { return origem; }

/// @brief Retorna a cidade de chegada desta etapa.
Cidade* Viagem::getDestino() { return destino; }