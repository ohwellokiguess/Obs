---
tags:
  - Спринт-3-cluster
  - subtheme
parent: "[[CLUSTERS/Спринт 3-cluster/Шаблоны|Шаблоны]]"
generation: 3
---
## Шаблонная перегрузка вывода точки
```c
template <typename T>
std::ostream& operator << (std::ostream &os, const Point<T> &point) {
    return os << "("s << point.x << "; "s << point.y << ")"s;
};
```

## Шаблонная перегрузка Vector2D
```c
template<typename T>
class Vector2D { 
public:
    Vector2D(Point<T> p_start, Point<T> p_end) 
        : start_(p_start), end_(p_end) {} 
        
    template<typename D> // Объявление перегрузки как дружественной функции.
    friend std::ostream& operator<<(std::ostream &, const Vector2D<D> &);
        
private:
  Point<T> start_;
  Point<T> end_; 
};

template<typename T> // Определение перегрузки.
std::ostream& operator<<(std::ostream &os, const Vector2D<T> &vec) {
        return os << "[("s << vec.start_.x << ", "s << vec.start_.y 
                  << "), ("s << vec.end_.x << ", "s << vec.end_.y << ")]"s;
}
```

Дружественная функция не является частью шаблона класса, поэтому для неё объявляется отдельный внутри класса.

## Перегрузка >> вместе с потоком ввода
```c
template<typename T> // Преобразует в строку.
std::string ToString(const T& x) { std::ostringstream s; s << x;
	return s.str(); }
```