#pragma once
#include <unordered_map>
#include <string>
#include "Book.h"
using namespace std;
class BorrowManager{
private:
	unordered_map<string, int> stock;
public:
	void initializeStock(Book book, int quantity);
	void borrowBook(const string& title);
	void returnBook(const string& title);
	void displayStock();
};