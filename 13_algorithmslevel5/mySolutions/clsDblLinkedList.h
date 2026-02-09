#pragma once

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class clsDblLinkedList
{
    public:
    class Node;

    private:

    Node* _head;
    Node* _tail;

    public:
    class Node
    {
        public:
        T value;
        Node* next;
        Node* prev;
    };
    clsDblLinkedList() : _head(NULL), _tail(NULL) {}

    void InsertAtBeginning(T value1)
    {
        Node* new_node = new Node();
        new_node->value = value1;
        if (_head == NULL)
        {
            _head = new_node;
            _head->next = NULL;
            _head->prev = NULL;
            return ;
        }
        new_node->next = _head;
        new_node->prev = NULL;

        _head->prev = new_node;
        _head = new_node;
    }

    Node* Find(T value1)
    {
        Node* current = _head;

        if (_head == NULL)
            return NULL;
        while (current != NULL)
        {
            if (current->value == value1)
            {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    void InsertAfter(Node* node, T value1)
    {
        Node* current = node;
        Node* new_node = new Node();
        new_node->value = value1;
        new_node->prev = node;

        if (node->next == NULL)
        {
            node->next = new_node;
            new_node->next = NULL;
            return;
        }
        current = node->next;
        node->next = new_node;
        current->prev = new_node;
        new_node->next = current;
    }
    
    void InsertAtEnd(T value1)
    {
        Node* curent = _head;
        Node* new_node = new Node();
        new_node->value = value1;
        new_node->next = NULL;

        if (_head == NULL)
        {   
            new_node->prev = NULL;
            _head = new_node;
            return ;
        }
        while(curent->next != NULL)
        {
            curent = curent->next;
        }
        curent->next = new_node;
        new_node->prev = curent;
    }

    void DeleteNode(Node* node)
    {
        Node* next_node = node;
        Node* prev_node = node;

        if (_head == NULL)
            return ;
        
        next_node = node->next;
        prev_node = node->prev;

        prev_node->next = next_node;
        next_node->prev = prev_node;
        
        delete node;
    }

    void DeleteFirstNode()
    {
        Node* node = _head;

        if (_head == NULL)
            return ;
        if (node->next == NULL)
        {
            _head = NULL;
            delete node;
            return ;
        }
        _head = node->next;
        _head->prev = NULL;

        delete node;
    }

    void DeleteLastNode()
    {
        Node* prev = _head;
        Node* last_node = prev;

        if (_head == NULL)
            return ;
        if (_head->next == NULL)
        {
            delete _head;
            _head = NULL;
            return ;
        }
        while (prev->next->next != NULL)
        {
            prev = prev->next;
        }

        last_node = prev->next;
        prev->next = NULL;

        delete last_node;
    }

    void PrintList()
    {
        Node* list = _head;
        while (list != NULL)
        {
            cout << list->value << " ";
            list = list->next;
        }
        cout << endl;
        delete list;
    }
};