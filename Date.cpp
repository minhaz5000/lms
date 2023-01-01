#include "Date.h"


Date::Date()
{
}

Date::Date(int _d, int _m, int _y)
	:d(_d), m(_m), y(_y)
{
}

Date::~Date()
{
}

void Date::setDay(int _d)
{
	d = _d;
}

void Date::setMonth(int _m)
{
	m = _m;
}

void Date::setYear(int _y)
{
	y = _y;
}

void Date::setDate(int _d, int _m, int _y)
{
	setDay(_d);
	setMonth(_m);
	setYear(_y);
}

int Date::getDay() const
{
	return d;
}

std::string Date::getMonth() const
{
	return month[m];
}

int Date::getYear() const
{
	return y;
}

std::string Date::getDate() const
{
	return std::to_string(d) + " " + month[m] + ", " + std::to_string(y);
}

bool Date::operator>(const Date& date) const
{
	if (y != date.y) return y > date.y;
	if (m != date.m) return m > date.m;
	return d > date.d;
}

bool Date::operator>=(const Date& date) const
{
	if (y != date.y) return y > date.y;
	if (m != date.m) return m > date.m;
	return d >= date.d;
}

bool Date::operator<(const Date& date) const
{
	if (y != date.y) return y < date.y;
	if (m != date.m) return m < date.m;
	return d < date.d;
}

bool Date::operator<=(const Date& date) const
{
	if (y != date.y) return y < date.y;
	if (m != date.m) return m < date.m;
	return d <= date.d;
}

bool Date::operator==(const Date& date) const
{
	return d == date.d and m == date.m and y == date.y;
}

int Date::operator-(const Date& date) const
{
	int days = y * 365 + m * 30 + d;
	int days2 = date.y * 365 + date.m * 30 + date.d;
	return days - days2;
}

//std::ostream& operator<<(std::ostream& out, const Date& d)
//{
//	out << d.getDay() << " " << d.getMonth() << ", " << d.getYear();
//	return out;
//}
//
//std::fstream& operator<<(std::fstream& out, const Date& d)
//{
//	out << d.getDay() << " " << d.getMonth() << ", " << d.getYear();
//	return out;
//}
//std::fstream& operator>>(std::fstream& in, Date& d)
//{
//	int date, month, year;
//	in >> date >> month >> year;
//	d.d = date, d.m = month, d.y = year;
//	return in;
//}
void Date::add_days(int days)
{
	int mm[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	y += days / 365;
	days = days % 365;
	while (days > mm[m - 1])
	{
		days -= mm[m - 1];
		m++;
		if (m > 12) y++, m = 1;
	}
}

void Date::add_months(int months)
{
	int mm[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	y += months / 12;
	months %= 12;
	m += months;
	if (m > 12) y++, m = 1;
	if (mm[m - 1] < d)
	{
		d -= mm[m - 1];
		m++;
	}
	if (m > 12) y++, m = 1;
}

void Date::add_years(int years)
{
	y += years;
}

const std::string Date::month[] = { "", "january", "February", "March", "April", "May", "June", "July", "August", "September", "October"
									"November", "December" };

Date GetSystemDate()
{
	SYSTEMTIME t;
	GetLocalTime(&t);
	return Date(t.wDay, t.wMonth, t.wYear);
}
