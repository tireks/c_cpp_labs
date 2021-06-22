

#include <iostream>
using namespace std;

typedef struct Node_1 {
    int dig_1;
    int dig_2;
    struct Node_1* next;
} Node_list_pairs;  // struct for list of pairs from input

Node_list_pairs* create_pairs_list(int first_dig, int sec_dig)
{
    Node_list_pairs* tmp = (Node_list_pairs*)malloc(sizeof(Node_list_pairs));
    tmp->dig_1 = first_dig;
    tmp->dig_2 = sec_dig;
    tmp->next = NULL;
    return(tmp);
}

void add_element_pairs_list(Node_list_pairs* list, int first_dig, int sec_dig)
{
    // Выделение памяти под корень списка
    Node_list_pairs* tmp = (Node_list_pairs*)malloc(sizeof(Node_list_pairs));
    // Присваивание значения узлу
    tmp->dig_1 = first_dig;
    tmp->dig_2 = sec_dig;
    // Присваивание указателю на следующий элемент значения NULL
    tmp->next = NULL;
    // Присваивание новому указателю указателя head. 
    // Присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
    Node_list_pairs* p = list;
    // Сдвиг указателя p в самый конец первоначального списка
    while (p->next != NULL)
        p = p->next;
    // Присваивание указателю p -> next значения указателя tmp (созданный новый узел)
    p->next = tmp;
}

bool new_add_element_p_l(Node_list_pairs* list, int first_dig, int sec_dig)
{
    Node_list_pairs* p1 = list;
    while (p1 != NULL)
    {
        if (((p1->dig_1 == first_dig)&&(p1->dig_2 == sec_dig))
            || ((p1->dig_1 == sec_dig)&&(p1->dig_2 == first_dig)))
        {
            return false;
        }
        else
        {
            p1 = p1->next;
        }
    }
    Node_list_pairs* tmp = (Node_list_pairs*)malloc(sizeof(Node_list_pairs));
    // Присваивание значения узлу
    tmp->dig_1 = first_dig;
    tmp->dig_2 = sec_dig;
    // Присваивание указателю на следующий элемент значения NULL
    tmp->next = NULL;
    // Присваивание новому указателю указателя head. 
    // Присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
    Node_list_pairs* p = list;
    // Сдвиг указателя p в самый конец первоначального списка
    while (p->next != NULL)
        p = p->next;
    // Присваивание указателю p -> next значения указателя tmp (созданный новый узел)
    p->next = tmp;
}

Node_list_pairs* remove_pairs_list(Node_list_pairs* head)
{
    while (head != NULL)
    {
        Node_list_pairs* p = head;
        head = head->next;
        free(p);
    }
    return NULL;
}

int max_peak_searcher(Node_list_pairs* list)
{
    Node_list_pairs* p;
    int max__ = 0;
    p = list;
    do
    {
        if (p->dig_1 > max__)
        {
            max__ = p->dig_1;
        }
        if (p->dig_2 > max__)
        {
            max__ = p->dig_2;
        }
        p = p->next;
    } while (p != NULL);
    return max__;
}

void adj_m_filler(Node_list_pairs* list, int** _matrix)
{
    Node_list_pairs* p;
    p = list;
    do
    {
        _matrix[p->dig_1 - 1][p->dig_2 - 1] = 1;
        _matrix[p->dig_2 - 1][p->dig_1 - 1] = 1;
        p = p->next;
    } while (p != NULL);
}

