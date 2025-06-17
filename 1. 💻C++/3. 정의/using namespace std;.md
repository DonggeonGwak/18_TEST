# 🧭 C++에서 `using namespace std;` 정리

## ✅ 이게 뭐야?

`using namespace std;`는  
**C++ 표준 라이브러리(`std`)를 편하게 쓰기 위해 선언하는 문장**이야.

> 쉽게 말하면:  
> `std::cout` 같은 긴 이름을 `cout`처럼 **짧게 쓰게 해주는 문장**!

---

## ✅ 왜 필요한가?

C++의 표준 기능(예: `cout`, `cin`, `string`, `vector`)은 전부 **`std`라는 이름공간(namespace)** 안에 들어 있음.

그래서 원래는 이렇게 써야 돼:

```cpp
std::cout << "Hello";  
std::string name = "Jinu";
```

근데 매번 `std::` 붙이기 불편하니까 이렇게 쓰는 거야:

```cpp
using namespace std;
cout << "Hello";  
string name = "Jinu";
```

---

## ✅ 이름공간(namespace)이란?

이름공간은 **함수나 변수 이름이 충돌하지 않게 구분짓는 개념**이야.

예:
```cpp
int max = 10;           // 내가 만든 max
std::max(3, 5);         // 표준 라이브러리의 max
```

- `std::max`과 내가 만든 `max`가 **이름이 같아도 구분됨**
- `using namespace std;`를 쓰면 `std::` 없이도 표준 max를 직접 써버리게 돼서 **충돌 위험**이 생길 수 있어

---

## ✅ 언제 쓰고, 언제 안 써야 해?

| 상황                         | 추천 여부 | 이유 |
|------------------------------|-----------|------|
| 공부하거나 예제 코드 작성 시 | ✅ 사용 O | 코드가 짧고 간편함 |
| 큰 프로젝트나 협업 시        | ❌ 사용 X | 다른 라이브러리와 이름 충돌 가능성 있음 |
| 함수명, 클래스명이 겹칠 위험 | ❌ 사용 X | `std::`를 명확히 써주는 게 안전함 |

---

## ✅ 안전한 대안

필요한 것만 지정해서 가져오기:

```cpp
using std::cout;
using std::cin;
using std::endl;
```

이러면 `cout`, `cin`, `endl`만 줄여 쓸 수 있고, 나머지는 충돌 걱정 없음

---

## ✅ 예제 코드

```cpp
#include <iostream>
using namespace std;

int main() {
    string name;
    cout << "이름 입력: ";
    cin >> name;
    cout << "안녕하세요, " << name << "님!" << endl;
    return 0;
}
```

---

## ✅ 요약 정리

| 항목         | 설명 |
|--------------|------|
| `std`        | C++ 표준 라이브러리의 이름공간 |
| `using namespace std;` | `std::` 생략하고 쓰게 해줌 |
| 장점         | 코드가 간단해짐 |
| 단점         | 이름 충돌 위험 있음 |
| 대안         | 필요한 것만 `using std::cout;`처럼 지정 |

---

**결론:**  
`using namespace std;`는 C++을 더 간단하게 쓸 수 있게 도와주는 문장이지만,  
규모가 커지면 `std::`를 명확히 쓰는 습관이 더 좋다!
