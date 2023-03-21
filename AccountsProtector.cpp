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
void search();
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
        search();
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
        f_save << as[i].email << "*" << as[i].password << "*" << as[i].platform << endl;
        int len = as[i].email.length() + as[i].password.length() + as[i].platform.length();
        for (int j = 0; j < len; j++)
        {
            f_save << "-";
        }
        f_save << endl;
    }
    f_save.close();
}

void search()
{
    string plat_form;
    int space_num = 0;
    char ch;
    vector<char> plf;
    cout << "Please Enter the Platform: ";
    getline(cin, plat_form);

    fstream f_search("Accounts.vas", ios::in);
    for (int i = 0; !f_search.eof(); i++)
    {
        if (space_num == 0 || space_num == 1)
        {
            f_search >> ch;
            if (ch == '*')
            {
                space_num += 1;
            }
        }

        if (space_num == 2)
        {
            f_search >> ch;
            plf.push_back(ch);
            if (ch == '-')
            {
                space_num = 0;
            }
        }
    }

    int plf_size = plf.size();
    vector<char> io_in;
    vector <string> plts;//main
    for (int i = 0; i < plf_size; i++)
    {
        if (plf[i] == '-')
        {
            int io_in_si = io_in.size();
            char io_char[io_in_si];
            for (int j = 0; j < io_in_si; j++)
            {
                io_char[j] = io_in[j];
            }
            string temp = io_char;
            plts.push_back(temp);

            for(int k = 0; k < io_in_si; k++)
            {
                io_in.pop_back();
            }
        }
        io_in.push_back(plf[i]);
    }

    int plts_si = plts.size();
    vector <int> exist_num;
    vector <string> exist_str;//main
    for(int i = 0; !f_search.eof(); i++)
    {
        string temp;
        getline(f_search, temp);
        exist_str.push_back(temp);
    }
   
    //still how to comapre the two vector to get the line number and print it to the screen
    //then edit it and delete it
    getch();
}
