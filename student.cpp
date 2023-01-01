#include "Student.h"

Student::Student()
{
}

Student::Student(string _name, int _id)
    : User(id, _name)
{
}

Student::~Student()
{
}

int Student::getBookCount() const
{
    return dt.size();
}

pair<vector<int>, vector<Date>> Student::getIssuedBooks() const
{
    return make_pair(BID,dt);
}

void Student::addBook(int bid, Date date)
{
    BID.push_back(bid);
    dt.push_back(date);
}

void Student::removeBook(int bid)
{
    int pos = find(BID.begin(), BID.end(), bid) - BID.begin();
    BID.erase(BID.begin() + pos);
    dt.erase(dt.begin() + pos);
}

double Student::calculateFine()
{
    Date curr = GetSystemDate();
    double fine = 0;
    for (int i = 0; i < BID.size(); i++)
    {
        if (curr - dt[i] > 20)
        {
            fine += (curr - dt[i] - 20) * 2;
        }
    }
    return fine;
}