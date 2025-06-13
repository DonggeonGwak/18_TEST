#pragma once
#include <iostream>

using namespace std;

// 타입에 의존하지 않게 템플릿 선언
template <typename T>
// 클래스 이름은 Simplevector
class Simplevector
{
private:
	int currentSize;		//현재 원소의 개수
	int currentCapacity;	//배열의 최대 크기
	T* data;				//타입을 가지지 않는 배열

public:
	//생성자 크기가 10인 데이터 배열
	Simplevector() : currentSize(0), currentCapacity(10)
	{
		data = new T[currentCapacity];
	}

	//크기를 인자로 받는 생성자
	Simplevector(int iniCapacity) : currentSize(0), currentCapacity(iniCapacity)
	{
		data = new T[currentCapacity];
	}


	void cleanVector()
	{
		delete[] data;
	}

	//push_back을 이용한 함수 인자로 받은 원소를  맨 뒤에 추가 합니다.반환값은 없습니다.배열의 크기가 꽉 찼는데 원소가 더 들어올경우 아무 동작도 하지 않습니다
	void Push_back(const T& value)
	{
		if (currentSize < currentCapacity)
			data[currentSize++] = value;
	}

	//pop_back 벡터의 마지막 원소를 제거 합니다.만약 제거할 원소가 없다면 아무 동작도 하지 않으며, 인자 및 반환값은 없습니다.
	void Pop_Back()
	{
		if (currentSize > 0)
			currentSize--;
	}

	// size는 인자가 없고 현재 원소의 개수를 반환합니다.
	int size()
	{
		return currentSize;
	}

	//- capacity 현재 내부 배열의 크기를 반환합니다.
	int capacity()
	{
		return currentCapacity;
	}

	void printAll()
	{
		cout << "현제 배열의 원소: ";

		for (int i = 0; i < currentSize; i++)
		{
			cout << data[i] << " ";
		}

		cout << endl;
	}

};