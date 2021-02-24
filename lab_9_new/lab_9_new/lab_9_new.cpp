// Lab_9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "stdafx.h"
#include <iostream>
#include <malloc.h>
using namespace std;
#define WORD_1 "не уходи смиренно в "
#define WORD_2 "сумрак вечной тьмы"
#define SENTENCE_1 "не уходи смиренно в сумрак вечной тьмы"

int main()
{
    setlocale(LC_ALL, "Russian");
    char* sentence_1 = (char*)malloc(sizeof(char) * (strlen(SENTENCE_1) + 1));
    strcpy(sentence_1, SENTENCE_1);
    char* word_1 = (char*)malloc(sizeof(char) * (strlen(SENTENCE_1) + 1) );
    strcpy(word_1, WORD_1);
    char* word_2 = (char*)malloc(sizeof(char) * (strlen(WORD_2) + 1));
    strcpy(word_2, WORD_2);
    cout << "1-e:" << strcat(word_1, word_2) << "\n" << endl;
    // word_5 = strcat(word_5, word_6);
    // word_4 = strcat(word_4, word_5);
    // word_3 = strcat(word_3, word_4);
    // word_2 = strcat(word_1, word_3);
     //word_1 = strcat(word_1, word_2);
     //cout << "2-e:" << word_1 << endl;
     /*free(word_1);
     free(word_2);
     free(sentence_1);*/
    free(word_1);
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
