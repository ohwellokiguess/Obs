---
tags:
  - Спринт-3-cluster
  - subtheme
parent: "[[CLUSTERS/Спринт 3-cluster/Перегрузка операций|Перегрузка операций]]"
generation: 2
---
## Пример создания списка для упрощения сравнения объектов класса Person
```c
// Подключаем библиотеку, чтобы использовать tie.
#include <tuple> 

struct Person {
    ...
    auto ListToCompare() const {
        // Возвращает {фамилия, имя, среднее имя}.
        return std::tie(surname, first_name, middle_name); 
    }
};

bool operator<(const Person& lhs, const Person& rhs) {
    // Сравниваем объекты.
    return lhs.ListToCompare() < rhs.ListToCompare();
}
...
```