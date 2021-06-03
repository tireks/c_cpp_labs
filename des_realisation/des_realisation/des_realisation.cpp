

#include <iostream>
using namespace std;

int tab_start_permut(int num_of_bit) {
    int mass_table[64] =
    {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
     62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
     57, 49, 41, 33, 25, 17, 9,  1, 59, 51, 43, 35, 27, 19, 11, 3,
     61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};
    return mass_table[num_of_bit];
}

int tab_1st_keysplit_1(int num_of_bit)
{
    int mass_table[28] =
    {57, 49, 41, 33, 25, 17, 9,
     1,  58, 50, 42, 34, 26, 18,
     10, 2,  59, 51, 43, 35, 27,
     19, 11, 3,  60, 52, 44, 36};
    return mass_table[num_of_bit];
}

int tab_1st_keysplit_2(int num_of_bit)
{
    int mass_table[28] =
    {63, 55, 47, 39, 31, 23, 15,
     7,  62, 54, 46, 38, 30, 22,
     14, 6,  61, 53, 45, 37, 29,
     21, 13, 5,  28, 20, 12, 4};
    return mass_table[num_of_bit];
}

int tab_key_zip(int num_of_bit)
{
    int mass_table[48] =
    {14, 17, 11, 24, 1,  5,  3,  28, 15, 6,  21, 10,
     23, 19, 12, 4,  26, 8,  16, 7,  27, 20, 13, 2,
     41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
     44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};
    return mass_table[num_of_bit];
}

int tab_text_expansion(int num_of_bit)
{
    int mass_table[48] =
    {32, 1,  2,  3,  4,  5,
     4,  5,  6,  7,  8,  9,
     8,  9,  10, 11, 12, 13,
     12, 13, 14, 15, 16, 17,
     16, 17, 18, 19, 20, 21,
     20, 21, 22, 23, 24, 25,
     24, 25, 26, 27, 28, 29,
     28, 29, 30, 31, 32, 1 };
    return mass_table[num_of_bit];
}