int main()
{
    Node_list_pairs* pairs_list = NULL;
    FILE* file_inp_1t; // input file for 1-st task
    FILE* file_out_1t; // output file for 1-st task
    char* filename_ = new char[11]; // for typing name of opening file
    char* print_buffer = new char [100]; // buffer for sniffing and printing from file
    int** adj_matrix; // adjacency matrix that needed to be filled correctly to pass the task
    //char* converter_buffer = new char[11]; // buffer for converting from input data
    char* estr; // needed for correct reading from file
    int i_counter = 0; // counter
    int first_dig = 0; // first digit, that 've ridden from file
    int sec_dig = 0; // second digit, that 've ridden from file
    int adj_m_size = 0; //size of adjacency matrix
    cout << "please input name of file, which would be using for data input" << endl;
    cin >> filename_;
    if ((file_inp_1t = fopen(filename_, "a+")) == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }
    if ((file_out_1t = fopen("1_out.txt", "w")) == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }
    while (!feof(file_inp_1t))
    {
        estr = fgets(print_buffer, 99, file_inp_1t);
        i_counter = 0;
        first_dig = 0;
        sec_dig = 0;
        if (estr != NULL)
        {
            cout << print_buffer << endl;
            while (print_buffer[i_counter] != 32)
            {
                //converter_buffer[i_counter] = print_buffer[i_counter];
                first_dig = first_dig*10 + (print_buffer[i_counter] - '0');
                i_counter++;
            }
            i_counter++;
            while (print_buffer[i_counter] != 10)
            {
                //converter_buffer[i_counter] = print_buffer[i_counter];
                sec_dig = sec_dig * 10 + (print_buffer[i_counter] - '0');
                i_counter++;
            }
            cout << "------" << first_dig << " " << sec_dig << endl;
            if (pairs_list == NULL)
            {
                pairs_list = create_pairs_list(first_dig, sec_dig);
            }
            else
            {
                add_element_pairs_list(pairs_list, first_dig, sec_dig);
            }
        }
    }
    adj_m_size = max_peak_searcher(pairs_list);

    adj_matrix = new int* [adj_m_size];
    for (size_t i = 0; i < adj_m_size; i++)
    {
        adj_matrix[i] = new int[adj_m_size];
        for (size_t j = 0; j < adj_m_size; j++)
        {
            adj_matrix[i][j] = 0 ;
        }
    }

    adj_m_filler(pairs_list, adj_matrix);
    fprintf(file_out_1t, "+");
    for (size_t i = 0; i < adj_m_size; i++)
    {
        fprintf(file_out_1t, " ");
        fprintf(file_out_1t, "%d", i + 1);
    }
    fprintf(file_out_1t, "\n");
    for (size_t i = 0; i < adj_m_size; i++)
    {
        fprintf(file_out_1t, "%d", i + 1);
        for (size_t j = 0; j < adj_m_size; j++)
        {
            if (adj_matrix[i][j] == 1)
            {
                fprintf(file_out_1t, " ");
                fprintf(file_out_1t, "%d", adj_matrix[i][j]);
            }
            else
            {
                fprintf(file_out_1t, " ");
                fprintf(file_out_1t, "-");
            }
        }
        fprintf(file_out_1t, "\n");
    }
    remove_pairs_list(pairs_list);
    fclose(file_inp_1t);
    fclose(file_out_1t);
    ////////////end of 1-st task
    FILE* file_out_2d;
    adj_m_size = 0;
    int j_counter;
    int cursor_counter;
    int cursor_adj;
    i_counter = 0;
    if ((file_out_1t = fopen("1_out.txt", "a+")) == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }
    if ((file_out_2d = fopen("2_out.txt", "w")) == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }
    fgets(print_buffer, 99, file_out_1t);
    while (print_buffer[i_counter] != 10)
    {
        if ((print_buffer[i_counter] != 45) && (print_buffer[i_counter] != 32) &&
            (print_buffer[i_counter] != 43) && (print_buffer[i_counter] != 10))
        {
            if ((print_buffer[i_counter + 1] == 45) || (print_buffer[i_counter + 1] == 32) ||
                (print_buffer[i_counter + 1] == 43) || (print_buffer[i_counter + 1] == 10))
            {
                adj_m_size++;
            }
            
        }
        i_counter++;
    }
    for (size_t i = 0; i < adj_m_size; i++)
    {
        for (size_t j = 0; j < adj_m_size; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }
    j_counter = 0;
    cursor_counter = 0;
    cursor_adj = 0;
    while (!feof(file_out_1t))
    {
        estr = fgets(print_buffer, 99, file_out_1t);
        i_counter = 0;
        if (estr != NULL)
        {
            cursor_counter = 0;
            cursor_adj = 0;
            print_buffer[0] = (char)('0');
            cout << print_buffer << endl;
            while (print_buffer[i_counter] != 10)
            {
                if ((print_buffer[i_counter] == 45))
                {
                    cursor_counter++;
                }
                if ((print_buffer[i_counter] == 49) )
                {
                    cursor_counter++;
                    adj_matrix[j_counter][cursor_adj] = cursor_counter;
                    cursor_adj++;
                }
                i_counter++;
            }
            j_counter++;
        }
    }
    i_counter = 0;
    j_counter = 0;
    for (size_t i = 0; i < adj_m_size; i++)
    {
        for (size_t j = 0; j < adj_m_size; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
    /*while (adj_matrix[i_counter][0] != 0)
    {
        fprintf(file_out_2d, "%d", i_counter + 1);
        fprintf(file_out_2d, " - ");
        while (adj_matrix[i_counter][j_counter] != 0)
        {
            fprintf(file_out_2d, "%d", adj_matrix[i_counter][j_counter]);
            fprintf(file_out_2d, ", ");
            j_counter++;
        }
        i_counter++;
        fprintf(file_out_2d, "\n");
    }*/

    for (i_counter = 0; i_counter < adj_m_size; i_counter++)
    {
        if (adj_matrix[i_counter][0] != 0)
        {
            fprintf(file_out_2d, "%d", i_counter + 1);
            fprintf(file_out_2d, " - ");
            for (size_t j_counter = 0; j_counter < adj_m_size; j_counter++)
            {
                if (adj_matrix[i_counter][j_counter] != 0)
                {
                    fprintf(file_out_2d, "%d", adj_matrix[i_counter][j_counter]);
                    fprintf(file_out_2d, ", ");
                }
            }
            fprintf(file_out_2d, "\n");
        }
        
    }
    fclose(file_out_2d);
    fclose(file_out_1t);
    //////////////////// end of 2-d task
    FILE* file_out_3d;
    Node_list_pairs* pairs_list_new = NULL;
    if ((file_out_2d = fopen("2_out.txt", "a+")) == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }
    if ((file_out_3d = fopen("3_out.txt", "w")) == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }    
    cursor_adj = 0; //here and now name of variable doesn't mean anything, didn't want to make new one
    cursor_counter = 0;
    while (!feof(file_out_2d))
    {
        estr = fgets(print_buffer, 99, file_out_2d);
        i_counter = 0;
        cursor_counter = 0;
        cursor_adj = 0;
        if (estr != NULL)
        {
            while (print_buffer[i_counter] != 32)
            {
                cursor_adj = cursor_adj * 10 + (print_buffer[i_counter] - '0');
                i_counter++;
            }
            i_counter = i_counter + 3;
            while (print_buffer[i_counter] != 10)
            {
                while ((print_buffer[i_counter] != 44) && (print_buffer[i_counter] != 10))
                {
                    cursor_counter = cursor_counter * 10 + (print_buffer[i_counter] - '0');
                    i_counter++;
                }
                i_counter = i_counter + 2;
                if (pairs_list_new == NULL)
                {
                    pairs_list_new = create_pairs_list(cursor_adj, cursor_counter);
                }
                else
                {
                    new_add_element_p_l(pairs_list_new, cursor_adj, cursor_counter);
                }
                cursor_counter = 0;
            }
        }
    }
    Node_list_pairs* p_curs = pairs_list_new;
    fprintf(file_out_3d, "\n");
    while (p_curs != NULL)
    {
        fprintf(file_out_3d, "%d", p_curs->dig_1);
        fprintf(file_out_3d, " , ");
        fprintf(file_out_3d, "%d", p_curs->dig_2);
        fprintf(file_out_3d, "\n");
        p_curs = p_curs->next;
    }
    remove_pairs_list(pairs_list_new);

    fclose(file_out_2d);
    fclose(file_out_3d);
    free(adj_matrix);
    free(filename_);
    free(print_buffer);
    //free(file_inp_1t);
}


