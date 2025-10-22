---
tags:
  - Спринт-3-cluster
  - subtheme
parent: "[[CLUSTERS/Спринт 3-cluster/Шаблоны|Шаблоны]]"
generation: 2
---
## Шаблонная функция сложения однотипных переменных
```c
template<typename T> // Шаблон функции сложения.
T Sum(T a, T b) {
    return a + b;
}

int main() {
    std::cout << Sum<int>(1, 1) << std::endl; 
    std::cout << Sum<double>(42., -42.) << std::endl;
    std::cout << Sum<std::string>("hello "s, "world"s) << std::endl;
}
```

## Шаблонная функция сложения векторов
```c
template<typename T>
Vector2D<T> Sum(Vector2D<T> v1, Vector2D<T> v2) {
    return Vector2D<T> {
        { v1.GetStart() + v2.GetStart() }, 
        { v1.GetEnd() + v2.GetEnd() }
    };
}
```

## Функция сложения разнотипных переменных с выведением типа через auto
```c
template<typename T, typename S>
auto Sum(T a, S b) {
    return a + b;
}
```