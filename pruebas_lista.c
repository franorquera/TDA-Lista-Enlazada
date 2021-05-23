#include "lista.h"
#include "testing.h"
#include "stdlib.h"
#include "stdio.h"

bool _modificar_dato(void* dato, void* valor) {
    if (*(int*) dato < *(int*) valor) {
        *(int*) dato *= *(int*) valor;
        return true;
    }
    return false;
}

static void prueba_lista_vacia(void) {
    lista_t* lista = lista_crear();
    print_test("La lista se puede crear", lista);
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    print_test("No hay un primer elemento", lista_ver_primero(lista) == NULL);
    print_test("No hay un ultimo elemento", lista_ver_ultimo(lista) == NULL);
    print_test("No puedo borrar el primer elemento", lista_borrar_primero(lista) == NULL);
    lista_destruir(lista, NULL);
}

static void prueba_lista_vacia_2(void) {
    lista_t* lista2 = lista_crear();
    print_test("La lista se puede crear", lista2);
    print_test("La lista esta vacia", lista_esta_vacia(lista2));
    print_test("El largo de mi lista es 0", lista_largo(lista2) == 0);
    print_test("No hay un primer elemento", lista_ver_primero(lista2) == NULL);
    print_test("No hay un ultimo elemento", lista_ver_ultimo(lista2) == NULL);
    print_test("No puedo borrar el primer elemento", lista_borrar_primero(lista2) == NULL);
    lista_destruir(lista2, free);
}

static void prueba_lista_vaciada() {
    lista_t* lista = lista_crear();
    int elem = 1, elem2 = 2;
    print_test("La lista se puede crear", lista);
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    print_test("No hay un primer elemento", lista_ver_primero(lista) == NULL);
    print_test("No hay un ultimo elemento", lista_ver_ultimo(lista) == NULL);
    print_test("No puedo borrar el primer elemento", lista_borrar_primero(lista) == NULL);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&elem));
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&elem2));
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem2);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem);
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    print_test("No hay un primer elemento", lista_ver_primero(lista) == NULL);
    print_test("No hay un ultimo elemento", lista_ver_ultimo(lista) == NULL);
    print_test("No puedo borrar el primer elemento", lista_borrar_primero(lista) == NULL);
    lista_destruir(lista, NULL);
}

static void prueba_insertar_primero() {
    lista_t* lista = lista_crear();
    int elem = 1, elem2 = 2, elem3 = 3, elem4 = 4;
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&elem));
    print_test("La lista no esta vacia", lista_esta_vacia(lista) == false);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&elem2));
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&elem3));
    print_test("El largo de mi lista es 3", lista_largo(lista) == 3);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&elem4));
    print_test("El largo de mi lista es 4", lista_largo(lista) == 4);
    print_test("La lista no esta vacia", lista_esta_vacia(lista) == false);
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &elem4);
    print_test("Puedo ver el ultimo elemento", lista_ver_ultimo(lista) == &elem);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem4);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem3);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem2);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem);
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    lista_destruir(lista, NULL);
}

static void prueba_insertar_ultimo() {
    lista_t* lista = lista_crear();
    int elem = 1, elem2 = 2, elem3 = 3, elem4 = 4;
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista,&elem));
    print_test("La lista no esta vacia", lista_esta_vacia(lista) == false);
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista,&elem2));
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista,&elem3));
    print_test("El largo de mi lista es 3", lista_largo(lista) == 3);
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista,&elem4));
    print_test("El largo de mi lista es 4", lista_largo(lista) == 4);
    print_test("La lista no esta vacia", lista_esta_vacia(lista) == false);
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &elem);
    print_test("Puedo ver el ultimo elemento", lista_ver_ultimo(lista) == &elem4);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem2);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem3);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem4);
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    lista_destruir(lista, NULL);
}

static void prueba_insertar_mezclado() {
    lista_t* lista = lista_crear();
    int elem = 1, elem2 = 2, elem3 = 3, elem4 = 4;
    char elem5[] = "elem5";
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista,&elem));
    print_test("La lista no esta vacia", lista_esta_vacia(lista) == false);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&elem2));
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista,&elem3));
    print_test("El largo de mi lista es 3", lista_largo(lista) == 3);
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista,&elem4));
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&elem5));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &elem5);
    print_test("Puedo ver el ultimo elemento", lista_ver_ultimo(lista) == &elem4);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem5);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem2);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem3);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem4);
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    lista_destruir(lista, NULL);
}

