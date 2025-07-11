# 🔢 인덱스(Index)란? (C++ 초심자용 설명)

## ✅ 인덱스란?

**인덱스(Index)**는  
배열이나 문자열 같은 **여러 데이터를 나열한 자료구조에서 각 요소의 "번호"**를 말해.

> 쉽게 말해:  
> **"배열에서 몇 번째 칸인가?"를 나타내는 숫자**

---

## ✅ 중요한 특징

- **C++에서는 인덱스 번호가 0부터 시작함**
  - 첫 번째 요소: 인덱스 0
  - 두 번째 요소: 인덱스 1
  - 세 번째 요소: 인덱스 2
- 배열, 문자열, vector 등에서 공통적으로 사용됨

---

## ✅ 예시 1: 배열에서의 인덱스

```cpp
int numbers[3] = {10, 20, 30};

cout << numbers[0] << endl; // 10
cout << numbers[1] << endl; // 20
cout << numbers[2] << endl; // 30
```

- `numbers[0]` → 첫 번째 값
- `numbers[1]` → 두 번째 값

---

## ✅ 예시 2: 문자열에서의 인덱스

```cpp
string name = "Jinu";

cout << name[0] << endl; // 'J'
cout << name[1] << endl; // 'i'
cout << name[2] << endl; // 'n'
cout << name[3] << endl; // 'u'
```

- 문자열도 글자 하나하나가 인덱스로 구분됨

---

## ✅ 예시 3: 반복문과 함께 사용

```cpp
int arr[5] = {1, 2, 3, 4, 5};

for (int i = 0; i < 5; i++) {
    cout << "arr[" << i << "] = " << arr[i] << endl;
}
```

- `i`가 인덱스 역할을 해서 배열을 순회함

---

## ✅ 잘못된 인덱스 사용 주의

```cpp
int arr[3] = {1, 2, 3};
cout << arr[3]; // ❌ 오류! 유효한 인덱스는 0, 1, 2까지만!
```

- **배열의 범위를 벗어난 인덱스 사용은 위험함 (오류 발생 or 이상한 값)**

---

## ✅ 요약 정리

| 항목       | 설명 |
|------------|------|
| 인덱스     | 배열/문자열 등에서 각 요소의 "번호" |
| 시작 번호  | C++에서는 항상 0부터 시작 |
| 사용 목적  | 원하는 위치의 데이터를 가져오거나 수정할 때 |
| 주의사항   | 범위를 벗어난 인덱스는 에러나 예외 발생 |

---

**인덱스는 모든 프로그래밍에서 매우 기본적이고 중요한 개념이야.**  
배열, 문자열, 반복문과 항상 함께 쓰이기 때문에 꼭 익숙해져야 해!
