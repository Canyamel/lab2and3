#pragma once

#include "linkedlist.hpp"
#include "node.hpp"
#include "sequence.hpp"

template <class T>
class LinkedListSequence : public Sequence<T>
{
private:
    LinkedList<T>* items;

public:
    LinkedListSequence();
    LinkedListSequence(T*, int);
    LinkedListSequence(LinkedList<T>*);
    T GetFirst() override;
    T GetLast() override;
    T Get(int);
    Sequence<T>* GetSubsequence(int, int) override;
    int GetLength() override;
    void Append(T) override;
    void Prepend(T) override;
    void InsertAt(T, int) override;
    Sequence<T>* Concat(Sequence<T>*) override;
};

template <class T>
LinkedListSequence<T>::LinkedListSequence()
{
    this->items = new LinkedList<T>(nullptr, nullptr, 0);
}

template <class T>
LinkedListSequence<T>::LinkedListSequence(T* item, int size)
{
    this->items = new LinkedList<T>(item, size);
}

template <class T>
LinkedListSequence<T>::LinkedListSequence(LinkedList<T>* list)
{
    this->items = new LinkedList<T>(list);
}

template <class T>
T LinkedListSequence<T>::GetFirst()
{
    return items->GetFirst();
}

template <class T>
T LinkedListSequence<T>::GetLast()
{
    return items->GetLast();
}

template <class T>
T LinkedListSequence<T>::Get(int index)
{
    return items->Get(index);
}

template <class T>
Sequence<T>* LinkedListSequence<T>::GetSubsequence(int startIndex, int endIndex)
{
    T* array = new T[endIndex - startIndex + 1];
    int j = 0;
    for (int i = startIndex; i <= endIndex; i++)
    {
        array[j] = this->items->Get(i);
        j++;
    }
    LinkedListSequence<T>* newList = new LinkedListSequence<T>(array, endIndex - startIndex + 1);
    Sequence<T>* res = newList;
    return res;
}

template <class T>
int LinkedListSequence<T>::GetLength()
{
    return items->GetLength();
}

template <class T>
void LinkedListSequence<T>::Append(T item)
{
    items->Append(item);
}

template <class T>
void LinkedListSequence<T>::Prepend(T item)
{
    items->Prepend(item);
}

template <class T>
void LinkedListSequence<T>::InsertAt(T item, int index)
{
    items->InsertAt(item, index);
}

template <class T>
Sequence<T>* LinkedListSequence<T>::Concat(Sequence<T>* list)
{
    T* array = new T[this->items->GetLength() + list->GetLength() + 1];
    int j = 0;
    for (int i = 0; i < this->items->GetLength(); i++)
    {
        array[j] = this->items->Get(i);
        j++;
    }
    for (int i = 0; i < list->GetLength(); i++)
    {
        array[j] = list->Get(i);
        j++;
    }
    LinkedListSequence<T>* newList = new LinkedListSequence<T>(array, this->items->GetLength() + list->GetLength());
    Sequence<T>* res = newList;
    return res;
}