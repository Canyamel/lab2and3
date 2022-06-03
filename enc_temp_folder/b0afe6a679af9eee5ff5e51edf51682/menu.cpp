#include "vector.hpp"
#include "sequence.hpp"
#include "arraysequence.hpp"
#include "linkedlistsequence.hpp"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <complex>

using namespace std;

int* CreateVector(int size)
{
    int* array = new int[size];
    int data;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter ";
        cout << i + 1;
        cout << " coordinate of the vector" << endl;
        cin >> data;
        array[i] = data;
    }
    return array;
}

void FuncMenu()
{
    setlocale(LC_ALL, "Russian");

    system("cls");
    cout << "Enter the dimension of the vector" << endl;
    int size;
    cin >> size;

    cout << "First vector" << endl;
    int* array1;
    array1 = CreateVector(size);
    cout << "Second vector" << endl;
    int* array2;
    array2 = CreateVector(size);


    Sequence<int>* vector1;
    Sequence<int>* vector2;

    ArraySequence<int> t(array1, size);
    vector1 = &t;
    vector2 = &t;

    int menu = 0;
    while (menu != 3)
    {
        system("cls");
        cout << "------------TERMINAL------------" << endl;
        cout << "1. Array" << endl;
        cout << "2. List" << endl;
        cout << "--------------------------------" << endl;
        cout << "Enter the item number" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
        {
            ArraySequence<int> items1(array1, size);
            ArraySequence<int> items2(array2, size);

            vector1 = &items1;
            vector2 = &items2;
            menu = 3;
            break;
        }

        case 2:
        {
            LinkedListSequence<int> items1(array1, size);
            LinkedListSequence<int> items2(array2, size);

            vector1 = &items1;
            vector2 = &items2;
            menu = 3;
            break;
        }

        default:
            cout << "There is no such item" << endl;
        }
    }

    Vector<int> v1(vector1);
    Vector<int> v2(vector2);

    while (menu != 4)
    {
        system("cls");
        cout << "------------TERMINAL------------" << endl;
        cout << "1. Change the vector" << endl;
        cout << "2. Operations on vectors" << endl;
        cout << "3. Displaying vectors on the screen" << endl;
        cout << "4. Exit" << endl;
        cout << "--------------------------------" << endl;
        cout << "Enter item number" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
            menu = 0;
            while (menu != 3)
            {
                system("cls");
                cout << "------------TERMINAL------------" << endl;
                cout << "1. Change the first vector" << endl;
                cout << "2. Change the second vector" << endl;
                cout << "3. Back" << endl;
                cout << "--------------------------------" << endl;
                cout << "Enter item number" << endl;
                cin >> menu;
                switch (menu)
                {
                case 1:
                {
                    int data;
                    for (int i = 0; i < size; i++)
                    {
                        cout << "Enter ";
                        cout << i + 1;
                        cout << " the coordinate of the vector" << endl;
                        cin >> data;
                        v1.Set(data, i);
                    }
                    break;
                }

                case 2:
                {
                    int data;
                    for (int i = 0; i < size; i++)
                    {
                        cout << "Enter ";
                        cout << i + 1;
                        cout << " the coordinate of the vector" << endl;
                        cin >> data;
                        v2.Set(data, i);
                    }
                    break;
                }

                case 3:
                    break;

                default:
                    cout << "There is no such item" << endl;
                }
            }
            break;

        case 2:
            menu = 0;
            while (menu != 7)
            {
                system("cls");
                cout << "------------TERMINAL------------" << endl;
                cout << "1. Sum of vectors" << endl;
                cout << "2. Scalar product of vectors" << endl;
                cout << "3. The product of the first vector by a scalar" << endl;
                cout << "4. The product of the second vector by a scalar" << endl;
                cout << "5. The normal of the first vector" << endl;
                cout << "6. The normal of the second vector" << endl;
                cout << "7. Back" << endl;
                cout << "--------------------------------" << endl;
                cout << "Enter item number" << endl;
                cin >> menu;
                switch (menu)
                {
                case 1:
                {
                    Vector<int> v3 = v1.Sum(v2);
                    cout << "( ";
                    for (int i = 0; i < size; i++)
                    {
                        cout << v3.Get(i);
                        cout << "; ";
                    }
                    cout << ")" << endl;
                    system("pause");
                    break;
                }

                case 2:
                {
                    double res = v1.MultV(v2);
                    cout << res << endl;
                    system("pause");
                    break;
                }

                case 3:
                {
                    int sc;
                    cout << "Enter a scalar" << endl;
                    cin >> sc;
                    Vector<int> v3 = v1.MultSc(sc);
                    cout << "( ";
                    for (int i = 0; i < size; i++)
                    {
                        cout << v3.Get(i);
                        cout << "; ";
                    }
                    cout << ")" << endl;
                    system("pause");
                    break;
                }

                case 4:
                {
                    int sc;
                    cout << "Enter a scalar" << endl;
                    cin >> sc;
                    Vector<int> v3 = v2.MultSc(sc);
                    cout << "( ";
                    for (int i = 0; i < size; i++)
                    {
                        cout << v3.Get(i);
                        cout << "; ";
                    }
                    cout << ")" << endl;
                    system("pause");
                    break;
                }

                case 5:
                {
                    double res = v1.GetNorm();
                    cout << res << endl;
                    system("pause");
                    break;
                }

                case 6:
                {
                    double res = v2.GetNorm();
                    cout << res << endl;
                    system("pause");
                    break;
                }

                case 7:
                    break;

                default:
                    cout << "There is no such item" << endl;
                }
            }
            break;

        case 3:
            menu = 0;
            while (menu != 3)
            {
                system("cls");
                cout << "------------TERMINAL------------" << endl;
                cout << "1. Output the first vector" << endl;
                cout << "2. Output the second vector" << endl;
                cout << "3. Back" << endl;
                cout << "--------------------------------" << endl;
                cout << "Enter item number" << endl;
                cin >> menu;
                switch (menu)
                {
                case 1:
                    cout << "( ";
                    for (int i = 0; i < size; i++)
                    {
                        cout << v2.Get(i);
                        cout << "; ";
                    }
                    cout << ")" << endl;;
                    system("pause");
                    break;

                case 2:
                    cout << "( ";
                    for (int i = 0; i < size; i++)
                    {
                        cout << v2.Get(i);
                        cout << "; ";
                    }
                    cout << ")" << endl;;
                    system("pause");
                    break;

                case 3:
                    break;

                default:
                    cout << "There is no such item" << endl;
                }
            }
            break;

        case 4:
            system("cls");
            cout << "End of the program" << endl;
            delete[] vector1;
            delete[] vector2;
            break;

        default:
            cout << "There is no such item" << endl;
        }
    }
}