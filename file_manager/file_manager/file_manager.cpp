

#include <iostream>
using namespace std;

typedef struct Node_1 {
    int user_id;
    char login[11];
    char password[9];
    struct Node_1* next;
} Node_auth;

typedef struct Node_2 {
    int user_id;
    bool read_permition;
    bool write_permition;
    bool append_permition;
    struct Node_2* next;
} Node_Pmatr_inner;

typedef struct Node_3 {
    int file_id;
    struct Node_3* next;
    Node_Pmatr_inner* containment;
} Node_Pmatr_outter;

typedef struct Node_4 {
    int file_id;
    char filename[16];
    struct Node_4* next;
} Node_file_id_comp;

Node_auth* create_auth(int id_input, char* login_, char* pass)
{
    Node_auth* tmp = (Node_auth*)malloc(sizeof(Node_auth));
    tmp->user_id = id_input;
    memcpy(tmp->login, login_, 11);
    memcpy(tmp->password, pass, 9);
    tmp->next = NULL;
    return(tmp);
}

Node_file_id_comp* create_comp_tab_file(int file_id_, char* filename_)
{
    Node_file_id_comp* tmp = (Node_file_id_comp*)malloc(sizeof(Node_file_id_comp));
    tmp->file_id = file_id_;
    memcpy(tmp->filename, filename_, 16);
    tmp->next = NULL;
    return(tmp);
}

Node_Pmatr_inner* create_Pmatr_inner(int user_id_, bool r_p, bool w_p, bool a_p)
{
    Node_Pmatr_inner* tmp = (Node_Pmatr_inner*)malloc(sizeof(Node_Pmatr_inner));
    tmp->user_id = user_id_;
    tmp->read_permition = r_p;
    tmp->write_permition = w_p;
    tmp->append_permition = a_p;
    tmp->next = NULL;
    return(tmp);
}

Node_Pmatr_outter* create_Pmatr_outter(Node_Pmatr_inner* start_cont, int file_id_)
{
    Node_Pmatr_outter* tmp = (Node_Pmatr_outter*)malloc(sizeof(Node_Pmatr_outter));
    tmp->file_id = file_id_;
    tmp->containment = start_cont;
    tmp->next = NULL;
    return(tmp);
}

/*Node_auth* addelem_auth(Node_auth* lst, int id_input, char* login_, char* pass)
{
    Node_auth* temp, * p;
    temp = (Node_auth*)malloc(sizeof(Node_auth));
    p = lst->next; // сохранение указателя на следующий узел
    lst->next = temp; // предыдущий узел указывает на создаваемый
    temp->user_id = id_input; // сохранение поля данных добавляемого узла 
    memcpy(temp->login, login_, 11);
    memcpy(temp->password, pass, 9);
    temp->next = p; // созданный узел указывает на следующий элемент
    return(temp);
}*/

void add_element_auth(Node_auth* list, int id_input, char* login_, char* pass)
{
    // Выделение памяти под корень списка
    Node_auth* tmp = (Node_auth*)malloc(sizeof(Node_auth));
    // Присваивание значения узлу
    memcpy(tmp->login, login_, 11);
    memcpy(tmp->password, pass, 9);
    tmp->user_id = id_input;
    // Присваивание указателю на следующий элемент значения NULL
    tmp->next = NULL;
    // Присваивание новому указателю указателя head. 
    // Присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
    Node_auth* p = list;
    // Сдвиг указателя p в самый конец первоначального списка
    while (p->next != NULL)
        p = p->next;
    // Присваивание указателю p -> next значения указателя tmp (созданный новый узел)
    p->next = tmp;
}

void add_element_file_tab(Node_file_id_comp* list, int file_id_, char* filename_)
{
    Node_file_id_comp* tmp = (Node_file_id_comp*)malloc(sizeof(Node_file_id_comp));
    memcpy(tmp->filename, filename_, 16);
    tmp->file_id = file_id_;
    tmp->next = NULL;
    Node_file_id_comp* p = list;
    while (p->next != NULL)
        p = p->next;
    p->next = tmp;
}

void add_element_Pmatr_inner(Node_Pmatr_inner* list, int user_id_, bool r_p, bool w_p, bool a_p)
{
    Node_Pmatr_inner* tmp = (Node_Pmatr_inner*)malloc(sizeof(Node_Pmatr_inner));
    tmp->user_id = user_id_;
    tmp->read_permition = r_p;
    tmp->write_permition = w_p;
    tmp->append_permition = a_p;
    tmp->next = NULL;
    Node_Pmatr_inner* p = list;
    while (p->next != NULL)
        p = p->next;
    p->next = tmp;
}

