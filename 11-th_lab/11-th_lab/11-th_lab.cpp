// 11-th_lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fcntl.h>      /* Needed only for _O_RDWR definition */
#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <share.h>
using namespace std;

int main()
{
    char temp_cin_cout [100] ;
    char temp_read_write[100];
    char temp_read_write2[100];
    gets_s(temp_cin_cout, 10);
    puts(temp_cin_cout);
    cin >> temp_cin_cout;
    cout << temp_cin_cout << endl;
    scanf("%s", temp_cin_cout);
    printf("%s", temp_cin_cout);
    FILE* fp;
    int fh, bytesread, i_count, end_string;
    bool flag_read;
    char name[] = "my.txt";
    if ((fp = fopen(name, "a+")) == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }
    cout << "now working with files" << endl;
    fscanf(fp, "%s", temp_cin_cout);
    cout << temp_cin_cout << endl;
    fprintf(fp, "%s", temp_cin_cout);
    rewind(fp);
    fscanf(fp, "%s", temp_cin_cout);
    cout << temp_cin_cout << endl;
    if (feof(fp) != 0)
    {
        cout << "smth gone wrong" << endl;
    }
    fclose(fp);
    if (_sopen_s(&fh, "crt_read.txt", _O_RDWR, _SH_DENYNO, 0))
    {
        perror("open failed on input file");
        exit(1);
    }
    flag_read = true;
    i_count = 0;
    if ((bytesread = _read(fh, temp_read_write, 10)) <= 0)
    {
        perror("Problem reading file");
    }
    else
    {
        while (flag_read)
        {
            if (temp_read_write[i_count] < -1)
            {
                flag_read = false;
                end_string = i_count;
            }
            i_count++;
            temp_read_write2[i_count] = temp_read_write[i_count];
            if (i_count >= 34)
            {
                flag_read = false;
            }
        }
        if (end_string != 0)
        {
            temp_read_write[end_string] = 0;
            temp_read_write2[end_string] = 0;
        }
        cout << "another_file" << endl;
        cout << temp_read_write << endl;
    }
    if ((bytesread = _write(fh, temp_read_write, end_string)) == -1)
    {
        switch (errno)
        {
        case EBADF:
            perror("Bad file descriptor!");
            break;
        case ENOSPC:
            perror("No space left on device!");
            break;
        case EINVAL:
            perror("Invalid parameter: buffer was NULL!");
            break;
        default:
            // An unrelated error occurred
            perror("Unexpected error!");
        }
    }
    else
    {
        strcat(temp_read_write, temp_read_write);
        cout << temp_read_write << endl;
    }

    _close(fh);
    
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
