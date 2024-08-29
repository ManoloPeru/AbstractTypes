/**************************************************************************************************/
/*Implementación 1*/
/**************************************************************************************************/
#include "pch.h"
using namespace System;

ref class Nodo {
public:
    int valor;
    Nodo^ siguiente;

    Nodo(int valor) {
        this->valor = valor;
        this->siguiente = nullptr;
    }
};

ref class Pila {
private:
    Nodo^ cima;

public:
    Pila() {
        cima = nullptr;
    }

    // Método para agregar un elemento a la Pila
    void agregarPila(int valor) {
        Nodo^ nuevoNodo = gcnew Nodo(valor);
        nuevoNodo->siguiente = cima;
        cima = nuevoNodo;
        Console::WriteLine("Nodo con valor {0} agregado a la Pila.", valor);
    }

    // Método para sacar un elemento de la Pila
    void sacarPila() {
        if (cima == nullptr) {
            Console::WriteLine("La Pila está vacía. No se puede sacar elementos.");
            return;
        }
        Console::WriteLine("Nodo con valor {0} sacado de la Pila.", cima->valor);
        cima = cima->siguiente;
    }

    // Método para mostrar todos los elementos de la Pila
    void mostrarPila() {
        if (cima == nullptr) {
            Console::WriteLine("La Pila está vacía.");
            return;
        }

        Nodo^ actual = cima;
        Console::WriteLine("Elementos en la Pila:");
        while (actual != nullptr) {
            Console::WriteLine(actual->valor);
            actual = actual->siguiente;
        }
    }

    // Método para buscar y eliminar un Nodo de la Pila
    void buscarYEliminar(int valor) {
        if (cima == nullptr) {
            Console::WriteLine("La Pila está vacía.");
            return;
        }

        // Si el nodo a eliminar es el primero
        if (cima->valor == valor) {
            cima = cima->siguiente;
            Console::WriteLine("Nodo con valor {0} eliminado de la Pila.", valor);
            return;
        }

        Nodo^ actual = cima;
        Nodo^ anterior = nullptr;

        while (actual != nullptr && actual->valor != valor) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (actual == nullptr) {
            Console::WriteLine("Nodo con valor {0} no encontrado en la Pila.", valor);
            return;
        }

        anterior->siguiente = actual->siguiente;
        Console::WriteLine("Nodo con valor {0} eliminado de la Pila.", valor);
    }
};

int main(array<String^>^ args) {
    Pila^ pila = gcnew Pila();

    pila->agregarPila(10);
    pila->agregarPila(20);
    pila->agregarPila(30);

    pila->mostrarPila();

    pila->sacarPila();
    pila->mostrarPila();

    pila->buscarYEliminar(20);
    pila->mostrarPila();

    pila->buscarYEliminar(50);

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
    // Crear una pila de enteros
    Stack<int>^ pila = gcnew Stack<int>();

    // Apilar (push) elementos en la pila
    pila->Push(10);
    pila->Push(20);
    pila->Push(30);

    // Desapilar (pop) elementos y mostrarlos
    while (pila->Count > 0)
    {
        int top = pila->Pop();
        Console::WriteLine(top);
    }

    return 0;
}
/**************************************************************************************************/