void add_element_Pmatr_outter(Node_Pmatr_outter* list, Node_Pmatr_inner* cont, int file_id_)
{
    Node_Pmatr_outter* tmp = (Node_Pmatr_outter*)malloc(sizeof(Node_Pmatr_outter));
    tmp->file_id = file_id_;
    tmp->containment = cont;
    tmp->next = NULL;
    Node_Pmatr_outter* p = list;
    while (p->next != NULL)
        p = p->next;
    p->next = tmp;
}

Node_auth* remove_all(Node_auth* head)
{
    while (head != NULL)
    {
        Node_auth* p = head;
        head = head->next;
        free(p);
    }
    return NULL;
}

Node_file_id_comp* remove_all_file_comp(Node_file_id_comp* head)
{
    while (head != NULL)
    {
        Node_file_id_comp* p = head;
        head = head->next;
        free(p);
    }
    return NULL;
}

Node_Pmatr_inner* remove_all_Pmatr_inner(Node_Pmatr_inner* head)
{
    while (head != NULL)
    {
        Node_Pmatr_inner* p = head;
        head = head->next;
        free(p);
    }
    return NULL;
}

Node_Pmatr_outter* remove_all_Pmatr_outter(Node_Pmatr_outter* head)
{
    while (head != NULL)
    {
        Node_Pmatr_outter* p = head;
        remove_all_Pmatr_inner(head->containment);
        head = head->next;
        free(p);
    }
    return NULL;
}

