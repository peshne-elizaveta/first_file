#include "string.hpp"

// функция для вычисления длины строки
size_t find_length(const char* str) {
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// функция копирования
void copy(char* new_, const char* last, size_t n) {
    for (size_t i = 0; i < n; i++) {
        new_[i] = last[i];
    }
}
// Конструкторы
String::String() { 
    my_str = nullptr;
    length = 0;
    capacity_ = 0;
}

String::String(const char* str) {
    length = find_length(str);
    capacity_ = length + 1;
    my_str = new char[capacity_];
    for (size_t i = 0; i < length; i++) {
        my_str[i] = str[i];
    }
    my_str[length] = '\0'; 
}

String::String(const char* str, size_t n){ 
    length = n;
    capacity_ = length + 1;
    my_str = new char[capacity_];
    for (size_t i = 0; i < length; i++) {
        my_str[i] = str[i];
    }
    my_str[length] = '\0'; 
}

String::String(size_t n, char c) {
    length = n;
    capacity_ = length + 1;
    my_str = new char[capacity_];
    for (size_t i = 0; i < length; i++) {
        my_str[i] = c;
    }
    my_str[length] = '\0'; 
}

String::String(const String& str) {
    length = str.length;
    capacity_ = str.capacity_;
    my_str = new char[capacity_ + 1];
    copy(my_str, str.my_str, capacity_);
}

String::String(const String& str, size_t pos, size_t len = npos) {
    if (pos > str.length) {
        throw std::out_of_range("Position out of range");
    }
    if ((len == npos) || (pos + len > str.length)) {
        len = str.length - pos;
    }
    length = len;
    capacity_ = length + 1;

    my_str = new char[capacity_];

    for (size_t i = 0; i < length; i++) {
        my_str[i] = str.my_str[pos + i];
    }
    my_str[length] = '\0';
}

// деструктор 
String::~String() {
    delete[] my_str;
}

// методы
size_t String::size() const {
    return length;
}

size_t String::capacity() const {
    return capacity_;
}

void String::reserve(size_t n = 0) { // с этим разобраться позже!!!
    if (n > capacity_) {
        char* new_str = new char[n];
        for (size_t i = 0; i < length; i++) {
            new_str[i] = my_str[i];
        }
        new_str[length] = '\0';
        delete[] my_str;
        my_str = new_str;
        capacity_ = n;
    }
}

void String::clear() {
    if (my_str) {
        my_str[0] = '\0';
    }
    length = 0;
}

bool String::empty() {
    return length == 0;
}


// возвращает символ строки по указанному индексу pos
// позволяет изменять символ
char& String::at(size_t pos) {
    if (pos >= length) {
        throw std::out_of_range("Index out of range");
    }
    return my_str[pos];
}

// тут прикол в том, что используется только тогда, 
// когда в обьекте string нельзя менять само значение
// возвращает константную ссылку, чтобы не было возможности изменить символ
const char& String::at(size_t pos) const {
    if (pos >= length) {
        throw std::out_of_range("Index out of range");
    }
    return my_str[pos];
}
// оператор делающий тоже самое, но не проверяющий границы(зачем нам это)
char& String::operator[](size_t pos) {
    return my_str[pos];
}
// выводит ссылку на последний символ строки
char& String::back() {
    if (length == 0) {
        throw std::out_of_range("String is empty");
    }
    return my_str[length - 1];
}
const char& String::back() const {
    if (length == 0) {
        throw std::out_of_range("String is empty");
    }
    return my_str[length - 1];
}
// выводит ссылку на первый символ строки
char& String::front() {
    if (length == 0) {
        throw std::out_of_range("String is empty");
    }
    return my_str[0];
}
const char& String::front() const {
    if (length == 0) {
        throw std::out_of_range("String is empty");
    }
    return my_str[0];
}

// операторы
// прибавляет другую строку
String& String::operator+=(const String& str) {
    size_t new_length = length + str.length;
    size_t new_capacity_ = new_length + 1;
    reserve(new_capacity_);

    for (size_t i = 0; i < str.length; i++) {
        my_str[length + i] = str.my_str[i];
    }

    length = new_length;
    my_str[length] = '\0';
    return *this;
}
// прибавляет строку которая представлена указателем на символы
String& String::operator+=(const char* str) {
    size_t prev_length = find_length(str);

    size_t new_length = length + prev_length;
    size_t new_capacity_ = new_length + 1;
    reserve(new_capacity_);

    for (size_t i = 0; i < prev_length; i++) {
        my_str[length + i] = str[i];
    }

    length = new_length;
    my_str[length] = '\0';
    return *this;

}
// добавляет новый символ 
String& String::operator+=(char c) {
    size_t new_length = length + 1;
    size_t new_capacity_ = new_length + 1;
    reserve(new_capacity_);

    my_str[length] = c; 
    length = new_length;
    my_str[length] = '\0';
    return *this; 
}

String& String::operator=(const String& str) {
    
}
String& String::operator=(const char* str) {}


