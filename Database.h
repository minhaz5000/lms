#pragma once
#include<string>
#include<fstream>
#include "Book.h"
#include "Student.h"

using namespace std;

class Database
{
private:
	vector<Book> books;
	vector<pair<int, int>> rq; // <uid, bid>
	vector<Student> stdnt;
	static int nextBookID;
public:
	/* Constructors and destructors*/
	Database();
	~Database();

	/*database handling functions*/
	void readRequest(string filename);
	void writeRequest(string filename);
	void addRequest(int uid, int bid);
	void acceptRequest(int n);
	void denyRequest(int n);
	vector<pair<int,int>> requestHistory();

	void readStudent(string filename);
	void writeStudent(string filename);
	double getFIne(int sid);
	pair<vector<int>, vector<Date>> issuedBooks(int uid);

	void readBook(string filename);
	void writeBook(string filename);
	void addBook(Book b);
	void deleteBook(int bid);
	//void displayAllBook();
	vector<Book> getBooks();

	/* Searching Functions */
	Book searchByID(int id);
	vector<Book> searchByAuthor(string auth);
	vector<Book> searchByTitle(string name);
	vector<Book> searchByPublisher(string pub);
	vector<Book> searchByGenre(string genre);
};