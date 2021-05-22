/*
Автор: Китанов Дмитрий
Группа: СБС-001; 2 подгруппа
Задача №12, вариант 2
Цель: составить программу с обобщённой функцией, меняющей местами элементы массива
*/
#include <iostream>
#include <climits>

using namespace std;

template <typename Type>
Type swap_of_elements(Type *&arr, int ind_1, int ind_2)
{
    Type tempor = arr[ind_1];
    arr[ind_1] = arr[ind_2];
    arr[ind_2] = tempor;
    return 0;
}

bool typeFail = 0;

void Size_Array(int &array_size)
{
    array_size = 0;

    do
    {
        cout << "Enter a size of the array >= 2\n";
        cin >> array_size;

        typeFail = cin.fail();
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    while ((typeFail) || (array_size < 2));

    return;
}

void Array_Filling(int array_size, int *&arr)
{
    for (int i = 0; i < array_size; i++)
    {
        do
        {
            cout << "Enter the " << i << " element of the int array\n";
            cin >> arr[i];

            typeFail = cin.fail();
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        while (typeFail);
    }

    return;
}

void Array_Filling(int array_size, double *&arr)
{
    for (int i = 0; i < array_size; i++)
    {
        do
        {
            cout << "Enter the " << i << " element of the double array\n";
            cin >> arr[i];

            typeFail = cin.fail();
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        while (typeFail);
    }

    return;
}

void Indices(int array_size, int &ind)
{
    do
    {
        cout << "Index:\n";
        cin >> ind;

        typeFail = cin.fail();
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    while ((typeFail) || (ind < 0) || (ind >= array_size));
}

int main()
{
    int array_size = 0;

    cout << "For int array:\n";
    Size_Array(array_size);

    int *arr_int;
    arr_int = new int [array_size];
    Array_Filling(array_size, arr_int);

    int ind_1 = 0;
    int ind_2 = 0;

    cout << "Enter an indices(>=0) of the two elements of the int array to be swapped.\n";
    Indices(array_size, ind_1);
    Indices(array_size, ind_2);

    swap_of_elements(arr_int, ind_1, ind_2);
    cout << "elem [" << ind_1 << "] = " << arr_int[ind_1] << "\n";
    cout << "elem [" << ind_2 << "] = " << arr_int[ind_2] << "\n";
    delete[] arr_int;

    cout << "For double array:\n";
    Size_Array(array_size);

    double *arr_double;
    arr_double = new double [array_size];
    Array_Filling(array_size, arr_double);

    cout << "Enter an indices(>=0) of the two elements of the double array to be swapped.\n";
    Indices(array_size, ind_1);
    Indices(array_size, ind_2);

    swap_of_elements(arr_double, ind_1, ind_2);
    cout << "elem [" << ind_1 << "] = " << arr_double[ind_1] << "\n";
    cout << "elem [" << ind_2 << "] = " << arr_double[ind_2] << "\n";
    delete[] arr_double;

    return 0;
}
