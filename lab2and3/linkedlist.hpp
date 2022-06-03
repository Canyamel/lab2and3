#pragma once

#include "node.hpp"
#include <iostream>

template <class T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList();
    LinkedList(T*, int);
    LinkedList(LinkedList<T>*);
    T GetFirst();
    T GetLast();
    T Get(int);
    LinkedList<T>* GetSubList(int, int);
    int GetLength();
    void Append(T);
    void Prepend(T);
    void InsertAt(T, int);
    LinkedList<T>* Concat(LinkedList<T>*);
};

template <class T>

LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template <class T>
LinkedList<T>::LinkedList(T* items, int size)
{
    this->size = size;
    for (int i = 0; i < size; i++)
    {
        Node<T>* p = new Node<T>(items[i]);
        if (i == 0)
        {
            this->head = p;
            this->tail = p;
        }
        else
        {
            this->tail->next = p;
            this->tail = p;
        }
    }
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T>* list)
{
    this->size = list->size;
    Node<T>* p = list->head;
    for (int i = 0; i < list->size; i++)
    {
        Node<T>* newp = new Node<T>(p->data);
        if (i == 0)
        {
            this->head = newp;
            this->tail = newp;
        }
        else
        {
            this->tail->next = newp;
            this->tail = newp;
        }
        p = p->next;
    }
}

template <class T>
T LinkedList<T>::GetFirst()
{
    return this->head->data;
}

template <class T>
T LinkedList<T>::GetLast()
{
    return tail->data;
}

template <class T>
T LinkedList<T>::Get(int index)
{
    Node<T>* p = this->head;
    for (int i = 0; i < index; i++)
    {
        p = p->next;
    }
    return p->data;
}

template <class T>
LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex)
{
    T* array = new T[endIndex - startIndex + 1];
    Node<T>* p = this->head;
    for (int i = 0; i < startIndex; i++)
    {
        p = p->next;
    }
    int j = 0;
    for (int i = startIndex; i <= endIndex; i++)
    {
        array[j] = p->data;
        p = p->next;
        j++;
    }
    LinkedList<T>* newList = new LinkedList<T>(array, endIndex - startIndex + 1);
    return newList;
}

template <class T>
int LinkedList<T>::GetLength()
{
    return this->size;
}

template <class T>
void LinkedList<T>::Append(T item)
{
    Node<T>* p = new Node<T>(item);
    if (this->head == nullptr)
    {
        this->head = p;
        this->tail = p;
    }
    else
    {
        this->tail->next = p;
        this->tail = p;
    }
}

template <class T>
void LinkedList<T>::Prepend(T item)
{
    Node<T>* p = new Node<T>(item);
    p->next = head;
    this->head = p;
}

template <class T>
void LinkedList<T>::InsertAt(T item, int index)
{
    Node<T>* p = head;
    for (int i = 0; i != index; i++)
    {
        p = p->next;
    }
    p->data = item;
}

template <class T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T>* list)
{
    T* array = new T[this->GetLength() + list->GetLength()];
    Node<T>* p = this->head;
    int j = 0;
    for (int i = 0; i < this->GetLength(); i++)
    {
        array[j] = p->data;
        p = p->next;
        j++;
    }
    p = list->head;
    for (int i = 0; i < list->GetLength(); i++)
    {
        array[j] = p->data;
        p = p->next;
        j++;
    }
    LinkedList<T>* newList = new LinkedList<T>(array, this->GetLength() + list->GetLength());
    return newList;
}