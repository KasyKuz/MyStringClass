#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <iostream>
using namespace std;
#include <cstring>
void MyString::clear()
{
	delete _str;
	_str = new char[1];
	_str[0] = '\0';
	_capasity = capacity();
	_size = size();
	_length = length();
}

bool MyString::empty()
{
	_capasity = capacity();
	_size = size();
	_length = length();
	if (_size == 0 && _capasity == 1) return true;
	return false;
}

MyString::~MyString()
{
	delete _str;
}

void MyString::erase(int index, int count)
{
	if (index + count > _size) { std::cout << "error in count or index, too much" << endl; return; }
	char* tmp = new char[this->_size+1];
	/* 
	for (int i = 0; i < index; i++) {
		tmp[i] = _str[i];
	}
	
	for (int i = index+count; i < _size; i++) {
		tmp[i-count] = _str[i];
	}
	*/
	strncpy(tmp, &(this->_str[index + count]), this->_size - index);
	for (size_t i = 0; i < count; i++) {
		this->_str[index +i] = '\0';
	}
	strcat(this->_str, tmp);
	delete tmp;
	this->_size = strlen(this->_str);
	//printf("%s\n", this->_str);

}
char& MyString::operator[](int c)
{
	//char* s = {'\0'};
	if (c<=_size) {
		return _str[c];
	}
	else {
		cout << "[ER] Index out of range, if index=0: " << endl;
		return _str[0];
	}
}

int MyString::size()const
{
	int i = 0;
	while (_str[i] != '\0') {

		i++;
	}
	
	//int i = sizeof(_str);
	return i;
}

int MyString::capacity() const
{
	size();


	if (_capasity >= _size + 1) return _capasity;
	return _size+1;
}

int MyString::length() const
{
	//_length = size();
	return size();
}


MyString::MyString(const char* s,int count)
{
	_str = new char[count + 1];
	//char t = ' ';
	int i = 0;
	while (i<count) {
		_str[i] = s[i];
		i++;
	}
	delete i;
	_str[count] = '\0';
	_size = size();
	_length = length();
	_capasity = capacity();

	
}

MyString::MyString(int count, char s)
{
	_str = new char[count + 1];
	int i = 0;
	while (i<count) {
		_str[i] = s;
		i++;
	}
	_str[count] = '\0';
	_size = size();
	_length = length();
	_capasity = capacity();
}

MyString::MyString(std::string stri)
{
	char t = ' ';
	int i = 0;
	while (t!='\0') {
		t = stri[i];
		i++;
	}
	_str = new char[i+1];
	i = 0;
	while (stri[i] != '\0') {
		_str[i] = stri[i];
		i++;
	}
	_str[i] = '\0';
	_size = size();
	_length = length();
	_capasity = capacity();
	
}

MyString::MyString(const char* stri)
{
	int len = strlen(stri);
	_str = new char[len+1];
	int i = 0;
	while (i<len) {
		_str[i] = stri[i];
		i++;
	}
    _str[i] ='\0';
	_size = size();
	_length = length();
	_capasity=capacity();
	
}

MyString::MyString(const MyString& str)
{
	int n = str._size+1;
	_str = new char[n];
	for (int i = 0; i < n-1; i++)
	{
		_str[i] = str._str[i];//сменить на получение по индексу
	}
	_str[n-1] = '\0';

	_size = size();
	_length = length();
	_capasity = capacity();
	
}

MyString::MyString()  {    // default constructor()
	_str = new char[1];
	_str[0] = '\0';

	_size = size();
	_length = length();
	_capasity = capacity();

}
char* MyString::c_str() const{
	return _str;
}
char* MyString::data() const {
	return _str;
}

