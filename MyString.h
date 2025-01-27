#ifndef MYSTR_H
#define MYSTR_H

#include <iostream>
#include <string.h>
#include <string>

using namespace std;
class MyString {
private:
    char* _str; // атрибут для хранения указателя на целочисленное значение на куче
    int _capasity;
    int _size;
    int _length;
    //add _str, _sapacity,_lengh
    //!!!!!!!
    
public:
   
   
    ~MyString();
    MyString(const char* s, int count);
    MyString(int count, char s);
    MyString(std::string str);
    MyString(const char* s);
    MyString(const MyString& str);  
    //MyString(char* s, int count);
    MyString(void);

    char* c_str() const;

    void  insert(int index, int count, char ins_val);
    void insert(int index, const char* ins_str);
    void insert(int index, const char* ins_str, int count);
    void insert(int index, std::string ins_str);
    void insert(int index, std::string ins_str, int count);

    int find(const char *str, int index);
    int find(const char* str);
    int find(std::string ins_str, int index);
    int find(std::string ins_str);

    MyString  substr(int index);
    MyString  substr(int  index, int  count);

    void replace(int index, int count, const char* s); // not low capacity

    void replace(int index, int count, std::string s); ////!!


    void clear();
    bool empty();
    void erase(int index, int count);
    void shrink_to_fit();   ///////////////////////////????????
    char * data() const;   ///////////////////////////????????

    void append(int count, char c);
    void append(const char* s);
    void append(const char* s, int index,int count);

    void append(std::string ins_str);
    void append(std::string ins_str, int index, int count);

    friend  std::ostream& operator<<(std::ostream& out, MyString& another);
    friend std::istream& operator>>(std::istream& in, MyString& another);

    char& operator[](int c);

    MyString operator+(const MyString & str);

    MyString operator+(const char* s);
    MyString operator+(std::string str);

    void operator+=(const MyString& another);
    void operator+=(const char* cur_str);
    void operator+=(std::string cur_str);

    void operator=(std::string& str);
    //void operator []= (int index,char);

    void operator=(const char* cur_str);
    void operator=(char c);   
    void operator=(const MyString& str);

    bool operator>(const MyString& str);
    bool operator>=(const MyString& str);
    bool operator<=(const MyString& str);
    bool operator<(const MyString& str);
    bool operator==(const MyString& str);
    bool operator!=(const MyString& str);

    int size() const;
    int capacity() const;
    int length() const;
   
   

};
#endif