int tab_S_united(int num_of_bit)
{
    int mass_table[513] =
    {-1,
     14, 4,  13, 1,  2,  15, 11, 8,  3,  10, 6,  12, 5,  9,  0,  7,
     0,  15, 7,  4,  14, 2,  13, 1,  10, 6,  12, 11, 9,  5,  3,  8,
     4,  1,  14, 8,  13, 6,  2,  11, 15, 12, 9,  7,  3,  10, 5,  0,
     15, 1 , 8 , 14, 6 , 11, 3 , 4 , 9 , 7 , 2 , 13, 12, 0 , 5 , 10,
     3 , 13, 4 , 7 , 15, 2 , 8 , 14, 12, 0 , 1 , 10, 6 , 9 , 11, 5,
     0 , 14, 7 , 11, 10, 4 , 13, 1 , 5 , 8 , 12, 6 , 9 , 3 , 2 , 15,
     13, 8 , 10, 1 , 3 , 15, 4 , 2 , 11, 6 , 7 , 12, 0 , 5 , 14, 9,
     10, 0 , 9 , 14, 6 , 3 , 15, 5 , 1 , 13, 12, 7 , 11, 4 , 2 , 8,
     13, 7 , 0 , 9 , 3 , 4 , 6 , 10, 2 , 8 , 5 , 14, 12, 11, 15, 1,
     13, 6 , 4 , 9 , 8 , 15, 3 , 0 , 11, 1 , 2 , 12, 5 , 10, 14, 7,
     1 , 10, 13, 0 , 6 , 9 , 8 , 7 , 4 , 15, 14, 3 , 11, 5 , 2 , 12,
     7 , 13, 14, 3 , 0 , 6 , 9 , 10, 1 , 2 , 8 , 5 , 11, 12, 4 , 15,
     13, 8 , 11, 5 , 6 , 15, 0 , 3 , 4 , 7 , 2 , 12, 1 , 10, 14, 9,
     10, 6 , 9 , 0 , 12, 11, 7 , 13, 15, 1 , 3 , 14, 5 , 2 , 8 , 4,
     3 , 15, 0 , 6 , 10, 1 , 13, 8 , 9 , 4 , 5 , 11, 12, 7 , 2 , 14,
     2 , 12, 4 , 1 , 7 , 10, 11, 6 , 8 , 5 , 3 , 15, 13, 0 , 14, 9,
     14, 11, 2 , 12, 4 , 7 , 13, 1 , 5 , 0 , 15, 10, 3 , 9 , 8 , 6,
     4 , 2 , 1 , 11, 10, 13, 7 , 8 , 15, 9 , 12, 5 , 6 , 3 , 0 , 14,
     11, 8 , 12, 7 , 1 , 14, 2 , 13, 6 , 15, 0 , 9 , 10, 4 , 5 , 3,
     12, 1 , 10, 15, 9 , 2 , 6 , 8 , 0 , 13, 3 , 4 , 14, 7 , 5 , 11,
     10, 15, 4 , 2 , 7 , 12, 9 , 5 , 6 , 1 , 13, 14, 0 , 11, 3 , 8,
     9 , 14, 15, 5 , 2 , 8 , 12, 3 , 7 , 0 , 4 , 10, 1 , 13, 11, 6,
     4 , 3 , 2 , 12, 9 , 5 , 15, 10, 11, 14, 1 , 7 , 6 , 0 , 8 , 13,
     4 , 11, 2 , 14, 15, 0 , 8 , 13, 3 , 12, 9 , 7 , 5 , 10, 6 , 1,
     13, 0 , 11, 7 , 4 , 9 , 1 , 10, 14, 3 , 5 , 12, 2 , 15, 8 , 6,
     1 , 4 , 11, 13, 12, 3 , 7 , 14, 10, 15, 6 , 8 , 0 , 5 , 9 , 2,
     6 , 11, 13, 8 , 1 , 4 , 10, 7 , 9 , 5 , 0 , 15, 14, 2 , 3 , 12,
     13, 2 , 8 , 4 , 6 , 15, 11, 1 , 10, 9 , 3 , 14, 5 , 0 , 12, 7,
     1 , 15, 13, 8 , 10, 3 , 7 , 4 , 12, 5 , 6 , 11, 0 , 14, 9 , 2,
     7 , 11, 4 , 1 , 9 , 12, 14, 2 , 0 , 6 , 10, 13, 15, 3 , 5 , 8,
     2 , 1 , 14, 7 , 4 , 10, 8 , 13, 15, 12, 9 , 0 , 3 , 5 , 6 , 11
    };
    return mass_table[num_of_bit];
}

int tab_p_permutation(int num_of_bit)
{
    int mass_table[32] =
    {16, 7 , 20, 21, 29, 12, 28, 17, 1 , 15, 23, 26, 5 , 18, 31, 10,
     2 , 8 , 24, 14, 32, 27, 3 , 9 , 19, 13, 30, 6 , 22, 11, 4 , 25,};
    return mass_table[num_of_bit];
}

int tab_end_permutation(int num_of_bit)
{
    int mass_table[64] =
    {40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
     38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
     36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
     34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9 , 49, 17, 57, 25};
    return mass_table[num_of_bit];
}

void start_permutation(bool* text1, bool* text2)
{
    for (size_t i = 0; i < 64; i++)
    {
        text2[i] = text1[tab_start_permut(i) - 1];
    }
}

void end_permutation(bool* text_1, bool* text_2)
{
    for (size_t i = 0; i < 64; i++)
    {
        text_2[i] = text_1[tab_end_permutation(i) - 1];
    }
}

void split_to_subblocks(bool* text_64, bool* text_32_1, bool* text_32_2)
{
    for (size_t i = 0; i < 32; i++)
    {
        text_32_1[i] = text_64[i];
    }
    for (size_t i = 0; i < 32; i++)
    {
        text_32_2[i] = text_64[i+32];
    }
}

