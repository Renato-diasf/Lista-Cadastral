#include <iostream>
#include "Lista/Lista.h"

using namespace std;

void imprime(Lista &lista);

int main() {
    Lista l{};
    Lista i{};
    Lista c{};
    int x = 100;
    bool ok, temElemento;
    Nodeptr ant, p;
    l.cria();
    c.cria();

    l.insere(54, &ok);
    l.procuraX(&x, ant, p, &ok);
    l.insere(23, &ok);
    l.insere(1000, &ok);
    l.insere(100, &ok);
    l.retira(x, &ok);
    x = 23;
    l.retira(x, &ok);
    x=54;

    c.insere(54, &ok);
    c.insere(102, &ok);
    c.insere(12, &ok);
    c.insere(32, &ok);

    imprime(l);

    l.intersec(i, c);
    imprime(i);

    cout << l.posicaoNaLista(&x);

}

void imprime(Lista &lista) {
    int x;
    bool temElemento;

    if (lista.vazia()) {
        cout << "Vazio mano, sai fora" << endl;
    } else {
        lista.PegaOPrimeiro(&x, &temElemento);
        while (temElemento) {
            cout << x << endl;
            lista.PegaOProximo(&x, &temElemento);
        }
    }
}
