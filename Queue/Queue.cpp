/**************************************************************************************************/
/*Implementación 1*/
/**************************************************************************************************/
#include "pch.h"
#include <iostream>
#include <cliext/list> // Para utilizar la clase List en C++/CLI

using namespace System;
using namespace cliext;

ref class Nodo {
public:
    int dato; // Dato almacenado en el Nodo
    Nodo^ siguiente; // Puntero al siguiente Nodo

    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

ref class Cola {
private:
    Nodo^ frente; // Puntero al primer elemento de la Cola
    Nodo^ final; // Puntero al último elemento de la Cola

public:
    Cola() {
        frente = nullptr;
        final = nullptr;
    }

    // Método para agregar un Nodo a la Cola
    void agregarCola(int valor) {
        Nodo^ nuevoNodo = gcnew Nodo(valor);

        if (final == nullptr) { // Si la cola está vacía
            frente = nuevoNodo;
            final = nuevoNodo;
        }
        else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }

        Console::WriteLine("Nodo con valor {0} agregado a la cola.", valor);
    }

    // Método para sacar un Nodo de la Cola
    void sacarCola() {
        if (frente == nullptr) { // Si la cola está vacía
            Console::WriteLine("La cola está vacía. No se puede sacar ningún nodo.");
            return;
        }

        Nodo^ nodoSacar = frente;
        frente = frente->siguiente;

        if (frente == nullptr) { // Si la cola se vacía después de sacar el Nodo
            final = nullptr;
        }

        Console::WriteLine("Nodo con valor {0} sacado de la cola.", nodoSacar->dato);
    }

    // Método para mostrar todos los elementos de la Cola
    void mostrarElementos() {
        if (frente == nullptr) {
            Console::WriteLine("La cola está vacía.");
            return;
        }

        Nodo^ actual = frente;
        Console::Write("Elementos en la cola: ");
        while (actual != nullptr) {
            Console::Write("{0} ", actual->dato);
            actual = actual->siguiente;
        }
        Console::WriteLine();
    }

    // Método para buscar y eliminar un Nodo de la Cola
    void buscarYEliminar(int valor) {
        if (frente == nullptr) { // Si la cola está vacía
            Console::WriteLine("La cola está vacía. No se puede buscar ni eliminar.");
            return;
        }

        Nodo^ actual = frente;
        Nodo^ anterior = nullptr;

        // Buscar el nodo
        while (actual != nullptr && actual->dato != valor) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (actual == nullptr) { // Si no se encontró el nodo
            Console::WriteLine("Nodo con valor {0} no encontrado en la cola.", valor);
            return;
        }

        // Eliminar el nodo
        if (anterior == nullptr) { // Si el nodo a eliminar es el primero
            frente = actual->siguiente;
        }
        else {
            anterior->siguiente = actual->siguiente;
        }

        if (actual == final) { // Si el nodo a eliminar es el último
            final = anterior;
        }

        Console::WriteLine("Nodo con valor {0} eliminado de la cola.", valor);
    }
};

int main() {
    Cola^ miCola = gcnew Cola();

    // Agregar elementos a la Cola
    miCola->agregarCola(10);
    miCola->agregarCola(20);
    miCola->agregarCola(30);

    // Mostrar elementos de la Cola
    miCola->mostrarElementos();

    // Sacar un elemento de la Cola
    miCola->sacarCola();

    // Mostrar elementos de la Cola nuevamente
    miCola->mostrarElementos();

    // Buscar y eliminar un nodo específico
    miCola->buscarYEliminar(20);

    // Mostrar elementos de la Cola nuevamente
    miCola->mostrarElementos();

    return 0;
}


/**************************************************************************************************/
/*Implementación 2*/
/**************************************************************************************************
#include "pch.h"

using namespace System;
using namespace System::Collections::Generic;

int main(array<System::String ^> ^args)
{
    // Crear una cola de enteros
    Queue<int>^ cola = gcnew Queue<int>();

    // Encolar (enqueue) elementos en la cola
    cola->Enqueue(10);
    cola->Enqueue(20);
    cola->Enqueue(30);

    // Desencolar (dequeue) elementos y mostrarlos
    while (cola->Count > 0)
    {
        int front = cola->Dequeue();
        Console::WriteLine(front);
    }

    return 0;
}
/**************************************************************************************************/