void unite_to_block(bool* text_64, bool* text_32_1, bool* text_32_2)
{
    for (size_t i = 0; i < 32; i++)
    {
        text_64[i] = text_32_1[i];
        text_64[32 + i] = text_32_2[i];
    }
}

void key_first_splitter(bool* key_64, bool* key_28_1, bool* key_28_2)
{
    for (size_t i = 0; i < 28; i++)
    {
        key_28_1[i] = key_64[tab_1st_keysplit_1(i) - 1];
    }
    for (size_t i = 0; i < 28; i++)
    {
        key_28_2[i] = key_64[tab_1st_keysplit_2(i) - 1];
    }
}

void left_cycl_shift(bool* mass, int mass_size ,int shift_step)
{
    bool temp_buf1;
    bool temp_buf2;
    if (shift_step == 1)
    {
        temp_buf1 = mass[0];
        for (int i = 1; i < mass_size; i++)
        {
            mass[i - 1] = mass[i];
        }
        mass[mass_size - 1] = temp_buf1;
    }
    if (shift_step == 2)
    {
        temp_buf1 = mass[0];
        temp_buf2 = mass[1];
        for (int i = 2; i < mass_size; i++)
        {
            mass[i - 2] = mass[i];
        }
        mass[mass_size - 2] = temp_buf1;
        mass[mass_size - 1] = temp_buf2;
    }
}

void right_cycl_shift(bool* mass, int mass_size, int shift_step)
{
    bool temp_buf1;
    bool temp_buf2;
    if (shift_step == 1)
    {
        temp_buf1 = mass[mass_size - 1];
        for (int i = 0; i < mass_size - 1; i++)
        {
            mass[i + 1] = mass[i];
        }
        mass[0] = temp_buf1;
    }
    if (shift_step == 2)
    {
        temp_buf1 = mass[mass_size - 2];
        temp_buf2 = mass[mass_size - 1];
        for (int i = 0; i < mass_size - 2; i++)
        {
            mass[i + 2] = mass[i];
        }
        mass[0] = temp_buf1;
        mass[1] = temp_buf2;
    }
}

void K_i_generator(bool* key_48, bool* key_56, 
                    bool* key_28_1, bool* key_28_2,
                    int level_num)
{
    if ((level_num == 0) || (level_num == 1) ||
        (level_num == 8) || (level_num == 15))
    {
        left_cycl_shift(key_28_1, 28, 1);
        left_cycl_shift(key_28_2, 28, 1);
    }
    else
    {
        left_cycl_shift(key_28_1, 28, 2);
        left_cycl_shift(key_28_2, 28, 2);
    }
    for (size_t i = 0; i < 28; i++)
    {
        key_56[i] = key_28_1[i];
    }
    for (size_t i = 0; i < 28; i++)
    {
        key_56[i + 28] = key_28_2[i];
    }
    for (size_t i = 0; i < 48; i++)
    {
        key_48[i] = key_56[tab_key_zip(i) - 1];
    }
}

void reverse_K_i_generator(bool* key_48, bool* key_56,
    bool* key_28_1, bool* key_28_2,
    int level_num)
{
    if ((level_num == 1) ||
        (level_num == 8) || (level_num == 15))
    {
        right_cycl_shift(key_28_1, 28, 1);
        right_cycl_shift(key_28_2, 28, 1);
    }
    else
    {
        if (level_num != 0)
        {
            right_cycl_shift(key_28_1, 28, 2);
            right_cycl_shift(key_28_2, 28, 2);
        }
    }
    for (size_t i = 0; i < 28; i++)
    {
        key_56[i] = key_28_1[i];
    }
    for (size_t i = 0; i < 28; i++)
    {
        key_56[i + 28] = key_28_2[i];
    }
    for (size_t i = 0; i < 48; i++)
    {
        key_48[i] = key_56[tab_key_zip(i) - 1];
    }
}

