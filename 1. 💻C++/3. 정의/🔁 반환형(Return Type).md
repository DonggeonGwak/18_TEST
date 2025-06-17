# 🔁 반환형(Return Type) - C++ 함수의 결과값 정의

## ✅ 반환형이란?

C++에서 **반환형(Return Type)**은  
함수가 실행을 마친 후 **호출한 쪽에 되돌려주는 값의 자료형**을 의미한다.

> 예: `int`, `double`, `string`, `void` 등

---

## ✅ 기본 구조

```cpp
반환형 함수이름(매개변수들) {
    return 결과값;
}
```

예시:

```cpp
int add(int a, int b) {
    return a + b;  // 반환형은 int
}
```

- `add()` 함수는 `int`형 값을 리턴한다.
- `return` 키워드는 반환값을 지정하는 역할을 한다.

---

## ✅ 반환형의 종류

| 반환형    | 설명 |
|-----------|------|
| `int`     | 정수형 값 반환 |
| `double`  | 실수형 값 반환 |
| `bool`    | 참/거짓 반환 |
| `string`  | 문자열 반환 |
| `void`    | 아무것도 반환하지 않음 |
| 사용자 정의 타입 | 구조체(struct)나 클래스 객체 반환 가능 |

---

## ✅ 반환형 예시 모음

### int 반환
```cpp
int square(int x) {
    return x * x;
}
```

### void 반환
```cpp
void printHello() {
    cout << "Hello!" << endl;
}
```

### bool 반환
```cpp
bool isEven(int n) {
    return n % 2 == 0;
}
```

### string 반환
```cpp
string getName() {
    return "Alice";
}
```

---

## ✅ void 반환형

- 함수가 **값을 반환하지 않을 때** 사용
- `return;` 만 쓰거나 생략 가능

```cpp
void sayHello() {
    cout << "안녕!" << endl;
}
```

---

## ✅ 반환값의 사용

함수를 호출한 쪽에서는 반환값을 **변수에 저장하거나, 바로 사용**할 수 있다.

```cpp
int result = add(3, 5);   // 변수에 저장
cout << add(2, 4);        // 직접 출력
```

---

## ✅ return 키워드

- 함수를 종료하고, 지정한 값을 반환함
- `return`을 만나면 함수는 즉시 종료됨

```cpp
int test() {
    return 42;
    cout << "이 코드는 실행되지 않음";
}
```

---

## ✅ 반환형이 없는 경우 (void)

```cpp
void reset() {
    // 초기화만 하고 아무것도 반환하지 않음
}
```

- 이 함수는 호출해도 값을 돌려주지 않음

---

## ✅ 사용자 정의 타입 반환

클래스나 구조체도 반환 가능

```cpp
struct Point {
    int x, y;
};

Point getOrigin() {
    return {0, 0};
}
```

---

## ✅ 요약 정리

| 항목        | 설명 |
|-------------|------|
| 반환형 정의  | 함수가 리턴하는 값의 자료형 |
| return 역할 | 함수 종료 + 결과값 반환 |
| void 의미    | 반환값 없음 |
| 활용 예시    | 연산 결과, 상태 정보, 문자열 등 리턴 가능 |
| 리턴 생략    | 반환형이 `void`일 때만 return 생략 가능 |

---

**반환형은 함수의 "결과물 타입"을 정의하는 매우 중요한 요소이며,  
함수 설계에서 가장 먼저 결정해야 하는 부분 중 하나이다.**
