#include "Book.h"
#include "BookManager.h"
#include "BorrowManager.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    BookManager bookmanager;
    BorrowManager borrowmanager;
    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while(true) {
        system("cls");
        cout << "\n도서관 관리 프로그램" << '\n';
        cout << "1. 책 추가" << '\n'; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << '\n'; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 종료" << '\n'; // 프로그램 종료
        cout << "4. 책 제목으로 검색" << '\n'; //책 제목으로 검색
        cout << "5. 책 저자로 검색" << '\n'; //책 저자로 검색
        cout << "6. 책 빌리기" << '\n';
        cout << "7. 책 반납하기" << '\n';
        cout << "선택: ";
    
        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if(choice == 1) {
            // 1번 선택: 책 추가
            // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
            string title, author;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            bookmanager.addBook(title, author); // 입력받은 책 정보를 추가
            borrowmanager.initializeStock(Book(title,author),3);
        }
        else if(choice == 2) {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록과 재고를 출력합니다.
            bookmanager.displayAllBooks();
            borrowmanager.displayStock();
        }
        else if(choice == 3) {
            // 3번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << '\n';
            break; // while 루프 종료
        }
        else if(choice == 4) {
            // 4번 선택: 책 제목으로 검색
            // 책 제목으로 해당 책의 제목과 저자를 출력합니다.
            string title;
            cout << "검색할 책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            bookmanager.searchByTitle(title);
        }
        else if(choice == 5) {
            // 5번 선택: 책 저자로 검색
            // 책 저자으로 해당 책의 제목과 저자를 출력합니다.
            string author;
            cout << "검색할 저자: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, author); // 제목 입력 (공백 포함)
            bookmanager.searchByAuthor(author);
        }
        else if(choice == 6) {
            // 6번 선택: 책 빌리기
            // 입력한 책을 빌립니다.
            string title;
            cout << "빌리고 싶은 책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            if(bookmanager.searchByTitle(title))
                borrowmanager.borrowBook(title);
        }
        else if(choice == 7) {
            // 6번 선택: 책 반납하기
            // 입력한 책을 반납합니다.
            string title;
            cout << "반납하고 싶은 책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            if(bookmanager.searchByTitle(title))
                borrowmanager.returnBook(title);
        }
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << '\n';
        }
        system("pause");
    }

    return 0; // 프로그램 정상 종료
}