static void prueba_null() {
    lista_t* lista = lista_crear();
    int elem = 1, elem2 = 2;
    int* elem3 = NULL;
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista,&elem));
    print_test("La lista no esta vacia", lista_esta_vacia(lista) == false);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&elem2));
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista,&elem3));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &elem2);
    print_test("Puedo ver el ultimo elemento", lista_ver_ultimo(lista) == &elem3);
    print_test("El largo de mi lista es 3", lista_largo(lista) == 3);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem2);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &elem3);
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    lista_destruir(lista, NULL);
}

static void prueba_modificar_elems() {
    lista_t* lista = lista_crear();
    int nums[4] = {1,2,3,4};
    int modificados[4] = {10,20,30,40};
    int modif = 10;
    bool insertado = true;
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    for (int i = 0; i < 4; i++) {
        if (insertado) insertado = lista_insertar_ultimo(lista, &nums[i]);
    }
    lista_iterar(lista, _modificar_dato, &modif);
    for (int i = 0; i < 4; i++) {
        print_test("Los numeros se triplicaron", nums[i] == modificados[i]);
    }
    lista_destruir(lista, NULL);
}

static void prueba_insertar_lista() {
    lista_t* lista = lista_crear();
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    lista_t* lista2 = lista_crear();
    print_test("La lista2 esta vacia", lista_esta_vacia(lista2));
    bool insertar = true;
    int nums[4] = {1,2,3,4};
    for (int i = 0; i < 4; i++){
        if (insertar) lista_insertar_ultimo(lista2, &nums[i]);
    }
    lista_insertar_ultimo(lista, lista2);
    lista_destruir(lista, NULL);
    lista_destruir(lista2, NULL);
}

static void prueba_lista_no_vacia() {
    lista_t* lista = lista_crear();
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    int* num1 = malloc(sizeof(int));
    int* num2 = malloc(sizeof(int));
    print_test("Agrego un elemento al principio", lista_insertar_primero(lista, num1));
    print_test("Agrego un elemento al principio", lista_insertar_primero(lista, num2));
    lista_destruir(lista, free);
}

static void prueba_lista_no_vacia_2() {
    lista_t* lista2 = lista_crear();
    print_test("La lista esta vacia", lista_esta_vacia(lista2));
    int* num1 = malloc(sizeof(int));
    int* num2 = malloc(sizeof(int));
    print_test("Agrego un elemento al principio", lista_insertar_primero(lista2, num1));
    print_test("Agrego un elemento al principio", lista_insertar_primero(lista2, num2));
    lista_destruir(lista2, NULL);
    free(num1);
    free(num2);
}


static void prueba_iter_interno_extra() {
    int valor = 4;
    lista_t* lista = lista_crear();
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    bool insertar = true;
    int nums[4] = {1,2,3,4};
    int modificado[4] = {4, 8, 12, 4};
    for (int i = 0; i < 4; i++){
        if (insertar) lista_insertar_ultimo(lista, &nums[i]);
    }
    lista_iterar(lista, _modificar_dato, &valor);
    print_test("El valor cambio correctamente", nums[0] == modificado[0]);
    print_test("El valor cambio correctamente", nums[1] == modificado[1]);
    print_test("El valor cambio correctamente", nums[2] == modificado[2]);
    print_test("El valor cambio correctamente", nums[3] == modificado[3]);
    lista_destruir(lista, NULL);
}

static void prubea_iter_externo_avanzar() {
    lista_t* lista = lista_crear();
    bool avanzar = true;
    int nums[3] = {1,2,3};
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&nums[2]));
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&nums[1]));
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&nums[0]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[0]);
    print_test("Puedo ver el primer elemento", lista_ver_ultimo(lista) == &nums[2]);
    lista_iter_t* iter = lista_iter_crear(lista);
    while (!lista_iter_al_final(iter) && avanzar) avanzar = lista_iter_avanzar(iter);
    lista_iter_destruir(iter);
    lista_destruir(lista, NULL);
}

