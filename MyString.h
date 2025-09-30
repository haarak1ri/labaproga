#pragma once

//#include <cstddef>
#include <iostream>

// using std::cout;
// using std::endl;
// using std::cin;


class MyString {
public:
    // === Конструкторы и деструктор ===
    MyString();                               // конструктор по умолчанию
    MyString(const char* str);                // конструктор с параметром
    MyString(const MyString& otherStr);       // конструктор копирования
    MyString& operator=(const MyString& otherStr); // оператор присваивания
    ~MyString();                              // деструктор

    // === Методы ===
    void setString(const char* str);              // изменение строки
    char* c_str() const;                          // вернуть C-строку
    char* getCopy() const;                        // вернуть копию строки
    MyString concat(const MyString& otherStr) const; // объединение строк
    int find(const char* substr) const;           // поиск подстроки
    size_t size() const;                          // длина строки

    // === Статические методы ===
    static int getObjectCount();

private:
    char* data;           // указатель на строку
    size_t length;        // длина строки
    static int object_count; // статический счётчик объектов
};
