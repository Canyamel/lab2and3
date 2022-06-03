#pragma once

#include <cmath>

#include "sequence.hpp"
#include "arraysequence.hpp"
//#include "linkedlistsequence.hpp"

template <typename T>
class Vector
{
private:
    Sequence<T>* vector;

public:
    Vector(Sequence<T>*);
    T Get(int);
    int GetSize();
    void Set(T, int);
    double GetNorm();
    Vector<T> Sum(Vector<T>);
    double MultV(Vector<T>);
    Vector<T> MultSc(T);
};

template <typename T>
Vector<T>::Vector(Sequence<T>* newSpisok)
{
    this->vector = newSpisok;
}

template <typename T>
T Vector<T>::Get(int index)
{
    return this->vector->Get(index);
}

template <typename T>
int Vector<T>::GetSize()
{
    return this->vector->GetLength();
}

template <typename T>
void Vector<T>::Set(T data, int index)
{
    this->vector->InsertAt(data, index);
}

template <typename T>
double Vector<T>::GetNorm()
{
    double result = 0;
    for (int i = 0; i < this->vector->GetLength(); i++)
    {
        T buf = this->vector->Get(i);
        result += buf * buf;
    }
    return sqrt(result);
}

template <typename T>
Vector<T> Vector<T>::Sum(Vector<T> other)
{
    T* array = new T[this->GetSize()];
    for (int i = 0; i < this->GetSize(); i++)
    {
        array[i] = this->vector->Get(i) + other.vector->Get(i);
    }
    ArraySequence<T>* v = new ArraySequence<T>(array, this->GetSize());
    Sequence<T>* sv = v;
    Vector<T> newVector(sv);
    return newVector;
}

template <typename T>
double Vector<T>::MultV(Vector<T> other)
{
    double result = 0;
    for (int i = 0; i < this->vector->GetLength(); i++)
    {
        result += this->Get(i) * other.Get(i);
    }
    return result;
}

template <typename T>
Vector<T> Vector<T>::MultSc(T scalar)
{
    T* array = new T[this->GetSize()];
    for (int i = 0; i < this->vector->GetLength(); i++)
    {
        array[i] = this->vector->Get(i) * scalar;
    }
    ArraySequence<T>* v = new ArraySequence<T>(array, this->GetSize());
    Sequence<T>* sv = v;
    Vector<T> newVector(sv);
    return newVector;
}