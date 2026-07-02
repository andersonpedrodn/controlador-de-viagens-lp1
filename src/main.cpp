#include <iostream>
#include <string>
#include <vector>
#include "ControladorDeTransito.h"

void exibirMenu() {
    std::cout << "\n=== Controlador de Viagens ===" << std::endl;
    std::cout << "1. Cadastrar Cidade" << std::endl;
    std::cout << "2. Cadastrar Trajeto" << std::endl;
    std::cout << "3. Cadastrar Transporte" << std::endl;
    std::cout << "4. Cadastrar Passageiro" << std::endl;
    std::cout << "5. Iniciar Viagem" << std::endl;
    std::cout << "6. Avançar Horas" << std::endl;
    std::cout << "7. Relatar Estado Geral" << std::endl;
    std::cout << "8. Relatar Passageiros" << std::endl;
    std::cout << "9. Relatar Transportes" << std::endl;
    std::cout << "10. Viagens em Andamento" << std::endl;
    std::cout << "11. Cidades Mais Visitadas" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << "Escolha: ";
}

int main() {
    ControladorDeTransito ctrl;
    int opcao;

    while (true) {
        exibirMenu();
        std::cin >> opcao;
        std::cin.ignore();

        if (opcao == 0) {
            std::cout << "Encerrando sistema." << std::endl;
            break;

        } else if (opcao == 1) {
            std::string nome;
            std::cout << "Nome da cidade: ";
            std::getline(std::cin, nome);
            ctrl.cadastrarCidade(nome);

        } else if (opcao == 2) {
            std::string origem, destino;
            char tipo;
            int distancia;
            std::cout << "Cidade de origem: ";
            std::getline(std::cin, origem);
            std::cout << "Cidade de destino: ";
            std::getline(std::cin, destino);
            std::cout << "Tipo (T=Terrestre, A=Aquático): ";
            std::cin >> tipo;
            std::cout << "Distância (km): ";
            std::cin >> distancia;
            std::cin.ignore();
            ctrl.cadastrarTrajeto(origem, destino, tipo, distancia);

        } else if (opcao == 3) {
            std::string nome, localAtual;
            char tipo;
            int capacidade, velocidade, distDescanso, tempoDescanso;
            std::cout << "Nome do transporte: ";
            std::getline(std::cin, nome);
            std::cout << "Tipo (T=Terrestre, A=Aquático): ";
            std::cin >> tipo;
            std::cout << "Capacidade de passageiros: ";
            std::cin >> capacidade;
            std::cout << "Velocidade (km/h): ";
            std::cin >> velocidade;
            std::cout << "Distância entre descansos (km): ";
            std::cin >> distDescanso;
            std::cout << "Tempo de descanso (horas): ";
            std::cin >> tempoDescanso;
            std::cin.ignore();
            std::cout << "Cidade atual: ";
            std::getline(std::cin, localAtual);
            ctrl.cadastrarTransporte(nome, tipo, capacidade, velocidade,
                                     distDescanso, tempoDescanso, localAtual);

        } else if (opcao == 4) {
            std::string nome, localAtual;
            std::cout << "Nome do passageiro: ";
            std::getline(std::cin, nome);
            std::cout << "Cidade atual: ";
            std::getline(std::cin, localAtual);
            ctrl.cadastrarPassageiro(nome, localAtual);

        } else if (opcao == 5) {
            std::string nomeTransporte, origem, destino, nomePassageiro;
            int qtd;
            std::cout << "Nome do transporte: ";
            std::getline(std::cin, nomeTransporte);
            std::cout << "Cidade de origem: ";
            std::getline(std::cin, origem);
            std::cout << "Cidade de destino: ";
            std::getline(std::cin, destino);
            std::cout << "Quantos passageiros? ";
            std::cin >> qtd;
            std::cin.ignore();
            std::vector<std::string> passageiros;
            for (int i = 0; i < qtd; i++) {
                std::cout << "Nome do passageiro " << (i+1) << ": ";
                std::getline(std::cin, nomePassageiro);
                passageiros.push_back(nomePassageiro);
            }
            ctrl.iniciarViagem(nomeTransporte, passageiros, origem, destino);

        } else if (opcao == 6) {
            int horas;
            std::cout << "Quantas horas avançar? ";
            std::cin >> horas;
            std::cin.ignore();
            ctrl.avancarHoras(horas);

        } else if (opcao == 7) {
            ctrl.relatarEstado();

        } else if (opcao == 8) {
            ctrl.relatarPassageiros();

        } else if (opcao == 9) {
            ctrl.relatarTransportes();

        } else if (opcao == 10) {
            ctrl.relatarViagensEmAndamento();

        } else if (opcao == 11) {
            ctrl.relatarCidadesMaisVisitadas();

        } else {
            std::cout << "Opção inválida." << std::endl;
        }
    }

    return 0;
}