void MyString::insert(int index, int count, char ins_val) 
{
	
	if (index <= this->_size+1) {
		char* tmp = new char[2];
		tmp[0] =ins_val;
		tmp[1] = '\0';
		for (size_t i = 0; i < count; i++) {
			insert(index, tmp);
		}
	}
	else { cout << "[ER] Index out of range" << endl; }
	_size = size();
	_length = length();
	//_capasity = capacity();
	


}
void MyString:: insert(int index, const char* string) 
{	
	if (index <= _size+1) {
		size_t len = strlen(string);
		char* tmp = new char[_size + 1 + len];
		size_t j = 0;
		for (size_t i = 0; i < (this->_size) + len; i++) {
			if (i == index) {
				for (size_t k = 0; k < len; k++) {
					tmp[index + k] = string[k];
				}
				i = index + len - 1;
			}
			else {
				tmp[i] = this->_str[j];
				j++;
			}
		}
		tmp[_size + len] = '\0';
		_str = new char[_size+1 + len];
		strncpy(_str, tmp, _size+1 + len);
		if (this->_capasity <_size) {
			this->_capasity = length();
		}
		this->_size = strlen(tmp);
		//printf("%s\n", _str);
	}
	else { cout << "[ER] Index out of range" << endl; }
	_size = size();
	_length = length();
	//printf("%d cp\n",_capasity);
	//_capasity = capacity();
	
}
void MyString::insert(int index, const char* ins_str, int count)
{
	int i = 0;
	while (i < count) {
		insert(index,1, ins_str[i]);
		index++;
		i++;
	}
	_size = size();
	_length = length();
	//_capasity = capacity();
	

}
void MyString::insert(int index, std::string ins_str)
{
	int i = 0;
	char t;
	while (i < ins_str.size()) {
		t = ins_str[i];
		insert(index + i, 1, t);
			
		i++;
	}
	//return ;
	_size = size();
	_length = length();
	//_capasity = capacity();
}
void MyString::insert(int index, std::string ins_str, int count)
{
	int i = 0;
	while (i < count) {
		insert(index + i, 1,ins_str[i]);
		i++;
	}
	//return;
	_size = size();
	_length = length();
	//_capasity = capacity();
}
int MyString::find(const char* cur_str, int index)
{
	if (strlen(cur_str) <= this->_size) {
		size_t find_letters = 0;
		size_t tmp_ind = 0;
		size_t j = 0;
		for (size_t i = index; i < this->_size; i++) {
			if (this->_str[i] == cur_str[j]) {
				find_letters++;
				j++;
				if (find_letters == 1) { tmp_ind = i; }
				if (find_letters == strlen(cur_str)) { return tmp_ind; }
			}
			else {
				find_letters = 0;
				j = 0;
			}
		}
		return -1;
	}
	else {
		cout << "[ER] Index out of range" << endl;
		return -1;
	}
}
void MyString::shrink_to_fit()
{
	this->_size = size();
	this->_capasity = this->_size + 1;
}
void MyString::append(int count, char c) {
	this->insert(this->_size, count, c);
}
void MyString::append(const char* s)
{
	insert(size(), s);
}
void MyString::append(const char* s, int index, int count)
{
	insert(index, s, count);
}
void MyString::append(std::string ins_str)
{
	insert(size(), ins_str);
}
void MyString::append(std::string ins_str, int index, int count)
{
	insert(index, ins_str, count);
}
int MyString::find(const char* str)
{
	return find(str,0);
}
int MyString::find(std::string str, int index)
{
	return find(&str[0], index);
}
int MyString::find(std::string ins_str)
{
	return find(&ins_str[0], 0);
}
MyString  MyString::substr(int index, int  count)
{
	MyString tmp(_str + index, count);
	return tmp;
}

MyString  MyString::substr(int index)
{
	return substr(index, size() - index);
}

void MyString::operator=(const char* cur_str) { // char string assignment
	delete this->_str;
	this->_str = new char[strlen(cur_str) + 1];
	this->_size = strlen(cur_str);
	_length = strlen(cur_str);
	int i = 0;
	while (i < _length) {
		_str[i] = cur_str[i];
		i++;
	}
	_str[_length] = '\0';
	//strncpy(this->_str, cur_str, this->_size);
	if (strlen(cur_str) >= this->_capasity) {
		this->_capasity = length();
	}
}
void MyString::operator=(std::string& cur_str) { // std::string assignment
	*this = static_cast<char*>(&cur_str[0]);
}
void MyString::operator=(char cur_char) { // char assignment
	delete _str;
	_str = new char[2];
	_str[0] = cur_char;
	_str[1] = '\0';
	
}

void MyString::operator=(const MyString& cur_str)
{
	delete this->_str;
	this->_str = new char[cur_str.size() + 1];
	this->_size = cur_str.size();
	char* s = cur_str._str;
	strncpy(this->_str, s, this->_size);
	if (strlen(s) >= this->_capasity) {
		this->_capasity = length();
	}
}

void MyString::operator+=(const MyString& another) { // assignment concatenate with char array
	this->insert(this->_size, another.data());
}

void MyString::operator+=(const char* cur_str) { // assignment concatenate with char array
	this->insert(this->_size, cur_str);
}
void MyString::operator+=(std::string cur_str)
{
	this->insert(this->_size, cur_str.c_str());
}

