/**************************************************************************************************/
/*Implementación 1*/
/**************************************************************************************************/
#include "pch.h"
using namespace System;
// Clase Nodo para la lista enlazada
// Va ser un elemento de la lista
ref class Node
{
    public:
        int data; //El tipo de dato puede cambiar a char, float o clase
        Node^ next;
        Node(int val)
        {
            data = val;
            next = nullptr;
        }
};

// Clase ListaEnlazada para gestionar la lista
ref class LinkedList
{
    private:
        Node^ head; //Variable que contendra la dirección del primer nodo de la lista
    public:
        // Método constructor 
        LinkedList()
        {
            head = nullptr; //head apunta a NULL, no existe ningun Nodo
        }

        // Método para agregar un nodo al final de la lista
        void Add(int val)
        {
            Node^ newNode = gcnew Node(val); //Asignamos un espacio de memoria
            if (head == nullptr)
            {
                //Si la lista esta vacia asignamos el primer nodo
                head = newNode;
            }
            else
            {
                //Lista no vacia
                Node^ current = head;
                while (current->next != nullptr)
                {   
                    //Recorremos la lista hasta el último Nodo
                    current = current->next;
                }
                //En el ultimo Nodo de la lista apuntamos (next) al un nuevo nodo y se convierte en el último
                current->next = newNode;
            }
        }

        // Método para remover un nodo según el valor buscado
        void Remove(int valor)
        {
            if (head == nullptr)
            {
                //Si la lista esta vacia asignamos el primer elemento
                Console::Write("Lista vacia...!");
                return;
            }

            //Buscar el nodo a eliminar
            if (head->data == valor)
            {
                //Si esta en el primer nodo
                head = head->next; //El segundo nodo pasa a ser el primer elemento
                return;
            }

            Node^ temp = head;
            Node^ prev = nullptr;

            while (temp != nullptr && temp->data != valor)
            {
                //Recorremos la lista buscando el nodo que tiene el valor que queremos eliminar. 
                // Mantenemos un puntero al nodo anterior (prev) para poder modificar su next 
                // cuando encontremos el nodo a eliminar.
                prev = temp;
                temp = temp->next;
            }

            if (temp == nullptr)
            {   //No existe el valor en la lista
                Console::WriteLine("Nodo con valor " + valor + " no encontrado.");
                return;
            }
            //Si encontramos el nodo, desvinculamos el nodo eliminando su referencia desde el nodo anterior
            prev->next = temp->next;
        }

        // Método para mostrar todos los Nodos de la lista
        void Display()
        {
            Node^ current = head; //current apunta al primer nodo "head" de la lista 
            while (current != nullptr)
            {
                Console::Write("{0} -> ", current->data);
                current = current->next;
            }
            Console::WriteLine("nullptr");//Libre para agregar otro Nodo
        }
};
int main(array<System::String^>^ args)
{
    LinkedList^ list = gcnew LinkedList();
    list->Add(10);
    list->Add(20);
    list->Add(30);
    list->Display(); // Muestra: 10 -> 20 -> 30 -> nullptr

    Console::WriteLine("Eliminar 20");
    list->Remove(20);
    list->Display(); // Muestra: 10 -> -> 30 -> nullptr

    Console::WriteLine("Eliminar 5");
    list->Remove(5); // No existe el elemento 5
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
    // Crear una lista enlazada de enteros
    LinkedList<int>^ lista = gcnew LinkedList<int>();

    // Agregar elementos a la lista
    lista->AddLast(10);
    lista->AddLast(20);
    lista->AddLast(30);

    // Insertar un elemento al principio
    lista->AddFirst(5);

    // Mostrar los elementos de la lista
    for each (int value in lista)
    {
        Console::WriteLine(value);
    }

    // Eliminar un elemento
    lista->Remove(20);

    // Mostrar los elementos de la lista después de la eliminación
    Console::WriteLine("Después de eliminar 20:");
    for each (int value in lista)
    {
        Console::WriteLine(value);
    }

    return 0;
}
/**************************************************************************************************/