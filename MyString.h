#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstddef>
#include <iostream>

class MyString {
private:
    char* data;            // указатель на динамически выделенную строку
    std::size_t length;    // длина строки
    static int objectCount; // статический член

public:
    // === Конструкторы и деструктор ===
    MyString();                          // конструктор по умолчанию
    MyString(const char* s);             // конструктор с параметром
    MyString(const MyString& other);     // конструктор копирования
    MyString& operator=(const MyString& other); // оператор присваивания
    ~MyString();                         // деструктор

    // === Методы ===
    void setString(const char* s);         // изменение строки
    char* c_str() const;                   // вернуть C-строку (char*)
    char* getCopy() const;                 // вернуть копию строки
    MyString concat(const MyString& other) const; // объединение строк
    int find(const char* substr) const;    // поиск подстроки
    std::size_t size() const;              // длина строки

    // === Статические методы ===
    static int getObjectCount();

    // === Перегрузка операторов ===
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
};

#endif
