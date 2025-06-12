#include "BorrowManager.h"
#include "BookManager.h"
//해당 book의 초기 재고를 설정하는 함수
//addBook 됐을 때 initializeStock 함수를 실행
void BorrowManager::initializeStock(Book book, int quantity){
	stock[book.title] = quantity;
}
//해당 책을 빌리는 함수 (재고값을 -1)
void BorrowManager::borrowBook(const string& title){
	if(stock[title] == 0) cout << "해당 책은 재고가 모두 소진되었습니다\n";
	else {
		cout << "위 책을 대출하였습니다\n";
		stock[title]-=1;
	}
}
//해당 책을 반납하는 함수 (재고값을 +1)
void BorrowManager::returnBook(const string& title){
	if(stock[title] == 3) cout << "해당 책은 재고가 가득찼습니다\n";
	else {
		cout << "위 책을 반납하였습니다\n";
		stock[title]+=1;
	}
}
//stock 변수의 저장되어있는 책과 재고량을 출력하는 함수
void BorrowManager::displayStock(){
	cout << "저장되어있는 책의 재고량:\n";
	for(auto iter = stock.begin(); iter != stock.end(); iter++){
		cout << "- " << iter->first << " 책은 " << iter->second << "권 남았습니다\n";
	}
}