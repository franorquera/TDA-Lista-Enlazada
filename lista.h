#ifndef LISTA_H
#define LISTA_H
#include <stdbool.h>
#include <stdlib.h>

struct lista;
struct lista_iter;
typedef struct lista lista_t;
typedef struct lista_iter lista_iter_t;

// Crea una lista
// Post: devuelve una lista vacia
lista_t *lista_crear(void);

// Devuelve verdadero si la lista no tiene elementos, falso en caso contrario.
// Pre: la lista fue creada.
bool lista_esta_vacia(const lista_t *lista);

// Agrega un nuevo primer elemento a la lista. Devuelve falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo primer elemento a la lista, dato se encuentra al principio
// de la lista.
bool lista_insertar_primero(lista_t *lista, void *dato);

// Agrega un nuevo ultimo elemento a la lista. Devuelve falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo ultimo elemento a la lista, dato se encuentra al final
// de la lista.
bool lista_insertar_ultimo(lista_t *lista, void *dato);

// Saca el primer elemento de la lista. Si la lista tiene elementos, se quita el
// primero de la lista, y se devuelve su valor, si está vacía, devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el valor del primer elemento anterior, la lista
// contiene un elemento menos, si la lista no estaba vacía.
void *lista_borrar_primero(lista_t *lista);

// Obtiene el valor del primer elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del primero, si está vacía devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el primer elemento de la lista, cuando no está vacía.
void *lista_ver_primero(const lista_t *lista);

// Obtiene el valor del ultimo elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del ultimo, si está vacía devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el ultimo elemento de la lista, cuando no está vacía.
void *lista_ver_ultimo(const lista_t* lista);

// Obitene el largo de la lista.
// Pre: la lista fue creada.
// Post: se devuelve el largo de la lista
size_t lista_largo(const lista_t *lista);

// Destruye la lista. Si se recibe la función destruir_dato por parámetro,
// para cada uno de los elementos de la lista llama a destruir_dato.
// Pre: la lista fue creada. destruir_dato es una función capaz de destruir
// los datos de la cola, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la lista.
void lista_destruir(lista_t *lista, void (*destruir_dato)(void *));

/* ITERADOR INTERNO */

// Recorre la lista. Si se recibe la funcion visitar por parametro,
// para cada uno de los elementos de la lista llama a visitar.
// Pre: la lista fue creada. visitar es una funcion capaz de modificar
// cada dato y aplicarle un extra el cual recibe la funcion visitar.
void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra);

/* ITERADOR EXTERNO */

// Crea un iterador el cual apunta al primer elemento.
// Pre: la lista fue creada.
// Post: devuelve un iterador de la lista
lista_iter_t *lista_iter_crear(lista_t *lista);

// Recorre desde el primer elemento de la lista, de a uno a la
// vez. Si la lista esta vacia devuelve false.
// Pre: La lista y el iterador fueron creados
// Post: avanza una posicion y devuelve true.
bool lista_iter_avanzar(lista_iter_t *iter);

// Devuelve el valor del elemento actual del iterador.
// En caso contrario devuelve Null.
// Pre: la lista y el iterador fueron creados.
void *lista_iter_ver_actual(const lista_iter_t *iter);

// Devuelve true si el iterador esta al final de la lista.
// Pre: la lista y el iterador fueron creados.
bool lista_iter_al_final(const lista_iter_t *iter);

// Destruye el iterador.
// Pre: el iterador fue creado.
void lista_iter_destruir(lista_iter_t *iter);

// Inserta un elemento delante del actual.
// Pre: la lista y el iterador fueron creados.
bool lista_iter_insertar(lista_iter_t *iter, void *dato);

// Borra y devuelve el elemento actual de la lista.
// Pre: la lista y el iterador fueron creados.
void *lista_iter_borrar(lista_iter_t *iter);

/* PRUEBAS UNITARIAS */

// Realiza pruebas sobre la implementación realizada.
//
// Las pruebas deben remplazarse en el archivo ‘pruebas_lista.c’, y
// solamente pueden emplear la interfaz pública tal y como aparece en lista.h
void pruebas_lista_estudiante(void);

#endif // LISTA_H   