void XORer(bool* first_mass, bool* sec_mass, int size_of_massives)
{
    for (int i = 0; i < size_of_massives; i++)
    {
        switch (first_mass[i])
        {
        case 1:
            if (sec_mass[i] == 1)
            {
                first_mass[i] = 0;
            }
            else
            {
                first_mass[i] = 1;
            }
            break;
        case 0:
            if (sec_mass[i] == 0)
            {
                first_mass[i] = 0;
            }
            else
            {
                first_mass[i] = 1;
            }
            break;
        }
    }
}

int Sblock_binary_determ(int first_bit, int last_bit)
{
    switch (first_bit)
    {
    case 0:
        switch (last_bit)
        {
        case 0:
            return 0;
            break;
        case 1:
            return 1;
            break;
        }
        break;
    case 1:
        switch (last_bit)
        {
        case 0:
            return 2;
            break;
        case 1:
            return 3;
            break;
        }
        break;
    }
}

void eight_block_worker(bool* text48,
                        bool* text_32_temp, bool* text_32_temp_2)
{
    int to_S_block_1 = 0;
    int to_S_block_2 = 0;
    int from_S_block = 0;
    int temp_binary_1 = 0;
    int temp_binary_2 = 0;
    int middle_4[4];
    int while_iteration = 0;
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            middle_4[j] = (int)text48[i * 6 + 1 + j];
        }
        for (int q = 3; q > -1; q--)
        {
            if (middle_4[q] == '1')
            {
                to_S_block_1 += pow(2, 4 - (q + 1));
            }
        }
        temp_binary_1 = (int)text48[i * 6];
        temp_binary_2 = (int)text48[i * 6 + 5];
        to_S_block_2 = Sblock_binary_determ(temp_binary_1, temp_binary_2);
        from_S_block = tab_S_united((64 * i + 1) + (to_S_block_2 * 15 + 1) + (to_S_block_1));
        while_iteration = 0;
        while (from_S_block > 0)
        {
            middle_4[3 - while_iteration] = from_S_block % 2;
            from_S_block = from_S_block / 2;
            while_iteration++;
        }
        for (size_t p = 0; p < 4; p++)
        {
            text_32_temp_2[4 * i + p] = middle_4[p];
        }
        
    }
    for (size_t t = 0; t < 32; t++)
    {
        text_32_temp[t] = text_32_temp_2[tab_p_permutation(t) - 1];
    }
}

void feistel_16_lvls(
    bool* text_1_32, bool* text_2_32, bool* text_temp_32, 
    bool* text_temp_32_2, bool* key_1_28, bool* key_2_28)
{
    bool* key_48;
    key_48 = new bool[48];
    for (size_t i = 0; i < 48; i++)
    {
        key_48[i] = 0;
    }
    bool* key56_text48;
    key56_text48 = new bool[56];
    for (size_t i = 0; i < 56; i++)
    {
        key56_text48[i] = 0;
    }
    for (size_t i = 0; i < 16; i++)
    {
        K_i_generator(key_48, key56_text48, key_1_28, key_2_28, i);
        for (size_t j = 0; j < 48; j++)
        {
            key56_text48[j] = text_2_32[tab_text_expansion(j) - 1];
        }
        XORer(key56_text48, key_48, 48);
        eight_block_worker(key56_text48, text_temp_32, text_temp_32_2);
        XORer(text_1_32, text_temp_32, 32);
        if (i < 16)
        {
            for (size_t j = 0; j < 32; j++)
            {
                text_temp_32[j] = text_1_32[j];
                text_1_32[j] = text_2_32[j];
                text_2_32[j] = text_temp_32[j];
            }
        }
    }
    free(key56_text48);
    free(key_48);
}

