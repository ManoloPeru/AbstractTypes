#include "pch.h"

using namespace System;

// Definición de la clase Nodo del árbol
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

// Definición de la clase Árbol Binario
public ref class BinaryTree
{
public:
    TreeNode^ root;

    // Constructor para inicializar el árbol vacío
    BinaryTree()
    {
        root = nullptr;
    }

    // Método para insertar un valor en el árbol
    void Insert(int val)
    {
        root = InsertRec(root, val);
    }

    // Método recursivo auxiliar para insertar un valor
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
    // Método para recorrer el árbol en orden
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

    // Método para buscar un valor en el árbol
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
    // Crear un árbol binario
    BinaryTree^ tree = gcnew BinaryTree();

    // Insertar elementos en el árbol
    tree->Insert(50);
    tree->Insert(30);
    tree->Insert(20);
    tree->Insert(40);
    tree->Insert(70);
    tree->Insert(60);
    tree->Insert(80);

    // Recorrer el árbol en orden y mostrar los elementos
    Console::WriteLine("Recorrido en orden del árbol:");
    tree->InOrder();
    Console::WriteLine();

    // Buscar elementos en el árbol
    int searchValue = 40;
    Console::WriteLine("Buscar {0} en el árbol: {1}", searchValue, tree->Search(searchValue) ? "Encontrado" : "No encontrado");

    searchValue = 90;
    Console::WriteLine("Buscar {0} en el árbol: {1}", searchValue, tree->Search(searchValue) ? "Encontrado" : "No encontrado");

    return 0;
}
