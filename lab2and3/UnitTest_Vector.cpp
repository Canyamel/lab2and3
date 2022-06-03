#include "UnitTest_Vector.h"
#include "vector.hpp"
#include "sequence.hpp"
#include "arraysequence.hpp"
#include "linkedlistsequence.hpp"

#include <cassert>
#include <iostream>

using namespace std;

void TestGetCoordinate()
{
    int array1[2] = { 1, 2 };
    int array2[2] = { 3, 4 };
    ArraySequence<int>* items1 = new ArraySequence<int>(array1, 2);
    LinkedListSequence<int>* items2 = new LinkedListSequence<int>(array2, 2);
    Sequence<int>* test1 = items1;
    Sequence<int>* test2 = items2;
    Vector<int> v1(items1);
    Vector<int> v2(items2);
    assert(v1.Get(0) == 1);
    assert(v2.Get(1) == 4);
    cout << "TestGetCoordinate OK" << endl;
}

void TestSize()
{
    int array1[2] = { 1, 2 };
    int array2[2] = { 3, 4 };
    ArraySequence<int>* items1 = new ArraySequence<int>(array1, 2);
    LinkedListSequence<int>* items2 = new LinkedListSequence<int>(array2, 2);
    Sequence<int>* test1 = items1;
    Sequence<int>* test2 = items2;
    Vector<int> v1(items1);
    Vector<int> v2(items2);
    assert(v1.GetSize() == 2);
    assert(v2.GetSize() == 2);
    cout << "TestGetSize OK" << endl;
}

void TestSet()
{
    int array1[2] = { 1, 2 };
    int array2[2] = { 3, 4 };
    ArraySequence<int>* items1 = new ArraySequence<int>(array1, 2);
    LinkedListSequence<int>* items2 = new LinkedListSequence<int>(array2, 2);
    Sequence<int>* test1 = items1;
    Sequence<int>* test2 = items2;
    Vector<int> v1(items1);
    Vector<int> v2(items2);
    v1.Set(5, 0);
    v2.Set(5, 1);
    assert(v1.Get(0) == 5);
    assert(v2.Get(1) == 5);
    cout << "TestSet OK" << endl;
}

void TestGetNorm()
{
    int array1[2] = { 1, 2 };
    int array2[2] = { 3, 4 };
    ArraySequence<int>* items1 = new ArraySequence<int>(array1, 2);
    LinkedListSequence<int>* items2 = new LinkedListSequence<int>(array2, 2);
    Sequence<int>* test1 = items1;
    Sequence<int>* test2 = items2;
    Vector<int> v1(items1);
    Vector<int> v2(items2);
    double eps = 0.00001;
    assert(v1.GetNorm() - 2.23607 < eps);
    assert(v2.GetNorm() - 5.00000 < eps);
    cout << "TestGetNorm OK" << endl;
}

void TestSum()
{
    int array1[2] = { 1, 2 };
    int array2[2] = { 3, 4 };
    ArraySequence<int>* items1 = new ArraySequence<int>(array1, 2);
    LinkedListSequence<int>* items2 = new LinkedListSequence<int>(array2, 2);
    Sequence<int>* test1 = items1;
    Sequence<int>* test2 = items2;
    Vector<int> v1(items1);
    Vector<int> v2(items2);
    Vector<int> v3 = v1.Sum(v2);
    assert(v3.Get(0) == 4);
    assert(v3.Get(1) == 6);
    cout << "TestSum OK" << endl;
}

void TestMultV()
{
    int array1[2] = { 1, 2 };
    int array2[2] = { 3, 4 };
    ArraySequence<int>* items1 = new ArraySequence<int>(array1, 2);
    LinkedListSequence<int>* items2 = new LinkedListSequence<int>(array2, 2);
    Sequence<int>* test1 = items1;
    Sequence<int>* test2 = items2;
    Vector<int> v1(items1);
    Vector<int> v2(items2);
    double test = v1.MultV(v2);
    assert(test == 11);
    cout << "TestMultV OK" << endl;
}

void TestMultSc()
{
    int array1[2] = { 1, 2 };
    int array2[2] = { 3, 4 };
    ArraySequence<int>* items1 = new ArraySequence<int>(array1, 2);
    LinkedListSequence<int>* items2 = new LinkedListSequence<int>(array2, 2);
    Sequence<int>* test1 = items1;
    Sequence<int>* test2 = items2;
    Vector<int> v1(items1);
    Vector<int> v2(items2);
    Vector<int> v3 = v1.MultSc(2);
    assert(v3.Get(0) == 2);
    assert(v3.Get(1) == 4);
    v3 = v2.MultSc(2);
    assert(v3.Get(0) == 6);
    assert(v3.Get(1) == 8);
    cout << "TestMultSc OK" << endl;
}



void UnitTest_Vector()
{
    TestGetCoordinate();
    TestSize();
    TestSet();
    TestGetNorm();
    TestSum();
    TestMultV();
    TestMultSc();
}