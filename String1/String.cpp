#include "String.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// ОПРЕДЕЛЕНИЕ КЛАССА - CLASS DEFINITION ////////////////////////////////////////

int String::get_size()const
{
	return size;
}
char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
//                         CONSTRUCTORS:
String::String(int size) :size(size), str(new char[size] {})
{
	cout << "Default_Constructor:\t" << this << endl;
}
String::String(const char* str) : String(strlen(str) + 1)//Делегируем выделение памяти конструктору по умолчанию
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
//                         THE RULE OF THREE:
String::String(const String& other) :String(other.str)
{
	//Deep copy
	cout << "Copy_Constructor:\t" << this << endl;
}
String::String(String&& other) : size(other.size), str(other.str)
{
	other.str = nullptr;
	other.size = 0;
	cout << "Move_Constructor:\t" << this << endl;
}
String::~String()
{
	delete[]this->str;
	cout << "Destructor:\t\t" << this << endl;
	//Memory leak
}

void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

//                          OPERATORS:
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	//Deep copy:
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "Copy_Assignment:\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	other.size;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//:: - Global scpoe (глобальное пространство имен)
::String operator+(const String& left, const String& right)
{
	String buffer(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		//buffer.get_str()[i] = left.get_str()[i];
		buffer[i] = left[i];
	//                  l-value = r-value;
	for (int i = 0; i < right.get_size(); i++)
		//buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		buffer[i + left.get_size() - 1] = right.get_str()[i];

	return buffer;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

/////////////////////////////////// КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА - CLASS DEFINITION END //////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
