#include "MyString.h"
#include <cstring> // strlen, strcpy, strcat, strstr

int MyString::object_count = 0;

// === Конструктор по умолчанию ===
MyString::MyString() {
    data = new char[1];
    data[0] = '\0';
    length = 0;
    ++object_count;
}

// === Конструктор с параметром ===
MyString::MyString(const char* str) {
    if (!str) {
        data = new char[1];
        data[0] = '\0';
        length = 0;
    } else {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }
    ++object_count;
}

// === Конструктор копирования ===
MyString::MyString(const MyString& otherStr) {
    length = otherStr.length;
    data = new char[length + 1];
    strcpy(data, otherStr.data);
    ++object_count;
}

// === Оператор присваивания ===
MyString& MyString::operator=(const MyString& otherStr) {
    if (this == &otherStr) return *this;
    delete[] data;
    length = otherStr.length;
    data = new char[length + 1];
    strcpy(data, otherStr.data);
    return *this;
}

// === Деструктор ===
MyString::~MyString() {
    delete[] data;
    --object_count;
}

// === Изменение строки ===
void MyString::setString(const char* str) {
    delete[] data;
    if (!str) {
        data = new char[1];
        data[0] = '\0';
        length = 0;
        return;
    }
    length = strlen(str);
    data = new char[length + 1];
    strcpy(data, str);
}

// === Вернуть C-строку ===
char* MyString::c_str() const {
    return data;
}

// === Вернуть копию строки ===
char* MyString::getCopy() const {
    char* copy = new char[length + 1];
    strcpy(copy, data);
    return copy;
}

// === Объединение строк ===
MyString MyString::concat(const MyString& otherStr) const {
    size_t newLen = length + otherStr.length;
    char* buffer = new char[newLen + 1];
    strcpy(buffer, data);
    strcat(buffer, otherStr.data);

    MyString result(buffer);
    delete[] buffer;
    return result;
}

// === Поиск подстроки ===
int MyString::find(const char* substr) const {
    if (!substr || substr[0] == '\0') return -1;
    const char* pos = strstr(data, substr);
    return pos ? (int)(pos - data) : -1;
}

// === Длина строки ===
size_t MyString::size() const {
    return length;
}

// === Количество объектов ===
int MyString::getObjectCount() {
    return object_count;
}
