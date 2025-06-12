#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Book.h"
using namespace std;
class BookManager {
private:
    vector<Book> books; // å ��� ����
public:
    // å �߰� �޼���
    void addBook(const string& title, const string& author);

    // ��� å ��� �޼���
    void displayAllBooks() const;

    //�ش� Title�� ���� å ������ ��ȯ
    int searchByTitle(const string& title);

    //�ش� Author�� ���� å ������ ��ȯ
    int searchByAuthor(const string& author);

};