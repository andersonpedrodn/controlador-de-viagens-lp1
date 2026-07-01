#include <iostream>
#include "Cidade.h"
#include "Trajeto.h"

int main() {
    Cidade natal("Natal");
    Cidade mossoro("Mossoró");

    Trajeto t(&natal, &mossoro, 'T', 280);

    std::cout << "Trajeto: " << t.getOrigem()->getNome()
              << " -> " << t.getDestino()->getNome()
              << " | Tipo: " << t.getTipo()
              << " | Distância: " << t.getDistancia() << "km"
              << std::endl;

    return 0;
}