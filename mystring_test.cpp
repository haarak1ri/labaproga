#include <gtest/gtest.h>
#include "MyString.h"

// === Тест конструктора по умолчанию ===
TEST(MyStringTest, DefaultConstructor) {
    MyString s;
    EXPECT_STREQ(s.c_str(), "");   // строка пустая
    EXPECT_EQ(s.size(), 0);        // длина 0
}

// === Тест конструктора с параметром ===
TEST(MyStringTest, ParamConstructor) {
    MyString s("Hello");
    EXPECT_STREQ(s.c_str(), "Hello");
    EXPECT_EQ(s.size(), 5);
}

// === Тест конструктора копирования ===
TEST(MyStringTest, CopyConstructor) {
    MyString s1("Hello");
    MyString s2(s1);  // копия
    EXPECT_STREQ(s2.c_str(), "Hello");
    EXPECT_EQ(s2.size(), 5);
}

// === Тест оператора присваивания ===
TEST(MyStringTest, AssignmentOperator) {
    MyString s1("Hello");
    MyString s2;
    s2 = s1;  // присваивание
    EXPECT_STREQ(s2.c_str(), "Hello");
    EXPECT_EQ(s2.size(), 5);
}

// === Тест изменения строки ===
TEST(MyStringTest, SetString) {
    MyString s;
    s.setString("World");
    EXPECT_STREQ(s.c_str(), "World");
    EXPECT_EQ(s.size(), 5);
}

// === Тест объединения строк ===
TEST(MyStringTest, ConcatStrings) {
    MyString s1("Hello");
    MyString s2(" World");
    MyString s3 = s1.concat(s2);
    EXPECT_STREQ(s3.c_str(), "Hello World");
    EXPECT_EQ(s3.size(), 11);
}

// === Тест поиска подстроки ===
TEST(MyStringTest, FindSubstring) {
    MyString s("abcdef");
    EXPECT_EQ(s.find("cd"), 2);   // индекс найденной подстроки
    EXPECT_EQ(s.find("xyz"), -1); // нет подстроки
    EXPECT_EQ(s.find(""), -1);    // пустая строка
}

// === Тест возврата копии строки ===
TEST(MyStringTest, GetCopy) {
    MyString s("Test");
    char* copy = s.getCopy();
    EXPECT_STREQ(copy, "Test");
    delete[] copy; // обязательно освободить!
}

// === Тест статического счётчика объектов ===
TEST(MyStringTest, ObjectCount) {
    int before = MyString::getObjectCount();
    {
        MyString s1("one");
        MyString s2("two");
        EXPECT_EQ(MyString::getObjectCount(), before + 2);
    }
    // После выхода из блока объекты уничтожены
    EXPECT_EQ(MyString::getObjectCount(), before);
}
