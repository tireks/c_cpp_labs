﻿// 11-th_lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <io.h>
using namespace std;

int main()
{
    char temp_cin_cout [20] ;
    gets_s(temp_cin_cout, 10);
    puts(temp_cin_cout);
    cin >> temp_cin_cout;
    cout << temp_cin_cout << endl;
    scanf("%s", temp_cin_cout);
    printf("%s", temp_cin_cout);
    FILE* fp;
    int fd;
    char name[] = "my.txt";
    if ((fp = fopen(name, "a+")) == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }
    fscanf(fp, "%s", temp_cin_cout);
    fprintf(fp, "%s", temp_cin_cout);
    if (feof(fp) == 0)
    {
        cout << "smth gone wrong" << endl;
    }
    fclose(fp);
    /*if ((fd = open("TEST.TST", O_RDONLY)) == -1) {
        printf("Cannot open file.\n");
        exit(1);
    }
    if (_read(fd, buffer, 100) != 100)
    {
        printf("Possible read error.");
    }*/
    
    return 0;
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
