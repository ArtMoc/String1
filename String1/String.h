#pragma once
#include <iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-----------------------------------------\n"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// ���������� ������ - CLASS DECLARATION ////////////////////////////////////////

class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

class String
{
	int size; //������ ������ � ������
	char* str; //����� ������ � ������������ ������
public:
	int get_size()const;
	char* get_str()const;
	char* get_str();
	//                         CONSTRUCTORS:
	explicit String(int size = 80);
	String(const char* str);
	//                         THE RULE OF THREE:
	String(const String& other);
	String(String&& other);
	~String();

	void print()const;

	//                          OPERATORS:
	String& operator =(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);

	const char& operator[](int i)const;
	char& operator[](int i);
};

/////////////////////////////////// ����� ���������� ������ - CLASS DECLARATION END //////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
