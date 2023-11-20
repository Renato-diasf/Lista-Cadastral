//
// Created by User on 20/11/2023.
//

#include "Lista.h"

void Lista::cria() {
    L_primeiro = nullptr;
    L_atual = nullptr;
}

bool Lista::cheia() {
    return false;
}

bool Lista::vazia() {
    if (L_primeiro == nullptr){
        return true;
    }
    return false;
}

void Lista::procuraX(int *x, Nodeptr& anterior, Nodeptr& p, bool* achouX) {
    p = this -> L_primeiro;
    anterior = nullptr;

    while ((p != nullptr) && (p -> info < *x)){
        anterior = p;
        p = p -> next;

        if (p != nullptr && p -> info == *x){
            *achouX = true;
        }
        else {
            *achouX = false;
        }
    }
}

void Lista::retira(int &x, bool *ok) {
    Nodeptr anterior, p;
    bool achouX;

    procuraX(&x, anterior, p, &achouX);

    if (achouX){
        if (p != L_primeiro){
            anterior -> next = p -> next;
            delete(p);
            p = nullptr;
            anterior = nullptr;
        }
        else {
            L_primeiro = L_primeiro -> next;
            delete(p);
            p = nullptr;
        }
        *ok = true;
    }
    else {
        *ok = false;
    }

}
void Lista::insere(int x, bool *ok) {
    Nodeptr anterior = nullptr, p = nullptr;
    bool achouX;

    procuraX(&x, anterior, p, &achouX);

    if (achouX) {
        *ok = false;
    } else {
        Nodeptr aux;
        aux = new Node();

        aux->info = x;
        *ok = true;

        if (p == L_primeiro) {  // Se p é nullptr, o novo nó deve ser inserido no início
            aux->next = L_primeiro;
            L_primeiro = aux;
        } else {
            aux->next = anterior->next;
            anterior->next = aux;
        }
    }
}


bool Lista::estaNaLista(int x) {
    bool temElemento;
    int y;
    if (vazia()) {
        return false;
    } else {
        PegaOPrimeiro(&y, &temElemento);
        while (temElemento) {
            if (y == x){
                return true;
            }
            PegaOProximo(&y, &temElemento);
        }
    }
    return false;
}

void Lista::PegaOPrimeiro(int *x, bool *temElemento) {
    L_atual = L_primeiro;
    if (L_atual == nullptr) {
        *temElemento = false;
    } else {
        *temElemento = true;
        *x = L_atual->info;
    }
}

void Lista::PegaOProximo(int *x, bool *temElemento) {
    if (L_atual == nullptr || L_atual->next == nullptr) {
        *temElemento = false;
    } else {
        L_atual = L_atual->next;
        *x = L_atual->info;
        *temElemento = true;
    }
}


void Lista::intersec(Lista& i, Lista& c) {
    i.cria();
    int x;
    bool ok, temElemento;

    this -> PegaOPrimeiro(&x, &temElemento);

    while(temElemento){
        if (c.estaNaLista(x)){
            i.insere(x, &ok);
        }
        this ->PegaOProximo(&x, &temElemento);
    }
}

int Lista::posicaoNaLista(const int *x) {
    bool temElemento;
    int y;
    int count = 1;

    if (!this->estaNaLista(*x)){
        return 0;
    }
    else {
        this ->PegaOPrimeiro(&y, &temElemento);
        while (temElemento){
            if (y == *x){
                return count;
            }
            PegaOProximo(&y, &temElemento);
            count++;
        }
    }
    return 0;
}






