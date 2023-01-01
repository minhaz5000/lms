#pragma once
#include<string>
#include<ostream>
#include<fstream>
#include<chrono>
#include<Windows.h>


class Date
{
private:
	int d, m, y;
	static const std::string month[13];
public:
	/*Constructor and Destructor*/
	Date();
	Date(int _d, int _m, int _y);
	~Date();

	/*Setter Functions*/
	void setDay(int _d);
	void setMonth(int _m);
	void setYear(int _y);
	void setDate(int _d, int _m, int _y);

	/*Getter Functions*/
	int getDay() const;
	std::string getMonth() const;
	int getYear() const;
	std::string getDate() const;

	/*Operator overload*/
	bool operator>(const Date& date) const;
	bool operator>=(const Date& date) const;
	bool operator<(const Date& date) const;
	bool operator<=(const Date& date) const;
	bool operator==(const Date& date) const;
	int operator-(const Date& d) const;
	//friend std::ostream& operator<<(std::ostream& out, const Date& d);
	//friend std::fstream& operator<<(std::fstream& out, const Date& d);
	//friend std::fstream& operator>>(std::fstream& out, Date& d);

	/* Others */
	void add_days(int days);
	void add_months(int months);
	void add_years(int years);
};

Date GetSystemDate();