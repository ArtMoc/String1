//constructors_delegation_in_string
#pragma warning (disable:4326)
#include "String.h"
//------------------------------------------------------------------------------------------------------------------


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