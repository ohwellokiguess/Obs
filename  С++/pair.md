---
node_size: "0"
tags:
  - subtheme
---

## Объявление и инициализация пары

```C++
#include <utility>
#include <iostream>

std::pair<std::string, int> person2{"Alexey"s, 20};

std::cout << person2.first << std::endl;
std::cout << person2.second << std::endl;
```
## Перегрузка + для пар <int, int>

```C++
struct Vector2I {
	int x; int y;
	
	Vector2I operator+(const Vector2I &other) const {
		return {x + other.x, y + other.y};
	}
	
	Vector2I operator*(const Vector2I &other) const {
		return {x * other.x, y * other.y};
	}
	
	Vector2I operator-(const int value) const {
		return {x - value, y - value};
	}
};
```

Все операции могут быть перегружены, за исключением четырёх:

- доступа к элементу области видимости (`::`)
- доступа к полю класса (`.`)
- тернарной (`?:`)
- доступа к полю класса через указатель (`.*`)

Не рекомендуется перегружать операторы `,`, `&&`, `||`. Они работают по особым правилам, и их перегрузка может привести к проблемам.

## Перегрузка + для пары <int, int> и string
```C++
using namespace std::literals;

using Vector2I = std::pair<int, int>;

std::string operator+(const Vector2I &vec, const std::string &str) {
    return {"{"s + std::to_string(vec.first) + ", "s +
            std::to_string(vec.second) + "}"s + str};
}

int main() {
    using namespace std;

    string a{"String value of Vector2I: "s};
    auto x_left = a + Vector2I{1, 1};
    cout << x_left << endl;

    string b{" - String value of Vector2I"s};
    auto x_right = Vector2I{1, 1} + b;
    cout << x_right << endl;
}
```

