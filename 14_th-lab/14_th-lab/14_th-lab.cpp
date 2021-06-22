

#include <iostream>
using namespace std;

typedef struct Node_1 {
    int dig_1;
    int dig_2;
    struct Node_1* next;
} Node_list_pairs;  // struct for list of pairs from input

Node_list_pairs* create_pairs(int first_dig, int sec_dig)
{
    Node_list_pairs* tmp = (Node_list_pairs*)malloc(sizeof(Node_list_pairs));
    tmp->dig_1 = first_dig;
    tmp->dig_2 = sec_dig;
    tmp->next = NULL;
    return(tmp);
}

int main()
{
    FILE* file_inp_1t; // input file for 1-st task
    char* filename_ = new char[11]; // for typing name of opening file
    char* print_buffer = new char [100]; // buffer for sniffing and printing from file
    //char* converter_buffer = new char[11]; // buffer for converting from input data
    char* estr;
    int i_counter = 0;
    int first_dig = 0;
    int sec_dig = 0;
    cout << "please input name of file, which would be using for data input" << endl;
    cin >> filename_;
    if ((file_inp_1t = fopen(filename_, "a+")) == NULL)
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

        }
    }
    
    //cout << print_buffer << endl;
    fclose(file_inp_1t);
    free(filename_);
    free(print_buffer);
    //free(file_inp_1t);
}


