#include "BorrowManager.h"
#include "BookManager.h"
//�ش� book�� �ʱ� ��� �����ϴ� �Լ�
//addBook ���� �� initializeStock �Լ��� ����
void BorrowManager::initializeStock(Book book, int quantity){
	stock[book.title] = quantity;
}
//�ش� å�� ������ �Լ� (����� -1)
void BorrowManager::borrowBook(const string& title){
	if(stock[title] == 0) cout << "�ش� å�� ��� ��� �����Ǿ����ϴ�\n";
	else {
		cout << "�� å�� �����Ͽ����ϴ�\n";
		stock[title]-=1;
	}
}
//�ش� å�� �ݳ��ϴ� �Լ� (����� +1)
void BorrowManager::returnBook(const string& title){
	if(stock[title] == 3) cout << "�ش� å�� ��� ����á���ϴ�\n";
	else {
		cout << "�� å�� �ݳ��Ͽ����ϴ�\n";
		stock[title]+=1;
	}
}
//stock ������ ����Ǿ��ִ� å�� ����� ����ϴ� �Լ�
void BorrowManager::displayStock(){
	cout << "����Ǿ��ִ� å�� ���:\n";
	for(auto iter = stock.begin(); iter != stock.end(); iter++){
		cout << "- " << iter->first << " å�� " << iter->second << "�� ���ҽ��ϴ�\n";
	}
}