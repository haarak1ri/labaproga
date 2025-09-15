#include "MyString.h"
#include <iostream>

// Демонстрация работы конструктора и деструктора
void demoScope() {
    MyString local("local");
    std::cout << "Inside demoScope: " << local << "\n";
}

int main() {
    // Конструктор с параметром
    MyString s1("Hello");

    // Конструктор по умолчанию + изменение строки
    MyString s2;
    s2.setString(", world!");

    // Объединение строк
    MyString s3 = s1.concat(s2);

    // Вывод объектов через перегруженный оператор <<
    std::cout << "s1: " << s1 << "\n";
    std::cout << "s2: " << s2 << "\n";
    std::cout << "s3: " << s3 << "\n";

    // Поиск подстроки
    std::cout << "Substring 'world' found in s3 at position: " << s3.find("world") << "\n";

    // Статический метод
    std::cout << "Object count: " << MyString::getObjectCount() << "\n";

    // Демонстрация вызова деструктора при выходе из области видимости
    demoScope();

    return 0;
}
