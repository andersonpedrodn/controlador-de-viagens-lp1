#include <iostream>
#include "ControladorDeTransito.h"

int main() {
    ControladorDeTransito ctrl;

    ctrl.cadastrarCidade("Natal");
    ctrl.cadastrarCidade("Mossoró");
    ctrl.cadastrarTrajeto("Natal", "Mossoró", 'T', 280);
    ctrl.cadastrarTransporte("Ônibus RN", 'T', 40, 80, 200, 1, "Natal");
    ctrl.cadastrarPassageiro("Anderson", "Natal");

    ctrl.iniciarViagem("Ônibus RN", {"Anderson"}, "Natal", "Mossoró");
    ctrl.avancarHoras(3);
    ctrl.relatarEstado();

    return 0;
}