static void prueba_iter_externo_insertar_principio() {
    int nums[5] = {1,2,3,4,5};
    int prim = 8;
    lista_t* lista = lista_crear();
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&nums[0]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[0]);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&nums[1]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[1]);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&nums[2]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[2]);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&nums[3]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[3]);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&nums[4]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[4]);
    print_test("El largo de mi lista es 5", lista_largo(lista) == 5);
    lista_iter_t* iter = lista_iter_crear(lista);
    print_test("Puedo crear el iterador", iter != NULL);
    print_test("Puedo ver el actual de mi iterador", lista_iter_ver_actual(iter) == &nums[4]);
    print_test("Puedo insertar el elemento", lista_iter_insertar(iter, &prim) == true);
    print_test("El largo de mi lista es 6", lista_largo(lista) == 6);
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &prim);
    lista_iter_destruir(iter);
    lista_destruir(lista, NULL);
}

static void prueba_iter_externo_insertar_medio() {
    int nums[5] = {1,2,3,4,5};
    int medio1 = 8, medio2 = 9;
    bool avanzar = true;
    lista_t* lista = lista_crear();
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&nums[0]));
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&nums[1]));
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&nums[2]));
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&nums[3]));
    print_test("Agregar elemento al principio", lista_insertar_primero(lista,&nums[4]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[4]);
    lista_iter_t* iter = lista_iter_crear(lista);
    print_test("Puedo ver el actual de mi iterador", lista_iter_ver_actual(iter) == &nums[4]);
    if (avanzar) avanzar = lista_iter_avanzar(iter);
    if (avanzar) avanzar = lista_iter_avanzar(iter);
    if (avanzar) avanzar = lista_iter_avanzar(iter);
    print_test("Puedo ver el actual de mi iterador", lista_iter_ver_actual(iter) == &nums[1]);
    print_test("Agregar elemento al medio", lista_iter_insertar(iter, &medio1) == true);
    print_test("Puedo ver el actual de mi iterador", lista_iter_ver_actual(iter) == &medio1);
    print_test("Agregar elemento al medio", lista_iter_insertar(iter, &medio2) == true);
    print_test("Puedo ver el actual de mi iterador", lista_iter_ver_actual(iter) == &medio2);
    lista_iter_destruir(iter);
    lista_destruir(lista, NULL);
}

static void prueba_iter_externo_insertar_final() {
    int nums[5] = {1,2,3,4,5};
    int prim = 8;
    lista_t* lista = lista_crear();
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista,&nums[0]));
    print_test("Puedo ver el ultimo elemento", lista_ver_ultimo(lista) == &nums[0]);
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista,&nums[1]));
    print_test("Puedo ver el ultimo elemento", lista_ver_ultimo(lista) == &nums[1]);
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista,&nums[2]));
    print_test("Puedo ver el ultimo elemento", lista_ver_ultimo(lista) == &nums[2]);
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista,&nums[3]));
    print_test("Puedo ver el ultimo elemento", lista_ver_ultimo(lista) == &nums[3]);
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista,&nums[4]));
    print_test("Puedo ver el ultimo elemento", lista_ver_ultimo(lista) == &nums[4]);
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[0]);
    print_test("El largo de mi lista es 5", lista_largo(lista) == 5);
    lista_iter_t* iter = lista_iter_crear(lista);
    print_test("Puedo crear el iterador", iter != NULL);
    print_test("Puedo ver el actual de mi iterador", lista_iter_ver_actual(iter) == &nums[0]);
    print_test("Puedo insertar el elemento", lista_iter_insertar(iter, &prim) == true);
    print_test("El largo de mi lista es 6", lista_largo(lista) == 6);
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &prim);
    lista_iter_destruir(iter);
    lista_destruir(lista, NULL);
}