void reverse_feistel_16_lvls(
    bool* text_1_32, bool* text_2_32, bool* text_temp_32,
    bool* text_temp_32_2, bool* key_1_28, bool* key_2_28)
{
    bool* key_48;
    key_48 = new bool[48];
    for (size_t i = 0; i < 48; i++)
    {
        key_48[i] = 0;
    }
    bool* key56_text48;
    key56_text48 = new bool[56];
    for (size_t i = 0; i < 56; i++)
    {
        key56_text48[i] = 0;
    }
    for (size_t i = 0; i < 16; i++)
    {
        reverse_K_i_generator(key_48, key56_text48, key_1_28, key_2_28, i);
        for (size_t j = 0; j < 48; j++)
        {
            key56_text48[j] = text_1_32[tab_text_expansion(j) - 1];
        }
        XORer(key56_text48, key_48, 48);
        eight_block_worker(key56_text48, text_temp_32, text_temp_32_2);
        XORer(text_2_32, text_temp_32, 32);
        if (i < 16)
        {
            for (size_t j = 0; j < 32; j++)
            {
                text_temp_32[j] = text_1_32[j];
                text_1_32[j] = text_2_32[j];
                text_2_32[j] = text_temp_32[j];
            }
        }
    }
    free(key56_text48);
    free(key_48);
}


