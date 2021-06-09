

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

void distr_content_wr(Node_file_id_comp* list)
{
    cout << "//////////////////////////////////////////////////////////" << endl;
    Node_file_id_comp* p;
    p = list;
    do {
        cout << p->filename << ".txt" << endl;
        p = p->next; // переход к следующему узлу
    } while (p != NULL);
    cout << "//////////////////////////////////////////////////////////" << endl;
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
    t = z->containment->next;
    s = p->containment;
    do {
        if (*id_sess != 1)
        {
            if (t->user_id == *id_sess)
            {
                add_element_Pmatr_inner(s, t->user_id, 1, 1, 1);
            }
            else
            {
                add_element_Pmatr_inner(s, t->user_id, 1, 0, 0);
            }
            t = t->next;
        }
    } while (t != NULL);
    return 1;
}

bool check_perm_file(int file_id, int* user_id, int perm_lvl, Node_Pmatr_outter* list)
{
    Node_Pmatr_outter* p;
    p = list;
    do {
        if (p->file_id != file_id)
        {
            p = p->next;
        }
        else
        {
            Node_Pmatr_inner* s;
            s = p->containment;
            do
            {
                if (s->user_id != *user_id)
                {
                    s = s->next;
                }
                else
                {
                    switch (perm_lvl)
                    {
                    case 1:
                        if (s->read_permition)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                        break;
                    case 2:
                        if (s->write_permition)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                        break;
                    case 3:
                        if (s->append_permition)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                        break;
                    }
                }
            } while (s != NULL);
            p = NULL;
        }
    } while (p != NULL);
}

void permission_changer(Node_Pmatr_outter* list, int user_id, int new_perm, int file_id)
{
    Node_Pmatr_outter* p;
    p = list;
    do
    {
        if (p->file_id != file_id)
        {
            p = p->next;
        }
        else
        {
            Node_Pmatr_inner* s;
            s = p->containment;
            do
            {
                if (s->user_id != user_id)
                {
                    s = s->next;
                }
                else
                {
                    switch (new_perm)
                    {
                    case 1:
                        s->read_permition = true;
                        s->write_permition = false;
                        s->append_permition = false;
                        break;
                    case 2:
                        s->read_permition = true;
                        s->write_permition = true;
                        s->append_permition = false;
                    case 3:
                        s->read_permition = true;
                        s->write_permition = true;
                        s->append_permition = true;
                        break;
                    }
                    s = NULL;
                }
            } while (s != NULL);
            p = NULL;
        }
    } while (p != NULL);
}

