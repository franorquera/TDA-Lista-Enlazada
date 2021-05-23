#include "lista.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct nodo {
    void* dato;
    struct nodo* prox;
} nodo_t;

struct lista {
    nodo_t* prim;
    nodo_t* ult;
    size_t len;
};

struct lista_iter {
    lista_t* lista;
    nodo_t* ant;
    nodo_t* act;
};

nodo_t *nodo_crear(void* valor) {
    nodo_t *nodo = malloc(sizeof(nodo_t));
    if (!nodo) return NULL;
    nodo->dato = valor;
    nodo->prox = NULL;
    return nodo;
}

lista_t *lista_crear(void) {
    lista_t* lista = malloc(sizeof(lista_t));
    if (!lista) return NULL;
    lista->prim = NULL, lista->ult = NULL;
    lista->len = 0;
    return lista;
}

bool lista_esta_vacia(const lista_t *lista) {
    return (!lista->prim && !lista->ult);
}

bool lista_insertar_primero(lista_t *lista, void *dato) {
    nodo_t* elem = nodo_crear(dato);
    if (!elem) return false;
    void* prim_ant = lista->prim;
    if(lista_esta_vacia(lista)) lista->ult = elem;
    else elem->prox = prim_ant;
    lista->prim = elem;
    lista->len++;
    return true;
}

bool lista_insertar_ultimo(lista_t *lista, void *dato) {
    nodo_t* elem = nodo_crear(dato);
    if(!elem) return false;
    if (lista_esta_vacia(lista)) lista->prim = elem;
    else lista->ult->prox = elem;
    lista->ult = elem;
    lista->len++;
    return true;
}

void *lista_borrar_primero(lista_t *lista) {
    if(lista_esta_vacia(lista)) return NULL;
    void* valor = lista->prim->dato;
    void* nuevo_prim = lista->prim->prox;
    free(lista->prim);
    lista->prim = nuevo_prim;
    if (!lista->prim) lista->ult = NULL;
    lista->len--;
    return valor;
}

void *lista_ver_primero(const lista_t *lista) {
    if (lista_esta_vacia(lista)) return NULL;
    return lista->prim->dato;
}

void *lista_ver_ultimo(const lista_t* lista) {
    if(lista_esta_vacia(lista)) return NULL;
    return lista->ult->dato;
}

size_t lista_largo(const lista_t *lista) {
    return lista->len;
}

void lista_destruir(lista_t *lista, void (*destruir_dato)(void *)) {
    while (!lista_esta_vacia(lista)) {
        void* dato = lista_borrar_primero(lista);
        if(destruir_dato) destruir_dato(dato);
    }
    free(lista);
}

/* ITERADOR INTERNO */

void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra) {
    nodo_t* act = lista->prim;
    while (act) {
        if(visitar && !visitar(act->dato, extra)) return;
        act = act->prox;
    }
}

/* ITERADOR EXTERNO */

lista_iter_t *lista_iter_crear(lista_t *lista) {
    lista_iter_t* lista_iter = malloc(sizeof(lista_iter_t));
    if (!lista_iter) return NULL;
    lista_iter->lista = lista;
    lista_iter->act = lista->prim;
    lista_iter->ant = NULL;
    return lista_iter;
}

void *lista_iter_ver_actual(const lista_iter_t *iter) {
    if (!iter->act) return NULL;
    return iter->act->dato;
}

bool lista_iter_al_final(const lista_iter_t *iter) {
    return !iter->act;
}

bool lista_iter_avanzar(lista_iter_t *iter) {
    if (lista_iter_al_final(iter)) return false;
    iter->ant = iter->act;
    iter->act = iter->act->prox;
    return true; 
}

bool lista_iter_insertar(lista_iter_t *iter, void *dato) {
    nodo_t* elem = nodo_crear(dato);
    if (!elem) return NULL;
   if (iter->lista->prim == iter->act) iter->lista->prim = elem;
   if (!iter->act) iter->lista->ult = elem;
   if (iter->ant) iter->ant->prox = elem;
   elem->prox = iter->act;
   iter->act = elem;
   iter->lista->len++;
    return true;
}

void *lista_iter_borrar(lista_iter_t *iter) {
    if (!iter->act) return NULL;
    void* borrado = iter->act->dato;
    nodo_t* prox = iter->act->prox; // NULL
    if (iter->lista->prim == iter->act) iter->lista->prim = prox;
    if (iter->lista->ult == iter->act) iter->lista->ult = iter->ant;
    free(iter->act);
    if (iter->ant) iter->ant->prox = prox;
    iter->act = prox;
    iter->lista->len--; 
    return borrado;
}

void lista_iter_destruir(lista_iter_t *iter) {
    free(iter);
}