int main()
{
    char start_string_input[9];
    char start_key_input[9];
    //uint64_t string_key_64 = 0;
    bool* text_64_1;
    bool* text_64_2;
    bool* text_32_1;
    bool* text_32_2;
    bool* text_32_temp;
    bool* text_32_temp_2;
    bool* key_64_1;
    bool* key_28_1;
    bool* key_28_2;
    bool* key_64_2;
    text_64_1 = new bool[64];
    for (size_t i = 0; i < 64; i++)
    {
        text_64_1[i] = 0;
    }
    text_64_2 = new bool[64];
    for (size_t i = 0; i < 64; i++)
    {
        text_64_2[i] = 0;
    }
    text_32_1 = new bool[32];
    for (size_t i = 0; i < 32; i++)
    {
        text_32_1[i] = 0;
    }
    text_32_2 = new bool[32];
    for (size_t i = 0; i < 32; i++)
    {
        text_32_2[i] = 0;
    }
    text_32_temp = new bool[32];
    for (size_t i = 0; i < 32; i++)
    {
        text_32_temp[i] = 0;
    }
    text_32_temp_2 = new bool[32];
    for (size_t i = 0; i < 32; i++)
    {
        text_32_temp_2[i] = 0;
    }
    key_64_1 = new bool[64];
    for (size_t i = 0; i < 64; i++)
    {
        key_64_1[i] = 0;
    }
    key_28_1 = new bool[28];
    for (size_t i = 0; i < 28; i++)
    {
        key_28_1[i] = 0;
    }
    key_28_2 = new bool[28];
    for (size_t i = 0; i < 28; i++)
    {
        key_28_2[i] = 0;
    }
    key_64_2 = new bool[64];
    for (size_t i = 0; i < 64; i++)
    {
        key_64_2[i] = 0;
    }
    int temp_buf;
    int while_iteration;
    //------------- inputing and parcing
    cout << "input 8 alphanumeric symbols" << endl;
    cin >> start_string_input;
    for (size_t i = 0; i < 8; i++)
    {
        cout << int(start_string_input[i]) << " ------ " << endl;
        temp_buf = int(start_string_input[i]);
        while_iteration = 0;
        while (temp_buf > 0)
        {
            text_64_1[i * 8 + (7 - while_iteration)] = temp_buf % 2;
            temp_buf = temp_buf / 2;
            while_iteration++;
        }
        if (while_iteration == 6)
        {
            text_64_1[i * 8] = 0;
        }
        else
        {
            if (while_iteration == 5)
            {
                text_64_1[i * 8] = 0;
                text_64_1[i * 8 + 1] = 0;
            }
        }
        for (size_t j = 0; j < 64; j++)
        {
            cout << text_64_1[j];
        }
        cout << endl;

    }
    cout << endl;
    cout << "input 8 alphanumeric symbols for key" << endl;
    cin >> start_key_input;
    for (size_t i = 0; i < 8; i++)
    {
        cout << int(start_key_input[i]) << "++++++++ " << endl;
        temp_buf = int(start_key_input[i]);
        while_iteration = 0;
        while (temp_buf > 0)
        {
            key_64_1[i * 8 + (7 - while_iteration)] = temp_buf % 2;
            temp_buf = temp_buf / 2;
            while_iteration++;
        }
        if (while_iteration == 6)
        {
            key_64_1[i * 8] = 0;
        }
        else
        {
            if (while_iteration == 5)
            {
                key_64_1[i * 8] = 0;
                key_64_1[i * 8 + 1] = 0;
            }
        }
        for (size_t j = 0; j < 64; j++)
        {
            cout << key_64_1[j];
        }
        cout << endl;
    }
    cout << endl;
    //------------- end of inputing and parcing

    start_permutation(text_64_1, text_64_2);

    for (size_t j = 0; j < 64; j++)
    {
        cout << text_64_2[j];
    }
    cout << endl;

    split_to_subblocks(text_64_2, text_32_1, text_32_2);

    key_first_splitter(key_64_1, key_28_1, key_28_2);

    for (size_t j = 0; j < 32; j++)
    {
        cout << text_32_1[j];
    }
    cout << endl;
    for (size_t j = 0; j < 32; j++)
    {
        cout << " ";
    }
    for (size_t j = 0; j < 32; j++)
    {
        cout << text_32_2[j];
    }
    cout << endl;

    for (size_t j = 0; j < 28; j++)
    {
        cout << key_28_1[j];
    }
    cout << endl;
    for (size_t j = 0; j < 28; j++)
    {
        cout << " ";
    }
    for (size_t j = 0; j < 28; j++)
    {
        cout << key_28_2[j];
    }
    cout << endl;

    feistel_16_lvls(text_32_1, text_32_2, text_32_temp, 
                    text_32_temp_2, key_28_1, key_28_2);

    unite_to_block(text_64_1, text_32_1, text_32_2);

    end_permutation(text_64_1, text_64_2);
    for (size_t j = 0; j < 64; j++)
    {
        cout << text_64_2[j];
    }
    cout << endl;
    //end of encryption
    for (size_t i = 0; i < 8; i++)
    {
        cout << int(start_key_input[i]) << "++++++++ " << endl;
        temp_buf = int(start_key_input[i]);
        while_iteration = 0;
        while (temp_buf > 0)
        {
            key_64_1[i * 8 + (7 - while_iteration)] = temp_buf % 2;
            temp_buf = temp_buf / 2;
            while_iteration++;
        }
        if (while_iteration == 6)
        {
            key_64_1[i * 8] = 0;
        }
        else
        {
            if (while_iteration == 5)
            {
                key_64_1[i * 8] = 0;
                key_64_1[i * 8 + 1] = 0;
            }
        }
        for (size_t j = 0; j < 64; j++)
        {
            cout << key_64_1[j];
        }
        cout << endl;
    }
    cout << endl;

    start_permutation(text_64_2, text_64_1);

    split_to_subblocks(text_64_1, text_32_1, text_32_2);

    key_first_splitter(key_64_1, key_28_1, key_28_2);

    reverse_feistel_16_lvls(text_32_1, text_32_2, text_32_temp,
        text_32_temp_2, key_28_1, key_28_2);

    unite_to_block(text_64_1, text_32_1, text_32_2);

    end_permutation(text_64_1, text_64_2);
    for (size_t j = 0; j < 64; j++)
    {
        cout << text_64_2[j];
    }
    cout << endl;
    
    free(text_64_1);
    free(text_64_2);
    free(text_32_1);
    free(text_32_2);
    free(text_32_temp);
    free(text_32_temp_2);
    free(key_28_1);
    free(key_28_2);
    free(key_64_1);
    free(key_64_2);

}


