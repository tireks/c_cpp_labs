

#include <iostream>
using namespace std;

void string_switcher(float **matrix_arr_func, int ind_1, 
                     int ind_2, int size_string) // ind_1 - string need to be replaced,
{                                                                    // ind_2 - string replacing
    float temp_buf;
    for (size_t i = 0; i < size_string; i++)
    {
        temp_buf = matrix_arr_func[ind_1][i];
        matrix_arr_func[ind_1][i] = matrix_arr_func[ind_2][i];
        matrix_arr_func[ind_2][i] = temp_buf;
    }
}

void string_cutter(
    float** matrix_arr_func, int which_string,
    int si_wh_col, int size_string, float elem_) // si_wh_col - since which column
{
    for (size_t i = si_wh_col; i < size_string; i++)
    {
        matrix_arr_func[which_string][i] = matrix_arr_func[which_string][i] / elem_;
    }
}

void column_cutter(
    float** matrix_arr_func, int which_column,
    int string_1, int column_size, int string_size)
{
    for (size_t i = 0; i < column_size; i++)
    {
        if (i != string_1)
        {
            float temp_saver = matrix_arr_func[i][which_column];
            for (size_t j = which_column; j < string_size; j++)
            {
                matrix_arr_func[i][j] = matrix_arr_func[i][j] -
                    temp_saver * matrix_arr_func[string_1][j];
            }
        }
    }
}

int main()
{
    float** matrix_arr;
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
    num_columns++;
    matrix_arr = new float*[num_strings];
    for (i_count = 0; i_count < num_strings; i_count++)
    {
        matrix_arr[i_count] = new float[num_columns];
    }
    
    for (i_count = 0; i_count < num_strings; i_count++)
    {
        for (j_count = 0; j_count < num_columns; j_count++)
        {
            //cin >> matrix_arr[i_count][j_count];
            fscanf(file_input, "%f", &matrix_arr[i_count][j_count]);
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

    cout << endl;
    cout << endl;
    int diap_stop = 0;
    for (i_count = 0; i_count < num_columns - 1; i_count++)
    {
        
        float max_elem = matrix_arr[diap_stop][i_count];
        int max_elem_index = diap_stop;
        for (size_t i = diap_stop; i < num_strings; i++)
        {
            if (matrix_arr[i][i_count] > max_elem)
            {
                max_elem_index = i;
                max_elem = matrix_arr[i][i_count];
            }
        }
        if (matrix_arr[diap_stop][i_count] != matrix_arr[max_elem_index][i_count])
        {
            string_switcher(matrix_arr, diap_stop, max_elem_index, num_columns);
        }
        string_cutter(matrix_arr, diap_stop, i_count, num_columns, max_elem);
        column_cutter(matrix_arr, i_count, diap_stop, num_strings, num_columns);
        //
        cout << endl;
        cout << endl;
        for (size_t i_c = 0; i_c < num_strings; i_c++)
        {
            cout << endl;
            for (size_t j_c = 0; j_c < num_columns; j_c++)
            {
                cout << matrix_arr[i_c][j_c] << "  ";
            }
        }
        //
        diap_stop++;
    }
    cout << endl;
    cout << endl;
    for (i_count = 0; i_count < num_strings; i_count++)
    {
        cout << endl;
        for (j_count = 0; j_count < num_columns; j_count++)
        {
            cout << matrix_arr[i_count][j_count] << "  ";
        }
    }
    cout << endl;
    for (i_count = 0; i_count < num_strings; i_count++)
    {
        cout << "x" << i_count + 1 << " = " << matrix_arr[i_count][num_columns - 1];
        cout << endl;
    }
    fclose(file_input);
    free(matrix_arr);
}

