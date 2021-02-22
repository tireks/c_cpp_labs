// Lab_8list_spisok.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct node //create new node structure
{
    int value;
    struct node* next;
} Nodelist_spisok;

Nodelist_spisok* initNodelist_spisok(int value) //function of creation of new node
{
    Nodelist_spisok* res = (Nodelist_spisok*)malloc(sizeof(Nodelist_spisok));
    res->value = value;
    res->next = NULL;
    return res;
}

typedef struct list // create new list structure
{
    Nodelist_spisok* head;
} List;

List* initList() //function of creation of new list
{
    List* list_spisok = (List*)malloc(sizeof(List));
    list_spisok->head = NULL;
    return list_spisok;
}


void add_tolist_spisok(List* list_spisok, int value) //function of adding new node to list
{
    if (list_spisok->head == NULL)// checkin if list is empty
    {
        list_spisok->head = initNodelist_spisok(value); //creating new node (head/first node)
        return;
    }

    Nodelist_spisok* head = list_spisok->head;
    Nodelist_spisok* prev = NULL;
    while (head != NULL)
    {
        prev = head;
        head = head->next;
    }
    head = initNodelist_spisok(value);
    prev->next = head;
}

void list_output(List* list_spisok)  //function for printing the list
{
    Nodelist_spisok* cur = list_spisok->head;
    while (cur != NULL)
    {
        printf("%d ", cur->value);
        cur = cur->next;
    }
}

int main()
{
    //int input_data = 0;
    List* list_spisok = initList();
    for (int i = 0; i < 10; i++)
    {
        add_tolist_spisok(list_spisok, i);
    }
    list_output(list_spisok);
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
