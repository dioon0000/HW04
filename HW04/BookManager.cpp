#include "BookManager.h"
#include "BorrowManager.h"

// å �߰� �޼���
void BookManager::addBook(const string& title, const string& author) {
    books.push_back(Book(title, author)); // push_back ���
    cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << '\n';
}

// ��� å ��� �޼���
void BookManager::displayAllBooks() const {
    if(books.empty()) {
        cout << "���� ��ϵ� å�� �����ϴ�." << '\n';
        return;
    }

    cout << "���� ���� ���:" << '\n';
    for(size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
        cout << "- " << books[i].title << " by " << books[i].author << '\n';
    }
}

//Title�� å �˻� �޼���
int BookManager::searchByTitle(const string& title){
    for(int i=0; i<books.size(); ++i){
        if(books[i].title == title){
            cout << "å ����: " << books[i].title << " by " << books[i].author << '\n';
            return 1;
        }
    }
    cout << "�ش� ������ å�� �������� �ʽ��ϴ�.\n";
    return 0;
}

//Author�� å �˻� �޼���
int BookManager::searchByAuthor(const string& author){
    for(int i=0; i<books.size(); ++i){
        if(books[i].author == author){
            cout << "���� ����: " << books[i].title << " by " << books[i].author << '\n';
            return 1;
        }
    }
    cout << "�ش� ������ å�� �������� �ʽ��ϴ�.\n";
    return 0;
}