#pragma once

#include "dynamicarray.hpp"
#include "node.hpp"
#include "linkedlist.hpp"
#include "sequence.hpp"

template <class T>
class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T>* items;

public:
    ArraySequence();
    ArraySequence(T*, int);
    ArraySequence(LinkedList<T>*);
    T GetFirst() override;
    T GetLast() override;
    T Get(int) override;
    Sequence<T>* GetSubsequence(int, int) override;
    int GetLength() override;
    void Append(T) override;
    void Prepend(T) override;
    void InsertAt(T, int) override;
    Sequence<T>* Concat(Sequence<T>*) override;

};

template <class T>
ArraySequence<T>::ArraySequence()
{
    this->items = new DynamicArray<T>(nullptr, 0);
}

template <class T>
ArraySequence<T>::ArraySequence(T* item, int size)
{
    this->items = new DynamicArray<T>(item, size);
}

template <class T>
ArraySequence<T>::ArraySequence(LinkedList<T>* list)
{
    T* array = new T[list->GetLength()];
    Node<T> p = list->head;
    for (int i = 0; i < list->size; i++)
    {
        array[i] = p->data;
        p = p->next;
    }
    this->items = new DynamicArray<T>(array, list->GetLength());
}

template <class T>
T ArraySequence<T>::GetFirst()
{
    return this->items->Get(0);
}

template <class T>
T ArraySequence<T>::GetLast()
{
    return this->items->Get(this->items->GetSize() - 1);
}

template <class T>
T ArraySequence<T>::Get(int index)
{
    return this->items->Get(index);
}

template <class T>
Sequence<T>* ArraySequence<T>::GetSubsequence(int startIndex, int endIndex)
{
    T* array = new T[endIndex - startIndex + 1];
    int j = 0;
    for (int i = startIndex; i <= endIndex; i++)
    {
        array[j] = this->items->Get(i);
        j++;
    }
    ArraySequence<T>* newList = new ArraySequence<T>(array, endIndex - startIndex + 1);
    Sequence<T>* res = newList;
    return res;
}

template <class T>
int ArraySequence<T>::GetLength()
{
    return this->items->GetSize();
}

template <class T>
void ArraySequence<T>::Append(T item)
{
    this->items->Resize(this->items->GetSize() + 1);
    this->items->Set(item, this->items->GetSize() - 1);
}

template <class T>
void ArraySequence<T>::Prepend(T item)
{
    this->items->Resize(this->items->GetSize() + 1);
    for (int i = this->items->GetSize() - 1; i > 0; i--)
    {
        this->items->Set(this->items->Get(i), i - 1);
    }
    this->items->Set(0, item);
}

template <class T>
void ArraySequence<T>::InsertAt(T item, int index)
{
    this->items->Set(item, index);
}

template <class T>
Sequence<T>* ArraySequence<T>::Concat(Sequence<T>* list)
{
    T* array = new T[this->items->GetSize() + list->GetLength() + 2];
    int j = 0;
    for (int i = 0; i < this->items->GetSize(); i++)
    {
        array[j] = this->items->Get(i);
        j++;
    }
    for (int i = 0; i < list->GetLength(); i++)
    {
        array[j] = list->Get(i);
        j++;
    }
    ArraySequence<T>* newList = new ArraySequence<T>(array, this->items->GetSize() + list->GetLength());
    Sequence<T>* res = newList;
    return res;
}