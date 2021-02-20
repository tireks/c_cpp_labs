// Lab_8_list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
} Node;

Node* initNode(int value)
{
    Node* res = (Node*)malloc(sizeof(Node));
    res->value = value;
    res->next = NULL;
    return res;
}

typedef struct list
{
    Node* head;
    int size;
} List;

List* initList()
{
    List* _list = (List*)malloc(sizeof(List));
    _list->head = NULL;
    _list->size = 0;
    return _list;
}
// Использую рекурсию, чтобы удалять Nodes | можно написать свою версию с линейным удалением (оно в вашем коде, но так красивее и вероятность ошибки меньше)
void deleteNodes(Node* _node)
{
    if (_node != NULL)
        deleteNodes(_node->next);
    else
        return;
    printf("\nI'm going to delete Node with value = %d, located in %d", _node->value, _node);
    free(_node);
}

void deleteList(List* _list)
{
    deleteNodes(_list->head);
    free(_list);
}

void pushToList(List* _list, int value)
{
    _list->size++;
    // Голова листа изначально указывает на NULL, а после первого пуша начинает уже на новый элемент
    if (_list->head == NULL)
    {
        _list->head = initNode(value);
        return;
    }

    Node* head = _list->head;
    Node* prev = NULL;
    while (head != NULL)
    {
        prev = head;
        head = head->next;
    }
    head = initNode(value);
    prev->next = head;
}

void printList(List* _list)
{
    Node* cur = _list->head;
    while (cur != NULL)
    {
        printf("%d ", cur->value);
        cur = cur->next;
    }
}

int main()
{
    List* _list = initList();
    for (int i = 0; i < 10; i++)
        pushToList(_list, i);
    printList(_list);
    deleteList(_list);
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
