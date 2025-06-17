# 🎯 특수 자료형(Special Data Types) - C++ 정리

## ✅ 특수 자료형이란?

C++에서 **기본형 자료(int, float 등)**과는 달리,  
**특정한 목적이나 동작을 위해 설계된 자료형**들을  
**특수 자료형(Special Data Types)**이라 부른다.

> 프로그램 구조, 메모리 제어, 확장성, 표현력 향상 등에 사용된다.

---

## ✅ 주요 특수 자료형 목록

| 자료형         | 설명 |
|----------------|------|
| `void`         | 값이 없음을 나타냄 |
| `nullptr_t`    | `nullptr`의 자료형 |
| `auto`         | 컴파일러가 자료형 자동 추론 |
| `decltype`     | 표현식의 자료형을 추론 |
| `nullptr`      | 포인터의 null 값 |
| `enum`         | 열거형 상수 모음 |
| `std::nullptr_t` | `nullptr`을 위한 타입 (C++11 이상) |

---

## ✅ 1. `void`

- **"값이 없다"는 개념**
- 주로 **함수 반환형** 또는 **void 포인터**에 사용

```cpp
void print();       // 반환값 없음
void* ptr;          // 어떤 자료형이든 가리킬 수 있음
```

---

## ✅ 2. `nullptr` / `nullptr_t`

- C++11부터 도입된 **타입 안전한 null 포인터**
- `nullptr_t`는 `nullptr`의 자료형

```cpp
int* p = nullptr;     // 널 포인터
std::nullptr_t x = nullptr;  // 자료형 확인용
```

---

## ✅ 3. `auto`

- **컴파일러가 자료형을 자동으로 추론**
- 코드를 간결하게 작성할 수 있음

```cpp
auto n = 42;          // int로 추론
auto name = "Alice";  // const char*
```

---

## ✅ 4. `decltype`

- 어떤 **변수나 표현식의 자료형을 추론해서 그대로 사용**하는 키워드

```cpp
int x = 10;
decltype(x) y = 20;  // x와 같은 자료형인 int
```

---

## ✅ 5. `enum` (열거형)

- 여러 개의 **상수 값에 이름을 붙여 관리**
- 가독성과 코드 안정성 향상

```cpp
enum Color { RED, GREEN, BLUE };
Color c = RED;
```

- 내부적으로는 `RED = 0`, `GREEN = 1`, `BLUE = 2`

---

## ✅ 6. `std::any`, `std::variant`, `std::optional` (C++17~)

- 현대 C++에서 자주 쓰이는 **고급 특수 자료형**

| 자료형         | 설명 |
|----------------|------|
| `std::any`      | 어떤 타입도 저장 가능 (런타임 타입 체크) |
| `std::variant`  | 여러 타입 중 하나만 저장 (타입 안전) |
| `std::optional` | 값이 있거나 없을 수 있는 자료형 (`null` 대체) |

```cpp
#include <optional>
std::optional<int> maybeNumber;
maybeNumber = 42;
```

---

## ✅ 요약

| 자료형       | 주된 용도 |
|--------------|-----------|
| `void`       | 반환 없음, 범용 포인터 |
| `nullptr_t`  | null 포인터용 자료형 |
| `auto`       | 자동 자료형 추론 |
| `decltype`   | 표현식의 자료형 추론 |
| `enum`       | 상수 목록 정의 |
| `std::any`   | 아무 타입이나 저장 가능 (C++17) |
| `std::variant` | 타입 안전한 다형성 (C++17) |
| `std::optional` | 값 유무 표현 (C++17) |

---

**특수 자료형은 C++의 확장성과 표현력을 높여주는 고급 도구들이며,  
기본형으로는 어려운 작업을 보다 안전하고 효율적으로 수행하게 해준다.**
