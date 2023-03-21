#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <string>
#include <cstring>
#include <windows.h>
#include <iomanip>

using namespace std;

struct Accounts
{
    string email, password, platform;
};

void add();
int main()
{
    int choose_list;
    cout << "Chooose From the list Below: " << endl;
    cout << "1.Add\n2.Search\n3.Delete\n4.Edit " << endl;
    cin >> choose_list;
    cin.ignore();

    system("cls");
    switch (choose_list)
    {
    case 1:
        add();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
    return 0;
}

void add()
{
    int acc_num = 1;
    fstream f_save("Accounts.vas", ios::out | ios::app);
    cout << "How many Accounts you want to enter: ";
    cin >> acc_num;
    cin.ignore();
    struct Accounts as[acc_num];

        system("cls");

    for (int i = 0; i < acc_num; i++)
    {
        cout << "Enter the Acccount N." << i + 1 << ": " << endl;
        cout << "Email: ";
        getline(cin, as[i].email);

        cout << "Password: ";
        getline(cin, as[i].password);

        cout << "PlatForm: ";
        getline(cin, as[i].platform);

        system("cls");
    }

    for (int i = 0; i < acc_num; i++)
    {
        f_save << as[i].email << " " << as[i].password << " " << as[i].platform << endl;
        int len = as[i].email.length() + as[i].password.length() + as[i].platform.length();
        for (int j = 0; j < len; j++)
        {
            f_save << "-";
        }
        f_save << endl;
    }
    f_save.close();
}