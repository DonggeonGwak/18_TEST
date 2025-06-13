# 🎯 매개변수(Parameter) - C++ 함수의 입력값 정의

## ✅ 매개변수란?

**매개변수(Parameter)**는  
**함수에 값을 전달받기 위해 함수 정의 시 괄호 안에 선언하는 변수**를 말한다.

> 쉽게 말하면:  
> **함수가 동작할 때 외부에서 넘겨주는 값을 받아주는 이름표**

---

## ✅ 예제

```cpp
int add(int a, int b) {
    return a + b;
}
```

- 여기서 `int a`, `int b` → 이게 **매개변수**
- 함수가 호출될 때 실제 값을 받아서 내부에서 사용함

---

## ✅ 함수 호출 시: "인자(Argument)"를 전달

```cpp
int result = add(3, 5);
```

- `3`, `5` → **인자(argument)**라고 부름
- `add` 함수의 `a`, `b`에 각각 **대입되어 동작**

| 용어 | 설명 |
|------|------|
| 매개변수(Parameter) | 함수 정의할 때 받는 변수 |
| 인자(Argument) | 함수 호출할 때 전달하는 실제 값 |

---

## ✅ 매개변수의 역할

| 역할 | 설명 |
|------|------|
| 외부 값 전달 | 함수 외부에서 값을 받아옴 |
| 내부 연산용 | 받은 값을 기반으로 함수 내부 계산 수행 |
| 유연한 함수 | 다양한 값에 대해 동일한 로직 수행 가능하게 함 |

---

## ✅ 다양한 자료형의 매개변수

```cpp
void printChar(char c) { cout << c << endl; }
void printDouble(double d) { cout << d << endl; }
void printString(string s) { cout << s << endl; }
```

---

## ✅ 매개변수와 인자의 관계

```cpp
void greet(string name) {       // 매개변수
    cout << "Hello, " << name;
}

greet("Alice");  // 인자 "Alice"가 name으로 전달됨
```

---

## ✅ 참고: 기본값을 지정한 매개변수 (Default parameter)

```cpp
void greet(string name = "Guest") {
    cout << "Hi, " << name << endl;
}

greet();           // Hi, Guest
greet("Alice");    // Hi, Alice
```

---

## ✅ 요약 정리

| 개념        | 설명 |
|-------------|------|
| 매개변수     | 함수 정의 시 값을 받기 위한 변수 |
| 인자         | 함수 호출 시 전달하는 실제 값 |
| 위치         | 매개변수: 정의부 / 인자: 호출부 |
| 자료형 다양성 | int, char, string 등 다양한 타입 가능 |
| 응용         | 기본값 지정, 포인터/참조 전달 등 |

---

**매개변수는 함수의 외부와 내부를 연결해주는 "입구" 역할을 하며,  
함수를 유연하게 만들고 재사용성을 높이는 핵심 요소다.**
