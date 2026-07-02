#pragma once
#include <vector>
#include <string>
#include "Cidade.h"
#include "Trajeto.h"
#include "Transporte.h"
#include "Passageiro.h"
#include "Viagem.h"
#include <fstream>

/**
 * @brief Núcleo do sistema — gerencia todos os cadastros e operações de viagem.
 *
 * Mantém as listas de cidades, trajetos, transportes, passageiros e viagens.
 * Expõe métodos públicos para cadastro, simulação (avancarHoras) e geração
 * de relatórios. Os métodos privados de busca e o algoritmo BFS são detalhes
 * internos usados apenas por esta classe.
 */
class ControladorDeTransito {
private:
    std::vector<Cidade*> cidades;        ///< Todas as cidades cadastradas
    std::vector<Trajeto*> trajetos;      ///< Todos os trajetos cadastrados
    std::vector<Transporte*> transportes;///< Todos os transportes cadastrados
    std::vector<Passageiro*> passageiros;///< Todos os passageiros cadastrados
    std::vector<Viagem*> viagens;        ///< Todas as etapas de viagem criadas

    /**
     * @brief Busca uma cidade pelo nome.
     * @return Ponteiro para a cidade, ou nullptr se não encontrada
     */
    Cidade* buscarCidade(std::string nome);

    /**
     * @brief Busca um transporte pelo nome.
     * @return Ponteiro para o transporte, ou nullptr se não encontrado
     */
    Transporte* buscarTransporte(std::string nome);

    /**
     * @brief Busca um passageiro pelo nome.
     * @return Ponteiro para o passageiro, ou nullptr se não encontrado
     */
    Passageiro* buscarPassageiro(std::string nome);

    /**
     * @brief Busca um trajeto direto entre duas cidades.
     * @return Ponteiro para o trajeto, ou nullptr se não existir ligação direta
     */
    Trajeto* buscarTrajeto(Cidade* origem, Cidade* destino);

    /**
     * @brief Calcula o menor caminho entre duas cidades usando BFS.
     *
     * Retorna a sequência de cidades do caminho, ou vetor vazio se não houver rota.
     */
    std::vector<Cidade*> calcularMelhorTrajeto(Cidade* origem, Cidade* destino);

public:
    /**
     * @brief Cadastra uma nova cidade no sistema.
     * @param nome Nome da cidade
     */
    void cadastrarCidade(std::string nome);

    /**
     * @brief Cadastra um trajeto entre duas cidades já cadastradas.
     * @param nomeOrigem  Nome da cidade de origem
     * @param nomeDestino Nome da cidade de destino
     * @param tipo        Tipo do trajeto ('T' ou 'A')
     * @param distancia   Distância em km
     */
    void cadastrarTrajeto(std::string nomeOrigem, std::string nomeDestino, char tipo, int distancia);

    /**
     * @brief Cadastra um transporte em uma cidade já cadastrada.
     * @param nome                  Nome do transporte
     * @param tipo                  Tipo do transporte ('T' ou 'A')
     * @param capacidade            Capacidade de passageiros
     * @param velocidade            Velocidade em km/h
     * @param distanciaEntreDescansos Km entre paradas obrigatórias
     * @param tempoDeDescanso       Horas de descanso por parada
     * @param localAtual            Nome da cidade inicial
     */
    void cadastrarTransporte(std::string nome, char tipo, int capacidade, int velocidade,
                             int distanciaEntreDescansos, int tempoDeDescanso, std::string localAtual);

    /**
     * @brief Cadastra um passageiro em uma cidade já cadastrada.
     * @param nome       Nome do passageiro
     * @param localAtual Nome da cidade inicial do passageiro
     */
    void cadastrarPassageiro(std::string nome, std::string localAtual);

    /**
     * @brief Inicia uma viagem decompondo a rota em etapas encadeadas.
     * @param nomeTransporte    Nome do transporte a ser utilizado
     * @param nomesPassageiros  Lista de nomes dos passageiros a embarcar
     * @param nomeOrigem        Nome da cidade de partida
     * @param nomeDestino       Nome da cidade de chegada
     */
    void iniciarViagem(std::string nomeTransporte, std::vector<std::string> nomesPassageiros,
                       std::string nomeOrigem, std::string nomeDestino);

    /**
     * @brief Avança o tempo de todas as viagens em andamento.
     * @param horas Número de horas a avançar
     */
    void avancarHoras(int horas);

    /**
     * @brief Exibe o estado de todas as viagens cadastradas.
     */
    void relatarEstado();

    /**
     * @brief Exibe a localização atual de todos os passageiros.
     */
    void relatarPassageiros();

    /**
     * @brief Exibe a localização atual de todos os transportes.
     */
    void relatarTransportes();

    /**
     * @brief Exibe apenas as viagens que estão em andamento no momento.
     */
    void relatarViagensEmAndamento();

    /**
     * @brief Exibe as cidades com mais chegadas registradas.
     */
    void relatarCidadesMaisVisitadas();

    /**
     * @brief Persiste todos os dados cadastrados em arquivos na pasta data/.
     */
    void salvarDados();

    /**
     * @brief Carrega dados previamente salvos dos arquivos na pasta data/.
     */
    void carregarDados();
};