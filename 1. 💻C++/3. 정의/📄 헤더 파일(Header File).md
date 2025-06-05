# 📄 헤더 파일(Header File) - C++ 개념 정리

## ✅ 헤더 파일이란?

**헤더 파일(Header File)**은  
C++에서 **함수 선언, 클래스 정의, 상수, 매크로 등**을  
미리 정리해 둔 **코드 정의 파일**이다.

> 확장자는 `.h` 또는 `.hpp`  
> 사용 목적: **중복 코드 제거 + 코드 분할 + 재사용**

---

## ✅ 사용하는 이유

| 목적         | 설명 |
|--------------|------|
| 코드 분리     | 선언과 구현을 나눠서 관리 |
| 재사용성 향상 | 여러 파일에서 공통 정의를 공유 |
| 가독성 향상   | 코드 구조가 명확해짐 |

---

## ✅ 헤더 파일의 예시 구성

### 🔹 헤더 파일 (MyMath.h)

```cpp
// MyMath.h
int add(int a, int b);
int subtract(int a, int b);
```

### 🔹 구현 파일 (MyMath.cpp)

```cpp
// MyMath.cpp
#include "MyMath.h"

int add(int a, int b) {
    return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
```

### 🔹 사용 파일 (main.cpp)

```cpp
#include <iostream>
#include "MyMath.h"  // 사용자 정의 헤더 포함

int main() {
    std::cout << add(3, 4) << std::endl;  // 7 출력
}
```

---

## ✅ 표준 헤더 vs 사용자 정의 헤더

| 종류              | 예시                    | include 방식       |
|-------------------|-------------------------|--------------------|
| 표준 라이브러리 헤더 | `<iostream>`, `<vector>` | `< >` 사용         |
| 사용자 정의 헤더    | `"MyHeader.h"`           | `" "` 사용         |

---

## ✅ include guard (중복 포함 방지)

헤더 파일은 한 번만 포함되도록 **매크로**를 이용해 방지해야 한다.

```cpp
// MyHeader.h
#ifndef MYHEADER_H
#define MYHEADER_H

// 선언 내용들

#endif
```

또는 C++20 이상에서는 `#pragma once` 한 줄로 가능:

```cpp
#pragma once
```

---

## ✅ 자주 사용하는 표준 헤더

| 헤더        | 기능 예시 |
|-------------|-----------|
| `<iostream>`| 입출력(cout, cin) |
| `<vector>`  | 동적 배열 |
| `<string>`  | 문자열 클래스 |
| `<cmath>`   | 수학 함수 |
| `<algorithm>` | 정렬, 검색 |

---

## ✅ 요약

| 항목        | 설명 |
|-------------|------|
| 정의        | 함수, 클래스 등의 선언을 담는 파일 |
| 확장자      | `.h`, `.hpp` |
| 사용 이유   | 코드 분리, 재사용성, 가독성 향상 |
| include 방식| `< >` (표준), `" "` (사용자 정의) |
| 필수 예절   | `#pragma once` 또는 include guard |

---

**헤더 파일은 코드의 선언부를 분리하고,  
여러 곳에서 재사용 가능하게 하며  
구조적인 프로그램을 만드는 핵심 도구다.**
