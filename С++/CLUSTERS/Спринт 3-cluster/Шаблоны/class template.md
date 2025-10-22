---
tags:
  - Спринт-3-cluster
  - subtheme
parent: "[[CLUSTERS/Спринт 3-cluster/Шаблоны|Шаблоны]]"
generation: 2
---
## Реализация и использование шаблона структуры Point
```c
template <typename T>
struct Point {
  T x;
  T y;
};

int main() {

  Point<int> p_int{3, 2}; 
  
  Point<double> p_double{1.5, 2.999}; 
  
}
```

## Реализация шаблонного класса Vector2D T
~~~c
template<typename T>
class Vector2D { 
public:

    Vector2D(Point<T> p_start, Point<T> p_end) 
        : start_(p_start), end_(p_end) {} 
    
private:

    Point<T> start_; // Точки заданного типа.
    Point<T> end_; 
};
~~~

В шаблонных классах и структурах определение не выносят в .cpp-файл, а пишут в том же .h-файле. Это необходимо, так как при использовании шаблонного метода компилятору должен быть доступен его полный код, чтобы было возможно выполнить настройку на заданные шаблонные аргументы. Если вынести шаблонный метод или конструктор шаблона в .cpp-файл, то вы получите ошибку линкера.

## Шаблон класса с двумя параметрами
 ```c
 template<typename K, typename V> // Шаблон с типовыми параметрами K и V.
class VectorOfPairs {
public:
    // Добавляет пару в конец вектора.
    void PushBack(const K& key, const V& value) { 
        content_.push_back({key, value});
    }
    // Позволяет получить пару по индексу.
    std::pair<K, V>& operator[](size_t i) const { 
        return content_[i];
    }
    // Устанавливает значение по ключу.
    void SetValueByKey(const K& key, const V& value);
    
private:
    std::vector<std::pair<K, V>> content_;
};
 ```