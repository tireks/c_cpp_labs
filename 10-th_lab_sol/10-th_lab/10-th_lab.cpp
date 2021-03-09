// 10-th_lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    short amount_mass;
    short container_mass[18];
    cout << "input amount of nums in array" << endl;
    cin >> amount_mass;
    for (short i = 0; i < 18; i++)
    {
        container_mass[i] = 0;
    }
    if ((amount_mass < 0) and (amount_mass > 1000))
    {
        return 0;
    }
    short* dyn_arr_input;
    dyn_arr_input = new short[amount_mass];
    short* dyn_arr_output;
    dyn_arr_output = new short[amount_mass];
    int counter = 0;
    cout << "now input as many numbers as you typed" << endl;
    for (short i = 0; i < amount_mass; i++)
    {
        cin >> *(dyn_arr_input + i) ;
        if ((*(dyn_arr_input + i) > 17) and (*(dyn_arr_input + i) < 0))
        {
            return 0;
        }
        container_mass[*(dyn_arr_input + i)]++;
    }
    cout << "results of 'garmoshka':" << endl;
    for (short i = 0; i < 18; i++)
    {
        cout << i << ": " << container_mass[i] << endl;
    }
    cout << "now, unzipped array" << endl;
    for (short i = 0; i < amount_mass; i++)
    {
        while (container_mass[counter] != 0)
        {
            *(dyn_arr_output + i) = counter;
            cout << *(dyn_arr_output + i) << "  ";
            container_mass[counter]--;
        }
        counter++;
    }

    delete[] dyn_arr_input;
    delete[] dyn_arr_output;


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