static void prueba_iter_externo_borrar() {
    int nums[3] = {1,2,3};
    lista_t* lista = lista_crear();
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista, &nums[2]));
    print_test("Puedo ver el ultimo elemento", lista_ver_ultimo(lista) == &nums[2]);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista, &nums[1]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[1]);
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista,&nums[0]))  ;
    print_test("El largo de mi lista es 3", lista_largo(lista) == 3);
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[1]);
    print_test("Puedo ver el ultimo elemento", lista_ver_ultimo(lista) == &nums[0]);
    lista_iter_t *iter = lista_iter_crear(lista);
    print_test("Puedo crear el iterador", iter != NULL);
    print_test("Puedo ver el actual de mi iterador", lista_iter_ver_actual(iter) == &nums[1]);
    print_test("Borro un elemento de mi iterador y mi lista", lista_iter_borrar(iter) == &nums[1]);
    print_test("Borro un segundo elemento de mi iterador y mi lista", lista_iter_borrar(iter) == &nums[2]);
    print_test("Ver el primer elemento de mi lista", lista_ver_primero(lista) == &nums[0]);
    print_test("Ver el ultimo elemento de mi lista", lista_ver_ultimo(lista) == &nums[0]);
    print_test("El largo de mi lista es 1", lista_largo(lista) == 1);
    lista_iter_destruir(iter);
    lista_destruir(lista, NULL);
}

static void prueba_iter_externo_al_final() {
    int nums[2] = {1,2};
    lista_t* lista = lista_crear();
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    print_test("Agregar elemento al final", lista_insertar_ultimo(lista, &nums[1]));
    print_test("Puedo ver el ultimo elemento", lista_ver_ultimo(lista) == &nums[1]);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista, &nums[0]));
    print_test("El largo de mi lista es 2", lista_largo(lista) == 2);
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[0]);
    lista_iter_t *iter = lista_iter_crear(lista);
    print_test("Puedo crear el iterador", iter != NULL);
    print_test("Puedo ver el actual de mi iterador", lista_iter_ver_actual(iter) == &nums[0]);
    lista_iter_avanzar(iter);
    print_test("El iterador no se encuentra al final", lista_iter_al_final(iter) == false);
    lista_iter_avanzar(iter);
    print_test("El iterador se encuentra al final", lista_iter_al_final(iter) == true);
    lista_iter_destruir(iter);
    lista_destruir(lista, NULL);
}

static void prubea_iter_externo_medio_insertar() {
    int nums[5] = {1,2,3,5,6};
    int medio = 4;
    bool avanzar = true;
    lista_t* lista = lista_crear();
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista, &nums[4]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[4]);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista, &nums[3]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[3]);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista, &nums[2]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[2]);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista, &nums[1]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[1]);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista, &nums[0]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[0]);
    print_test("Puedo ver el ultimo elemento", lista_ver_ultimo(lista) == &nums[4]);
    lista_iter_t *iter = lista_iter_crear(lista);
    print_test("Puedo crear el iterador", iter != NULL);
    if (avanzar) avanzar = lista_iter_avanzar(iter);
    if (avanzar) avanzar = lista_iter_avanzar(iter);
    print_test("Puedo ver el actual de mi iterador", lista_iter_ver_actual(iter) == &nums[2]);
    print_test("El iterador no se encuentra al final", lista_iter_al_final(iter) == false);
    print_test("Puedo insertar el elemento", lista_iter_insertar(iter, &medio) == true);
    lista_iter_destruir(iter);
    lista_iter_t *iter2 = lista_iter_crear(lista);
    print_test("Puedo crear un segundo iterador", iter != NULL);
    while (!lista_iter_al_final(iter2) && avanzar) avanzar = lista_iter_avanzar(iter2);
    print_test("Puedo ver el ultimo elemento de mi lista", lista_ver_ultimo(lista) == &nums[4]);
    print_test("El iterador se encuentra al final", lista_iter_al_final(iter2) == true);
    lista_iter_destruir(iter2);
    lista_destruir(lista, NULL);
}


