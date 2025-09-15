#include "MyString.h"
#include <cstring> // strlen, strcpy, strcat, strstr

int MyString::objectCount = 0;

// === Конструктор по умолчанию ===
MyString::MyString() {
    data = new char[1];
    data[0] = '\0';
    length = 0;
    ++objectCount;
}

// === Конструктор с параметром ===
MyString::MyString(const char* s) {
    if (!s) {
        data = new char[1];
        data[0] = '\0';
        length = 0;
    } else {
        length = std::strlen(s);
        data = new char[length + 1];
        std::strcpy(data, s);
    }
    ++objectCount;
}

// === Конструктор копирования ===
MyString::MyString(const MyString& other) {
    length = other.length;
    data = new char[length + 1];
    std::strcpy(data, other.data);
    ++objectCount;
}

// === Оператор присваивания ===
MyString& MyString::operator=(const MyString& other) {
    if (this == &other) return *this;
    delete[] data;
    length = other.length;
    data = new char[length + 1];
    std::strcpy(data, other.data);
    return *this;
}

// === Деструктор ===
MyString::~MyString() {
    delete[] data;
    --objectCount;
}

// === Изменение строки ===
void MyString::setString(const char* s) {
    delete[] data;
    if (!s) {
        data = new char[1];
        data[0] = '\0';
        length = 0;
        return;
    }
    length = std::strlen(s);
    data = new char[length + 1];
    std::strcpy(data, s);
}

// === Вернуть C-строку (char*) ===
char* MyString::c_str() const {
    return data;
}

// === Вернуть копию строки ===
char* MyString::getCopy() const {
    char* copy = new char[length + 1];
    std::strcpy(copy, data);
    return copy;
}

// === Объединение двух строк ===
MyString MyString::concat(const MyString& other) const {
    std::size_t newLen = length + other.length;
    char* buffer = new char[newLen + 1];
    std::strcpy(buffer, data);
    std::strcat(buffer, other.data);

    MyString result(buffer);
    delete[] buffer;
    return result;
}

// === Поиск подстроки ===
int MyString::find(const char* substr) const {
    if (!substr || substr[0] == '\0') return -1;
    const char* pos = std::strstr(data, substr);
    return pos ? (int)(pos - data) : -1;
}

// === Длина строки ===
std::size_t MyString::size() const {
    return length;
}

// === Количество объектов ===
int MyString::getObjectCount() {
    return objectCount;
}

// === Перегрузка оператора << для cout ===
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.data;
    return os;
}
