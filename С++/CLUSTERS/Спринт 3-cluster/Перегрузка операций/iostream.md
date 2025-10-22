---
tags:
  - subtheme
---
При перегрузке операций ввода вывода всегда стоит возвращать поток, чтобы сохранить свойство **Каскадирования**. Так же стоит делать их свободными, т.к. потоки не являются членами класса.
## Перегрузка операции вывода << для vector int
~~~C++
using VectorInt = std::vector<int>;

std::ostream& operator<<(std::ostream &os, const VectorInt &vector) {
    for (auto item : vector) {
        os << item << " "s; // Выводим элементы вектора.
    }
    return os; // Возвращаем исходную ссылку на поток.
}
~~~
## Перегрузка операции ввода >> для vector int
```C++
using PairInt = std::pair<int, int>;

std::istream& operator>>(std::istream& is, PairInt& pair_int) {
    is >> pair_int.first >> pair_int.second; // Записываем значения.
    return is; // Возвращаем ссылку на поток.
}
```
## Перегрузка >> с проверками для класса Rational
```C
inline std::istream& operator>>(std::istream& is, Rational& r){

	char delimeter = '0';

	is >> r.numerator_;

	if (!(is >> std::ws >> delimeter)) {
	//std::ws стирает пробелы до первого отличного символа.
		is.clear();//Снятие флага ошибки потока методом `clear`.
		return is;
	}

	if (delimeter != '/') {
		is.unget();//Возвращает последний прочтённый символ обратно в поток.
		return is;
	}

	if (!(is >> r.denominator_) || (r.denominator_ == 0)) {
		is.setstate(std::ios::failbit);//Установка флага провальной операции.
		return is;

	}
	return is;
}
```