MyString MyString::operator+(const MyString& another) { // concatenate with Mystring
	char* tmp_str = new char[_size+1 + another._size];
	
	int i = 0;
	while (i < _size) {
		tmp_str[i] = _str[i];
		i++;
	}
	//printf("%s %d\n",_str, _size);
//	char* s = another.c_str();
	i = _size;
	int len = another._size+ _size;
	while (i < len) {
		tmp_str[i] = another._str[i-_size];
		//printf("%c ", another._str[i - _size]);
		i++;
	}
	
	//printf("\n%s %d \n", another._str, another._size);
	tmp_str[_size + another._size ] = '\0';
	//delete tmp_str;
	MyString tmp(tmp_str);
	delete tmp_str;
	return tmp;
}

MyString MyString::operator+(const char* cur_str) { // concatenate with char array
	char* tmp_str = new char[_size + 1 + strlen(cur_str)];
	strncpy(tmp_str, this->_str, this->_size);
	int i = _size;
	int len = _capasity + strlen(cur_str);
	while (i < len) {
		tmp_str[i] = cur_str[i - _size];
		i++;
	}
	//strcat(tmp_str, cur_str);
	tmp_str[_size  + strlen(cur_str) ] = '\0';
	//printf("test %s\n", tmp_str);

	MyString tmp(tmp_str);
	delete tmp_str;
	//printf("test %s %d\n", tmp._str, tmp.size());
	return tmp;
}
MyString MyString::operator+(const std::string cur_str) { // concatenate with std::string
	MyString a(this->_str);
	MyString tmp = a + &cur_str[0];
	return tmp;
}

bool MyString::operator>(const MyString& another) {
	int i = 0;
	int t = 0;
	if (_size > another._size) return true;
	if (_size < another._size) return false;
	while (i < _size && i < another._size) {
		if ( (int)_str[i]< (int)another._str[i]) return false;
		if ((int)_str[i] == (int)another._str[i])t++;
		i++;
	}
	if (t == _size) return false;
	return true;
}

bool MyString::operator<(const MyString& another) {
	int i = 0;
	int t = 0;
	if (_size > another._size) return false;
	if (_size < another._size) return true;
	while (i < _size && i < another._size) {
		if ( (int)_str[i] >(int)another._str[i]) return false;
		if ((int)_str[i] == (int)another._str[i])t++;
		i++;
	}
	if (t == _size) return false;
	return true;
}

bool MyString::operator>=(const MyString& another) {
	int i = 0;
	if (_size < another._size) return false;
	if (_size > another._size) return true;
	while (i < _size && i < another._size) {
		if ((int)_str[i]< (int)another._str[i]) return false;
		i++;
	}
	return true;
}

bool MyString::operator<=(const MyString& another) {
	int i = 0;
	if (_size > another._size) return false;
	if (_size < another._size) return true;
	while (i < _size && i < another._size) {
		if ((int)_str[i]> (int)another._str[i]) return false;
		i++;
	}
	return true;
}

bool MyString::operator!=(const MyString& another) {
	int i = 0;
	int t = 0;
	if (_size != another._size) return true;
	while (i < _size && i < another._size) {
		if (another._str[i] == _str[i]) t++;
		i++;
	}
	if (t == _size) return false;
	else return true;
}

bool MyString::operator==(const MyString& another) {
	//return *this == another.data();
	int i = 0;
	if (_size != another._size) return false;
	while (i < _size && i < another._size) {
		if (another._str[i] != _str[i]) return false;
		i++;
	}
	return true;
}


void MyString::replace(int index, int count, const char* s)
{
	if (index <= this->_capasity) {
		this->erase(index, count);
		this->insert(index, s);
	}
	else { cout << "[ER] Index out of range" << endl; }
}
void MyString::replace(int index, int count, std::string s)
{
	if (index <= this->_capasity) {
		this->replace(index, count, static_cast<char*>(&s[0]));
	}
	else { cout << "[ER] Index out of range" << endl; }
}

std::ostream& operator<<(std::ostream& out, MyString& another)
{
	out << another.data();
	//out << ' ';
	return out;
}

std::istream& operator>>(std::istream& in, MyString& another)
{
	char c = 'a';
	//printf("%d \n", another._capasity);
	int i = 0;
	c = in.get();
	while ((c != '\n') && (c != EOF)) {
		
		another.append(1, c);	
		c = in.get();
	}

	
	another.append(1, '\0');
	//another._length -= 1;
	//another._size = another._length;
	//printf("d %d\n", another.length());
	return in;
}