int main()
{
    
    bool kill_session_flag = false;
    bool sess_authorised = false;
    int temp_action_switch = 0;
    int cur_id_sess;
    int iter__;
    int i_c;
    Node_file_id_comp* p_file;
    Node_file_id_comp* temp_curs;
    Node_file_id_comp* temp_curs1;
    Node_Pmatr_outter* temp_curs2;
    Node_auth* p_auth_k;
    cur_id_sess = 0;
    bool perm_granted;
    bool stop_cycl;
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
    filename[0] = (char)('f');
    filename[1] = (char)('i');
    filename[2] = (char)('l');
    filename[3] = (char)('e');
    filename[4] = (char)('1');
    filename[5] = 0;
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
                    free(filename);
                    free(login_);
                    free(password);
                    return 0;
                    break;
                }
            }
        }
        while (sess_authorised)
        {
            distr_content_wr(file_comp_tab);
            cout << "if you wanna know about available commands - type 0" << endl;
            cout << "or type command that you know" << endl;
            cin >> temp_action_switch;
            switch (temp_action_switch)
            {
            case 0:
                cout << "list of commands:" << endl;
                cout << "1-open one of files for reading" << endl;
                cout << "2-open one of files for reading and writing" << endl;
                cout << "3-check append permission for one of files" << endl;
                cout << "4-create file with standart permissions" << endl;
                cout << "5-create file with settable permissions" << endl;
                cout << "6-chahge permission for my appendable files" << endl;
                cout << "9-logout " << endl;
                break;
            case 1:
                cout << "which file?" << endl;
                iter__ = 0;
                p_file = file_comp_tab;
                do {
                    iter__++;
                    cout << iter__<< " - " << p_file->filename << ".txt" << endl;
                    p_file = p_file->next; // переход к следующему узлу
                } while (p_file != NULL);
                cin >> iter__;
                temp_curs1 = file_comp_tab;
                temp_curs2 = permition_matr;
                do
                {
                    if (iter__ != temp_curs1->file_id)
                    {
                        temp_curs2 = temp_curs2->next;
                        temp_curs1 = temp_curs1->next;
                    }
                    else
                    {
                        memcpy(filename, temp_curs1->filename, 16);
                        perm_granted = check_perm_file(iter__, &cur_id_sess, 1, permition_matr);
                        if (perm_granted)
                        {
                            cout << "Success!" << endl;
                            //////////// -- место для работы с файлом
                        }
                        else
                        {
                            cout << "Sorry, you dont have permissions" << endl;
                        }
                        temp_curs1 = NULL;
                    }
                     
                } while ((temp_curs1 != NULL) && (temp_curs2 != NULL));
                break;
            case 2:
                cout << "which file?" << endl;
                iter__ = 0;
                p_file = file_comp_tab;
                do {
                    iter__++;
                    cout << iter__ << " - " << p_file->filename << ".txt" << endl;
                    p_file = p_file->next; // переход к следующему узлу
                } while (p_file != NULL);
                cin >> iter__;
                temp_curs1 = file_comp_tab;
                temp_curs2 = permition_matr;
                do
                {
                    if (iter__ != temp_curs1->file_id)
                    {
                        temp_curs2 = temp_curs2->next;
                        temp_curs1 = temp_curs1->next;
                    }
                    else
                    {
                        memcpy(filename, temp_curs1->filename, 16);
                        perm_granted = check_perm_file(iter__, &cur_id_sess, 2, permition_matr);
                        if (perm_granted)
                        {
                            cout << "Success!" << endl;
                            //////////// -- место для работы с файлом
                        }
                        else
                        {
                            cout << "Sorry, you dont have permissions" << endl;
                        }
                        temp_curs1 = NULL;
                    }

                } while ((temp_curs1 != NULL) && (temp_curs2 != NULL));
                break;
            case 3:
                cout << "which file?" << endl;
                iter__ = 0;
                p_file = file_comp_tab;
                do {
                    iter__++;
                    cout << iter__ << " - " << p_file->filename << ".txt" << endl;
                    p_file = p_file->next;
                } while (p_file != NULL);
                cin >> iter__;
                temp_curs1 = file_comp_tab;
                temp_curs2 = permition_matr;
                do
                {
                    if (iter__ != temp_curs1->file_id)
                    {
                        temp_curs2 = temp_curs2->next;
                        temp_curs1 = temp_curs1->next;
                    }
                    else
                    {
                        memcpy(filename, temp_curs1->filename, 16);
                        perm_granted = check_perm_file(iter__, &cur_id_sess, 3, permition_matr);
                        if (perm_granted)
                        {
                            cout << "Success! You have admin permissions for that file" << endl;
                            ///////// -- место для какихто действий
                        }
                        else
                        {
                            cout << "Sorry, you dont have permissions" << endl;
                        }
                        temp_curs1 = NULL;
                    }

                } while ((temp_curs1 != NULL) && (temp_curs2 != NULL));
                break;
            case 4:
                cout << "type name of file" << endl;
                cin >> filename;
                i_c = 1;
                temp_curs = file_comp_tab;
                do
                {
                    i_c++;
                    temp_curs = temp_curs->next; // переход к следующему узлу
                } while (temp_curs != NULL);
                add_element_file_tab(file_comp_tab, i_c, filename);
                //написать компэрер названия файла и id по табл, будет возвращать id, нужно будет для универсального добавления прав в матрицу, затем само добавление и вывод матрицы
                i_c = add_file_per_matr(permition_matr, &cur_id_sess, compare_filename_id(filename, file_comp_tab));
                switch (i_c)
                {
                case -1:
                    cout << "some problems with compare table" << endl;
                    break;
                case -2:
                    cout << "some problems with comparing in table or in cycle" << endl;
                    break;
                case 1:
                    cout << "everything's great" << endl;
                    break;
                }
                break;
            case 5:
                stop_cycl = false;
                cout << "type name of file" << endl;
                cin >> filename;
                i_c = 1;
                temp_curs = file_comp_tab;
                do
                {
                    i_c++;
                    temp_curs = temp_curs->next; // переход к следующему узлу
                } while (temp_curs != NULL);
                add_element_file_tab(file_comp_tab, i_c, filename);
                i_c = add_file_per_matr(permition_matr, &cur_id_sess, compare_filename_id(filename, file_comp_tab));
                switch (i_c)
                {
                case -1:
                    cout << "some problems with compare table" << endl;
                    break;
                case -2:
                    cout << "some problems with comparing in table or in cycle" << endl;
                    break;
                case 1:
                    cout << "everything's great" << endl;
                    break;
                }
                while (!stop_cycl)
                {
                    int iter__ = 0;
                    int iter1__ = 0;
                    p_auth_k = auth_data_list;
                    do {
                        iter__++;
                        cout << iter__ << " - " << p_auth_k->login << endl;
                        p_auth_k = p_auth_k->next;
                    } while (p_auth_k != NULL);
                    cout <<  "which user?" << endl;
                    cin >> iter__;
                    if (iter__ != 1)
                    {
                        cout << "which permission want to grant?" << endl;
                        cout << "1 - read" << endl;
                        cout << "2 - read and write" << endl;
                        cout << "3 - append permission" << endl;
                        cin >> iter1__;
                        permission_changer(permition_matr, iter__, iter1__, compare_filename_id(filename, file_comp_tab));
                        cout << "permission of this user successfully changed" << endl;
                        cout << "do you want to change someone else permissions?" << endl;
                        cout << "1 - yes" << endl;
                        cout << "2 - no" << endl;
                        cin >> i_c;
                        if (i_c == 2)
                        {
                            stop_cycl = true;
                        }
                    }
                    else
                    {
                        cout << "sorry, but you cant" << endl;
                    }
                }
                break;
            case 6:
                stop_cycl = false;
                while (!stop_cycl)
                {
                    cout << "which file?" << endl;
                    iter__ = 0;
                    int iter1__ = 0;
                    int iter2__ = 0;
                    p_file = file_comp_tab;
                    do {
                        iter__++;
                        cout << iter__ << " - " << p_file->filename << ".txt" << endl;
                        p_file = p_file->next; // переход к следующему узлу
                    } while (p_file != NULL);
                    cin >> iter__;
                    perm_granted = check_perm_file(iter__, &cur_id_sess, 3, permition_matr);
                    if (perm_granted)
                    {
                        p_auth_k = auth_data_list;
                        do {
                            int i_i = 0;
                            i_i++;
                            cout << i_i << " - " << p_auth_k->login << endl;
                            p_auth_k = p_auth_k->next;
                        } while (p_auth_k != NULL);
                        cout << "which user?" << endl;
                        cin >> iter1__;
                        if (iter1__ != 1)
                        {
                            cout << "which permission want to grant?" << endl;
                            cout << "1 - read" << endl;
                            cout << "2 - read and write" << endl;
                            cout << "3 - append permission" << endl;
                            cin >> iter2__;
                            permission_changer(permition_matr, iter1__, iter2__, iter__);
                            cout << "permission of this user for chosen file successfully changed" << endl;
                            stop_cycl = true;
                        }
                        else
                        {
                            cout << "sorry, but you cant" << endl;
                        }
                    }
                    else
                    {
                        cout << "sorry, you dont have enough permissions" << endl;
                    }
                }
                break;
            case 9:
                sess_authorised = false;
                break;
            }
            
        }
        //kill_session_flag = true; //////temp!!!!!
    }
    remove_all(auth_data_list);
    remove_all_file_comp(file_comp_tab);
    remove_all_Pmatr_outter(permition_matr);
    free(filename);
    free(login_);
    free(password);
}

