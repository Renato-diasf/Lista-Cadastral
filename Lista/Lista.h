//
// Created by User on 20/11/2023.
//

#ifndef LISTA_CADASTRAL_LISTA_H
#define LISTA_CADASTRAL_LISTA_H

class Node {
public:
    int info;
    Node *next;

};

typedef class Node *Nodeptr;

class Lista {

private:
    Nodeptr L_primeiro;
    Nodeptr L_atual;

public:
    void cria();

    static bool cheia();

    bool vazia();

    void procuraX(int*, Nodeptr&, Nodeptr&, bool*);

    void retira(int&, bool*);

    void insere(int, bool*);

    bool estaNaLista(int);

    void PegaOPrimeiro (int* , bool *temElemento);

    void PegaOProximo(int *, bool *temElemento);

    void intersec(Lista &i, Lista &c);

    int posicaoNaLista(const int *x);
};


#endif //LISTA_CADASTRAL_LISTA_H
