#pragma once

template <class T>
class DynamicArray
{
private:
    T* array;
    int size;


public:
    DynamicArray(int);
    DynamicArray(T*, int);
    DynamicArray(DynamicArray<T>*);
    T Get(int);
    int GetSize();
    void Set(T, int);
    void Resize(int);
};

template <class T>
DynamicArray<T>::DynamicArray(int size)
{
    this->size = size;
    array = new T[size];
}

template <class T>
DynamicArray<T>::DynamicArray(T* item, int size)
{
    this->size = size;
    array = new T[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = item[i];
    }
}

template <class T>
DynamicArray<T>::DynamicArray(DynamicArray<T>* dynamicArray)
{
    size = dynamicArray->size;
    array = new T[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = dynamicArray->array[i];
    }
}

template <class T>
T DynamicArray<T>::Get(int index)
{
    return array[index];
}

template <class T>
int DynamicArray<T>::GetSize()
{
    return size;
}

template <class T>
void DynamicArray<T>::Set(T data, int index)
{
    this->array[index] = data;
}

template <class T>
void DynamicArray<T>::Resize(int newSize)
{
    this->size = newSize;
    T* newArray = new T[newSize];
    for (int i = 0; i < newSize; i++)
    {
        newArray[i] = this->array[i];
    }
    delete[] this->array;
    this->array = newArray;
}