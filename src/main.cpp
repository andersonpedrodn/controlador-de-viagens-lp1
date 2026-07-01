#include <iostream>
#include "Cidade.h"
#include "Transporte.h"
#include "Passageiro.h"
#include "Viagem.h"

int main() {
    Cidade natal("Natal");
    Cidade mossoro("Mossoró");

    Transporte onibus("Ônibus RN", 'T', 40, 80, 200, 1, &natal);
    Passageiro anderson("Anderson", &natal);

    std::vector<Passageiro*> passageiros = {&anderson};

    Viagem v(&onibus, passageiros, &natal, &mossoro);
    v.iniciarViagem();
    v.avancarHoras(2);
    v.relatarEstado();

    return 0;
}