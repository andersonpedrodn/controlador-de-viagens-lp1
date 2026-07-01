#include <iostream>
#include "Cidade.h"
#include "Transporte.h"

int main() {
    Cidade natal("Natal");

    Transporte onibus("Ônibus RN", 'T', 40, 80, 200, 1, &natal);

    std::cout << "Transporte: " << onibus.getNome() << std::endl;
    std::cout << "Tipo: " << onibus.getTipo() << std::endl;
    std::cout << "Capacidade: " << onibus.getCapacidade() << " passageiros" << std::endl;
    std::cout << "Velocidade: " << onibus.getVelocidade() << " km/h" << std::endl;
    std::cout << "Local atual: " << onibus.getLocalAtual()->getNome() << std::endl;

    return 0;
}