#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;


class User
{
protected:
    int id;
    string name;

public:
    User();
    User(int _id, string _name);
    void setName(string s);
    void setID(int _id);
    string getName() const;
    int getID() const;
};


bool is_Registered(int ID, string password);

class Admin :public User
{
private:
    string password;
    string securityQuestion;

public:
    Admin();
    bool verify(string pass);
    //void reset_Password();
};

void addStudent(int uid, string pass);



