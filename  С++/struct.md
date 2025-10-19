---
tags:
  - subtheme
---
[[Класс]]
## Описание структуры
~~~C++
struct Person {
	std::string name;
	std::string surname;
	int birth_year;
};
~~~

## Инициализация структуры
 ```C++
 Person person = {"John Doe"s, 30, Gender::MALE};
 
 person = Person{"John Doe"s, 30, Gender::MALE};
 
 Person person{ "Sarah Connor", 35, Gender::FEMALE };
 
 auto person = Person{ "Lara Croft"s, 21, Gender::FEMALE };
 ```