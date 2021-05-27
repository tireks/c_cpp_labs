

#include <iostream>
using namespace std;

int tab_start_recomb(int num_of_bit) {
    int mass_table[64] =
    {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
     62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
     57, 49, 41, 33, 25, 17, 9,  1, 59, 51, 43, 35, 27, 19, 11, 3,
     61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};
    return mass_table[num_of_bit];
}

int main()
{
    char start_string[9];
    char start_key[8];
    uint64_t string_key_64 = 0;
    uint64_t string_text_64 = 0;
    //------------- inputing and parcing
    cout << "input 8 alphanumeric symbols" << endl;
    cin >> start_string;
    for (size_t i = 0; i < 8; i++)
    {
        cout << int(start_string[i]) << " ------ " << endl;
        string_text_64 = string_text_64 << 8;
        string_text_64 = string_text_64 | int(start_string[i]);
        cout << string_text_64 << endl;
    }
    cout << endl;
    cout << "input 7 alphanumeric symbols for key" << endl;
    cin >> start_key;
    for (size_t i = 0; i < 7; i++)
    {
        cout << int(start_key[i]) << "++++++++ " << endl;
        string_key_64 = string_key_64 << 8;
        string_key_64 = string_key_64 | int(start_key[i]);
        cout << string_key_64 << endl;
    }
    cout << endl;
    //------------- end of inputing and parcing


}