bool login_check(char* login_, Node_auth* list)
{
    Node_auth* p;
    p = list;
    int authoriser = -1;
    do {
        //printf("%d ", p->field); // вывод значения элемента p
        if (strlen(p->login) == strlen(login_))
        {
            authoriser = strcmp(p->login, login_);
        }
        p = p->next; // переход к следующему узлу
    } while ((p != NULL) && (authoriser != 0));
    if (authoriser != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool password_check(char* password, Node_auth* list, int* id_sess)
{
    Node_auth* p;
    p = list;
    int authoriser = -1;
    do {
        //printf("%d ", p->field); // вывод значения элемента p
        if (strlen(p->password) == strlen(password))
        {
            authoriser = strcmp(p->password, password);
            if (authoriser == 0)
            {
                *id_sess = p->user_id;
            }
        }
        
        p = p->next; // переход к следующему узлу
    } while ((p != NULL) && (authoriser != 0));
    if (authoriser != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void create_new_user(char* login_, char* pass_, Node_auth* list, 
                    Node_Pmatr_outter* per_matr, int* id_sess)
{
    Node_auth* p;
    p = list;
    int temp_counter = 0;
    do {
        //printf("%d ", p->field); // вывод значения элемента p
        temp_counter++;
        p = p->next; // переход к следующему узлу
    } while (p != NULL);
    add_element_auth(list, temp_counter + 1, login_, pass_);
    Node_Pmatr_outter* out_curs;
    out_curs = per_matr;
    //int temp_counter = 0;
    do {
        add_element_Pmatr_inner(out_curs->containment, temp_counter + 1, 1, 0, 0);
        out_curs = out_curs->next; // переход к следующему узлу
    } while (out_curs != NULL);
    *id_sess = temp_counter + 1;
}

int compare_filename_id(char* filename_, Node_file_id_comp* list)
{
    Node_file_id_comp* p;
    p = list;
    int temp_ = -1;
    do {
        //printf("%d ", p->field); // вывод значения элемента p
        if (strlen(p->filename) == strlen(filename_))
        {
            temp_ = strcmp(p->filename, filename_);
        }
        if (temp_ != 0)
        {
            p = p->next; // переход к следующему узлу
        }
    } while ((p != NULL) && (temp_ != 0));
    if (temp_ != 0)
    {
        return -1;
    }
    if (temp_ == 0)
    {
        return p->file_id;
    }
}

int add_file_per_matr(Node_Pmatr_outter* per_matr, int* id_sess, int file_id)
{
    if (file_id == -1)
    {
        return -1;
    }
    add_element_Pmatr_outter(per_matr, create_Pmatr_inner(1,1,1,1), file_id);
    Node_Pmatr_outter* p;
    Node_Pmatr_outter* z;
    p = per_matr;
    z = p;
    int temp_counter = 1;
    do {
        //printf("%d ", p->field); // вывод значения элемента p
        z = p;
        p = p->next;
        temp_counter++;
    } while (p->next != NULL);
    if ((temp_counter) != file_id)
    {
        return -2;
    }
    Node_Pmatr_inner* t;
    Node_Pmatr_inner* s;
    t = z->next->containment;
    s = p->containment;
    do {
        if (t->user_id == *id_sess)
        {
            add_element_Pmatr_inner(s, t->user_id, 1, 1, 1);
        }
        else
        {
            add_element_Pmatr_inner(s, t->user_id, 1, 0, 0);
        }
        t = t->next;
    } while (t != NULL);
    return 1;
}

int main()
{
    
    bool kill_session_flag = false;
    bool sess_authorised = false;
    int temp_action_switch = 0;
    int cur_id_sess;
    cur_id_sess = 0;
    char* login_ = new char[11];
    
    /*for (size_t i = 0; i < 11; i++)
    {
        login_[i] = 0;
    }*/
    login_[0] = (char)('a'); 
    login_[1] = (char)('d');
    login_[2] = (char)('m');
    login_[3] = (char)('i');
    login_[4] = (char)('n');
    login_[5] = 0;
    char* password = new char[9];
    /*for (size_t i = 0; i < 9; i++)
    {
        password[i] = 0;
    }*/
    password[0] = (char)('a');
    password[1] = (char)('d');
    password[2] = (char)('m');
    password[3] = (char)('i');
    password[4] = (char)('n');
    password[5] = 0;
    Node_auth* auth_data_list = create_auth(1, login_, password);
    char* filename = new char[16];
    password[0] = (char)('f');
    password[1] = (char)('i');
    password[2] = (char)('l');
    password[3] = (char)('e');
    password[4] = (char)('1');
    password[5] = 0;
    Node_file_id_comp* file_comp_tab = create_comp_tab_file(1, filename);
    Node_Pmatr_outter* permition_matr = create_Pmatr_outter(create_Pmatr_inner(1, 1, 1, 1), 1);
    while (!kill_session_flag)
    {
        while (!sess_authorised)
        {
            bool login_correct = false;
            bool pass_correct = false;
            cout << "Hello, please, authorize yourself, if you have an account" << endl;
            cout << "type '1'" << endl;
            cout << "if you dont and want to create one" << endl;
            cout << "type '2'" << endl;
            cout << "if you want to exit" << endl;
            cout << "type '3'" << endl;
            cin >> temp_action_switch;
            if ((temp_action_switch == 1) || 
               ((temp_action_switch == 2)) ||
               ((temp_action_switch == 3)))
            {
                switch (temp_action_switch)
                {
                case 1:
                    cout << "login:" << endl;
                    cin >> login_;
                    login_correct = login_check(login_, auth_data_list);
                    if (login_correct)
                    {
                        int tmp_count = 0;
                        while ((tmp_count < 3) && (!sess_authorised))
                        {
                            cout << "login found, password:" << endl;
                            cin >> password;
                            pass_correct = password_check(password, auth_data_list, &cur_id_sess);
                            if (pass_correct)
                            {
                                sess_authorised = true;
                                cout << "OK, you're in" << endl;
                            }
                            else
                            {
                                cout << "wrong password, try again" << endl;
                            }
                            tmp_count++;
                        }
                    }
                    else
                    {
                        cout << "wrong login, are you sure about your account?" << endl;
                        cout << "restarting auth..." << endl;
                    }
                    break;
                case 2:
                    cout << "input login, which you'll use to operate(max - 10 symbols)" << endl;
                    cin >> login_;
                    cout << "input password, which you'll use to operate(max - 8 symbols)" << endl;
                    cin >> password;
                    create_new_user(login_, password, auth_data_list, permition_matr, &cur_id_sess);
                    cout << "Perfect, data saved, you're authorised now" << endl;
                    sess_authorised = true;
                    ///////
                    Node_auth* p;
                    p = auth_data_list;
                    //int temp_counter = 0;
                    do {
                        //printf("%d ", p->field); // вывод значения элемента p
                        cout << "login:" << p->login << endl;
                        cout << "pass:" << p->password << endl;
                        p = p->next; // переход к следующему узлу
                    } while (p != NULL);
                    ///////
                    break;
                case 3:
                    remove_all(auth_data_list);
                    remove_all_file_comp(file_comp_tab);
                    remove_all_Pmatr_outter(permition_matr);
                    free(login_);
                    free(password);
                    return 0;
                    break;
                }
            }
        }
        while (sess_authorised)
        {
            cout << "testy functional" << endl;
            cout << "type name of file" << endl;
            cin >> filename;
            int i_c = 1;
            Node_file_id_comp* temp_curs;
            temp_curs = file_comp_tab;
            do 
            {   
                i_c++;
                temp_curs = temp_curs->next; // переход к следующему узлу
            } while (temp_curs != NULL);
            add_element_file_tab(file_comp_tab, i_c, filename);
            //написать компэрер названия файла и id по табл, будет возвращать id, нужно будет для универсального добавления прав в матрицу, затем само добавление и вывод матрицы
 
        }
        kill_session_flag = true; //////temp!!!!!
    }
    remove_all(auth_data_list);
    remove_all_file_comp(file_comp_tab);
    remove_all_Pmatr_outter(permition_matr);
    free(login_);
    free(password);
}

