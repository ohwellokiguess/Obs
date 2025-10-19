---
tags:
  - Спринт-3-cluster
  - subtheme
parent: "[[CLUSTERS/Спринт 3-cluster/Шаблоны|Шаблоны]]"
generation: 2
---
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

```c
template<typename T>
Vector2D<T> Sum(Vector2D<T> v1, Vector2D<T> v2) {
    return Vector2D<T> {
        { v1.GetStart() + v2.GetStart() }, 
        { v1.GetEnd() + v2.GetEnd() }
    };
}
```