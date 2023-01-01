#include "Database.h"
#include "Book.h"

Database::Database()
{
	readBook("book.txt");
	readStudent("student.txt");
	readRequest("request.txt");
}

Database::~Database()
{
	for (auto& b : books)
		b.~Book();
}

void Database::readRequest(string filename)
{
	fstream f(filename);
	int n;
	f >> n;
	for (int i = 0; i < n; i++)
	{
		int uid, bid;
		f >> uid >> bid;
		rq.emplace_back(uid, bid);
	}
	f.close();
}

void Database::writeRequest(string filename)
{
	fstream f(filename);
	int n = rq.size();
	f << n << "\n";
	for (int i = 0; i < n; i++)
	{
		f << rq[i].first << " " << rq[i].second << "\n";
	}
	f.close();
}

void Database::addRequest(int uid, int bid)
{
	rq.emplace_back(uid, bid);
}

void Database::acceptRequest(int n)
{
	Date curr = GetSystemDate();
	if (n > rq.size()) return;
	for (int i = 0; i < stdnt.size(); i++)
	{
		if (rq[n - 1].first == stdnt[i].getID())
		{
			stdnt[i].addBook(rq[n - 1].second,curr);
			break;
		}
	}
	rq.erase(rq.begin() + n - 1);
}

void Database::denyRequest(int n)
{
	rq.erase(rq.begin() + n - 1);
}

vector<pair<int, int>> Database::requestHistory()
{
	return rq;
}

void Database::readStudent(string filename)
{
	fstream f(filename);
	int n;
	f >> n;
	for (int i = 0; i < n; i++)
	{
		string name, username;
		int id, bookcnt;
		getline(f, name);
		f >> id >> bookcnt;
		stdnt.push_back(Student());
		stdnt[i].setName(name);
		stdnt[i].setID(id);
		for (int j = 0; j < bookcnt; j++)
		{
			int x;
			Date d;
			int day, mon, year;
			f >> x >> day >> mon >> year;
			d.setDate(day, mon, year);
			stdnt[i].addBook(x,d);
		}
	}
	f.close();
}

void Database::writeStudent(string filename)
{
	fstream f(filename);
	f << stdnt.size() << "\n";
	for (int i = 0; i < stdnt.size(); i++)
	{
		f << stdnt[i].getName() << "\n";
		f << stdnt[i].getID() << "\n";
		f << stdnt[i].getBookCount() << "\n";
		auto v = stdnt[i].getIssuedBooks();
		for (int j = 0; j < stdnt[i].getBookCount(); j++)
			cout << v.first[j] << " "
			<< v.second[j].getDay() << " "
			<< v.second[j].getMonth() << " "
			<< v.second[j].getYear() << "\n";
	}
	f.close();
}

double Database::getFIne(int sid)
{
	int pos = -1;
	for (int i = 0; i < stdnt.size(); i++)
	{
		if (stdnt[i].getID() == sid)
		{
			return stdnt[i].calculateFine();
		}
	}
	return 0.0;
}

pair<vector<int>, vector<Date>> Database::issuedBooks(int uid)
{
	for (int i = 0; i < stdnt.size(); i++)
		if (stdnt[i].getID() == uid)
			return stdnt[i].getIssuedBooks();
	return pair<vector<int>, vector<Date>>();
}

void Database::readBook(string filename)
{
	ifstream f(filename);
	f >> nextBookID;
	int n;
	f >> n;
	f.ignore();
	books.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		string s;
		int id;
		getline(f, s);
		//f.ignore();
		books[i].setName(s);
		//cout << s << endl;
		s = "";
	    getline(f, s);
		//f.ignore();
		books[i].setAuthor(s);
		//cout << s << endl;
		//s = "";
		//getline(f, s);
		//books[i].setDescription(s);
		f >> id;
		f.ignore();
		books[i].setID(id);
		getline(f, s);
		//s = "";
		//cout << s << endl;
		books[i].setPublisher(s);
		getline(f, s);
		//s = "";
		//cout << s << endl;
		books[i].setGenre(s);
		//cout << s << endl;
	}
	f.close();
}

void Database::writeBook(string filename)
{
	fstream f(filename);
	f << nextBookID << "\n";
	f << books.size() << "\n";
	for (int i = 0; i < books.size(); i++)
	{
		f << books[i].getName() << "\n";
		f << books[i].getAuthor() << "\n";
		//f << books[i].getDescription() << "\n";
		f << books[i].getID() << "\n";
		f << books[i].getPublisher() << "\n";
		f << books[i].getgenre() << "\n";
	}
	f.close();
}

void Database::addBook(Book b)
{
	b.setID(nextBookID);
	books.push_back(b);
	nextBookID++;
}

void Database::deleteBook(int bid)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (bid == books[i].getID())
		{
			books.erase(books.begin() + i);
			return;
		}
	}
}

vector<Book> Database::getBooks()
{
	return books;
}

Book Database::searchByID(int id)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getID() == id)
		{
			return books[i];
		}
	}
	return Book();
}

vector<Book> Database::searchByAuthor(string auth)
{
	vector<Book> ret;
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getAuthor() == auth)
		{
			ret.push_back(books[i]);
		}
	}
	return ret;
}

vector<Book> Database::searchByTitle(string name)
{
	vector<Book> ret;
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getName() == name)
		{
			ret.push_back(books[i]);
		}
	}
	return ret;
}

vector<Book> Database::searchByPublisher(string pub)
{
	vector<Book> ret;
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getPublisher() == pub)
		{
			ret.push_back(books[i]);
		}
	}
	return ret;
}

vector<Book> Database::searchByGenre(string genre)
{
	vector<Book> ret;
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getgenre() == genre)
		{
			ret.push_back(books[i]);
		}
	}
	return ret;
}


int Database::nextBookID = 0;