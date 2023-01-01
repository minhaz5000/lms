#pragma once
#include<string>
#include<vector>
#include<iostream>
#include"Date.h"

class Book
{
private:
	std::string name, author, publisher, genre;
	int id;
	static int cnt;

public:
	/*Constructor and destructor*/
	Book();
	~Book();

	/*setter functions*/
	void setName(std::string _name);
	/*void setDescription(std::string _description);*/
	void setAuthor(std::string _author);
	void setPublisher(std::string _publisher);
	void setGenre(std::string _genre);
	static void setCount(int _cnt);
	void setID(int _id);

	/*Getter Functions*/
	std::string getName() const;
	/*std::string getDescription() const;*/
	std::string getAuthor() const;
	std::string getPublisher() const;
	std::string getgenre() const;
	void display() const;
	static int getCount();
	int getID() const;
};