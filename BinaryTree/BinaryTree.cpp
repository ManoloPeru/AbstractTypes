#include "pch.h"

using namespace System;

// Definici�n de la clase Nodo del �rbol
public ref class TreeNode
{
public:
    int value;
    TreeNode^ left;
    TreeNode^ right;

    // Constructor para inicializar un nodo con un valor
    TreeNode(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Definici�n de la clase �rbol Binario
public ref class BinaryTree
{
public:
    TreeNode^ root;

    // Constructor para inicializar el �rbol vac�o
    BinaryTree()
    {
        root = nullptr;
    }

    // M�todo para insertar un valor en el �rbol
    void Insert(int val)
    {
        root = InsertRec(root, val);
    }

    // M�todo recursivo auxiliar para insertar un valor
private:
    TreeNode^ InsertRec(TreeNode^ node, int val)
    {
        if (node == nullptr)
        {
            node = gcnew TreeNode(val);
            return node;
        }

        if (val < node->value)
        {
            node->left = InsertRec(node->left, val);
        }
        else if (val > node->value)
        {
            node->right = InsertRec(node->right, val);
        }

        return node;
    }

public:
    // M�todo para recorrer el �rbol en orden
    void InOrder()
    {
        InOrderRec(root);
    }

private:
    void InOrderRec(TreeNode^ node)
    {
        if (node != nullptr)
        {
            InOrderRec(node->left);
            Console::Write("{0} ", node->value);
            InOrderRec(node->right);
        }
    }

    // M�todo para buscar un valor en el �rbol
public:
    bool Search(int val)
    {
        return SearchRec(root, val);
    }

private:
    bool SearchRec(TreeNode^ node, int val)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (node->value == val)
        {
            return true;
        }
        else if (val < node->value)
        {
            return SearchRec(node->left, val);
        }
        else
        {
            return SearchRec(node->right, val);
        }
    }
};

int main(array<System::String ^> ^args)
{
    // Crear un �rbol binario
    BinaryTree^ tree = gcnew BinaryTree();

    // Insertar elementos en el �rbol
    tree->Insert(50);
    tree->Insert(30);
    tree->Insert(20);
    tree->Insert(40);
    tree->Insert(70);
    tree->Insert(60);
    tree->Insert(80);

    // Recorrer el �rbol en orden y mostrar los elementos
    Console::WriteLine("Recorrido en orden del �rbol:");
    tree->InOrder();
    Console::WriteLine();

    // Buscar elementos en el �rbol
    int searchValue = 40;
    Console::WriteLine("Buscar {0} en el �rbol: {1}", searchValue, tree->Search(searchValue) ? "Encontrado" : "No encontrado");

    searchValue = 90;
    Console::WriteLine("Buscar {0} en el �rbol: {1}", searchValue, tree->Search(searchValue) ? "Encontrado" : "No encontrado");

    return 0;
}
