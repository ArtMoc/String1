//constructors_delegation_in_string
#pragma warning (disable:4326)
#include <iostream>
using namespace std;

#define delimiter "\n-----------------------------------------\n"

class String;
String operator+(const String& left, const String& right);

class String
{
	int size; //ðàçìåð ñòðîêè â áàéòàõ
	char* str; //àäðåñ ñòðîêè â äèíàìè÷åñêîé ïàìÿòè
public:
	int get_size()const
	{
		return size;
	}
	char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//                         CONSTRUCTORS:
	explicit String(int size = 80) :size(size), str(new char[size] {})
	{
		cout << "Default_Constructor:\t" << this << endl;
	}
	String(const char* str) :String(strlen(str) + 1)//Делегируем выделение памяти конструктору по умолчанию
	{
		//for (int i = 0; i < size; i++)this->str[i] = str[i];

		strcpy(this->str, str);
		//strcpy - string copy
		//strcpy(dst, src);
		//dst - destination - СТРОКА ПОЛУЧАТЕЛЬ, СТРОКА, В КОТОРУЮ КОПИРУЕТСЯ СОДЕРЖИМОЕ
		//src - source - СТРОКА ИСТОЧНИК, СТРОКА, ИЗ КОТОРОЙ КОПИРУЕТСЯ СОДЕРЖИМОЕ

		cout << "Constructor:\t\t" << this << endl;
	}
	//                         THE RULE OF THREE:
	String(const String& other) :String(other.str)
	{
		//Deep copy
		cout << "Copy_Constructor:\t" << this << endl;
	}
	String(String&& other):size(other.size), str(other.str)
	{
		other.str = nullptr;
		other.size = 0;
		cout << "Move_Constructor:\t" << this << endl;
	}
	~String()
	{
		delete[]this->str;
		cout << "Destructor:\t\t" << this << endl;
		//Memory leak
	}

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}

	//                          OPERATORS:
	String& operator =(const String& other)
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
	String& operator=(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		other.size;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	const char& operator[](int i)const
	{
		return str[i];
	}char& operator[](int i)
	{
		return str[i];
	}
};

String operator+(const String& left, const String& right)
{
	String buffer (left.get_size() + right.get_size() - 1);
	strcpy(buffer.get_str(), left.get_str());
	strcat(buffer.get_str(), right.get_str());
	//strcat - ВЫПОЛНЯЕТ КОНКАТЕНАЦИЮ СТРОК
	//strcat(dst, src);
	//dst - destination - СТРОКА ПОЛУЧАТЕЛЬ, СТРОКА, В КОТОРУЮ КОПИРУЕТСЯ СОДЕРЖИМОЕ
	//src - source - СТРОКА ИСТОЧНИК, СТРОКА, ИЗ КОТОРОЙ КОПИРУЕТСЯ СОДЕРЖИМОЕ
	//В dst будет объединенная строка


/*	for (int i = 0; i < left.get_size(); i++)
		//buffer.get_str()[i] = left.get_str()[i];
		buffer[i] = left[i];
	//                  l-value = r-value;
	for (int i = 0; i < right.get_size(); i++)
		//buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		buffer[i + left.get_size() - 1] = right.get_str()[i];*/



	return buffer;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHEK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	String str; //Default constructor
	str.print();

	String str1 = "Hello"; //Single-argument constructor
	//str1.print();
	cout << str1 << endl;

	String str2 = str1; //Copy constructor
	cout << str2 << endl;

	String str3;
	str3 = str2; //Shallow copy (поверхностное копирование)
	cout << str3 << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR_PLUS_CHEK
	/*String str1 = "Hello";
str1 = str1;
cout << str1 << endl;*/

	String str1 = "Hello ";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1 + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
	/*cout << delimiter << endl;
	str1 += str2;
	cout << delimiter << endl;
	cout << str1 << endl;*/
#endif // OPERATOR_PLUS_CHEK

	String str1 (25); //Default constructor
	str1.print();
	String str2 = "Hello"; //Single-argument constructor (с одним параметром)
	//cout << str2 << endl;
	str2.print();
	String str3("World"); //Single-argument constructor (с одним параметром)
	cout << str3 << endl;
	String str4(); //ОБЪЯВЛЯЕТСЯ ФУНКЦИЯ str4, КОТОРАЯ НИЧЕГО НЕ ПРИНИМАЕТ И 
	               //ВОЗВРАЩАЕТ ОБЪЕКТ КЛАССА String, то есть не создается объект
	String str5{}; //ЯВНЫЙ ВЫЗОВ КОНСТРУКТОРА ПО УМОЛЧАНИЮ
	cout << str5 << endl;
	String str6{ "Параметры в конструктор можно передавать в фигурных скобках" };
	cout << str6 << endl;
	String str7 = str6;
	cout << str7 << endl;
	cout << str2 + " " + str3 << endl;

}