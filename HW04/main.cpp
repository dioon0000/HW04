#include <iostream>
#include <vector>
#include <string>
#include "Book.h"
#include "BookManager.h"
#include "BorrowManager.h"
using namespace std;

int main() {
    BookManager bookmanager;
    BorrowManager borrowmanager;
    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while(true) {
        cout << "\n������ ���� ���α׷�" << '\n';
        cout << "1. å �߰�" << '\n'; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << '\n'; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. ����" << '\n'; // ���α׷� ����
        cout << "4. å �������� �˻�" << '\n'; //å �������� �˻�
        cout << "5. å ���ڷ� �˻�" << '\n'; //å ���ڷ� �˻�
        cout << "6. å ������" << '\n';
        cout << "7. å �ݳ��ϱ�" << '\n';
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if(choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            bookmanager.addBook(title, author); // �Է¹��� å ������ �߰�
            borrowmanager.initializeStock(Book(title,author),3);
        }
        else if(choice == 2) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ��ϰ� ��� ����մϴ�.
            bookmanager.displayAllBooks();
            borrowmanager.displayStock();
        }
        else if(choice == 3) {
            // 3�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << '\n';
            break; // while ���� ����
        }
        else if(choice == 4) {
            // 4�� ����: å �������� �˻�
            // å �������� �ش� å�� ����� ���ڸ� ����մϴ�.
            string title;
            cout << "�˻��� å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            bookmanager.searchByTitle(title);
        }
        else if(choice == 5) {
            // 5�� ����: å ���ڷ� �˻�
            // å �������� �ش� å�� ����� ���ڸ� ����մϴ�.
            string author;
            cout << "�˻��� ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, author); // ���� �Է� (���� ����)
            bookmanager.searchByAuthor(author);
        }
        else if(choice == 6) {
            // 6�� ����: å ������
            // �Է��� å�� �����ϴ�.
            string title;
            cout << "������ ���� å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            if(bookmanager.searchByTitle(title))
                borrowmanager.borrowBook(title);
        }
        else if(choice == 7) {
            // 6�� ����: å �ݳ��ϱ�
            // �Է��� å�� �ݳ��մϴ�.
            string title;
            cout << "�ݳ��ϰ� ���� å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            if(bookmanager.searchByTitle(title))
                borrowmanager.returnBook(title);
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << '\n';
        }
    }

    return 0; // ���α׷� ���� ����
}