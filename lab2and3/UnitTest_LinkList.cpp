#include "UnitTest_LinkList.h"
#include "linkedlist.hpp"

#include <cassert>
#include <iostream>

using namespace std;

void TestGetFirst_LinkList()
{
    int array[3] = { 1, 2, 3 };
    LinkedList<int> items(array, 3);
    assert(items.GetFirst() == 1);
    cout << "TestGetFirst OK" << endl;
}

void TestGetLast_LinkList()
{
    int array[3] = { 1, 2, 3 };
    LinkedList<int> items(array, 3);
    assert(items.GetLast() == 3);
    cout << "TestGetLast OK" << endl;
}

void TestGet_LinkList()
{
    int array[3] = { 1, 2, 3 };
    LinkedList<int> items(array, 3);
    assert(items.Get(1) == 2);
    cout << "TestGet OK" << endl;
}

void TestCopy_LinkList()
{
    int array[3] = { 1, 2, 3 };
    LinkedList<int> items1(array, 3);
    LinkedList<int> items2(&items1);
    assert(items1.GetLength() == items2.GetLength());
    assert(items1.GetFirst() == items2.GetFirst());
    assert(items1.Get(1) == items2.Get(1));
    assert(items1.GetLast() == items2.GetLast());
    cout << "TestCopy OK" << endl;
}

void TestGetSubList_LinkList()
{
    int array[5] = { 1, 2, 3, 4, 5 };
    LinkedList<int> items1(array, 5);
    LinkedList<int>* items2 = items1.GetSubList(1, 3);
    assert(items2->GetLength() == 3);
    assert(items2->GetFirst() == 2);
    assert(items2->Get(1) == 3);
    assert(items2->GetLast() == 4);
    cout << "TestGetSubList OK" << endl;
}

void TestGetLength_LinkList()
{
    int array[3] = { 1, 2, 3 };
    LinkedList<int> items(array, 3);
    assert(items.GetLength() == 3);
    cout << "TestGetLength OK" << endl;
}

void TestAppend_LinkList()
{
    int array[3] = { 1, 2, 3 };
    LinkedList<int> items(array, 3);
    items.Append(4);
    assert(items.Get(3) == 4);
    cout << "TestAppend OK" << endl;
}

void TestPrepend_LinkList()
{
    int array[3] = { 1, 2, 3 };
    LinkedList<int> items(array, 3);
    items.Prepend(4);
    assert(items.Get(0) == 4);
    cout << "TestPrepend OK" << endl;
}

void TestInsertAt_LinkList()
{
    int array[3] = { 1, 2, 3 };
    LinkedList<int> items(array, 3);
    items.InsertAt(4, 1);
    assert(items.Get(1) == 4);
    cout << "TestInsertAt OK" << endl;
}

void TestConcat_LinkList()
{
    int array1[3] = { 1, 2, 3 };
    LinkedList<int> items1(array1, 3);
    int array2[3] = { 4, 5, 6 };
    LinkedList<int> items2(array2, 3);
    LinkedList<int>* items3 = items1.Concat(&items2);
    assert(items3->GetLength() == 6);
    assert(items3->GetFirst() == 1);
    assert(items3->Get(3) == 4);
    assert(items3->GetLast() == 6);
    cout << "TestConcat OK" << endl;
}



void UnitTest_LinkList()
{
    TestGetFirst_LinkList();
    TestGetLast_LinkList();
    TestGet_LinkList();
    TestCopy_LinkList();
    TestGetSubList_LinkList();
    TestGetLength_LinkList();
    TestAppend_LinkList();
    TestPrepend_LinkList();
    TestInsertAt_LinkList();
    TestConcat_LinkList();
}