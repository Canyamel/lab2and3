#include "UnitTest_ArraySeq.h"
#include "sequence.hpp"
#include "arraysequence.hpp"

#include <cassert>
#include <iostream>

using namespace std;

void TestGetFirst_ArraySeq()
{
    int array[3] = { 1, 2, 3 };
    ArraySequence<int> items(array, 3);
    assert(items.GetFirst() == 1);
    cout << "TestGetFirst OK" << endl;
}

void TestGetLast_ArraySeq()
{
    int array[3] = { 1, 2, 3 };
    int size = 3;
    ArraySequence<int> items(array, size);
    assert(items.GetLast() == 3);
    cout << "TestGetLast OK" << endl;
}

void TestGet_ArraySeq()
{
    int array[3] = { 1, 2, 3 };
    ArraySequence<int> items(array, 3);
    assert(items.Get(1) == 2);
    cout << "TestGet OK" << endl;
}

void TestCopy_ArraySeq()
{
    int array[3] = { 1, 2, 3 };
    ArraySequence<int> items(array, 3);
    assert(items.GetLength() == 3);
    assert(items.GetFirst() == 1);
    assert(items.Get(1) == 2);
    assert(items.GetLast() == 3);
    cout << "TestCopy OK" << endl;
}

void TestGetSubsequence_ArraySeq()
{
    int array[5] = { 1, 2, 3, 4, 5 };
    ArraySequence<int> items(array, 5);
    Sequence<int>* test = items.GetSubsequence(1, 3);
    assert(test->GetLength() == 3);
    assert(test->GetFirst() == 2);
    assert(test->Get(1) == 3);
    assert(test->GetLast() == 4);
    cout << "TestGetSubList OK" << endl;
}

void TestGetLength_ArraySeq()
{
    int array[3] = { 1, 2, 3 };
    ArraySequence<int> items(array, 3);
    assert(items.GetLength() == 3);
    cout << "TestGetLength OK" << endl;
}

void TestAppend_ArraySeq()
{
    int array[3] = { 1, 2, 3 };
    ArraySequence<int> items(array, 3);
    items.Append(4);
    assert(items.GetLength() == 4);
    assert(items.Get(3) == 4);
    cout << "TestAppend OK" << endl;
}

void TestPrepend_ArraySeq()
{
    int array[3] = { 1, 2, 3 };
    ArraySequence<int> items(array, 3);
    items.Prepend(0);
    assert(items.GetLength() == 4);
    assert(items.Get(0) == 0);
    cout << "TestPrepend OK" << endl;
}

void TestInsertAt_ArraySeq()
{
    int array[3] = { 1, 2, 3 };
    ArraySequence<int> items(array, 3);
    items.InsertAt(4, 1);
    assert(items.Get(1) == 4);
    cout << "TestInsertAt OK" << endl;
}

void TestConcat_ArraySeq()
{
    int array1[3] = { 1, 2, 3 };
    ArraySequence<int> items1(array1, 3);
    int array2[3] = { 4, 5, 6 };
    ArraySequence<int> items2(array2, 3);
    Sequence<int>* test = &items2;
    test = items1.Concat(test);
    assert(test->GetLength() == 6);
    assert(test->GetFirst() == 1);
    assert(test->Get(3) == 4);
    assert(test->GetLast() == 6);
    cout << "TestConcat OK" << endl;
}



void UnitTest_ArraySeq()
{
    TestGetFirst_ArraySeq();
    TestGetLast_ArraySeq();
    TestGet_ArraySeq();
    TestCopy_ArraySeq();
    TestGetSubsequence_ArraySeq();
    TestGetLength_ArraySeq();
    TestAppend_ArraySeq();
    TestPrepend_ArraySeq();
    TestInsertAt_ArraySeq();
    TestConcat_ArraySeq();
}