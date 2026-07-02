#include "Transporte.h"

/**
 * @brief Construtor da classe Transporte.
 *
 * Inicializa todos os atributos do transporte. O tempoDeDescansoAtual
 * começa em 0 pois nenhuma parada foi acumulada ainda. O localAtual
 * aponta para uma cidade já existente no sistema — não cria uma cópia.
 */
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

/// @brief Retorna o nome do transporte.
std::string Transporte::getNome() { return nome; }

/// @brief Retorna o tipo do transporte ('T' ou 'A').
char Transporte::getTipo() { return tipo; }

/// @brief Retorna a capacidade máxima de passageiros.
int Transporte::getCapacidade() { return capacidade; }

/// @brief Retorna a velocidade em km/h.
int Transporte::getVelocidade() { return velocidade; }

/// @brief Retorna a distância em km entre descansos obrigatórios.
int Transporte::getDistanciaEntreDescansos() { return distanciaEntreDescansos; }

/// @brief Retorna a duração de cada parada de descanso em horas.
int Transporte::getTempoDescanso() { return tempoDeDescanso; }

/// @brief Retorna as horas de descanso acumuladas na viagem atual.
int Transporte::getTempoDescansoAtual() { return tempoDeDescansoAtual; }

/// @brief Retorna a cidade onde o transporte se encontra.
Cidade* Transporte::getLocalAtual() { return localAtual; }

/**
 * @brief Atualiza a cidade onde o transporte se encontra.
 *
 * Chamado por Viagem::avancarHoras quando a viagem é concluída,
 * posicionando o transporte na cidade de destino.
 */
void Transporte::setLocalAtual(Cidade* local) { this->localAtual = local; }