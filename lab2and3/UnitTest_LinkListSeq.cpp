#include "UnitTest_LinkListSeq.h"
#include "linkedlistsequence.hpp"
#include "sequence.hpp"

#include <cassert>
#include <iostream>

using namespace std;

void TestGetFirst_LinkListSeq()
{
    int array[3] = { 1, 2, 3 };
    LinkedListSequence<int> items(array, 3);
    assert(items.GetFirst() == 1);
    cout << "TestGetFirst OK" << endl;
}

void TestGetLast_LinkListSeq()
{
    int array[3] = { 1, 2, 3 };
    LinkedListSequence<int> items(array, 3);
    assert(items.GetLast() == 3);
    cout << "TestGetLast OK" << endl;
}

void TestGet_LinkListSeq()
{
    int array[3] = { 1, 2, 3 };
    LinkedListSequence<int> items(array, 3);
    assert(items.Get(1) == 2);
    cout << "TestGet OK" << endl;
}

void TestCopy_LinkListSeq()
{
    int array[3] = { 1, 2, 3 };
    LinkedList<int> list(array, 3);
    LinkedListSequence<int> items(&list);
    assert(items.GetLength() == 3);
    assert(items.GetFirst() == 1);
    assert(items.Get(1) == 2);
    assert(items.GetLast() == 3);
    cout << "TestCopy OK" << endl;
}

void TestGetSubsequence_LinkListSeq()
{
    int array[5] = { 1, 2, 3, 4, 5 };
    LinkedListSequence<int> items(array, 5);
    Sequence<int>* test = items.GetSubsequence(1, 3);
    assert(test->GetLength() == 3);
    assert(test->GetFirst() == 2);
    assert(test->Get(1) == 3);
    assert(test->GetLast() == 4);
    cout << "TestGetGetSubsequence OK" << endl;
}

void TestGetLength_LinkListSeq()
{
    int array[3] = { 1, 2, 3 };
    LinkedListSequence<int> items(array, 3);
    assert(items.GetLength() == 3);
    cout << "TestGetLength OK" << endl;
}

void TestAppend_LinkListSeq()
{
    int array[3] = { 1, 2, 3 };
    LinkedListSequence<int> items(array, 3);
    items.Append(4);
    assert(items.Get(3) == 4);
    cout << "TestAppend OK" << endl;
}

void TestPrepend_LinkListSeq()
{
    int array[3] = { 1, 2, 3 };
    LinkedListSequence<int> items(array, 3);
    items.Prepend(4);
    assert(items.Get(0) == 4);
    cout << "TestPrepend OK" << endl;
}

void TestInsertAt_LinkListSeq()
{
    int array[3] = { 1, 2, 3 };
    LinkedListSequence<int> items(array, 3);
    items.InsertAt(4, 1);
    assert(items.Get(1) == 4);
    cout << "TestInsertAt OK" << endl;
}

void TestConcat_LinkListSeq()
{
    int array1[3] = { 1, 2, 3 };
    LinkedListSequence<int> items1(array1, 3);
    int array2[3] = { 4, 5, 6 };
    LinkedListSequence<int> items2(array2, 3);
    Sequence<int>* test = items1.Concat(&items2);
    assert(test->GetLength() == 6);
    assert(test->GetFirst() == 1);
    assert(test->Get(3) == 4);
    assert(test->GetLast() == 6);
    cout << "TestConcat OK" << endl;
}



void UnitTest_LinkListSeq()
{
    TestGetFirst_LinkListSeq();
    TestGetLast_LinkListSeq();
    TestGet_LinkListSeq();
    TestCopy_LinkListSeq();
    TestGetSubsequence_LinkListSeq();
    TestGetLength_LinkListSeq();
    TestAppend_LinkListSeq();
    TestPrepend_LinkListSeq();
    TestInsertAt_LinkListSeq();
    TestConcat_LinkListSeq();
}