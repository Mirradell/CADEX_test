// CADEX_Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <algorithm>
#include <format>

#include "Helix.h"
#include "Ellipse.h"

void CreateRandomCurves(vector<Curve*>& list, int count) {
    for (int i = 0; i < count; i++) {

        switch (rand() % 3)
        {
        case 0:
            list.push_back((new Circle())->CreateRandom());
            break;
        case 1:
            list.push_back((new Ellipse())->CreateRandom());
            break;
        case 2:
            list.push_back((new Helix())->CreateRandom());
            break;
        }
    }
}

void ForeachActionInVector(vector<Curve*>& list, int count, Point(Curve::*action)(float), float t) {
    for (int i = 0; i < count; i++) {
        cout << "\t" << i << ":\t";
        (list[i]->*action)(t).printl();
    }
}

void ForeachActionInVector(vector<Curve*>& list, int count, Vector(Curve::*action)(float), float t) {
    for (int i = 0; i < count; i++) {
        cout << "\t" << i << ":\t";
        (list[i]->*action)(t).printl();
    }
}

void PrintVector(vector<Curve*>& list, int count) {
    for (int i = 0; i < count; i++) {
        cout << "\t" << i << ":\t";
        list[i]->Print();
        cout << endl;
    }
}

int CirclesRadiiSum(vector<Curve*>::iterator begin, vector<Curve*>::iterator end) {
    int result = 0;
    for (auto i = begin; i != end; i++)
        result += ((Circle*)(*i))->radius;

    return result;
}

int main()
{
    cout << "Starting program...\n";

    srand(time(NULL));
    int count = 13;
    vector<Curve*> list;

    cout << "Creating " << count << " random curves...\n";    
    CreateRandomCurves(list, count);

    cout << "\nDone. Created curves are:\n";
    PrintVector(list, count);
    
    cout << "\nPoint coordinates at Pi/4:\n";
    ForeachActionInVector(list, count, &Curve::GetPoint, M_PI_4);

    cout << "\nPrint first derivative at Pi/4:\n";
    ForeachActionInVector(list, count, &Curve::FirstDerivative, M_PI_4);

    cout << "\nCreating and filling second container...";
    vector<Curve*> listCirclesOnly;
    int secondCount = 0;
    for (vector<Curve*>::iterator i = list.begin(); i != list.end(); i++) {
        if (typeid(**i) == typeid(Circle)) {
            listCirclesOnly.push_back(*i);
            secondCount++;
        }
    }

    cout << "\nDone. Shares of circles only are:\n";
    PrintVector(listCirclesOnly, secondCount);

    cout << "\nSorting circles in the ascending order...";
    sort(listCirclesOnly.begin(), listCirclesOnly.end(), 
        [](Curve* const& a, Curve* const& b) {return ((Circle*)a)->radius < ((Circle*)b)->radius; });

    cout << "\nDone. Sorted circles are:\n";
    PrintVector(listCirclesOnly, secondCount);

    cout << "\nStarting computing radii sum in the second container...";
    int sum = CirclesRadiiSum(listCirclesOnly.begin(), listCirclesOnly.end());

    cout << "\nDone. Computed sum is " << sum << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
