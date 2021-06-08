

#include <iostream>
using namespace std;

typedef struct Node {
    int user_id;
    char login[11];
    char password[9];
    struct Node* next;
} Node_auth;

Node_auth* create_auth(int id_input, char* login_, char* pass)
{
    Node_auth* tmp = (Node_auth*)malloc(sizeof(Node_auth));
    tmp->user_id = id_input;
    memcpy(tmp->login, login_, 11);
    memcpy(tmp->password, pass, 9);
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

Node_auth* remove_all(Node_auth* head)
{
    // Сдвиг указателя head в самый конец первоначального списка
    while (head != NULL)
    {
        // Присваивание новому указателю указателя head
        Node_auth* p = head;
        head = head->next;
        // Освобождение памяти для указателя p
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

bool password_check(char* password, Node_auth* list)
{
    Node_auth* p;
    p = list;
    int authoriser = -1;
    do {
        //printf("%d ", p->field); // вывод значения элемента p
        if (strlen(p->password) == strlen(password))
        {
            authoriser = strcmp(p->password, password);
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

void create_new_user(char* login_, char* pass_, Node_auth* list)
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
}

int main()
{
    
    bool kill_session_flag = false;
    bool sess_authorised = false;
    int temp_action_switch = 0;
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
                            pass_correct = password_check(password, auth_data_list);
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
                    create_new_user(login_, password, auth_data_list);
                    cout << "Perfect, data saved, you're authorised now" << endl;
                    sess_authorised = true;
                    ///////
                    Node_auth* p;
                    p = auth_data_list;
                    int temp_counter = 0;
                    do {
                        //printf("%d ", p->field); // вывод значения элемента p
                        cout << "login:" << p->login << endl;
                        cout << "pass:" << p->password << endl;
                        p = p->next; // переход к следующему узлу
                    } while (p != NULL);
                    ///////
                    break;
                }
            }
        }
        kill_session_flag = true; //////temp!!!!!
    }
    remove_all(auth_data_list);
    free(login_);
    free(password);
}

