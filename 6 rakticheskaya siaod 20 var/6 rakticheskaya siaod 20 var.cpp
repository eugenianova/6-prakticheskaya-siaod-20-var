#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

struct Node //Узел
{
    Node* pNext; //указатель на следующий элемент
    int data; //значение узла

    Node(int s, Node* ptr = nullptr) //конструктор узла
    {
        data = s;
        pNext = nullptr;
    }
};

struct Stack //Стек
{
    Node* first; //указатель на первый элемент
};

double func_1_it(int n) //реализация упражнения 1 (итерационный алгоритм)
{
    double sum = 0, num;
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        sum += num;
    }

    return sum / n;
}

double func_2_rec(int n)
{
    int num;
    cin >> num;

    if (n == 1)
        return num;
    else
        return (num + func_2_rec(n - 1) * (n - 1)) / n;
}

Node* func_3_rec(int n)
{
    int num;
    cin >> num;
    Node* cur = new Node(num);
    if (n == 1)
    {
        return cur;
    }
    else
    {
        cur->pNext = func_3_rec(n - 1);
        return cur;
    }

}

void print_stack(Stack& s)
{
    cout << "\nПолученный стек: ";
    while (s.first != nullptr)
    {
        Node* curr = s.first;
        while (curr != nullptr)
        {
            if (curr == s.first && curr->pNext == nullptr)
            {
                cout << curr->data << endl;
                s.first = nullptr;
            }
            if (curr->pNext != nullptr && curr->pNext->pNext == nullptr)
            {
                cout << curr->pNext->data << " ";
                curr->pNext = nullptr;
            }
            curr = curr->pNext;
        }

    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа №6 \"Рекурсивные алгоритмы и их реализация.\" Тараканова Е О." << endl << endl;

    int mode;
    cout << "\nВыберите функцию: \n1 - Вычислить среднее значение всех элементов массива (итерационный алгоритм) \n2 - Вычислить среднее значение всех элементов массива (рекурсивный алгоритм)" <<
        "\n3 - Создание связного стека из n элементов. \n--->";

    do
    {
        cin >> mode;
        if (mode < 1 || mode > 3) cout << "Функции под таким номером нет. Введите корректный номер: ";
    } while (mode < 1 || mode > 3);

    int n;
    cout << "\nВведите размер массива/стека: ";
    do
    {
        cin >> n;
        if (n < 1) cout << "Размер массива не может быть меньше единицы. Повторите ввод: ";
    } while (n < 1);

    switch (mode)
    {
    case 1:
    {
        cout << "\nСреднее значение элементов массива: " << func_1_it(n);
        break;
    }
    case 2:
    {
        cout << "Введите элементы массива: ";
        cout << "\nСреднее значение элементов массива: " << func_2_rec(n);
        break;
    }
    case 3:
    {
        cout << "Введите элементы стека: ";
        Stack s;
        s.first = func_3_rec(n);
        print_stack(s);
        break;
    }
    }
}
