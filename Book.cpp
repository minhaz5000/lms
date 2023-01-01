#include "Book.h"

Book::Book() { }

Book::~Book()
{
	/*for (auto& s : subject)
		s.clear();
	subject.clear();*/
}

void Book::setName(std::string _name)
{
	name = _name;
}

//void Book::setDescription(std::string _description)
//{
//	description = _description;
//}

void Book::setAuthor(std::string _author)
{
	author = _author;
}

void Book::setPublisher(std::string _publisher)
{
	publisher = _publisher;
}

//void Book::addSubject(std::string _sub)
//{
//	subject.push_back(_sub);
//}

void Book::setGenre(std::string _genre)
{
	genre = _genre;
}

void Book::setCount(int _cnt)
{
	cnt = _cnt;
}

void Book::setID(int _id)
{
	id = _id;
}

std::string Book::getName() const
{
	return name;
}

//std::string Book::getDescription() const
//{
//	return description;
//}

std::string Book::getAuthor() const
{
	return author;
}

std::string Book::getPublisher() const
{
	return publisher;
}

//std::vector<std::string> Book::getSubject() const
//{
//	return subject;
//}

std::string Book::getgenre() const
{
	return genre;
}

void Book::display() const
{
	std::cout << "Title      :  " << name << "\n";
	std::cout << "Author     :  " << author << "\n";
	std::cout << "publisher  :  " << publisher << "\n";
	std::cout << "Gnere      :  " << publisher << "\n";
	/*std::cout << "Description:  " << description << "\n";*/
	////std::cout << "Subjects   :  " << subject[0];
 //	for (int i = 1; i < subject.size(); i++)
	//	std::cout << ", " << subject[i];
	//std::cout << "\n";
}

int Book::getCount()
{
	return cnt;
}

int Book::getID() const
{
	return id;
}

int Book::cnt = 0;