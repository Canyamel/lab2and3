#pragma once

template <class T>
class Node
{
public:
    T data;
    Node<T>* next;

    Node(T);
};

template <class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = nullptr;
}