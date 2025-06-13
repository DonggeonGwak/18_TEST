//-클래스의 이름은 SimpleVector라고 합니다.
//- 타입에 의존하지 않고 데이터를 받을수 있는 배열을 멤버변수로 갖습니다.
//- 생성자는 아래와 같이 구현 합니다.
//  - 기본 생성자는 크기가 10인 배열을 만듭니다.
//  - 숫자를 하나 받는 생성자는 해당 숫자에 해당되는 크기의 배열을 만듭니다.
//- 아래와 같은 멤버함수를 구현 합니다.
//  - push_back  인자로 받은 원소를  맨 뒤에 추가 합니다.반환값은 없습니다.배열의 크기가 꽉 찼는데 원소가 더 들어올경우 아무 동작도 하지 않습니다.
//  - pop_back은 벡터의 마지막 원소를 제거 합니다.만약 제거할 원소가 없다면 아무 동작도 하지 않으며, 인자 및 반환값은 없습니다.
//  - size는 인자가 없고 현재 원소의 개수를 반환합니다.
//  - capacity 현재 내부 배열의 크기를 반환합니다.
#include <iostream>
#include "Simplevector.h"


using namespace std;

int main()
{	
	Simplevector<int> sm;
	sm.Push_back(10);
	sm.Push_back(20);
	sm.Push_back(30);

	cout << sm.size() << endl;
	cout << sm.capacity() << endl;

	sm.printAll();

	sm.cleanVector();

	Simplevector<char> sm2(5);
	sm2.Push_back('s');
	sm2.Push_back('d');
	sm2.Push_back('e');
	sm2.Push_back('q');

	cout << sm2.size() << endl;
	cout << sm2.capacity() << endl;

	sm2.printAll();

	sm2.cleanVector();
	
	cout << "튜터님 죄송함돠><" << endl;

}