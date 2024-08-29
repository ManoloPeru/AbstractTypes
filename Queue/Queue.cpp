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
