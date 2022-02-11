#include <Windows.h>	
#include <math.h>   					
#include <iomanip> 
#include <iostream>	 
#include <new>


typedef unsigned int int_set;
using namespace std;


class Set
{
public:
	//конструкторы
	Set();													//конструктор по умолчанию
	Set(const Set&); 										//конструктор копирования
	~Set();													//деструктор
	
	//методы
	Set & operator = (const Set&);							//оператор присваивания
	Set	& operator += (const int);							//добавление элемента
	bool operator == (const Set&);							//оператор ==
	bool operator != (const Set&);							//оператор !=
	bool belongSet(const int) const;						//принадлежность элемента множеству
	void print(const char *) const;							//печать множества

	//геттер и сеттер 
	int getSize() const;									//получение количества элементов множества
	void setNumber(const int_set, const int);				//изменение числа множества

	//дружественные функции
	friend Set operator + (const Set&, const Set&);			//объединение
	friend Set operator - (const Set&, const Set&);			//вычитание
	friend Set operator * (const Set&, const Set&);			//пересечение
	friend istream& operator >> (istream&, Set&);			//оператор ввод
	friend ostream& operator << (ostream&, const Set&);		//оператор вывода

private:
	int* pointer;											//указатель на множество
	int_set p_size;											//количество элементов множества
};