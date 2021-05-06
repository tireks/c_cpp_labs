

#include <iostream>
using namespace std;

int main()
{
    int** matrix_arr;
    int num_strings;
    int i_count;
    int j_count;
    int num_columns;
    FILE* file_input;
    char name[] = "test1.txt";
    /*cout << "input num of strs" << endl;
    cin >>num_strings;
    cout << "input num of cols" << endl;
    cin >> num_columns;*/
    if ((file_input = fopen(name, "r")) == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }
    fscanf(file_input, "%d", &num_strings);
    fscanf(file_input, "%d", &num_columns);
    matrix_arr = new int*[num_strings];
    for (i_count = 0; i_count < num_strings; i_count++)
    {
        matrix_arr[i_count] = new int[num_columns];
    }
    
    for (i_count = 0; i_count < num_strings; i_count++)
    {
        for (j_count = 0; j_count < num_columns; j_count++)
        {
            //cin >> matrix_arr[i_count][j_count];
            fscanf(file_input, "%d", &matrix_arr[i_count][j_count]);
        }
    }

    for (i_count = 0; i_count < num_strings; i_count++)
    {
        cout << endl;
        for (j_count = 0; j_count < num_columns; j_count++)
        {
            cout << matrix_arr[i_count][j_count] << "  ";
        }
    }
    free(matrix_arr);
}

