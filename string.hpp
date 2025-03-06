#include "cstddef"
#include "stdexcept"


//String.hpp
class String {
private:
    char* my_str; // указываем на массив символов
    size_t length; // длина массива
    size_t capacity_; // обьем выделенной памяти 

    
public:
  // констукторы
    String();
    String(const char* str);
    String(const char* str, size_t n);
    String(size_t n, char c);
    String(const String& str);
    String(const String& str, size_t pos, size_t len = npos);
    virtual ~String();

public:
  // лайтовые методы
    size_t size() const;
    size_t capacity() const;
    void reserve(size_t n = 0);
    void clear();
    bool empty();


public:
    char& at(size_t pos);
    const char& at(size_t pos) const;

    char& operator[](size_t pos);
    const char& operator[](size_t pos) const;

public:
    char& back();
    const char& back() const;

    char& front();
    const char& front() const;

public:
  // операторы
    String& operator+=(const String& str);
    String& operator+=(const char* str);
    String& operator+=(char c);

    String& operator=(const String& str);
    String& operator=(const char* str);

public: // потом будем делать

    //выполняет вставку строки str в позицию pos.
    //Если pos больше размера строки, то выбрасывается исключение throw std::out_of_range("message");.
    String& insert(size_t pos, const String&  str);
    String& insert(size_t pos, const char* str);

    //выполняет удаление подстроки в строке начиная с позиции pos и охватывая len символов.
    //Если len равняется npos, то удаление происходит с позиции pos до конца строки. Если pos больше размера строки, то выбрасывается исключение throw    . 
    //std::out_of_range("message");.
    String& erase(size_t pos = 0, size_t len = npos);

    //выполняет замену подстроки в строке начиная с позиции pos и охватывая len символов.
    //Если len равняется npos, то удаление происходит с позиции pos до конца строки.
    //Если pos больше размера строки, то выбрасывается исключение throw std::out_of_range("message");.
    String& replace(size_t pos, size_t len, const String& str);
    String& replace(size_t pos, size_t len, const char* str);
    String& replace(size_t pos, size_t len, size_t n, char c);

    void swap(String& str);
    const char* data();

    //возвращает индекс подстроки str (или символа c) в строке. pos - задает позицию с которой начинать поиск.
    //Если подстроку не нашли или pos больше размера строки, метод возращает npos.
    size_t find(const String& str, size_t pos = 0);
    size_t find(const char* str, size_t pos = 0);
    size_t find(char c, size_t pos = 0);

    String substr(size_t pos = 0, size_t len = npos);

    int compare(const String& str);
  //статическая константа с максимальным значением size_t.
  // Это значением может быть использовано в методах для параметра len, что означает "до конца строки".
  //Также эта константа может быть использована в качестве возвращаемого значения для указания отсутствия совпадений.
    static const size_t npos = -1;

    size_t countRef();
};