static void prueba_iter_externo_medio_borrar() {
    int nums[5] = {1,2,3,8,4};
    bool avanzar = true;
    lista_t* lista = lista_crear();
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista, &nums[4]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[4]);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista, &nums[3]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[3]);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista, &nums[2]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[2]);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista, &nums[1]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[1]);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista, &nums[0]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[0]);
    print_test("Puedo ver el ultimo elemento", lista_ver_ultimo(lista) == &nums[4]);
    lista_iter_t *iter = lista_iter_crear(lista);
    print_test("Puedo crear el iterador", iter != NULL);
    if (avanzar) avanzar = lista_iter_avanzar(iter);
    if (avanzar) avanzar = lista_iter_avanzar(iter);
    if (avanzar) avanzar = lista_iter_avanzar(iter);
    print_test("Puedo ver el actual de mi iterador", lista_iter_ver_actual(iter) == &nums[3]);
    lista_iter_borrar(iter);
    lista_iter_destruir(iter);
    lista_iter_t *iter2 = lista_iter_crear(lista);
    print_test("Puedo crear un segundo iterador", iter != NULL);
    print_test("Ver el ultimo elemento de mi lista", lista_ver_ultimo(lista) == &nums[4]);
    print_test("Puedo ver el actual de mi iterador", lista_iter_ver_actual(iter2) == &nums[0]);
    if (avanzar) avanzar = lista_iter_avanzar(iter2);
    if (avanzar) avanzar = lista_iter_avanzar(iter2);
    if (avanzar) avanzar = lista_iter_avanzar(iter2);
    if (avanzar) avanzar = lista_iter_avanzar(iter2);
    print_test("El iterador se encuentra al final", lista_iter_al_final(iter2));
    lista_iter_destruir(iter2);
    lista_destruir(lista, NULL);
}

static void prueba_iterador_borrar_2() {
    int nums[3] = {1,2,3};
    lista_t* lista = lista_crear();
    print_test("La lista se puede crear", lista);
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El largo de mi lista es 0", lista_largo(lista) == 0);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista, &nums[2]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[2]);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista, &nums[1]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[1]);
    print_test("Agregar elemento al principio", lista_insertar_primero(lista, &nums[0]));
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[0]);
    lista_iter_t *iter = lista_iter_crear(lista);
    print_test("Puedo crear el iterador", iter != NULL);
    print_test("Puedo ver el actual de mi iterador", lista_iter_ver_actual(iter) == &nums[0]);
    print_test("Elimino el actual de mi iterador", lista_iter_borrar(iter) == &nums[0]);
    print_test("Puedo ver el actual de mi iterador", lista_iter_ver_actual(iter) == &nums[1]);
    print_test("Elimino el actual de mi iterador", lista_iter_borrar(iter) == &nums[1]);
    print_test("Puedo ver el actual de mi iterador", lista_iter_ver_actual(iter) == &nums[2]);
    print_test("La lista esta vacia", lista_esta_vacia(lista) == false);
    print_test("El largo de mi lista no es 0", lista_largo(lista) == 1);
    print_test("Puedo ver el primer elemento", lista_ver_primero(lista) == &nums[2]);
    print_test("Puedo ver el primer elemento", lista_ver_ultimo(lista) == &nums[2]);
    print_test("Elimino el actual de mi iterador", lista_iter_borrar(iter) == &nums[2]);
    print_test("El iterador se encuentra al final", lista_iter_al_final(iter));
    lista_iter_destruir(iter);
    lista_destruir(lista, NULL);
}

void pruebas_lista_estudiante() {
    prueba_lista_vacia();
    prueba_lista_vacia_2();
    prueba_lista_vaciada();
    prueba_insertar_primero();
    prueba_insertar_ultimo();
    prueba_insertar_mezclado();
    prueba_null();
    prueba_modificar_elems();
    prueba_insertar_lista();
    prueba_lista_no_vacia();
    prueba_lista_no_vacia_2();
    prueba_iter_interno_extra();
    prubea_iter_externo_avanzar();
    prueba_iter_externo_insertar_principio();
    prueba_iter_externo_insertar_medio();
    prueba_iter_externo_insertar_final();
    prueba_iter_externo_borrar();
    prueba_iter_externo_al_final();
    prubea_iter_externo_medio_insertar();
    prueba_iter_externo_medio_borrar();
    prueba_iterador_borrar_2();
}


#ifndef CORRECTOR

int main(void) {
    pruebas_lista_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif