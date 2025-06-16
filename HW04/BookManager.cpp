#include "BookManager.h"
#include "BorrowManager.h"

// 책 추가 메서드
void BookManager::addBook(const string& title, const string& author) {
    books.push_back(Book(title, author)); // push_back 사용
    cout << "책이 추가되었습니다: " << title << " by " << author << '\n';
}
// 모든 책 출력 메서드
void BookManager::displayAllBooks() const {
    if(books.empty()) {
        cout << "현재 등록된 책이 없습니다." << '\n';
        return;
    }

    cout << "현재 도서 목록:" << '\n';
    for(size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
        cout << "- " << books[i].title << " by " << books[i].author << '\n';
    }
}
//Title로 책 검색 메서드
int BookManager::searchByTitle(const string& title){
    for(int i=0; i<books.size(); ++i){
        if(books[i].title == title){
            cout << "책 정보: " << books[i].title << " by " << books[i].author << '\n';
            return 1;
        }
    }
    cout << "해당 제목의 책은 존재하지 않습니다.\n";
    return 0;
}
//Author로 책 검색 메서드
int BookManager::searchByAuthor(const string& author){
    for(int i=0; i<books.size(); ++i){
        if(books[i].author == author){
            cout << "저자 정보: " << books[i].title << " by " << books[i].author << '\n';
            return 1;
        }
    }
    cout << "해당 저자의 책은 존재하지 않습니다.\n";
    return 0;
}