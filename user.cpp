#include "user.h"
#include<fstream>
#include<conio.h>

User::User()
{
}

User::User(int _id, string _name):id(_id),name(_name)
{

}

void User::setName(string s)
{
    name = s;
}

void User::setID(int _id)
{
    id = _id;
}

string User::getName() const
{
    return name;
}

int User::getID() const
{
    return id;
}


Admin::Admin()
{
    ifstream fin;
    fin.open("password.txt");
    fin >> password;
}


bool Admin::verify(string pass)
{
    if (password == pass)
    {
        return true;
    }
    return false;
}

//void Admin::reset_Password()
//{
//
//}

bool is_Registered(int ID, string password)
{
    vector <pair <int, string>> v;
    int data;
    string pass;
    fstream fin;
    fin.open("studentID.txt");
    while (!fin.eof())
    {
        fin >> data;
        fin >> pass;
        v.push_back(make_pair(data,pass));
    }

    vector <pair<int, string>>::iterator i1;
    i1 = std::find(v.begin(), v.end(), make_pair(ID,pass));
    if (i1 != v.end())
    {

        return true;
    }
    else
    {
        return false;
    }
}

void addStudent(int uid, string pass)
{
    fstream fout;
    fout.open("studentID.txt", std::ios::app);
    fout << '\n' << uid << '\n' << pass;
}

