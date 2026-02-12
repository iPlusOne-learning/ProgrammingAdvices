#pragma once

#include <iostream>
#include <vector>
#include "clsDblLinkedList.h"

using namespace std;

template <class T>
class clsMyQueue
{

public:

    protected:
    clsDblLinkedList <T> _MyList;
    
    public:
    void push(T Item)
    {
        _MyList.InsertAtEnd(Item);
    }

    T front()
    {
        return _MyList.GetItem(0);
    }

    T back()
    {
        return _MyList.GetItem(Size() - 1);
    }

    void pop()
    {
        _MyList.DeleteFirstNode();
    }

    void Print()
    {
       _MyList.PrintList();
    }

    bool IsEmpty()
    {
        return _MyList.IsEmpty();
    }
    unsigned int Size()
    {
        return _MyList.Size();
    }

    T GetItem(T Index)
    {
       return _MyList.GetItem(Index);
    }
    void Reverse()
    {
        _MyList.Reverse();
    }
    bool UpdateItem(T Index, T NewValue)
    {
        return _MyList.UpdateItem(Index, NewValue);
    }
    void InsertAfter(T Index, T Value)
    {
        _MyList.InsertAfter(Index, Value);
    }
    void InsertAtFront(T Value)
    {
        _MyList.InsertAtBeginning(Value);
    }
        void InsertAtBack(T Value)
    {
        _MyList.InsertAtEnd(Value);
    }
    void Clear()
    {
        _MyList.Clear();
    }
};


// template <class T>
// class clsMyQueue
// {

// public:
//     class Node
//     {
//     public:
//         T value;
//         Node *next;
//         Node *prev;
//     };

//     Node *head = nullptr;
//     unsigned int Counter = 0;

//     void push(T Element)
//     {
//         Node *current = head;
//         Node *newNode = new Node();

//         newNode->value = Element;
//         newNode->next = nullptr;
//         if (head == nullptr)
//         {
//             newNode->prev = nullptr;
//             head = newNode;
//             Counter++;
//             return;
//         }
//         if (head->next == nullptr)
//         {
//             current->next = newNode;
//             newNode->prev = current;
//             Counter++;
//             return;
//         }
//         while (current->next != NULL)
//         {
//             current = current->next;
//         }
//         current->next = newNode;
//         newNode->prev = current;
//         Counter++;
//     }

//     T front()
//     {
//         return head->value;
//     }

//     T back()
//     {
//         Node* current = head;
//         while(current->next != nullptr)
//         {
//             current  = current->next;
//         }
//         return current->value;
//     }

//     void pop()
//     {
//         Node* current = head;
//         Node* toDelete = head;

//         current = current->next;
//         current->prev = nullptr;
//         head = current;
//         delete toDelete;
//     }

//     void Print()
//     {
//         Node *current = head;
//         while (current != nullptr)
//         {
//             cout << current->value << " ";
//             current = current->next;
//         }
//         cout << "\n";
//     }

//     unsigned int Size()
//     {
//         return Counter;
//     }
// };
