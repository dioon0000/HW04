#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Book.h"
using namespace std;
class BookManager {
private:
    vector<Book> books; // 책 목록 저장
public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author);

    // 모든 책 출력 메서드
    void displayAllBooks() const;

    //해당 Title을 가진 책 정보를 반환
    int searchByTitle(const string& title);

    //해당 Author를 가진 책 정보를 반환
    int searchByAuthor(const string& author);

};