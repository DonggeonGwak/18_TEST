# 📚 C++ 벡터(Vector)의 주요 함수 정리

## ✅ vector란?

`std::vector`는 C++ 표준 템플릿 라이브러리(STL)에서 제공하는 **동적 배열 컨테이너**로,  
일반 배열보다 안전하고 유연하며 다양한 내장 함수를 제공한다.

```cpp
#include <vector>
using namespace std;

vector<int> v;  // 정수형 벡터 선언
```

---

## ✅ 자주 사용하는 벡터 함수

| 함수 이름            | 설명                   |
| ---------------- | -------------------- |
| `push_back(val)` | 벡터 끝에 요소 추가          |
| `pop_back()`     | 마지막 요소 제거            |
| `size()`         | 현재 요소 개수 반환          |
| `empty()`        | 벡터가 비었는지 확인          |
| `clear()`        | 모든 요소 삭제             |
| `at(i)`          | i번째 요소 반환 (범위 검사 O)  |
| `operator[]`     | i번째 요소 반환 (범위 검사 X)  |
| `front()`        | 첫 번째 요소 반환           |
| `back()`         | 마지막 요소 반환            |
| `insert()`       | 특정 위치에 삽입            |
| `erase()`        | 특정 위치/범위 삭제          |
| `resize(n)`      | 크기 변경 (늘리면 기본값으로 채움) |
| `assign(n, val)` | n개의 val로 초기화         |
| `swap()`         | 두 벡터 내용 교환           |

---

## ✅ 예제 코드

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);      // [10, 20, 30]

    cout << "첫 번째 요소: " << v.front() << endl;
    cout << "마지막 요소: " << v.back() << endl;
    cout << "크기: " << v.size() << endl;

    v.pop_back();         // [10, 20]
    v.insert(v.begin(), 5);  // [5, 10, 20]
    v.erase(v.begin() + 1);  // [5, 20]

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";

    v.clear();  // 벡터 비우기
}
```

---

## ✅ 반복문으로 벡터 순회

```cpp
vector<int> v = {1, 2, 3, 4};

// 인덱스 기반
for (int i = 0; i < v.size(); ++i)
    cout << v[i] << " ";

// 범위 기반 for문 (C++11 이상)
for (int x : v)
    cout << x << " ";
```

---

## ✅ 정렬 등 알고리즘과 함께 사용

```cpp
#include <algorithm>

vector<int> v = {4, 1, 3, 2};
sort(v.begin(), v.end());  // 오름차순 정렬
reverse(v.begin(), v.end());  // 뒤집기
```

---

## ✅ 요약

| 함수            | 동작 예시                         |
|-----------------|------------------------------------|
| 요소 추가        | `v.push_back(5)`                  |
| 요소 삭제        | `v.pop_back()`, `v.erase(pos)`    |
| 접근             | `v[i]`, `v.at(i)`, `v.front()`     |
| 전체 삭제        | `v.clear()`                       |
| 반복             | `for`, `range-based for`, `iterator` |
| 정렬/역정렬      | `sort(v.begin(), v.end())`, `reverse()` |

---

**`std::vector`는 가장 자주 쓰이는 C++ 컨테이너이며,  
내장 함수만 잘 익혀도 동적 자료구조를 매우 편리하게 다룰 수 있다.**
