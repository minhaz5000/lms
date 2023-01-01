#pragma once
#include "User.h"
#include<string>
#include<vector>
#include "Date.h"

using namespace std;

class Student : public User
{
private:
    vector<pair<int, Date>> issued; // <bid, issue date>
    vector<int> BID;
    vector<Date> dt;
public:

    Student();
    Student(string _name, int _id);
    ~Student();

    /* Setter Functions */
    //void setID(int _id);

    /* Getter Functions */
    //int getID() const;
    int getBookCount() const;
    pair<vector<int>, vector<Date>> getIssuedBooks() const;

    /* Others */
    void addBook(int bid, Date date);
    void removeBook(int bid);
    double calculateFine();
};