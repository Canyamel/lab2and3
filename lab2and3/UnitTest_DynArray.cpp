#include "UnitTest_DynArray.h"
#include "dynamicarray.hpp"

#include <cassert>
#include <iostream>

using namespace std;

void TestGet_DynArray()
{
    int array[3] = { 1, 2, 3 };
    DynamicArray<int> items(array, 3);
    assert(items.Get(0) == 1);
    assert(items.Get(1) == 2);
    assert(items.Get(2) == 3);
    cout << "TestGet OK" << endl;
}

void TestGetSize_DynArray()
{
    DynamicArray<int> items(3);
    assert(items.GetSize() == 3);
    cout << "TestGetSize OK" << endl;
}

void TestCopy_DynArray()
{
    int array[3] = { 1, 2, 3 };
    DynamicArray<int> items1(array, 3);
    DynamicArray<int> items2(&items1);
    assert(items1.GetSize() == items2.GetSize());
    assert(items1.Get(0) == items2.Get(0));
    assert(items1.Get(1) == items2.Get(1));
    assert(items1.Get(2) == items2.Get(2));
    cout << "TestCopy OK" << endl;
}

void TestSet_DynArray()
{
    DynamicArray<int> items(3);
    items.Set(5, 1);
    assert(items.Get(1) == 5);
    cout << "TestSet OK" << endl;
}

void TestResize_DynArray()
{
    int array[3] = { 1, 2, 3 };
    DynamicArray<int> items(array, 3);
    items.Resize(5);
    assert(items.GetSize() == 5);
    assert(items.Get(0) == 1);
    assert(items.Get(1) == 2);
    assert(items.Get(2) == 3);
    cout << "TestResize OK" << endl;
}



void UnitTest_DynArray()
{
    TestGet_DynArray();
    TestGetSize_DynArray();
    TestCopy_DynArray();
    TestSet_DynArray();
    TestResize_DynArray();
}